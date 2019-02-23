#include <stdio.h>
#include <curses.h>
#include "cursesXt.h"
#include "defs.h"

void initCursesXt()
{ /* called by do_initscr ; */
  ;
}

int getLINES() { return(LINES) ; }
int getCOLS()  { return(COLS) ; }

int wgetchR(w)
WINDOW *w ;
{ int x,y,c ;
  for ( c = wgetch(w)
      ; ( c == REDRAW_INT ) || ( optX && ( c == OPTX_INT ) )
      ; c = wgetch(w)
      )
    { if ( c == REDRAW_INT )
	{ getyx(w,y,x) ;
	  redraw() ;
          wmove(w,y,x) ;
	  wrefresh(w) ;
	}
      else if ( c == OPTX_INT )
	{ curStat() ; }
    }
  return(c) ;
}

int getchR()
{ return(wgetchR(stdscr)) ; }

void quitcterm()
{ quit() ;
}

void wshow (win,line,cp,ystart,xstart,xlen,rep)
WINDOW *win ;
char *line ;
int cp, ystart,xstart,xlen ;
char *rep ;
{ showline(line,cp,win,ystart,xstart,xlen,rep) ;
}

void show (line,cp,ystart,xstart,xlen,rep)
char *line ;
int cp, ystart,xstart,xlen ;
char *rep ;
{ showline(line,cp,stdscr,ystart,xstart,xlen,rep) ;
}

int wedit (win,line,curpos,ystart,xstart,xlen,rep)
WINDOW *win ;
char *line ;
int curpos, ystart, xstart, xlen ;
char *rep ;
{ int c ;
  c = editline (line,BUFSIZE,&curpos,win,ystart,xstart,xlen,rep) ;
  addlogsn(LOGCURS2,"wedit returns",c) ;
  return( c ) ;
}

int edit (line,curpos,ystart,xstart,xlen,rep)
char *line ;
int curpos, ystart, xstart, xlen ;
char *rep ;
{ int c ;
  c = editline (line,BUFSIZE,&curpos,stdscr,ystart,xstart,xlen,rep) ;
  addlogsn(LOGCURS2,"edit returns",c) ;
  return( c ) ;
}

void mybeep() { fprintf(stderr,"%c",7) ; }
void nobeep() { ; }

void wclrreg(w,top,bot)
WINDOW *w ;
int top,bot ;
{ int i ;
  for ( i = top ; i <= bot ; i++ )
    { wmove(w,i,0) ;
      wclrtoeol(w) ;
    }
}

void clrreg(top,bot)
int top,bot ;
{ wclrreg(stdscr,top,bot) ; }

void ctermlog(s) char *s ; { addlogss(LOGAPPL,"LOG",s) ; }

int editq(n)      int n ;   { return(addQuitEdit(n)) ; }
void editreset()            { emptyQuitEdit() ; }
int editl(n)      int n ;   { return(addLeftEdit(n)) ; }
void editlreset()           { emptyLeftEdit() ; }
int editr(n)      int n ;   { return(addRightEdit(n)) ; }
void editrreset()           { emptyRightEdit() ; }
void curnop()               { ; }
void curflush()             { ; }

/*
Example implementations of killchar() ; erasechar() ; beep() ;
Quite non-portable; just to show that it should be simple.

#include <termio.h>

killchar()
{ struct termio ttt ;
  ioctl(0,TCGETA,&ttt) ;
  return(ttt.c_cc[VKILL]) ;
}

erasechar()
{ struct termio ttt ;
  ioctl(0,TCGETA,&ttt) ;
  return(ttt.c_cc[VERASE]) ;
}

beep()
{ BEEP() ;
}

*/

/* On a Convex, add the following lines for compatibility.

cbreak() { crmode() ; }
nocbreak() { nocrmode() ; }

*/
