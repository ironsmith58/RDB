#! /local/bin/perl

do 'cdefs.types' ;

unlink('cdefs.c') ;
unlink('cdefs.pl') ;
open(STDIN,'cdefs.in') || die 'can\'t open cdefs.in' ; 
open(C,'>cdefs.c')     || die 'can\'t write cdefs.c' ;
open(P,'>cdefs.pl')    || die 'can\'t write cdefs.pl' ;

$curdef = '0' ;
$sep = "\\034" ;

print C "#include <stdio.h>\n" ;
print C "#include <curses.h>\n" ;
print C "#include \"cursesXt.h\"\n" ;
print C "#include \"defs.h\"\n" ;
print C "\n" ;
for ( sort keys %type )
  { if ( $type{$_} eq 'int' )
      { print C "static int $_ ;\n" ; }
    elsif ( $type{$_} eq 'char' )
      { print C "static char $_ ;\n" ; }
    elsif ( $type{$_} eq 'str' )
      { print C "static char $_\[BUFSIZE] ;\n" ; }
    elsif ( $type{$_} eq 'win' )
      { print C "static WINDOW *$_ ;\n" ; }
  }
print C "static int res ;\n" ;
print C "\n" ;

while ( $_ = <STDIN> )
  { chop ;
    next if $_ =~ /^[ \t]*$/ || /^#/ ;
    @ret = () ;
    @arg = () ;
    $varargs = 0 ;
    $arg = '' ;
    $body = '' ;
    $form = '' ;
    @_ = split ;
    $func = shift @_ ;
    push(@func,$func) ;
    print C "void do_$func() {\n" ;
    print C "  addlogs(LOGCURS1,\"$func\") ;\n" ;
    print P "# $_\n" ;
    print P "\$curfun{'$func'} = '$_' ;\n" ;
    print P "sub $func {\n" ;
    $form = "$curdef$sep" ;
    for ( $i = 0 ; $i <= $#_ ; $i++ )
      { $arg = $_[$i] ;
	if ( $type{$arg} eq 'char' )
          { $form .= "%c$sep" ;
            print C "  $arg = nextChr() ;\n" ;
	  }
	elsif ( $type{$arg} eq 'str' )
          { $form .= "%s$sep" ;
            print C "  strcpy($arg,nextStr()) ;\n" ;
	  }
	elsif ( $type{$arg} eq 'int' )
          { $form .= "%d$sep" ;
            print C "  $arg = nextInt() ;\n" ;
	  }
	elsif ( $type{$arg} eq 'win' )
          { $form .= "%d$sep" ;
            print C "  $arg = windows[nextInt()] ;\n" ;
	  }
	elsif ( $type{$arg} eq 'var' )
          { $arg =~ s/^&(.*)/$1/ ;
	    $varargs++ ;
	  }
	elsif ( $arg eq 'RETURN' )
	  { @ret = @_[$i+1..$#_] ;
	    last ;
	  }
	elsif ( $arg eq 'FLUSH' )
	  { last ; }
	else
	  { print "unknown argument $arg in $_\n" ; }
	push(@arg,$arg) ;
      }

    if ( $#arg - $varargs < 0 )
      { print P "  print(\"$form\") ;\n" ; }
    elsif ( $#arg - $varargs == 0 )
      { print P "  printf(\"$form\",\$_[0]) ;\n" ; }
    else
      { print P "  printf(\"$form\",\@_) ;\n" ; }

    if ( $#ret >= 0 )
      { print P '  local($', join(',$',@ret), ") ;\n" ; }

    if ( $func eq 'initscr' )
      { print C "  initscr() ;\n" ;
	print C "  hasWin = 1 ;\n" ;
	print C "  initWindows() ;\n" ;
	print C "  saveWindow(stdscr) ;\n" ;
	print C "  saveWindow(curscr) ;\n" ;
	print C "  initCursesXt() ;\n" ;
	$body .= "  \$stdscr = 0 ;\n" ;
	$body .= "  \$curscr = 1 ;\n" ;
	$body .= "  \$LINES = &getLINES ;\n" ;
	$body .= "  \$COLS = &getCOLS ;\n" ;
      }
    elsif ( $func eq 'endwin' )
      { print C "  endwin() ;\n" ;
	print C "  hasWin = 0 ;\n" ;
        $body .= "  &curFlush ;\n" ;
      }
    elsif ( $func eq 'delwin' )
      { print C "  win = windows[$arg] ;\n" ;
        print C "  unsaveWindow($arg) ;\n" ;
        print C "  delwin(win) ;\n" ;
      }
    elsif ( $arg eq 'RETURN' )
      { $body .= "  &curFlush ;\n" ;
	@res = grep(/^res(int|str|win)$/,@ret) ;
        if ( $#res > 0 )
	  { print "$_ : you may specify res... only once\n" ; }
        elsif ( $#res == 0 )
	  { if ( $type{$res[0]} eq 'str' )
	      { print C "  strcpy($res[0],$func(". join(',',@arg) . ")) ;\n" ; }
	    else
	      { print C "  $res[0] = $func(". join(',',@arg) . ") ;\n" ; }
	  }
	else
	  { print C "  $func(". join(',',@arg) . ") ;\n" ; }
        for $ret ( @ret )
	  { $body .= "  \$$ret = <STDIN> ; chop(\$$ret) ;\n" ;
	    if ( $type{$ret} eq 'str' )
	      { print C "  fprintf(OUT,\"%s\\n\",$ret) ;\n" ;
	        print C "  addlogss(LOGCURS1," ;
		print C "\"do_$func prints OUT\",$ret) ;\n" ;
	      }
	    elsif ( $type{$ret} eq 'win' )
	      { print C "  res = saveWindow($ret) ;\n" ;
	        print C "  fprintf(OUT,\"%d\\n\",res) ;\n" ;
	        print C "  addlogsn(LOGCURS1," ;
		print C "\"do_$func prints OUT\",res) ;\n" ;
	      }
	    elsif ( $type{$ret} eq 'int' )
	      { print C "  fprintf(OUT,\"%d\\n\",$ret) ;\n" ;
	        print C "  addlogsn(LOGCURS1," ;
		print C "\"do_$func prints OUT\",$ret) ;\n" ;
	      }
	    else
	      { print "I have no type for $ret\n" ; }
	  }
	print C "  fflush(OUT) ;\n" ;
        $body .= '  return $'. join(', $',@ret) . "  ;\n" ;
      }
    elsif ( $arg eq 'FLUSH' )
      { $body .= "  &curFlush ;\n" ;
        print C "  $func(". join(',',@arg) . ") ;\n" ;
      }
    else
      { print C "  $func(". join(',',@arg) . ") ;\n" ; }

    print P $body, "}\n" ;
    print C "}\n" ;
    $curdef++ ;
  }

print P "\n1 ;\n" ;

print C "void (*(funtab[$curdef]))() ;\n" ;
print C "void init_funtab() {\n" ;
$i = 0 ;
for $func ( @func )
  { print C "  funtab[$i] = do_$func ;\n" ;
    $i++ ;
  }
print C "}\n" ;
