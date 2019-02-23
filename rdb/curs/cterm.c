#include <curses.h>
#include "cursesXt.h"
#include <signal.h>
#include <stdio.h>
#include "defs.h"

FILE *OUT ;
WINDOW *windows[MAXNUMWINDOWS] ;
int optX = 0, hasWin = 0 ;

static int hasOUT = 0 ;
static FILE *LOG ;
static int in = -1, out = -1 ;
static int n, loglevel = -1 ;
static char com[BUFSIZE], buf[BUFSIZE] ;
static int comSize = 0, bufSize = 0, bufhead = 0, buftail = 0 ;
static int numread = 0, numreads = 0 ;
static char outstr[1024] ;

curStat()
{ int n,i,y,x ;
  char s[80] ;

  sprintf(s,"reads %d, read %d, average %d",numreads,numread,numread/numreads) ;
  getyx(stdscr,y,x) ;
  mvinsch(0,0,'|') ;
  for (i=strlen(s)-1 ; i>=0 ; i--)
    { mvinsch(0,0,s[i]) ; }
  move(y,x) ;
  refresh() ;
}

void redraw()
{ int i ;

  for ( i = 0 ; i < MAXNUMWINDOWS ; i++ )
    if ( ( windows[i] != NULL ) && ( windows[i] != curscr ) )
      { clearok(windows[i],1) ;
        wrefresh(windows[i]) ;
      }
}

void addlogs(level,s)
int level ;
char *s ;
{ if ( level <= loglevel )
    { fprintf(LOG,"%s\n",s) ;
      fflush(LOG) ;
    }
}

void addlogsn(level,s,n)
int level ;
char *s ;
int n ;
{ if ( level <= loglevel )
    { fprintf(LOG,"%s %d\n",s,n) ;
      fflush(LOG) ;
    }
}

void addlogss(level,s1,s2)
int level ;
char *s1, *s2 ;
{ if ( level <= loglevel )
    { fprintf(LOG,"%s %s\n",s1,s2) ;
      fflush(LOG) ;
    }
}

void quit()
{ addlogs(LOGCURS1,"quit") ;
  if ( hasWin ) { addlogs(LOGCURS1,"endwin") ; endwin() ; }
  if ( hasOUT ) fclose(OUT) ; else close(out) ;
  addlogs(LOGCURS1,"gone") ;
  exit(1) ;
}

void sig_quit()
{ addlogs(LOGCURS1,"sig_quit") ;
  quit() ;
}

int incMod(x,y) int *x, y ; { *x = ((*x)+1) % y ; return(*x) ; }

int isemptyq() { return(bufSize == 0) ; }

void enqueue(c)
char c ;
{ buf[buftail] = c ; bufSize++ ; incMod(&buftail,BUFSIZE) ; }

int dequeue()
{ char c ;
  c = buf[bufhead] ; bufSize-- ; incMod(&bufhead,BUFSIZE) ; return(c) ;
}

int getCom()
{ int res, c, i, found ;
  char row[BUFSIZE2] ;
  char mes[100] ;

  res = 1 ;
  found = 0 ;
  comSize = 0 ;

  do { c = 'x' ;
       while ( ( !isemptyq() ) && ( (c = dequeue()) != SEP ) )
	 { com[comSize++] = c ; }
       if (c == SEP)
	 { com[comSize] = 0 ;
	   found = 1 ;
	 }
       else
	 { res = read(in,row,BUFSIZE2) ;
	   if (res < 0)
	     { addlogs(LOGCURS1,"read error") ;
	       quit() ;
	     }
	   if ( res )
             { numread += res ;
	       numreads++ ;
	       for (i=0 ; i<res ; i++)
                 { enqueue(row[i]) ; }
             }
	   else
	     { addlogs(LOGCURS1,"read 0 chars") ;
	       found = 1 ;
	     }
	 }
     }
  while ( ! found ) ;

  addlogs(LOGCURS2,com) ;

  return(res) ;
}

int nextInt()
{ int n ;
  if ( ! getCom() ) quit() ;
  sscanf(com,"%d",&n) ;
  addlogsn(LOGCURS1,"nextInt",n) ;
  return(n) ;
}

int nextCom()
{ int n ;
  if ( ! getCom() ) quit() ;
  sscanf(com,"%d",&n) ;
  addlogsn(LOGCURS2,"nextCom",n) ;
  return(n) ;
}

int nextChr()
{ int c = 0 ;
  if ( ! getCom() ) quit() ;
  addlogsn(LOGCURS1,"nextChr",com[0]) ;
  return(com[0]) ;
}

char *nextStr()
{ if ( ! getCom() ) quit() ;
  addlogss(LOGCURS1,"nextStr",com) ;
  return(&(com[0])) ;
}

void initWindows()
{ int i ;
  for ( i = 0 ; i < MAXNUMWINDOWS ; i++ )
    { windows[i] = NULL ; }
}

void unsaveWindow(i) int i ; { windows[i] = NULL ; }

int saveWindow(w)
WINDOW *w ;
{ int i ;
  for ( i = 0 ; i < MAXNUMWINDOWS && windows[i] != NULL ; i++ ) { ; }
  if ( i < MAXNUMWINDOWS )
   { windows[i] = w ; return(i) ; }
  else
    { delwin(w) ; return(-1) ; }
}

main(argc,argv)
int argc ;
char **argv ;
{ int c ;
  char *prog ;

  prog = argv[0] ; argv++ ; argc-- ;

  if ( argc < 2 )
    { fprintf(stderr,"Usage: cterm in out [options] [logfile [level]]\n") ; 
      fprintf(stderr,"cterm version 2.1, ") ; 
      fprintf(stderr,"Copyright (c) 1990, Henk P. Penning.\n") ; 
      exit(1) ;
    } 
  else
    { in  = atoi(*argv) ; argc-- ; argv++ ;
      out = atoi(*argv) ; argc-- ; argv++ ;
    }

  while ( ( argc > 0 ) && ( argv[0][0] == '-' ) )
    { switch ( argv[0][1] ) {
      case 'X' : optX = 1 ;
		 break ;
      case 0   : fprintf(stderr,"unknown option %s\n", "-") ; 
	         exit(1) ;
		 break ;
      default  : fprintf(stderr,"unknown option %c\n", argv[0][1]) ; 
	         exit(1) ;
		 break ;
      }
      argc-- ; argv++ ;
    }

  if ( argc > 0 )
    { LOG = fopen(*argv,"w") ;
      if ( LOG == NULL )
	{ fprintf(stderr,"cannot open log file %s\n", *argv) ; 
	  exit(1) ;
	} 
      argc-- ; argv++ ;
      if ( argc > 0 )
        { loglevel = atoi(*argv) ; }
      else
        { loglevel = 0 ; } 
    }

  signal(SIGINT,sig_quit) ;
  signal(SIGPIPE,sig_quit) ;

  OUT = fdopen (out,"w") ; hasOUT++ ;

  addlogsn(LOGCURS1,"option X",optX) ;

  init_funtab() ;

  while (1)
    { n = nextCom() ;
      (*(funtab[n]))() ;
    }

}
