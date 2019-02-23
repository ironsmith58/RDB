#include <stdio.h>
#include <curses.h>
#include "cursesXt.h"
#include "defs.h"

static int attrs ;
static int bot ;
static char ch ;
static int chint ;
static int curpos ;
static int delw ;
static int fd ;
static int flag ;
static char hor ;
static int ms ;
static int newcol ;
static int newrow ;
static int num_cols ;
static int num_lines ;
static int oldcol ;
static int oldrow ;
static int pad ;
static int pmincol ;
static int pminrow ;
static char rep[BUFSIZE] ;
static int resint ;
static char resstr[BUFSIZE] ;
static WINDOW *reswin ;
static int smaxcol ;
static int smaxrow ;
static int smincol ;
static int sminrow ;
static char str[BUFSIZE] ;
static int top ;
static char vert ;
static WINDOW *win ;
static WINDOW *win1 ;
static WINDOW *win2 ;
static int x ;
static int xlen ;
static int y ;
static int res ;

void do_getLINES() {
  addlogs(LOGCURS1,"getLINES") ;
  resint = getLINES() ;
  fprintf(OUT,"%d\n",resint) ;
  addlogsn(LOGCURS1,"do_getLINES prints OUT",resint) ;
  fflush(OUT) ;
}
void do_getCOLS() {
  addlogs(LOGCURS1,"getCOLS") ;
  resint = getCOLS() ;
  fprintf(OUT,"%d\n",resint) ;
  addlogsn(LOGCURS1,"do_getCOLS prints OUT",resint) ;
  fflush(OUT) ;
}
void do_edit() {
  addlogs(LOGCURS1,"edit") ;
  strcpy(str,nextStr()) ;
  curpos = nextInt() ;
  y = nextInt() ;
  x = nextInt() ;
  xlen = nextInt() ;
  strcpy(rep,nextStr()) ;
  resint = edit(str,curpos,y,x,xlen,rep) ;
  fprintf(OUT,"%s\n",str) ;
  addlogss(LOGCURS1,"do_edit prints OUT",str) ;
  fprintf(OUT,"%d\n",resint) ;
  addlogsn(LOGCURS1,"do_edit prints OUT",resint) ;
  fflush(OUT) ;
}
void do_wedit() {
  addlogs(LOGCURS1,"wedit") ;
  win = windows[nextInt()] ;
  strcpy(str,nextStr()) ;
  curpos = nextInt() ;
  y = nextInt() ;
  x = nextInt() ;
  xlen = nextInt() ;
  strcpy(rep,nextStr()) ;
  resint = wedit(win,str,curpos,y,x,xlen,rep) ;
  fprintf(OUT,"%s\n",str) ;
  addlogss(LOGCURS1,"do_wedit prints OUT",str) ;
  fprintf(OUT,"%d\n",resint) ;
  addlogsn(LOGCURS1,"do_wedit prints OUT",resint) ;
  fflush(OUT) ;
}
void do_show() {
  addlogs(LOGCURS1,"show") ;
  strcpy(str,nextStr()) ;
  curpos = nextInt() ;
  y = nextInt() ;
  x = nextInt() ;
  xlen = nextInt() ;
  strcpy(rep,nextStr()) ;
  show(str,curpos,y,x,xlen,rep) ;
}
void do_wshow() {
  addlogs(LOGCURS1,"wshow") ;
  win = windows[nextInt()] ;
  strcpy(str,nextStr()) ;
  curpos = nextInt() ;
  y = nextInt() ;
  x = nextInt() ;
  xlen = nextInt() ;
  strcpy(rep,nextStr()) ;
  wshow(win,str,curpos,y,x,xlen,rep) ;
}
void do_editq() {
  addlogs(LOGCURS1,"editq") ;
  chint = nextInt() ;
  editq(chint) ;
}
void do_editreset() {
  addlogs(LOGCURS1,"editreset") ;
  editreset() ;
}
void do_editl() {
  addlogs(LOGCURS1,"editl") ;
  chint = nextInt() ;
  editl(chint) ;
}
void do_editlreset() {
  addlogs(LOGCURS1,"editlreset") ;
  editlreset() ;
}
void do_editr() {
  addlogs(LOGCURS1,"editr") ;
  chint = nextInt() ;
  editr(chint) ;
}
void do_editrreset() {
  addlogs(LOGCURS1,"editrreset") ;
  editrreset() ;
}
void do_ctermlog() {
  addlogs(LOGCURS1,"ctermlog") ;
  strcpy(str,nextStr()) ;
  ctermlog(str) ;
}
void do_quitcterm() {
  addlogs(LOGCURS1,"quitcterm") ;
  quitcterm() ;
}
void do_getchR() {
  addlogs(LOGCURS1,"getchR") ;
  resint = getchR() ;
  fprintf(OUT,"%d\n",resint) ;
  addlogsn(LOGCURS1,"do_getchR prints OUT",resint) ;
  fflush(OUT) ;
}
void do_wgetchR() {
  addlogs(LOGCURS1,"wgetchR") ;
  win = windows[nextInt()] ;
  resint = wgetchR(win) ;
  fprintf(OUT,"%d\n",resint) ;
  addlogsn(LOGCURS1,"do_wgetchR prints OUT",resint) ;
  fflush(OUT) ;
}
void do_clrreg() {
  addlogs(LOGCURS1,"clrreg") ;
  top = nextInt() ;
  bot = nextInt() ;
  clrreg(top,bot) ;
}
void do_wclrreg() {
  addlogs(LOGCURS1,"wclrreg") ;
  win = windows[nextInt()] ;
  top = nextInt() ;
  bot = nextInt() ;
  wclrreg(win,top,bot) ;
}
void do_addch() {
  addlogs(LOGCURS1,"addch") ;
  ch = nextChr() ;
  addch(ch) ;
}
void do_addstr() {
  addlogs(LOGCURS1,"addstr") ;
  strcpy(str,nextStr()) ;
  addstr(str) ;
}
void do_attroff() {
  addlogs(LOGCURS1,"attroff") ;
  attrs = nextInt() ;
  attroff(attrs) ;
}
void do_attron() {
  addlogs(LOGCURS1,"attron") ;
  attrs = nextInt() ;
  attron(attrs) ;
}
void do_attrset() {
  addlogs(LOGCURS1,"attrset") ;
  attrs = nextInt() ;
  attrset(attrs) ;
}
void do_baudrate() {
  addlogs(LOGCURS1,"baudrate") ;
  resint = baudrate() ;
  fprintf(OUT,"%d\n",resint) ;
  addlogsn(LOGCURS1,"do_baudrate prints OUT",resint) ;
  fflush(OUT) ;
}
void do_beep() {
  addlogs(LOGCURS1,"beep") ;
  beep() ;
}
void do_box() {
  addlogs(LOGCURS1,"box") ;
  win = windows[nextInt()] ;
  vert = nextChr() ;
  hor = nextChr() ;
  box(win,vert,hor) ;
}
void do_cbreak() {
  addlogs(LOGCURS1,"cbreak") ;
  cbreak() ;
}
void do_clear() {
  addlogs(LOGCURS1,"clear") ;
  clear() ;
}
void do_clearok() {
  addlogs(LOGCURS1,"clearok") ;
  win = windows[nextInt()] ;
  flag = nextInt() ;
  clearok(win,flag) ;
}
void do_clrtobot() {
  addlogs(LOGCURS1,"clrtobot") ;
  clrtobot() ;
}
void do_clrtoeol() {
  addlogs(LOGCURS1,"clrtoeol") ;
  clrtoeol() ;
}
void do_delch() {
  addlogs(LOGCURS1,"delch") ;
  delch() ;
}
void do_deleteln() {
  addlogs(LOGCURS1,"deleteln") ;
  deleteln() ;
}
void do_delwin() {
  addlogs(LOGCURS1,"delwin") ;
  delw = nextInt() ;
  win = windows[delw] ;
  unsaveWindow(delw) ;
  delwin(win) ;
}
void do_doupdate() {
  addlogs(LOGCURS1,"doupdate") ;
  doupdate() ;
}
void do_draino() {
  addlogs(LOGCURS1,"draino") ;
  ms = nextInt() ;
  draino(ms) ;
}
void do_echo() {
  addlogs(LOGCURS1,"echo") ;
  echo() ;
}
void do_endwin() {
  addlogs(LOGCURS1,"endwin") ;
  endwin() ;
  hasWin = 0 ;
}
void do_erase() {
  addlogs(LOGCURS1,"erase") ;
  erase() ;
}
void do_erasechar() {
  addlogs(LOGCURS1,"erasechar") ;
  resint = erasechar() ;
  fprintf(OUT,"%d\n",resint) ;
  addlogsn(LOGCURS1,"do_erasechar prints OUT",resint) ;
  fflush(OUT) ;
}
void do_fixterm() {
  addlogs(LOGCURS1,"fixterm") ;
  fixterm() ;
}
void do_flash() {
  addlogs(LOGCURS1,"flash") ;
  flash() ;
}
void do_flushinp() {
  addlogs(LOGCURS1,"flushinp") ;
  flushinp() ;
}
void do_getch() {
  addlogs(LOGCURS1,"getch") ;
  resint = getch() ;
  fprintf(OUT,"%d\n",resint) ;
  addlogsn(LOGCURS1,"do_getch prints OUT",resint) ;
  fflush(OUT) ;
}
void do_getstr() {
  addlogs(LOGCURS1,"getstr") ;
  getstr(str) ;
  fprintf(OUT,"%s\n",str) ;
  addlogss(LOGCURS1,"do_getstr prints OUT",str) ;
  fflush(OUT) ;
}
void do_getyx() {
  addlogs(LOGCURS1,"getyx") ;
  win = windows[nextInt()] ;
  getyx(win,y,x) ;
  fprintf(OUT,"%d\n",y) ;
  addlogsn(LOGCURS1,"do_getyx prints OUT",y) ;
  fprintf(OUT,"%d\n",x) ;
  addlogsn(LOGCURS1,"do_getyx prints OUT",x) ;
  fflush(OUT) ;
}
void do_has_ic() {
  addlogs(LOGCURS1,"has_ic") ;
  resint = has_ic() ;
  fprintf(OUT,"%d\n",resint) ;
  addlogsn(LOGCURS1,"do_has_ic prints OUT",resint) ;
  fflush(OUT) ;
}
void do_has_il() {
  addlogs(LOGCURS1,"has_il") ;
  resint = has_il() ;
  fprintf(OUT,"%d\n",resint) ;
  addlogsn(LOGCURS1,"do_has_il prints OUT",resint) ;
  fflush(OUT) ;
}
void do_idlok() {
  addlogs(LOGCURS1,"idlok") ;
  win = windows[nextInt()] ;
  flag = nextInt() ;
  idlok(win,flag) ;
}
void do_inch() {
  addlogs(LOGCURS1,"inch") ;
  resint = inch() ;
  fprintf(OUT,"%d\n",resint) ;
  addlogsn(LOGCURS1,"do_inch prints OUT",resint) ;
  fflush(OUT) ;
}
void do_initscr() {
  addlogs(LOGCURS1,"initscr") ;
  initscr() ;
  hasWin = 1 ;
  initWindows() ;
  saveWindow(stdscr) ;
  saveWindow(curscr) ;
  initCursesXt() ;
}
void do_insch() {
  addlogs(LOGCURS1,"insch") ;
  ch = nextChr() ;
  insch(ch) ;
}
void do_insertln() {
  addlogs(LOGCURS1,"insertln") ;
  insertln() ;
}
void do_intrflush() {
  addlogs(LOGCURS1,"intrflush") ;
  win = windows[nextInt()] ;
  flag = nextInt() ;
  intrflush(win,flag) ;
}
void do_keypad() {
  addlogs(LOGCURS1,"keypad") ;
  win = windows[nextInt()] ;
  flag = nextInt() ;
  keypad(win,flag) ;
}
void do_killchar() {
  addlogs(LOGCURS1,"killchar") ;
  resint = killchar() ;
  fprintf(OUT,"%d\n",resint) ;
  addlogsn(LOGCURS1,"do_killchar prints OUT",resint) ;
  fflush(OUT) ;
}
void do_leaveok() {
  addlogs(LOGCURS1,"leaveok") ;
  win = windows[nextInt()] ;
  flag = nextInt() ;
  leaveok(win,flag) ;
}
void do_longname() {
  addlogs(LOGCURS1,"longname") ;
  strcpy(resstr,longname()) ;
  fprintf(OUT,"%s\n",resstr) ;
  addlogss(LOGCURS1,"do_longname prints OUT",resstr) ;
  fflush(OUT) ;
}
void do_meta() {
  addlogs(LOGCURS1,"meta") ;
  win = windows[nextInt()] ;
  flag = nextInt() ;
  resint = meta(win,flag) ;
  fprintf(OUT,"%d\n",resint) ;
  addlogsn(LOGCURS1,"do_meta prints OUT",resint) ;
  fflush(OUT) ;
}
void do_move() {
  addlogs(LOGCURS1,"move") ;
  y = nextInt() ;
  x = nextInt() ;
  move(y,x) ;
}
void do_mvaddch() {
  addlogs(LOGCURS1,"mvaddch") ;
  y = nextInt() ;
  x = nextInt() ;
  ch = nextChr() ;
  mvaddch(y,x,ch) ;
}
void do_mvaddstr() {
  addlogs(LOGCURS1,"mvaddstr") ;
  y = nextInt() ;
  x = nextInt() ;
  strcpy(str,nextStr()) ;
  mvaddstr(y,x,str) ;
}
void do_mvcur() {
  addlogs(LOGCURS1,"mvcur") ;
  oldrow = nextInt() ;
  oldcol = nextInt() ;
  newrow = nextInt() ;
  newcol = nextInt() ;
  mvcur(oldrow,oldcol,newrow,newcol) ;
}
void do_mvdelch() {
  addlogs(LOGCURS1,"mvdelch") ;
  y = nextInt() ;
  x = nextInt() ;
  mvdelch(y,x) ;
}
void do_mvgetch() {
  addlogs(LOGCURS1,"mvgetch") ;
  y = nextInt() ;
  x = nextInt() ;
  resint = mvgetch(y,x) ;
  fprintf(OUT,"%d\n",resint) ;
  addlogsn(LOGCURS1,"do_mvgetch prints OUT",resint) ;
  fflush(OUT) ;
}
void do_mvgetstr() {
  addlogs(LOGCURS1,"mvgetstr") ;
  y = nextInt() ;
  x = nextInt() ;
  mvgetstr(y,x,str) ;
  fprintf(OUT,"%s\n",str) ;
  addlogss(LOGCURS1,"do_mvgetstr prints OUT",str) ;
  fflush(OUT) ;
}
void do_mvinch() {
  addlogs(LOGCURS1,"mvinch") ;
  y = nextInt() ;
  x = nextInt() ;
  resint = mvinch(y,x) ;
  fprintf(OUT,"%d\n",resint) ;
  addlogsn(LOGCURS1,"do_mvinch prints OUT",resint) ;
  fflush(OUT) ;
}
void do_mvinsch() {
  addlogs(LOGCURS1,"mvinsch") ;
  y = nextInt() ;
  x = nextInt() ;
  ch = nextChr() ;
  mvinsch(y,x,ch) ;
}
void do_mvwaddch() {
  addlogs(LOGCURS1,"mvwaddch") ;
  win = windows[nextInt()] ;
  y = nextInt() ;
  x = nextInt() ;
  ch = nextChr() ;
  mvwaddch(win,y,x,ch) ;
}
void do_mvwaddstr() {
  addlogs(LOGCURS1,"mvwaddstr") ;
  win = windows[nextInt()] ;
  y = nextInt() ;
  x = nextInt() ;
  strcpy(str,nextStr()) ;
  mvwaddstr(win,y,x,str) ;
}
void do_mvwdelch() {
  addlogs(LOGCURS1,"mvwdelch") ;
  win = windows[nextInt()] ;
  y = nextInt() ;
  x = nextInt() ;
  mvwdelch(win,y,x) ;
}
void do_mvwgetch() {
  addlogs(LOGCURS1,"mvwgetch") ;
  win = windows[nextInt()] ;
  y = nextInt() ;
  x = nextInt() ;
  resint = mvwgetch(win,y,x) ;
  fprintf(OUT,"%d\n",resint) ;
  addlogsn(LOGCURS1,"do_mvwgetch prints OUT",resint) ;
  fflush(OUT) ;
}
void do_mvwgetstr() {
  addlogs(LOGCURS1,"mvwgetstr") ;
  win = windows[nextInt()] ;
  y = nextInt() ;
  x = nextInt() ;
  mvwgetstr(win,y,x,str) ;
  fprintf(OUT,"%s\n",str) ;
  addlogss(LOGCURS1,"do_mvwgetstr prints OUT",str) ;
  fflush(OUT) ;
}
void do_mvwin() {
  addlogs(LOGCURS1,"mvwin") ;
  win = windows[nextInt()] ;
  y = nextInt() ;
  x = nextInt() ;
  mvwin(win,y,x) ;
}
void do_mvwinch() {
  addlogs(LOGCURS1,"mvwinch") ;
  win = windows[nextInt()] ;
  y = nextInt() ;
  x = nextInt() ;
  resint = mvwinch(win,y,x) ;
  fprintf(OUT,"%d\n",resint) ;
  addlogsn(LOGCURS1,"do_mvwinch prints OUT",resint) ;
  fflush(OUT) ;
}
void do_mvwinsch() {
  addlogs(LOGCURS1,"mvwinsch") ;
  win = windows[nextInt()] ;
  y = nextInt() ;
  x = nextInt() ;
  ch = nextChr() ;
  mvwinsch(win,y,x,ch) ;
}
void do_napms() {
  addlogs(LOGCURS1,"napms") ;
  ms = nextInt() ;
  napms(ms) ;
}
void do_newpad() {
  addlogs(LOGCURS1,"newpad") ;
  num_lines = nextInt() ;
  num_cols = nextInt() ;
  reswin = newpad(num_lines,num_cols) ;
  res = saveWindow(reswin) ;
  fprintf(OUT,"%d\n",res) ;
  addlogsn(LOGCURS1,"do_newpad prints OUT",res) ;
  fflush(OUT) ;
}
void do_newwin() {
  addlogs(LOGCURS1,"newwin") ;
  num_lines = nextInt() ;
  num_cols = nextInt() ;
  y = nextInt() ;
  x = nextInt() ;
  reswin = newwin(num_lines,num_cols,y,x) ;
  res = saveWindow(reswin) ;
  fprintf(OUT,"%d\n",res) ;
  addlogsn(LOGCURS1,"do_newwin prints OUT",res) ;
  fflush(OUT) ;
}
void do_nl() {
  addlogs(LOGCURS1,"nl") ;
  nl() ;
}
void do_nocbreak() {
  addlogs(LOGCURS1,"nocbreak") ;
  nocbreak() ;
}
void do_nodelay() {
  addlogs(LOGCURS1,"nodelay") ;
  win = windows[nextInt()] ;
  flag = nextInt() ;
  nodelay(win,flag) ;
}
void do_noecho() {
  addlogs(LOGCURS1,"noecho") ;
  noecho() ;
}
void do_nonl() {
  addlogs(LOGCURS1,"nonl") ;
  nonl() ;
}
void do_noraw() {
  addlogs(LOGCURS1,"noraw") ;
  noraw() ;
}
void do_overlay() {
  addlogs(LOGCURS1,"overlay") ;
  win1 = windows[nextInt()] ;
  win2 = windows[nextInt()] ;
  overlay(win1,win2) ;
}
void do_overwrite() {
  addlogs(LOGCURS1,"overwrite") ;
  win1 = windows[nextInt()] ;
  win2 = windows[nextInt()] ;
  overwrite(win1,win2) ;
}
void do_pnoutrefresh() {
  addlogs(LOGCURS1,"pnoutrefresh") ;
  pad = nextInt() ;
  pminrow = nextInt() ;
  pmincol = nextInt() ;
  sminrow = nextInt() ;
  smincol = nextInt() ;
  smaxrow = nextInt() ;
  smaxcol = nextInt() ;
  pnoutrefresh(pad,pminrow,pmincol,sminrow,smincol,smaxrow,smaxcol) ;
}
void do_prefresh() {
  addlogs(LOGCURS1,"prefresh") ;
  pad = nextInt() ;
  pminrow = nextInt() ;
  pmincol = nextInt() ;
  sminrow = nextInt() ;
  smincol = nextInt() ;
  smaxrow = nextInt() ;
  smaxcol = nextInt() ;
  prefresh(pad,pminrow,pmincol,sminrow,smincol,smaxrow,smaxcol) ;
}
void do_raw() {
  addlogs(LOGCURS1,"raw") ;
  raw() ;
}
void do_refresh() {
  addlogs(LOGCURS1,"refresh") ;
  refresh() ;
}
void do_resetterm() {
  addlogs(LOGCURS1,"resetterm") ;
  resetterm() ;
}
void do_resetty() {
  addlogs(LOGCURS1,"resetty") ;
  resetty() ;
}
void do_saveterm() {
  addlogs(LOGCURS1,"saveterm") ;
  saveterm() ;
}
void do_savetty() {
  addlogs(LOGCURS1,"savetty") ;
  savetty() ;
}
void do_scroll() {
  addlogs(LOGCURS1,"scroll") ;
  win = windows[nextInt()] ;
  scroll(win) ;
}
void do_scrollok() {
  addlogs(LOGCURS1,"scrollok") ;
  win = windows[nextInt()] ;
  flag = nextInt() ;
  scrollok(win,flag) ;
}
void do_setscrreg() {
  addlogs(LOGCURS1,"setscrreg") ;
  top = nextInt() ;
  bot = nextInt() ;
  setscrreg(top,bot) ;
}
void do_standend() {
  addlogs(LOGCURS1,"standend") ;
  standend() ;
}
void do_standout() {
  addlogs(LOGCURS1,"standout") ;
  standout() ;
}
void do_subwin() {
  addlogs(LOGCURS1,"subwin") ;
  win = windows[nextInt()] ;
  num_lines = nextInt() ;
  num_cols = nextInt() ;
  y = nextInt() ;
  x = nextInt() ;
  reswin = subwin(win,num_lines,num_cols,y,x) ;
  res = saveWindow(reswin) ;
  fprintf(OUT,"%d\n",res) ;
  addlogsn(LOGCURS1,"do_subwin prints OUT",res) ;
  fflush(OUT) ;
}
void do_touchwin() {
  addlogs(LOGCURS1,"touchwin") ;
  win = windows[nextInt()] ;
  touchwin(win) ;
}
void do_typeahead() {
  addlogs(LOGCURS1,"typeahead") ;
  fd = nextInt() ;
  typeahead(fd) ;
}
void do_unctrl() {
  addlogs(LOGCURS1,"unctrl") ;
  chint = nextInt() ;
  strcpy(resstr,unctrl(chint)) ;
  fprintf(OUT,"%s\n",resstr) ;
  addlogss(LOGCURS1,"do_unctrl prints OUT",resstr) ;
  fflush(OUT) ;
}
void do_waddch() {
  addlogs(LOGCURS1,"waddch") ;
  win = windows[nextInt()] ;
  ch = nextChr() ;
  waddch(win,ch) ;
}
void do_waddstr() {
  addlogs(LOGCURS1,"waddstr") ;
  win = windows[nextInt()] ;
  strcpy(str,nextStr()) ;
  waddstr(win,str) ;
}
void do_wattroff() {
  addlogs(LOGCURS1,"wattroff") ;
  win = windows[nextInt()] ;
  attrs = nextInt() ;
  wattroff(win,attrs) ;
}
void do_wattron() {
  addlogs(LOGCURS1,"wattron") ;
  win = windows[nextInt()] ;
  attrs = nextInt() ;
  wattron(win,attrs) ;
}
void do_wattrset() {
  addlogs(LOGCURS1,"wattrset") ;
  win = windows[nextInt()] ;
  attrs = nextInt() ;
  wattrset(win,attrs) ;
}
void do_wclear() {
  addlogs(LOGCURS1,"wclear") ;
  win = windows[nextInt()] ;
  wclear(win) ;
}
void do_wclrtobot() {
  addlogs(LOGCURS1,"wclrtobot") ;
  win = windows[nextInt()] ;
  wclrtobot(win) ;
}
void do_wclrtoeol() {
  addlogs(LOGCURS1,"wclrtoeol") ;
  win = windows[nextInt()] ;
  wclrtoeol(win) ;
}
void do_wdelch() {
  addlogs(LOGCURS1,"wdelch") ;
  win = windows[nextInt()] ;
  wdelch(win) ;
}
void do_wdeleteln() {
  addlogs(LOGCURS1,"wdeleteln") ;
  win = windows[nextInt()] ;
  wdeleteln(win) ;
}
void do_werase() {
  addlogs(LOGCURS1,"werase") ;
  win = windows[nextInt()] ;
  werase(win) ;
}
void do_wgetch() {
  addlogs(LOGCURS1,"wgetch") ;
  win = windows[nextInt()] ;
  resint = wgetch(win) ;
  fprintf(OUT,"%d\n",resint) ;
  addlogsn(LOGCURS1,"do_wgetch prints OUT",resint) ;
  fflush(OUT) ;
}
void do_wgetstr() {
  addlogs(LOGCURS1,"wgetstr") ;
  win = windows[nextInt()] ;
  wgetstr(win,str) ;
  fprintf(OUT,"%s\n",str) ;
  addlogss(LOGCURS1,"do_wgetstr prints OUT",str) ;
  fflush(OUT) ;
}
void do_winch() {
  addlogs(LOGCURS1,"winch") ;
  win = windows[nextInt()] ;
  resint = winch(win) ;
  fprintf(OUT,"%d\n",resint) ;
  addlogsn(LOGCURS1,"do_winch prints OUT",resint) ;
  fflush(OUT) ;
}
void do_winsch() {
  addlogs(LOGCURS1,"winsch") ;
  win = windows[nextInt()] ;
  ch = nextChr() ;
  winsch(win,ch) ;
}
void do_winsertln() {
  addlogs(LOGCURS1,"winsertln") ;
  win = windows[nextInt()] ;
  winsertln(win) ;
}
void do_wmove() {
  addlogs(LOGCURS1,"wmove") ;
  win = windows[nextInt()] ;
  y = nextInt() ;
  x = nextInt() ;
  wmove(win,y,x) ;
}
void do_wnoutrefresh() {
  addlogs(LOGCURS1,"wnoutrefresh") ;
  win = windows[nextInt()] ;
  wnoutrefresh(win) ;
}
void do_wrefresh() {
  addlogs(LOGCURS1,"wrefresh") ;
  win = windows[nextInt()] ;
  wrefresh(win) ;
}
void do_wsetscrreg() {
  addlogs(LOGCURS1,"wsetscrreg") ;
  win = windows[nextInt()] ;
  top = nextInt() ;
  bot = nextInt() ;
  wsetscrreg(win,top,bot) ;
}
void do_wstandend() {
  addlogs(LOGCURS1,"wstandend") ;
  win = windows[nextInt()] ;
  wstandend(win) ;
}
void do_wstandout() {
  addlogs(LOGCURS1,"wstandout") ;
  win = windows[nextInt()] ;
  wstandout(win) ;
}
void (*(funtab[126]))() ;
void init_funtab() {
  funtab[0] = do_getLINES ;
  funtab[1] = do_getCOLS ;
  funtab[2] = do_edit ;
  funtab[3] = do_wedit ;
  funtab[4] = do_show ;
  funtab[5] = do_wshow ;
  funtab[6] = do_editq ;
  funtab[7] = do_editreset ;
  funtab[8] = do_editl ;
  funtab[9] = do_editlreset ;
  funtab[10] = do_editr ;
  funtab[11] = do_editrreset ;
  funtab[12] = do_ctermlog ;
  funtab[13] = do_quitcterm ;
  funtab[14] = do_getchR ;
  funtab[15] = do_wgetchR ;
  funtab[16] = do_clrreg ;
  funtab[17] = do_wclrreg ;
  funtab[18] = do_addch ;
  funtab[19] = do_addstr ;
  funtab[20] = do_attroff ;
  funtab[21] = do_attron ;
  funtab[22] = do_attrset ;
  funtab[23] = do_baudrate ;
  funtab[24] = do_beep ;
  funtab[25] = do_box ;
  funtab[26] = do_cbreak ;
  funtab[27] = do_clear ;
  funtab[28] = do_clearok ;
  funtab[29] = do_clrtobot ;
  funtab[30] = do_clrtoeol ;
  funtab[31] = do_delch ;
  funtab[32] = do_deleteln ;
  funtab[33] = do_delwin ;
  funtab[34] = do_doupdate ;
  funtab[35] = do_draino ;
  funtab[36] = do_echo ;
  funtab[37] = do_endwin ;
  funtab[38] = do_erase ;
  funtab[39] = do_erasechar ;
  funtab[40] = do_fixterm ;
  funtab[41] = do_flash ;
  funtab[42] = do_flushinp ;
  funtab[43] = do_getch ;
  funtab[44] = do_getstr ;
  funtab[45] = do_getyx ;
  funtab[46] = do_has_ic ;
  funtab[47] = do_has_il ;
  funtab[48] = do_idlok ;
  funtab[49] = do_inch ;
  funtab[50] = do_initscr ;
  funtab[51] = do_insch ;
  funtab[52] = do_insertln ;
  funtab[53] = do_intrflush ;
  funtab[54] = do_keypad ;
  funtab[55] = do_killchar ;
  funtab[56] = do_leaveok ;
  funtab[57] = do_longname ;
  funtab[58] = do_meta ;
  funtab[59] = do_move ;
  funtab[60] = do_mvaddch ;
  funtab[61] = do_mvaddstr ;
  funtab[62] = do_mvcur ;
  funtab[63] = do_mvdelch ;
  funtab[64] = do_mvgetch ;
  funtab[65] = do_mvgetstr ;
  funtab[66] = do_mvinch ;
  funtab[67] = do_mvinsch ;
  funtab[68] = do_mvwaddch ;
  funtab[69] = do_mvwaddstr ;
  funtab[70] = do_mvwdelch ;
  funtab[71] = do_mvwgetch ;
  funtab[72] = do_mvwgetstr ;
  funtab[73] = do_mvwin ;
  funtab[74] = do_mvwinch ;
  funtab[75] = do_mvwinsch ;
  funtab[76] = do_napms ;
  funtab[77] = do_newpad ;
  funtab[78] = do_newwin ;
  funtab[79] = do_nl ;
  funtab[80] = do_nocbreak ;
  funtab[81] = do_nodelay ;
  funtab[82] = do_noecho ;
  funtab[83] = do_nonl ;
  funtab[84] = do_noraw ;
  funtab[85] = do_overlay ;
  funtab[86] = do_overwrite ;
  funtab[87] = do_pnoutrefresh ;
  funtab[88] = do_prefresh ;
  funtab[89] = do_raw ;
  funtab[90] = do_refresh ;
  funtab[91] = do_resetterm ;
  funtab[92] = do_resetty ;
  funtab[93] = do_saveterm ;
  funtab[94] = do_savetty ;
  funtab[95] = do_scroll ;
  funtab[96] = do_scrollok ;
  funtab[97] = do_setscrreg ;
  funtab[98] = do_standend ;
  funtab[99] = do_standout ;
  funtab[100] = do_subwin ;
  funtab[101] = do_touchwin ;
  funtab[102] = do_typeahead ;
  funtab[103] = do_unctrl ;
  funtab[104] = do_waddch ;
  funtab[105] = do_waddstr ;
  funtab[106] = do_wattroff ;
  funtab[107] = do_wattron ;
  funtab[108] = do_wattrset ;
  funtab[109] = do_wclear ;
  funtab[110] = do_wclrtobot ;
  funtab[111] = do_wclrtoeol ;
  funtab[112] = do_wdelch ;
  funtab[113] = do_wdeleteln ;
  funtab[114] = do_werase ;
  funtab[115] = do_wgetch ;
  funtab[116] = do_wgetstr ;
  funtab[117] = do_winch ;
  funtab[118] = do_winsch ;
  funtab[119] = do_winsertln ;
  funtab[120] = do_wmove ;
  funtab[121] = do_wnoutrefresh ;
  funtab[122] = do_wrefresh ;
  funtab[123] = do_wsetscrreg ;
  funtab[124] = do_wstandend ;
  funtab[125] = do_wstandout ;
}
