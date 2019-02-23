# getLINES RETURN resint
$curfun{'getLINES'} = 'getLINES RETURN resint' ;
sub getLINES {
  print("0\034") ;
  local($resint) ;
  &curFlush ;
  $resint = <STDIN> ; chop($resint) ;
  return $resint  ;
}
# getCOLS RETURN resint
$curfun{'getCOLS'} = 'getCOLS RETURN resint' ;
sub getCOLS {
  print("1\034") ;
  local($resint) ;
  &curFlush ;
  $resint = <STDIN> ; chop($resint) ;
  return $resint  ;
}
# edit str curpos y x xlen rep RETURN str resint
$curfun{'edit'} = 'edit str curpos y x xlen rep RETURN str resint' ;
sub edit {
  printf("2\034%s\034%d\034%d\034%d\034%d\034%s\034",@_) ;
  local($str,$resint) ;
  &curFlush ;
  $str = <STDIN> ; chop($str) ;
  $resint = <STDIN> ; chop($resint) ;
  return $str, $resint  ;
}
# wedit win str curpos y x xlen rep RETURN str resint
$curfun{'wedit'} = 'wedit win str curpos y x xlen rep RETURN str resint' ;
sub wedit {
  printf("3\034%d\034%s\034%d\034%d\034%d\034%d\034%s\034",@_) ;
  local($str,$resint) ;
  &curFlush ;
  $str = <STDIN> ; chop($str) ;
  $resint = <STDIN> ; chop($resint) ;
  return $str, $resint  ;
}
# show str curpos y x xlen rep
$curfun{'show'} = 'show str curpos y x xlen rep' ;
sub show {
  printf("4\034%s\034%d\034%d\034%d\034%d\034%s\034",@_) ;
}
# wshow win str curpos y x xlen rep
$curfun{'wshow'} = 'wshow win str curpos y x xlen rep' ;
sub wshow {
  printf("5\034%d\034%s\034%d\034%d\034%d\034%d\034%s\034",@_) ;
}
# editq chint
$curfun{'editq'} = 'editq chint' ;
sub editq {
  printf("6\034%d\034",$_[0]) ;
}
# editreset
$curfun{'editreset'} = 'editreset' ;
sub editreset {
  print("7\034") ;
}
# editl chint
$curfun{'editl'} = 'editl chint' ;
sub editl {
  printf("8\034%d\034",$_[0]) ;
}
# editlreset
$curfun{'editlreset'} = 'editlreset' ;
sub editlreset {
  print("9\034") ;
}
# editr chint
$curfun{'editr'} = 'editr chint' ;
sub editr {
  printf("10\034%d\034",$_[0]) ;
}
# editrreset
$curfun{'editrreset'} = 'editrreset' ;
sub editrreset {
  print("11\034") ;
}
# ctermlog str
$curfun{'ctermlog'} = 'ctermlog str' ;
sub ctermlog {
  printf("12\034%s\034",$_[0]) ;
}
# quitcterm FLUSH
$curfun{'quitcterm'} = 'quitcterm FLUSH' ;
sub quitcterm {
  print("13\034") ;
  &curFlush ;
}
# getchR RETURN resint
$curfun{'getchR'} = 'getchR RETURN resint' ;
sub getchR {
  print("14\034") ;
  local($resint) ;
  &curFlush ;
  $resint = <STDIN> ; chop($resint) ;
  return $resint  ;
}
# wgetchR win RETURN resint
$curfun{'wgetchR'} = 'wgetchR win RETURN resint' ;
sub wgetchR {
  printf("15\034%d\034",$_[0]) ;
  local($resint) ;
  &curFlush ;
  $resint = <STDIN> ; chop($resint) ;
  return $resint  ;
}
# clrreg top bot
$curfun{'clrreg'} = 'clrreg top bot' ;
sub clrreg {
  printf("16\034%d\034%d\034",@_) ;
}
# wclrreg win top bot
$curfun{'wclrreg'} = 'wclrreg win top bot' ;
sub wclrreg {
  printf("17\034%d\034%d\034%d\034",@_) ;
}
# addch ch
$curfun{'addch'} = 'addch ch' ;
sub addch {
  printf("18\034%c\034",$_[0]) ;
}
# addstr str
$curfun{'addstr'} = 'addstr str' ;
sub addstr {
  printf("19\034%s\034",$_[0]) ;
}
# attroff attrs
$curfun{'attroff'} = 'attroff attrs' ;
sub attroff {
  printf("20\034%d\034",$_[0]) ;
}
# attron attrs
$curfun{'attron'} = 'attron attrs' ;
sub attron {
  printf("21\034%d\034",$_[0]) ;
}
# attrset attrs
$curfun{'attrset'} = 'attrset attrs' ;
sub attrset {
  printf("22\034%d\034",$_[0]) ;
}
# baudrate RETURN resint
$curfun{'baudrate'} = 'baudrate RETURN resint' ;
sub baudrate {
  print("23\034") ;
  local($resint) ;
  &curFlush ;
  $resint = <STDIN> ; chop($resint) ;
  return $resint  ;
}
# beep
$curfun{'beep'} = 'beep' ;
sub beep {
  print("24\034") ;
}
# box win vert hor
$curfun{'box'} = 'box win vert hor' ;
sub box {
  printf("25\034%d\034%c\034%c\034",@_) ;
}
# cbreak
$curfun{'cbreak'} = 'cbreak' ;
sub cbreak {
  print("26\034") ;
}
# clear
$curfun{'clear'} = 'clear' ;
sub clear {
  print("27\034") ;
}
# clearok win flag
$curfun{'clearok'} = 'clearok win flag' ;
sub clearok {
  printf("28\034%d\034%d\034",@_) ;
}
# clrtobot
$curfun{'clrtobot'} = 'clrtobot' ;
sub clrtobot {
  print("29\034") ;
}
# clrtoeol
$curfun{'clrtoeol'} = 'clrtoeol' ;
sub clrtoeol {
  print("30\034") ;
}
# delch
$curfun{'delch'} = 'delch' ;
sub delch {
  print("31\034") ;
}
# deleteln
$curfun{'deleteln'} = 'deleteln' ;
sub deleteln {
  print("32\034") ;
}
# delwin delw
$curfun{'delwin'} = 'delwin delw' ;
sub delwin {
  printf("33\034%d\034",$_[0]) ;
}
# doupdate
$curfun{'doupdate'} = 'doupdate' ;
sub doupdate {
  print("34\034") ;
}
# draino ms
$curfun{'draino'} = 'draino ms' ;
sub draino {
  printf("35\034%d\034",$_[0]) ;
}
# echo
$curfun{'echo'} = 'echo' ;
sub echo {
  print("36\034") ;
}
# endwin FLUSH
$curfun{'endwin'} = 'endwin FLUSH' ;
sub endwin {
  print("37\034") ;
  &curFlush ;
}
# erase
$curfun{'erase'} = 'erase' ;
sub erase {
  print("38\034") ;
}
# erasechar RETURN resint
$curfun{'erasechar'} = 'erasechar RETURN resint' ;
sub erasechar {
  print("39\034") ;
  local($resint) ;
  &curFlush ;
  $resint = <STDIN> ; chop($resint) ;
  return $resint  ;
}
# fixterm
$curfun{'fixterm'} = 'fixterm' ;
sub fixterm {
  print("40\034") ;
}
# flash
$curfun{'flash'} = 'flash' ;
sub flash {
  print("41\034") ;
}
# flushinp
$curfun{'flushinp'} = 'flushinp' ;
sub flushinp {
  print("42\034") ;
}
# getch RETURN resint
$curfun{'getch'} = 'getch RETURN resint' ;
sub getch {
  print("43\034") ;
  local($resint) ;
  &curFlush ;
  $resint = <STDIN> ; chop($resint) ;
  return $resint  ;
}
# getstr &str RETURN str
$curfun{'getstr'} = 'getstr &str RETURN str' ;
sub getstr {
  print("44\034") ;
  local($str) ;
  &curFlush ;
  $str = <STDIN> ; chop($str) ;
  return $str  ;
}
# getyx win &y &x RETURN y x
$curfun{'getyx'} = 'getyx win &y &x RETURN y x' ;
sub getyx {
  printf("45\034%d\034",$_[0]) ;
  local($y,$x) ;
  &curFlush ;
  $y = <STDIN> ; chop($y) ;
  $x = <STDIN> ; chop($x) ;
  return $y, $x  ;
}
# has_ic RETURN resint
$curfun{'has_ic'} = 'has_ic RETURN resint' ;
sub has_ic {
  print("46\034") ;
  local($resint) ;
  &curFlush ;
  $resint = <STDIN> ; chop($resint) ;
  return $resint  ;
}
# has_il RETURN resint
$curfun{'has_il'} = 'has_il RETURN resint' ;
sub has_il {
  print("47\034") ;
  local($resint) ;
  &curFlush ;
  $resint = <STDIN> ; chop($resint) ;
  return $resint  ;
}
# idlok win flag
$curfun{'idlok'} = 'idlok win flag' ;
sub idlok {
  printf("48\034%d\034%d\034",@_) ;
}
# inch RETURN resint
$curfun{'inch'} = 'inch RETURN resint' ;
sub inch {
  print("49\034") ;
  local($resint) ;
  &curFlush ;
  $resint = <STDIN> ; chop($resint) ;
  return $resint  ;
}
# initscr
$curfun{'initscr'} = 'initscr' ;
sub initscr {
  print("50\034") ;
  $stdscr = 0 ;
  $curscr = 1 ;
  $LINES = &getLINES ;
  $COLS = &getCOLS ;
}
# insch ch
$curfun{'insch'} = 'insch ch' ;
sub insch {
  printf("51\034%c\034",$_[0]) ;
}
# insertln
$curfun{'insertln'} = 'insertln' ;
sub insertln {
  print("52\034") ;
}
# intrflush win flag
$curfun{'intrflush'} = 'intrflush win flag' ;
sub intrflush {
  printf("53\034%d\034%d\034",@_) ;
}
# keypad win flag
$curfun{'keypad'} = 'keypad win flag' ;
sub keypad {
  printf("54\034%d\034%d\034",@_) ;
}
# killchar RETURN resint
$curfun{'killchar'} = 'killchar RETURN resint' ;
sub killchar {
  print("55\034") ;
  local($resint) ;
  &curFlush ;
  $resint = <STDIN> ; chop($resint) ;
  return $resint  ;
}
# leaveok win flag
$curfun{'leaveok'} = 'leaveok win flag' ;
sub leaveok {
  printf("56\034%d\034%d\034",@_) ;
}
# longname RETURN resstr
$curfun{'longname'} = 'longname RETURN resstr' ;
sub longname {
  print("57\034") ;
  local($resstr) ;
  &curFlush ;
  $resstr = <STDIN> ; chop($resstr) ;
  return $resstr  ;
}
# meta win flag RETURN resint
$curfun{'meta'} = 'meta win flag RETURN resint' ;
sub meta {
  printf("58\034%d\034%d\034",@_) ;
  local($resint) ;
  &curFlush ;
  $resint = <STDIN> ; chop($resint) ;
  return $resint  ;
}
# move y x
$curfun{'move'} = 'move y x' ;
sub move {
  printf("59\034%d\034%d\034",@_) ;
}
# mvaddch y x ch
$curfun{'mvaddch'} = 'mvaddch y x ch' ;
sub mvaddch {
  printf("60\034%d\034%d\034%c\034",@_) ;
}
# mvaddstr y x str
$curfun{'mvaddstr'} = 'mvaddstr y x str' ;
sub mvaddstr {
  printf("61\034%d\034%d\034%s\034",@_) ;
}
# mvcur oldrow oldcol newrow newcol
$curfun{'mvcur'} = 'mvcur oldrow oldcol newrow newcol' ;
sub mvcur {
  printf("62\034%d\034%d\034%d\034%d\034",@_) ;
}
# mvdelch y x
$curfun{'mvdelch'} = 'mvdelch y x' ;
sub mvdelch {
  printf("63\034%d\034%d\034",@_) ;
}
# mvgetch y x RETURN resint
$curfun{'mvgetch'} = 'mvgetch y x RETURN resint' ;
sub mvgetch {
  printf("64\034%d\034%d\034",@_) ;
  local($resint) ;
  &curFlush ;
  $resint = <STDIN> ; chop($resint) ;
  return $resint  ;
}
# mvgetstr y x &str RETURN str
$curfun{'mvgetstr'} = 'mvgetstr y x &str RETURN str' ;
sub mvgetstr {
  printf("65\034%d\034%d\034",@_) ;
  local($str) ;
  &curFlush ;
  $str = <STDIN> ; chop($str) ;
  return $str  ;
}
# mvinch y x RETURN resint
$curfun{'mvinch'} = 'mvinch y x RETURN resint' ;
sub mvinch {
  printf("66\034%d\034%d\034",@_) ;
  local($resint) ;
  &curFlush ;
  $resint = <STDIN> ; chop($resint) ;
  return $resint  ;
}
# mvinsch y x ch
$curfun{'mvinsch'} = 'mvinsch y x ch' ;
sub mvinsch {
  printf("67\034%d\034%d\034%c\034",@_) ;
}
# mvwaddch win y x ch
$curfun{'mvwaddch'} = 'mvwaddch win y x ch' ;
sub mvwaddch {
  printf("68\034%d\034%d\034%d\034%c\034",@_) ;
}
# mvwaddstr win y x str
$curfun{'mvwaddstr'} = 'mvwaddstr win y x str' ;
sub mvwaddstr {
  printf("69\034%d\034%d\034%d\034%s\034",@_) ;
}
# mvwdelch win y x
$curfun{'mvwdelch'} = 'mvwdelch win y x' ;
sub mvwdelch {
  printf("70\034%d\034%d\034%d\034",@_) ;
}
# mvwgetch win y x RETURN resint
$curfun{'mvwgetch'} = 'mvwgetch win y x RETURN resint' ;
sub mvwgetch {
  printf("71\034%d\034%d\034%d\034",@_) ;
  local($resint) ;
  &curFlush ;
  $resint = <STDIN> ; chop($resint) ;
  return $resint  ;
}
# mvwgetstr win y x &str RETURN str
$curfun{'mvwgetstr'} = 'mvwgetstr win y x &str RETURN str' ;
sub mvwgetstr {
  printf("72\034%d\034%d\034%d\034",@_) ;
  local($str) ;
  &curFlush ;
  $str = <STDIN> ; chop($str) ;
  return $str  ;
}
# mvwin win y x
$curfun{'mvwin'} = 'mvwin win y x' ;
sub mvwin {
  printf("73\034%d\034%d\034%d\034",@_) ;
}
# mvwinch win y x RETURN resint
$curfun{'mvwinch'} = 'mvwinch win y x RETURN resint' ;
sub mvwinch {
  printf("74\034%d\034%d\034%d\034",@_) ;
  local($resint) ;
  &curFlush ;
  $resint = <STDIN> ; chop($resint) ;
  return $resint  ;
}
# mvwinsch win y x ch
$curfun{'mvwinsch'} = 'mvwinsch win y x ch' ;
sub mvwinsch {
  printf("75\034%d\034%d\034%d\034%c\034",@_) ;
}
# napms ms
$curfun{'napms'} = 'napms ms' ;
sub napms {
  printf("76\034%d\034",$_[0]) ;
}
# newpad num_lines num_cols RETURN reswin
$curfun{'newpad'} = 'newpad num_lines num_cols RETURN reswin' ;
sub newpad {
  printf("77\034%d\034%d\034",@_) ;
  local($reswin) ;
  &curFlush ;
  $reswin = <STDIN> ; chop($reswin) ;
  return $reswin  ;
}
# newwin num_lines num_cols y x RETURN reswin
$curfun{'newwin'} = 'newwin num_lines num_cols y x RETURN reswin' ;
sub newwin {
  printf("78\034%d\034%d\034%d\034%d\034",@_) ;
  local($reswin) ;
  &curFlush ;
  $reswin = <STDIN> ; chop($reswin) ;
  return $reswin  ;
}
# nl
$curfun{'nl'} = 'nl' ;
sub nl {
  print("79\034") ;
}
# nocbreak
$curfun{'nocbreak'} = 'nocbreak' ;
sub nocbreak {
  print("80\034") ;
}
# nodelay win flag
$curfun{'nodelay'} = 'nodelay win flag' ;
sub nodelay {
  printf("81\034%d\034%d\034",@_) ;
}
# noecho
$curfun{'noecho'} = 'noecho' ;
sub noecho {
  print("82\034") ;
}
# nonl
$curfun{'nonl'} = 'nonl' ;
sub nonl {
  print("83\034") ;
}
# noraw
$curfun{'noraw'} = 'noraw' ;
sub noraw {
  print("84\034") ;
}
# overlay win1 win2
$curfun{'overlay'} = 'overlay win1 win2' ;
sub overlay {
  printf("85\034%d\034%d\034",@_) ;
}
# overwrite win1 win2
$curfun{'overwrite'} = 'overwrite win1 win2' ;
sub overwrite {
  printf("86\034%d\034%d\034",@_) ;
}
# pnoutrefresh pad pminrow pmincol sminrow smincol smaxrow smaxcol
$curfun{'pnoutrefresh'} = 'pnoutrefresh pad pminrow pmincol sminrow smincol smaxrow smaxcol' ;
sub pnoutrefresh {
  printf("87\034%d\034%d\034%d\034%d\034%d\034%d\034%d\034",@_) ;
}
# prefresh pad pminrow pmincol sminrow smincol smaxrow smaxcol
$curfun{'prefresh'} = 'prefresh pad pminrow pmincol sminrow smincol smaxrow smaxcol' ;
sub prefresh {
  printf("88\034%d\034%d\034%d\034%d\034%d\034%d\034%d\034",@_) ;
}
# raw
$curfun{'raw'} = 'raw' ;
sub raw {
  print("89\034") ;
}
# refresh
$curfun{'refresh'} = 'refresh' ;
sub refresh {
  print("90\034") ;
}
# resetterm
$curfun{'resetterm'} = 'resetterm' ;
sub resetterm {
  print("91\034") ;
}
# resetty
$curfun{'resetty'} = 'resetty' ;
sub resetty {
  print("92\034") ;
}
# saveterm
$curfun{'saveterm'} = 'saveterm' ;
sub saveterm {
  print("93\034") ;
}
# savetty
$curfun{'savetty'} = 'savetty' ;
sub savetty {
  print("94\034") ;
}
# scroll win
$curfun{'scroll'} = 'scroll win' ;
sub scroll {
  printf("95\034%d\034",$_[0]) ;
}
# scrollok win flag
$curfun{'scrollok'} = 'scrollok win flag' ;
sub scrollok {
  printf("96\034%d\034%d\034",@_) ;
}
# setscrreg top bot
$curfun{'setscrreg'} = 'setscrreg top bot' ;
sub setscrreg {
  printf("97\034%d\034%d\034",@_) ;
}
# standend
$curfun{'standend'} = 'standend' ;
sub standend {
  print("98\034") ;
}
# standout
$curfun{'standout'} = 'standout' ;
sub standout {
  print("99\034") ;
}
# subwin win num_lines num_cols y x RETURN reswin
$curfun{'subwin'} = 'subwin win num_lines num_cols y x RETURN reswin' ;
sub subwin {
  printf("100\034%d\034%d\034%d\034%d\034%d\034",@_) ;
  local($reswin) ;
  &curFlush ;
  $reswin = <STDIN> ; chop($reswin) ;
  return $reswin  ;
}
# touchwin win
$curfun{'touchwin'} = 'touchwin win' ;
sub touchwin {
  printf("101\034%d\034",$_[0]) ;
}
# typeahead fd
$curfun{'typeahead'} = 'typeahead fd' ;
sub typeahead {
  printf("102\034%d\034",$_[0]) ;
}
# unctrl chint RETURN resstr
$curfun{'unctrl'} = 'unctrl chint RETURN resstr' ;
sub unctrl {
  printf("103\034%d\034",$_[0]) ;
  local($resstr) ;
  &curFlush ;
  $resstr = <STDIN> ; chop($resstr) ;
  return $resstr  ;
}
# waddch win ch
$curfun{'waddch'} = 'waddch win ch' ;
sub waddch {
  printf("104\034%d\034%c\034",@_) ;
}
# waddstr win str
$curfun{'waddstr'} = 'waddstr win str' ;
sub waddstr {
  printf("105\034%d\034%s\034",@_) ;
}
# wattroff win attrs
$curfun{'wattroff'} = 'wattroff win attrs' ;
sub wattroff {
  printf("106\034%d\034%d\034",@_) ;
}
# wattron win attrs
$curfun{'wattron'} = 'wattron win attrs' ;
sub wattron {
  printf("107\034%d\034%d\034",@_) ;
}
# wattrset win attrs
$curfun{'wattrset'} = 'wattrset win attrs' ;
sub wattrset {
  printf("108\034%d\034%d\034",@_) ;
}
# wclear win
$curfun{'wclear'} = 'wclear win' ;
sub wclear {
  printf("109\034%d\034",$_[0]) ;
}
# wclrtobot win
$curfun{'wclrtobot'} = 'wclrtobot win' ;
sub wclrtobot {
  printf("110\034%d\034",$_[0]) ;
}
# wclrtoeol win
$curfun{'wclrtoeol'} = 'wclrtoeol win' ;
sub wclrtoeol {
  printf("111\034%d\034",$_[0]) ;
}
# wdelch win
$curfun{'wdelch'} = 'wdelch win' ;
sub wdelch {
  printf("112\034%d\034",$_[0]) ;
}
# wdeleteln win
$curfun{'wdeleteln'} = 'wdeleteln win' ;
sub wdeleteln {
  printf("113\034%d\034",$_[0]) ;
}
# werase win
$curfun{'werase'} = 'werase win' ;
sub werase {
  printf("114\034%d\034",$_[0]) ;
}
# wgetch win RETURN resint
$curfun{'wgetch'} = 'wgetch win RETURN resint' ;
sub wgetch {
  printf("115\034%d\034",$_[0]) ;
  local($resint) ;
  &curFlush ;
  $resint = <STDIN> ; chop($resint) ;
  return $resint  ;
}
# wgetstr win &str RETURN str
$curfun{'wgetstr'} = 'wgetstr win &str RETURN str' ;
sub wgetstr {
  printf("116\034%d\034",$_[0]) ;
  local($str) ;
  &curFlush ;
  $str = <STDIN> ; chop($str) ;
  return $str  ;
}
# winch win RETURN resint
$curfun{'winch'} = 'winch win RETURN resint' ;
sub winch {
  printf("117\034%d\034",$_[0]) ;
  local($resint) ;
  &curFlush ;
  $resint = <STDIN> ; chop($resint) ;
  return $resint  ;
}
# winsch win ch
$curfun{'winsch'} = 'winsch win ch' ;
sub winsch {
  printf("118\034%d\034%c\034",@_) ;
}
# winsertln win
$curfun{'winsertln'} = 'winsertln win' ;
sub winsertln {
  printf("119\034%d\034",$_[0]) ;
}
# wmove win y x
$curfun{'wmove'} = 'wmove win y x' ;
sub wmove {
  printf("120\034%d\034%d\034%d\034",@_) ;
}
# wnoutrefresh win
$curfun{'wnoutrefresh'} = 'wnoutrefresh win' ;
sub wnoutrefresh {
  printf("121\034%d\034",$_[0]) ;
}
# wrefresh win
$curfun{'wrefresh'} = 'wrefresh win' ;
sub wrefresh {
  printf("122\034%d\034",$_[0]) ;
}
# wsetscrreg win top bot
$curfun{'wsetscrreg'} = 'wsetscrreg win top bot' ;
sub wsetscrreg {
  printf("123\034%d\034%d\034%d\034",@_) ;
}
# wstandend win
$curfun{'wstandend'} = 'wstandend win' ;
sub wstandend {
  printf("124\034%d\034",$_[0]) ;
}
# wstandout win
$curfun{'wstandout'} = 'wstandout win' ;
sub wstandout {
  printf("125\034%d\034",$_[0]) ;
}

1 ;
