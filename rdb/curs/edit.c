#include <curses.h>
#include "cursesXt.h"
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "defs.h"

#ifndef BEEP
#define BEEP nobeep
#endif

static int Erase = 0, Kill = 0, initialized = 0 ;
static int quitEdit[MAXQUITEDIT], quitEditSize = 0 ;
static int leftEdit[MAXQUITEDIT], leftEditSize = 0 ;
static int rightEdit[MAXQUITEDIT], rightEditSize = 0 ;

static char save[BUFSIZE], temp[BUFSIZE] ;

void initEdit()
{ Erase = erasechar() ;
  Kill = killchar() ;
#ifdef EDIT_LEFT
  addLeftEdit(EDIT_LEFT) ;
#endif
#ifdef EDIT_RIGHT
  addRightEdit(EDIT_RIGHT) ;
#endif
}

void emptyQuitEdit() { quitEditSize = 0 ; }

int addQuitEdit(n)
int n ;
{ if ( inQuitEdit(n) ) return 1 ;
  if ( quitEditSize >= MAXQUITEDIT ) return(0) ;
  quitEdit[quitEditSize++] = n ;
  return(1) ;
}

int inQuitEdit(n)
int n ;
{ int i ;
  for ( i = 0 ; i < quitEditSize ; i++ ) if ( quitEdit[i] == n ) return(1) ;
  return(0) ;
}

void emptyLeftEdit() { leftEditSize = 0 ; }

int addLeftEdit(n)
int n ;
{ if ( inLeftEdit(n) ) return 1 ;
  if ( leftEditSize >= MAXQUITEDIT ) return(0) ;
  leftEdit[leftEditSize++] = n ;
  return(1) ;
}

int inLeftEdit(n)
int n ;
{ int i ;
  for ( i = 0 ; i < leftEditSize ; i++ ) if ( leftEdit[i] == n ) return(1) ;
  return(0) ;
}

void emptyRightEdit() { rightEditSize = 0 ; }

int addRightEdit(n)
int n ;
{ if ( inRightEdit(n) ) return 1 ;
  if ( rightEditSize >= MAXQUITEDIT ) return(0) ;
  rightEdit[rightEditSize++] = n ;
  return(1) ;
}

int inRightEdit(n)
int n ;
{ int i ;
  for ( i = 0 ; i < rightEditSize ; i++ ) if ( rightEdit[i] == n ) return(1) ;
  return(0) ;
}

void showline (line,cp,win,ystart,xstart,xlen,rep)
char *line ;
int cp ;
WINDOW* win ;
int ystart,xstart,xlen ;
char rep[4] ;
{ int ll = strlen(line) ;
  int i, h = xlen/2 ;
  char lc, lo, ro, rc ;

  lc = rep[0] ;
  lo = rep[1] ;
  ro = rep[2] ;
  rc = rep[3] ;

  wmove(win,ystart,xstart) ;

  if ( (ll <= xlen) && (cp < xlen) )
    { waddch(win,lc) ;
      for (i=0 ; i<=ll-1 ; i++)
	waddch(win,line[i]) ;
      for (i=ll ; i<xlen ; i++)
	waddch(win,' ') ;
      waddch(win,rc) ;
      wmove(win,ystart,xstart+1+cp) ;
    }
  else if ( (ll == xlen) && (cp == xlen) )
    { waddch(win,lo) ;
      for (i=1 ; i<=ll-1 ; i++)
	waddch(win,line[i]) ;
      waddch(win,' ') ;
      waddch(win,rc) ;
      wmove(win,ystart,xstart+1+cp-1) ;
    }
  else /* ll > xlen */
  if ( cp < h+1 )
    { waddch(win,lc) ;
      for (i=0 ; i<xlen ; i++)
	waddch(win,line[i]) ;
      waddch(win,ro) ;
      wmove(win,ystart,xstart+1+cp) ;
    }
  else if ( cp < ll-xlen+h )
    { waddch(win,lo) ;
      for (i=cp-h ; i<=cp-h+xlen-1 ; i++)
	waddch(win,line[i]) ;
      waddch(win,ro) ;
      wmove(win,ystart,xstart+1+h) ;
    }
  else if ( cp < ll )
    { waddch(win,lo) ;
      for (i=ll-xlen ; i<=ll-1 ; i++)
	waddch(win,line[i]) ;
      waddch(win,rc) ;
      wmove(win,ystart,xstart+1+cp-ll+xlen) ;
    }
  else /* cp == ll */
    { waddch(win,lo) ;
      for (i=ll-xlen+1 ; i<=ll-1 ; i++)
	waddch(win,line[i]) ;
      waddch(win,' ') ;
      waddch(win,rc) ;
      wmove(win,ystart,xstart+1+xlen-1) ;
    }
  wrefresh(win) ;
}

