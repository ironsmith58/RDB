#include <curses.h>
#include <stdio.h>

main() {
#ifdef TRUE
  printf("$curcon{'TRUE'} = %d ;\n",TRUE) ;
#else
  fprintf(stderr,"warning: no definition for TRUE\n") ;
#endif
#ifdef FALSE
  printf("$curcon{'FALSE'} = %d ;\n",FALSE) ;
#else
  fprintf(stderr,"warning: no definition for FALSE\n") ;
#endif
#ifdef OK
  printf("$curcon{'OK'} = %d ;\n",OK) ;
#else
  fprintf(stderr,"warning: no definition for OK\n") ;
#endif
#ifdef ERR
  printf("$curcon{'ERR'} = %d ;\n",ERR) ;
#else
  fprintf(stderr,"warning: no definition for ERR\n") ;
#endif
#ifdef A_STANDOUT
  printf("$curcon{'A_STANDOUT'} = %d ;\n",A_STANDOUT) ;
#else
  fprintf(stderr,"warning: no definition for A_STANDOUT\n") ;
#endif
#ifdef A_UNDERLINE
  printf("$curcon{'A_UNDERLINE'} = %d ;\n",A_UNDERLINE) ;
#else
  fprintf(stderr,"warning: no definition for A_UNDERLINE\n") ;
#endif
#ifdef A_REVERSE
  printf("$curcon{'A_REVERSE'} = %d ;\n",A_REVERSE) ;
#else
  fprintf(stderr,"warning: no definition for A_REVERSE\n") ;
#endif
#ifdef A_BLINK
  printf("$curcon{'A_BLINK'} = %d ;\n",A_BLINK) ;
#else
  fprintf(stderr,"warning: no definition for A_BLINK\n") ;
#endif
#ifdef A_DIM
  printf("$curcon{'A_DIM'} = %d ;\n",A_DIM) ;
#else
  fprintf(stderr,"warning: no definition for A_DIM\n") ;
#endif
#ifdef A_BOLD
  printf("$curcon{'A_BOLD'} = %d ;\n",A_BOLD) ;
#else
  fprintf(stderr,"warning: no definition for A_BOLD\n") ;
#endif
#ifdef A_ALTCHARSET
  printf("$curcon{'A_ALTCHARSET'} = %d ;\n",A_ALTCHARSET) ;
#else
  fprintf(stderr,"warning: no definition for A_ALTCHARSET\n") ;
#endif
#ifdef A_INVIS
  printf("$curcon{'A_INVIS'} = %d ;\n",A_INVIS) ;
#else
  fprintf(stderr,"warning: no definition for A_INVIS\n") ;
#endif
#ifdef A_PROTECT
  printf("$curcon{'A_PROTECT'} = %d ;\n",A_PROTECT) ;
#else
  fprintf(stderr,"warning: no definition for A_PROTECT\n") ;
#endif
#ifdef A_NORMAL
  printf("$curcon{'A_NORMAL'} = %d ;\n",A_NORMAL) ;
#else
  fprintf(stderr,"warning: no definition for A_NORMAL\n") ;
#endif
#ifdef A_ATTRIBUTES
  printf("$curcon{'A_ATTRIBUTES'} = %d ;\n",A_ATTRIBUTES) ;
#else
  fprintf(stderr,"warning: no definition for A_ATTRIBUTES\n") ;
#endif
#ifdef A_CHARTEXT
  printf("$curcon{'A_CHARTEXT'} = %d ;\n",A_CHARTEXT) ;
#else
  fprintf(stderr,"warning: no definition for A_CHARTEXT\n") ;
#endif
#ifdef KEY_BREAK
  printf("$curcon{'KEY_BREAK'} = %d ;\n",KEY_BREAK) ;
  printf("$curkey{%d} = 'KEY_BREAK' ;\n",KEY_BREAK) ;
#else
  fprintf(stderr,"warning: no definition for KEY_BREAK\n") ;
#endif
#ifdef KEY_DOWN
  printf("$curcon{'KEY_DOWN'} = %d ;\n",KEY_DOWN) ;
  printf("$curkey{%d} = 'KEY_DOWN' ;\n",KEY_DOWN) ;
#else
  fprintf(stderr,"warning: no definition for KEY_DOWN\n") ;
#endif
#ifdef KEY_UP
  printf("$curcon{'KEY_UP'} = %d ;\n",KEY_UP) ;
  printf("$curkey{%d} = 'KEY_UP' ;\n",KEY_UP) ;
#else
  fprintf(stderr,"warning: no definition for KEY_UP\n") ;
#endif
#ifdef KEY_LEFT
  printf("$curcon{'KEY_LEFT'} = %d ;\n",KEY_LEFT) ;
  printf("$curkey{%d} = 'KEY_LEFT' ;\n",KEY_LEFT) ;
#else
  fprintf(stderr,"warning: no definition for KEY_LEFT\n") ;
#endif
#ifdef KEY_RIGHT
  printf("$curcon{'KEY_RIGHT'} = %d ;\n",KEY_RIGHT) ;
  printf("$curkey{%d} = 'KEY_RIGHT' ;\n",KEY_RIGHT) ;
#else
  fprintf(stderr,"warning: no definition for KEY_RIGHT\n") ;
#endif
#ifdef KEY_HOME
  printf("$curcon{'KEY_HOME'} = %d ;\n",KEY_HOME) ;
  printf("$curkey{%d} = 'KEY_HOME' ;\n",KEY_HOME) ;
#else
  fprintf(stderr,"warning: no definition for KEY_HOME\n") ;
#endif
#ifdef KEY_BACKSPACE
  printf("$curcon{'KEY_BACKSPACE'} = %d ;\n",KEY_BACKSPACE) ;
  printf("$curkey{%d} = 'KEY_BACKSPACE' ;\n",KEY_BACKSPACE) ;
#else
  fprintf(stderr,"warning: no definition for KEY_BACKSPACE\n") ;
#endif
#ifdef KEY_F0
  printf("$curcon{'KEY_F0'} = %d ;\n",KEY_F0) ;
  printf("$curkey{%d} = 'KEY_F0' ;\n",KEY_F0) ;
#else
  fprintf(stderr,"warning: no definition for KEY_F0\n") ;
#endif
#ifdef KEY_F
  printf("$curcon{'KEY_F(1)'} = %d ;\n",KEY_F(1)) ;
  printf("$curkey{%d} = 'KEY_F(1)' ;\n",KEY_F(1)) ;
#else
  fprintf(stderr,"warning: no definition for KEY_F(1)\n") ;
#endif
#ifdef KEY_F
  printf("$curcon{'KEY_F(2)'} = %d ;\n",KEY_F(2)) ;
  printf("$curkey{%d} = 'KEY_F(2)' ;\n",KEY_F(2)) ;
#else
  fprintf(stderr,"warning: no definition for KEY_F(2)\n") ;
#endif
#ifdef KEY_F
  printf("$curcon{'KEY_F(3)'} = %d ;\n",KEY_F(3)) ;
  printf("$curkey{%d} = 'KEY_F(3)' ;\n",KEY_F(3)) ;
#else
  fprintf(stderr,"warning: no definition for KEY_F(3)\n") ;
#endif
#ifdef KEY_F
  printf("$curcon{'KEY_F(4)'} = %d ;\n",KEY_F(4)) ;
  printf("$curkey{%d} = 'KEY_F(4)' ;\n",KEY_F(4)) ;
#else
  fprintf(stderr,"warning: no definition for KEY_F(4)\n") ;
#endif
#ifdef KEY_F
  printf("$curcon{'KEY_F(5)'} = %d ;\n",KEY_F(5)) ;
  printf("$curkey{%d} = 'KEY_F(5)' ;\n",KEY_F(5)) ;
#else
  fprintf(stderr,"warning: no definition for KEY_F(5)\n") ;
#endif
#ifdef KEY_F
  printf("$curcon{'KEY_F(6)'} = %d ;\n",KEY_F(6)) ;
  printf("$curkey{%d} = 'KEY_F(6)' ;\n",KEY_F(6)) ;
#else
  fprintf(stderr,"warning: no definition for KEY_F(6)\n") ;
#endif
#ifdef KEY_F
  printf("$curcon{'KEY_F(7)'} = %d ;\n",KEY_F(7)) ;
  printf("$curkey{%d} = 'KEY_F(7)' ;\n",KEY_F(7)) ;
#else
  fprintf(stderr,"warning: no definition for KEY_F(7)\n") ;
#endif
#ifdef KEY_F
  printf("$curcon{'KEY_F(8)'} = %d ;\n",KEY_F(8)) ;
  printf("$curkey{%d} = 'KEY_F(8)' ;\n",KEY_F(8)) ;
#else
  fprintf(stderr,"warning: no definition for KEY_F(8)\n") ;
#endif
#ifdef KEY_F
  printf("$curcon{'KEY_F(9)'} = %d ;\n",KEY_F(9)) ;
  printf("$curkey{%d} = 'KEY_F(9)' ;\n",KEY_F(9)) ;
#else
  fprintf(stderr,"warning: no definition for KEY_F(9)\n") ;
#endif
#ifdef KEY_DL
  printf("$curcon{'KEY_DL'} = %d ;\n",KEY_DL) ;
  printf("$curkey{%d} = 'KEY_DL' ;\n",KEY_DL) ;
#else
  fprintf(stderr,"warning: no definition for KEY_DL\n") ;
#endif
#ifdef KEY_IL
  printf("$curcon{'KEY_IL'} = %d ;\n",KEY_IL) ;
  printf("$curkey{%d} = 'KEY_IL' ;\n",KEY_IL) ;
#else
  fprintf(stderr,"warning: no definition for KEY_IL\n") ;
#endif
#ifdef KEY_DC
  printf("$curcon{'KEY_DC'} = %d ;\n",KEY_DC) ;
  printf("$curkey{%d} = 'KEY_DC' ;\n",KEY_DC) ;
#else
  fprintf(stderr,"warning: no definition for KEY_DC\n") ;
#endif
#ifdef KEY_IC
  printf("$curcon{'KEY_IC'} = %d ;\n",KEY_IC) ;
  printf("$curkey{%d} = 'KEY_IC' ;\n",KEY_IC) ;
#else
  fprintf(stderr,"warning: no definition for KEY_IC\n") ;
#endif
#ifdef KEY_EIC
  printf("$curcon{'KEY_EIC'} = %d ;\n",KEY_EIC) ;
  printf("$curkey{%d} = 'KEY_EIC' ;\n",KEY_EIC) ;
#else
  fprintf(stderr,"warning: no definition for KEY_EIC\n") ;
#endif
#ifdef KEY_CLEAR
  printf("$curcon{'KEY_CLEAR'} = %d ;\n",KEY_CLEAR) ;
  printf("$curkey{%d} = 'KEY_CLEAR' ;\n",KEY_CLEAR) ;
#else
  fprintf(stderr,"warning: no definition for KEY_CLEAR\n") ;
#endif
#ifdef KEY_EOS
  printf("$curcon{'KEY_EOS'} = %d ;\n",KEY_EOS) ;
  printf("$curkey{%d} = 'KEY_EOS' ;\n",KEY_EOS) ;
#else
  fprintf(stderr,"warning: no definition for KEY_EOS\n") ;
#endif
#ifdef KEY_EOL
  printf("$curcon{'KEY_EOL'} = %d ;\n",KEY_EOL) ;
  printf("$curkey{%d} = 'KEY_EOL' ;\n",KEY_EOL) ;
#else
  fprintf(stderr,"warning: no definition for KEY_EOL\n") ;
#endif
#ifdef KEY_SF
  printf("$curcon{'KEY_SF'} = %d ;\n",KEY_SF) ;
  printf("$curkey{%d} = 'KEY_SF' ;\n",KEY_SF) ;
#else
  fprintf(stderr,"warning: no definition for KEY_SF\n") ;
#endif
#ifdef KEY_SR
  printf("$curcon{'KEY_SR'} = %d ;\n",KEY_SR) ;
  printf("$curkey{%d} = 'KEY_SR' ;\n",KEY_SR) ;
#else
  fprintf(stderr,"warning: no definition for KEY_SR\n") ;
#endif
#ifdef KEY_NPAGE
  printf("$curcon{'KEY_NPAGE'} = %d ;\n",KEY_NPAGE) ;
  printf("$curkey{%d} = 'KEY_NPAGE' ;\n",KEY_NPAGE) ;
#else
  fprintf(stderr,"warning: no definition for KEY_NPAGE\n") ;
#endif
#ifdef KEY_PPAGE
  printf("$curcon{'KEY_PPAGE'} = %d ;\n",KEY_PPAGE) ;
  printf("$curkey{%d} = 'KEY_PPAGE' ;\n",KEY_PPAGE) ;
#else
  fprintf(stderr,"warning: no definition for KEY_PPAGE\n") ;
#endif
#ifdef KEY_STAB
  printf("$curcon{'KEY_STAB'} = %d ;\n",KEY_STAB) ;
  printf("$curkey{%d} = 'KEY_STAB' ;\n",KEY_STAB) ;
#else
  fprintf(stderr,"warning: no definition for KEY_STAB\n") ;
#endif
#ifdef KEY_CTAB
  printf("$curcon{'KEY_CTAB'} = %d ;\n",KEY_CTAB) ;
  printf("$curkey{%d} = 'KEY_CTAB' ;\n",KEY_CTAB) ;
#else
  fprintf(stderr,"warning: no definition for KEY_CTAB\n") ;
#endif
#ifdef KEY_CATAB
  printf("$curcon{'KEY_CATAB'} = %d ;\n",KEY_CATAB) ;
  printf("$curkey{%d} = 'KEY_CATAB' ;\n",KEY_CATAB) ;
#else
  fprintf(stderr,"warning: no definition for KEY_CATAB\n") ;
#endif
#ifdef KEY_ENTER
  printf("$curcon{'KEY_ENTER'} = %d ;\n",KEY_ENTER) ;
  printf("$curkey{%d} = 'KEY_ENTER' ;\n",KEY_ENTER) ;
#else
  fprintf(stderr,"warning: no definition for KEY_ENTER\n") ;
#endif
#ifdef KEY_SRESET
  printf("$curcon{'KEY_SRESET'} = %d ;\n",KEY_SRESET) ;
  printf("$curkey{%d} = 'KEY_SRESET' ;\n",KEY_SRESET) ;
#else
  fprintf(stderr,"warning: no definition for KEY_SRESET\n") ;
#endif
#ifdef KEY_RESET
  printf("$curcon{'KEY_RESET'} = %d ;\n",KEY_RESET) ;
  printf("$curkey{%d} = 'KEY_RESET' ;\n",KEY_RESET) ;
#else
  fprintf(stderr,"warning: no definition for KEY_RESET\n") ;
#endif
#ifdef KEY_PRINT
  printf("$curcon{'KEY_PRINT'} = %d ;\n",KEY_PRINT) ;
  printf("$curkey{%d} = 'KEY_PRINT' ;\n",KEY_PRINT) ;
#else
  fprintf(stderr,"warning: no definition for KEY_PRINT\n") ;
#endif
#ifdef KEY_LL
  printf("$curcon{'KEY_LL'} = %d ;\n",KEY_LL) ;
  printf("$curkey{%d} = 'KEY_LL' ;\n",KEY_LL) ;
#else
  fprintf(stderr,"warning: no definition for KEY_LL\n") ;
#endif
#ifdef KEY_A1
  printf("$curcon{'KEY_A1'} = %d ;\n",KEY_A1) ;
  printf("$curkey{%d} = 'KEY_A1' ;\n",KEY_A1) ;
#else
  fprintf(stderr,"warning: no definition for KEY_A1\n") ;
#endif
#ifdef KEY_A3
  printf("$curcon{'KEY_A3'} = %d ;\n",KEY_A3) ;
  printf("$curkey{%d} = 'KEY_A3' ;\n",KEY_A3) ;
#else
  fprintf(stderr,"warning: no definition for KEY_A3\n") ;
#endif
#ifdef KEY_B2
  printf("$curcon{'KEY_B2'} = %d ;\n",KEY_B2) ;
  printf("$curkey{%d} = 'KEY_B2' ;\n",KEY_B2) ;
#else
  fprintf(stderr,"warning: no definition for KEY_B2\n") ;
#endif
#ifdef KEY_C1
  printf("$curcon{'KEY_C1'} = %d ;\n",KEY_C1) ;
  printf("$curkey{%d} = 'KEY_C1' ;\n",KEY_C1) ;
#else
  fprintf(stderr,"warning: no definition for KEY_C1\n") ;
#endif
#ifdef KEY_C3
  printf("$curcon{'KEY_C3'} = %d ;\n",KEY_C3) ;
  printf("$curkey{%d} = 'KEY_C3' ;\n",KEY_C3) ;
#else
  fprintf(stderr,"warning: no definition for KEY_C3\n") ;
#endif
#ifdef KEY_BTAB
  printf("$curcon{'KEY_BTAB'} = %d ;\n",KEY_BTAB) ;
  printf("$curkey{%d} = 'KEY_BTAB' ;\n",KEY_BTAB) ;
#else
  fprintf(stderr,"warning: no definition for KEY_BTAB\n") ;
#endif
#ifdef KEY_BEG
  printf("$curcon{'KEY_BEG'} = %d ;\n",KEY_BEG) ;
  printf("$curkey{%d} = 'KEY_BEG' ;\n",KEY_BEG) ;
#else
  fprintf(stderr,"warning: no definition for KEY_BEG\n") ;
#endif
#ifdef KEY_CANCEL
  printf("$curcon{'KEY_CANCEL'} = %d ;\n",KEY_CANCEL) ;
  printf("$curkey{%d} = 'KEY_CANCEL' ;\n",KEY_CANCEL) ;
#else
  fprintf(stderr,"warning: no definition for KEY_CANCEL\n") ;
#endif
#ifdef KEY_CLOSE
  printf("$curcon{'KEY_CLOSE'} = %d ;\n",KEY_CLOSE) ;
  printf("$curkey{%d} = 'KEY_CLOSE' ;\n",KEY_CLOSE) ;
#else
  fprintf(stderr,"warning: no definition for KEY_CLOSE\n") ;
#endif
#ifdef KEY_COMMAND
  printf("$curcon{'KEY_COMMAND'} = %d ;\n",KEY_COMMAND) ;
  printf("$curkey{%d} = 'KEY_COMMAND' ;\n",KEY_COMMAND) ;
#else
  fprintf(stderr,"warning: no definition for KEY_COMMAND\n") ;
#endif
#ifdef KEY_COPY
  printf("$curcon{'KEY_COPY'} = %d ;\n",KEY_COPY) ;
  printf("$curkey{%d} = 'KEY_COPY' ;\n",KEY_COPY) ;
#else
  fprintf(stderr,"warning: no definition for KEY_COPY\n") ;
#endif
#ifdef KEY_CREATE
  printf("$curcon{'KEY_CREATE'} = %d ;\n",KEY_CREATE) ;
  printf("$curkey{%d} = 'KEY_CREATE' ;\n",KEY_CREATE) ;
#else
  fprintf(stderr,"warning: no definition for KEY_CREATE\n") ;
#endif
#ifdef KEY_END
  printf("$curcon{'KEY_END'} = %d ;\n",KEY_END) ;
  printf("$curkey{%d} = 'KEY_END' ;\n",KEY_END) ;
#else
  fprintf(stderr,"warning: no definition for KEY_END\n") ;
#endif
#ifdef KEY_EXIT
  printf("$curcon{'KEY_EXIT'} = %d ;\n",KEY_EXIT) ;
  printf("$curkey{%d} = 'KEY_EXIT' ;\n",KEY_EXIT) ;
#else
  fprintf(stderr,"warning: no definition for KEY_EXIT\n") ;
#endif
#ifdef KEY_FIND
  printf("$curcon{'KEY_FIND'} = %d ;\n",KEY_FIND) ;
  printf("$curkey{%d} = 'KEY_FIND' ;\n",KEY_FIND) ;
#else
  fprintf(stderr,"warning: no definition for KEY_FIND\n") ;
#endif
#ifdef KEY_HELP
  printf("$curcon{'KEY_HELP'} = %d ;\n",KEY_HELP) ;
  printf("$curkey{%d} = 'KEY_HELP' ;\n",KEY_HELP) ;
#else
  fprintf(stderr,"warning: no definition for KEY_HELP\n") ;
#endif
#ifdef KEY_MARK
  printf("$curcon{'KEY_MARK'} = %d ;\n",KEY_MARK) ;
  printf("$curkey{%d} = 'KEY_MARK' ;\n",KEY_MARK) ;
#else
  fprintf(stderr,"warning: no definition for KEY_MARK\n") ;
#endif
#ifdef KEY_MESSAGE
  printf("$curcon{'KEY_MESSAGE'} = %d ;\n",KEY_MESSAGE) ;
  printf("$curkey{%d} = 'KEY_MESSAGE' ;\n",KEY_MESSAGE) ;
#else
  fprintf(stderr,"warning: no definition for KEY_MESSAGE\n") ;
#endif
#ifdef KEY_MOVE
  printf("$curcon{'KEY_MOVE'} = %d ;\n",KEY_MOVE) ;
  printf("$curkey{%d} = 'KEY_MOVE' ;\n",KEY_MOVE) ;
#else
  fprintf(stderr,"warning: no definition for KEY_MOVE\n") ;
#endif
#ifdef KEY_NEXT
  printf("$curcon{'KEY_NEXT'} = %d ;\n",KEY_NEXT) ;
  printf("$curkey{%d} = 'KEY_NEXT' ;\n",KEY_NEXT) ;
#else
  fprintf(stderr,"warning: no definition for KEY_NEXT\n") ;
#endif
#ifdef KEY_OPEN
  printf("$curcon{'KEY_OPEN'} = %d ;\n",KEY_OPEN) ;
  printf("$curkey{%d} = 'KEY_OPEN' ;\n",KEY_OPEN) ;
#else
  fprintf(stderr,"warning: no definition for KEY_OPEN\n") ;
#endif
#ifdef KEY_OPTIONS
  printf("$curcon{'KEY_OPTIONS'} = %d ;\n",KEY_OPTIONS) ;
  printf("$curkey{%d} = 'KEY_OPTIONS' ;\n",KEY_OPTIONS) ;
#else
  fprintf(stderr,"warning: no definition for KEY_OPTIONS\n") ;
#endif
#ifdef KEY_PREVIOUS
  printf("$curcon{'KEY_PREVIOUS'} = %d ;\n",KEY_PREVIOUS) ;
  printf("$curkey{%d} = 'KEY_PREVIOUS' ;\n",KEY_PREVIOUS) ;
#else
  fprintf(stderr,"warning: no definition for KEY_PREVIOUS\n") ;
#endif
#ifdef KEY_REDO
  printf("$curcon{'KEY_REDO'} = %d ;\n",KEY_REDO) ;
  printf("$curkey{%d} = 'KEY_REDO' ;\n",KEY_REDO) ;
#else
  fprintf(stderr,"warning: no definition for KEY_REDO\n") ;
#endif
#ifdef KEY_REFERENCE
  printf("$curcon{'KEY_REFERENCE'} = %d ;\n",KEY_REFERENCE) ;
  printf("$curkey{%d} = 'KEY_REFERENCE' ;\n",KEY_REFERENCE) ;
#else
  fprintf(stderr,"warning: no definition for KEY_REFERENCE\n") ;
#endif
#ifdef KEY_REFRESH
  printf("$curcon{'KEY_REFRESH'} = %d ;\n",KEY_REFRESH) ;
  printf("$curkey{%d} = 'KEY_REFRESH' ;\n",KEY_REFRESH) ;
#else
  fprintf(stderr,"warning: no definition for KEY_REFRESH\n") ;
#endif
#ifdef KEY_REPLACE
  printf("$curcon{'KEY_REPLACE'} = %d ;\n",KEY_REPLACE) ;
  printf("$curkey{%d} = 'KEY_REPLACE' ;\n",KEY_REPLACE) ;
#else
  fprintf(stderr,"warning: no definition for KEY_REPLACE\n") ;
#endif
#ifdef KEY_RESTART
  printf("$curcon{'KEY_RESTART'} = %d ;\n",KEY_RESTART) ;
  printf("$curkey{%d} = 'KEY_RESTART' ;\n",KEY_RESTART) ;
#else
  fprintf(stderr,"warning: no definition for KEY_RESTART\n") ;
#endif
#ifdef KEY_RESUME
  printf("$curcon{'KEY_RESUME'} = %d ;\n",KEY_RESUME) ;
  printf("$curkey{%d} = 'KEY_RESUME' ;\n",KEY_RESUME) ;
#else
  fprintf(stderr,"warning: no definition for KEY_RESUME\n") ;
#endif
#ifdef KEY_SAVE
  printf("$curcon{'KEY_SAVE'} = %d ;\n",KEY_SAVE) ;
  printf("$curkey{%d} = 'KEY_SAVE' ;\n",KEY_SAVE) ;
#else
  fprintf(stderr,"warning: no definition for KEY_SAVE\n") ;
#endif
#ifdef KEY_SBEG
  printf("$curcon{'KEY_SBEG'} = %d ;\n",KEY_SBEG) ;
  printf("$curkey{%d} = 'KEY_SBEG' ;\n",KEY_SBEG) ;
#else
  fprintf(stderr,"warning: no definition for KEY_SBEG\n") ;
#endif
#ifdef KEY_SCANCEL
  printf("$curcon{'KEY_SCANCEL'} = %d ;\n",KEY_SCANCEL) ;
  printf("$curkey{%d} = 'KEY_SCANCEL' ;\n",KEY_SCANCEL) ;
#else
  fprintf(stderr,"warning: no definition for KEY_SCANCEL\n") ;
#endif
#ifdef KEY_SCOMMAND
  printf("$curcon{'KEY_SCOMMAND'} = %d ;\n",KEY_SCOMMAND) ;
  printf("$curkey{%d} = 'KEY_SCOMMAND' ;\n",KEY_SCOMMAND) ;
#else
  fprintf(stderr,"warning: no definition for KEY_SCOMMAND\n") ;
#endif
#ifdef KEY_SCOPY
  printf("$curcon{'KEY_SCOPY'} = %d ;\n",KEY_SCOPY) ;
  printf("$curkey{%d} = 'KEY_SCOPY' ;\n",KEY_SCOPY) ;
#else
  fprintf(stderr,"warning: no definition for KEY_SCOPY\n") ;
#endif
#ifdef KEY_SCREATE
  printf("$curcon{'KEY_SCREATE'} = %d ;\n",KEY_SCREATE) ;
  printf("$curkey{%d} = 'KEY_SCREATE' ;\n",KEY_SCREATE) ;
#else
  fprintf(stderr,"warning: no definition for KEY_SCREATE\n") ;
#endif
#ifdef KEY_SDC
  printf("$curcon{'KEY_SDC'} = %d ;\n",KEY_SDC) ;
  printf("$curkey{%d} = 'KEY_SDC' ;\n",KEY_SDC) ;
#else
  fprintf(stderr,"warning: no definition for KEY_SDC\n") ;
#endif
#ifdef KEY_SDL
  printf("$curcon{'KEY_SDL'} = %d ;\n",KEY_SDL) ;
  printf("$curkey{%d} = 'KEY_SDL' ;\n",KEY_SDL) ;
#else
  fprintf(stderr,"warning: no definition for KEY_SDL\n") ;
#endif
#ifdef KEY_SELECT
  printf("$curcon{'KEY_SELECT'} = %d ;\n",KEY_SELECT) ;
  printf("$curkey{%d} = 'KEY_SELECT' ;\n",KEY_SELECT) ;
#else
  fprintf(stderr,"warning: no definition for KEY_SELECT\n") ;
#endif
#ifdef KEY_SEND
  printf("$curcon{'KEY_SEND'} = %d ;\n",KEY_SEND) ;
  printf("$curkey{%d} = 'KEY_SEND' ;\n",KEY_SEND) ;
#else
  fprintf(stderr,"warning: no definition for KEY_SEND\n") ;
#endif
#ifdef KEY_SEOL
  printf("$curcon{'KEY_SEOL'} = %d ;\n",KEY_SEOL) ;
  printf("$curkey{%d} = 'KEY_SEOL' ;\n",KEY_SEOL) ;
#else
  fprintf(stderr,"warning: no definition for KEY_SEOL\n") ;
#endif
#ifdef KEY_SEXIT
  printf("$curcon{'KEY_SEXIT'} = %d ;\n",KEY_SEXIT) ;
  printf("$curkey{%d} = 'KEY_SEXIT' ;\n",KEY_SEXIT) ;
#else
  fprintf(stderr,"warning: no definition for KEY_SEXIT\n") ;
#endif
#ifdef KEY_SFIND
  printf("$curcon{'KEY_SFIND'} = %d ;\n",KEY_SFIND) ;
  printf("$curkey{%d} = 'KEY_SFIND' ;\n",KEY_SFIND) ;
#else
  fprintf(stderr,"warning: no definition for KEY_SFIND\n") ;
#endif
#ifdef KEY_SHELP
  printf("$curcon{'KEY_SHELP'} = %d ;\n",KEY_SHELP) ;
  printf("$curkey{%d} = 'KEY_SHELP' ;\n",KEY_SHELP) ;
#else
  fprintf(stderr,"warning: no definition for KEY_SHELP\n") ;
#endif
#ifdef KEY_SHOME
  printf("$curcon{'KEY_SHOME'} = %d ;\n",KEY_SHOME) ;
  printf("$curkey{%d} = 'KEY_SHOME' ;\n",KEY_SHOME) ;
#else
  fprintf(stderr,"warning: no definition for KEY_SHOME\n") ;
#endif
#ifdef KEY_SIC
  printf("$curcon{'KEY_SIC'} = %d ;\n",KEY_SIC) ;
  printf("$curkey{%d} = 'KEY_SIC' ;\n",KEY_SIC) ;
#else
  fprintf(stderr,"warning: no definition for KEY_SIC\n") ;
#endif
#ifdef KEY_SLEFT
  printf("$curcon{'KEY_SLEFT'} = %d ;\n",KEY_SLEFT) ;
  printf("$curkey{%d} = 'KEY_SLEFT' ;\n",KEY_SLEFT) ;
#else
  fprintf(stderr,"warning: no definition for KEY_SLEFT\n") ;
#endif
#ifdef KEY_SMESSAGE
  printf("$curcon{'KEY_SMESSAGE'} = %d ;\n",KEY_SMESSAGE) ;
  printf("$curkey{%d} = 'KEY_SMESSAGE' ;\n",KEY_SMESSAGE) ;
#else
  fprintf(stderr,"warning: no definition for KEY_SMESSAGE\n") ;
#endif
#ifdef KEY_SMOVE
  printf("$curcon{'KEY_SMOVE'} = %d ;\n",KEY_SMOVE) ;
  printf("$curkey{%d} = 'KEY_SMOVE' ;\n",KEY_SMOVE) ;
#else
  fprintf(stderr,"warning: no definition for KEY_SMOVE\n") ;
#endif
#ifdef KEY_SNEXT
  printf("$curcon{'KEY_SNEXT'} = %d ;\n",KEY_SNEXT) ;
  printf("$curkey{%d} = 'KEY_SNEXT' ;\n",KEY_SNEXT) ;
#else
  fprintf(stderr,"warning: no definition for KEY_SNEXT\n") ;
#endif
#ifdef KEY_SOPTIONS
  printf("$curcon{'KEY_SOPTIONS'} = %d ;\n",KEY_SOPTIONS) ;
  printf("$curkey{%d} = 'KEY_SOPTIONS' ;\n",KEY_SOPTIONS) ;
#else
  fprintf(stderr,"warning: no definition for KEY_SOPTIONS\n") ;
#endif
#ifdef KEY_SPREVIOUS
  printf("$curcon{'KEY_SPREVIOUS'} = %d ;\n",KEY_SPREVIOUS) ;
  printf("$curkey{%d} = 'KEY_SPREVIOUS' ;\n",KEY_SPREVIOUS) ;
#else
  fprintf(stderr,"warning: no definition for KEY_SPREVIOUS\n") ;
#endif
#ifdef KEY_SPRINT
  printf("$curcon{'KEY_SPRINT'} = %d ;\n",KEY_SPRINT) ;
  printf("$curkey{%d} = 'KEY_SPRINT' ;\n",KEY_SPRINT) ;
#else
  fprintf(stderr,"warning: no definition for KEY_SPRINT\n") ;
#endif
#ifdef KEY_SREDO
  printf("$curcon{'KEY_SREDO'} = %d ;\n",KEY_SREDO) ;
  printf("$curkey{%d} = 'KEY_SREDO' ;\n",KEY_SREDO) ;
#else
  fprintf(stderr,"warning: no definition for KEY_SREDO\n") ;
#endif
#ifdef KEY_SREPLACE
  printf("$curcon{'KEY_SREPLACE'} = %d ;\n",KEY_SREPLACE) ;
  printf("$curkey{%d} = 'KEY_SREPLACE' ;\n",KEY_SREPLACE) ;
#else
  fprintf(stderr,"warning: no definition for KEY_SREPLACE\n") ;
#endif
#ifdef KEY_SRIGHT
  printf("$curcon{'KEY_SRIGHT'} = %d ;\n",KEY_SRIGHT) ;
  printf("$curkey{%d} = 'KEY_SRIGHT' ;\n",KEY_SRIGHT) ;
#else
  fprintf(stderr,"warning: no definition for KEY_SRIGHT\n") ;
#endif
#ifdef KEY_SRSUME
  printf("$curcon{'KEY_SRSUME'} = %d ;\n",KEY_SRSUME) ;
  printf("$curkey{%d} = 'KEY_SRSUME' ;\n",KEY_SRSUME) ;
#else
  fprintf(stderr,"warning: no definition for KEY_SRSUME\n") ;
#endif
#ifdef KEY_SSAVE
  printf("$curcon{'KEY_SSAVE'} = %d ;\n",KEY_SSAVE) ;
  printf("$curkey{%d} = 'KEY_SSAVE' ;\n",KEY_SSAVE) ;
#else
  fprintf(stderr,"warning: no definition for KEY_SSAVE\n") ;
#endif
#ifdef KEY_SSUSPEND
  printf("$curcon{'KEY_SSUSPEND'} = %d ;\n",KEY_SSUSPEND) ;
  printf("$curkey{%d} = 'KEY_SSUSPEND' ;\n",KEY_SSUSPEND) ;
#else
  fprintf(stderr,"warning: no definition for KEY_SSUSPEND\n") ;
#endif
#ifdef KEY_SUNDO
  printf("$curcon{'KEY_SUNDO'} = %d ;\n",KEY_SUNDO) ;
  printf("$curkey{%d} = 'KEY_SUNDO' ;\n",KEY_SUNDO) ;
#else
  fprintf(stderr,"warning: no definition for KEY_SUNDO\n") ;
#endif
#ifdef KEY_SUSPEND
  printf("$curcon{'KEY_SUSPEND'} = %d ;\n",KEY_SUSPEND) ;
  printf("$curkey{%d} = 'KEY_SUSPEND' ;\n",KEY_SUSPEND) ;
#else
  fprintf(stderr,"warning: no definition for KEY_SUSPEND\n") ;
#endif
#ifdef KEY_UNDO
  printf("$curcon{'KEY_UNDO'} = %d ;\n",KEY_UNDO) ;
  printf("$curkey{%d} = 'KEY_UNDO' ;\n",KEY_UNDO) ;
#else
  fprintf(stderr,"warning: no definition for KEY_UNDO\n") ;
#endif
#ifdef EDIT_LEFT
  printf("$curcon{'EDIT_LEFT'} = %d ;\n",EDIT_LEFT) ;
#else
  fprintf(stderr,"warning: no definition for EDIT_LEFT\n") ;
#endif
#ifdef EDIT_RIGHT
  printf("$curcon{'EDIT_RIGHT'} = %d ;\n",EDIT_RIGHT) ;
#else
  fprintf(stderr,"warning: no definition for EDIT_RIGHT\n") ;
#endif
  printf("$curcon{'KEY_RET'} = %d ;\n",13) ;
  printf("$curkey{13} = 'KEY_RET' ;\n") ;
  printf("$curcon{'KEY_TAB'} = %d ;\n",9) ;
  printf("$curkey{9} = 'KEY_TAB' ;\n") ;
  exit(0) ;
}