void doCurRight(ll,cp)
int *ll,*cp ;
{ if ( *cp < *ll )
    (*cp)++ ;
  else
    BEEP() ;
}

void doCurLeft(ll,cp)
int *ll,*cp ;
{ if ( *cp > 0 )
    (*cp)-- ;
  else
    BEEP() ;
}

doErase(line,ll,cp)
char *line ;
int *ll,*cp ;
{ int i ; 

  if (*ll == 0 || *cp == 0)
    { strcpy(temp,line) ;
      strcpy(line,save) ;
      strcpy(save,temp) ;
      *ll = strlen(line) ;
      *cp = 0 ;
    }
  else
    { for (i=(*cp)-1 ; i<*ll ; i++)
        line[i] = line[i+1] ;
      (*ll)-- ;
      (*cp)-- ;
    }
}

void doDel(line,ll,cp)
char *line ;
int *ll,*cp ;
{ int i ; 
  
  if (*ll == 0)
    BEEP() ;
  if (*cp == *ll)
    doCurLeft(ll,cp) ;
  else
    { for (i = *cp ; i < *ll ; i++)
        line[i] = line[i+1] ;
      (*ll)-- ;
      if ( *cp > *ll )
        *cp = *ll ;
    }
}

void doInsert(line,maxlinelen,ll,cp,c)
char *line ;
int *ll, *cp, c ;
{ int i ;

  if (*ll > maxlinelen)
    BEEP() ;
  else
    for (i = *ll ; i >= *cp ; i--)
      line[i+1] = line[i] ;
    line[*cp] = c ;
    (*cp)++ ;
    (*ll)++ ;
}

void editCom (line,maxLineLen,linelen,curpos,c)
char *line ;
int maxLineLen, *linelen, *curpos ;
int c ;
{ if ( c == Kill )
    doDel(line,linelen,curpos) ;
  else if ( c == Erase )
    doErase(line,linelen,curpos) ;
  else if ( inRightEdit(c) )
    doCurRight(linelen,curpos) ;
  else if ( inLeftEdit(c) )
    doCurLeft(linelen,curpos) ;
  else if ( (c < 32) || (c > 127) )
    BEEP() ;
  else
    doInsert(line,maxLineLen,linelen,curpos,c) ;
}

int editline (line,maxlinelen,curpos,win,ystart,xstart,xlen,rep)
char *line ;
int maxlinelen, *curpos ;
WINDOW *win ;
int ystart, xstart, xlen ;
char *rep ;
{ int linelen = strlen(line) ;
  int c ;

  if ( ! initialized ) { initEdit() ; initialized = 1 ; }

  strcpy(save,"") ;

  showline(line,*curpos,win,ystart,xstart,xlen,rep) ;

  for ( c=wgetchR(win)
      ; ( c != EOF) && ( ! inQuitEdit(c) )
      ; c=wgetchR(win)
      )
    { editCom(line,maxlinelen,&linelen,curpos,c) ;
      showline(line,*curpos,win,ystart,xstart,xlen,rep) ;
    }

  showline(line,0,win,ystart,xstart,xlen,rep) ;
  return(c) ;
}
