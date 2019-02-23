#! /local/bin/perl

open(STDIN,'curcon.in')  || die "can't open curcon\n" ;
open(STDOUT,'>curcon.c') || die "can't create curcon.c\n" ;

print "#include <curses.h>\n" ;
print "#include <stdio.h>\n" ;
print "\n" ;
print "main() {\n" ;

while ( $_ = <STDIN> )
  { chop ;
    next if $_ =~ /^[ \t]*$/ || $_ =~ /^#/ ;
    $arg = ( /^(.*)\(.*\)/ ) ? $1 : $_ ;
    print "#ifdef $arg\n" ;
    print "  printf(\"\$curcon{'$_'} = %d ;\\n\",$_) ;\n" ;
    if ( $_ =~ /^KEY/ )
      { print "  printf(\"\$curkey{%d} = '$_' ;\\n\",$_) ;\n" ; }
    print "#else\n" ;
    print "  fprintf(stderr,\"warning: no definition for $_\\n\") ;\n" ;
    print "#endif\n" ;
  }
for ( 'EDIT_LEFT', 'EDIT_RIGHT' )
  { print "#ifdef $_\n" ;
    print "  printf(\"\$curcon{'$_'} = %d ;\\n\",$_) ;\n" ;
    print "#else\n" ;
    print "  fprintf(stderr,\"warning: no definition for $_\\n\") ;\n" ;
    print "#endif\n" ;
  }

print "  printf(\"\$curcon{'KEY_RET'} = %d ;\\n\",13) ;\n" ;
print "  printf(\"\$curkey{13} = 'KEY_RET' ;\\n\") ;\n" ;
print "  printf(\"\$curcon{'KEY_TAB'} = %d ;\\n\",9) ;\n" ;
print "  printf(\"\$curkey{9} = 'KEY_TAB' ;\\n\") ;\n" ;
print "  exit(0) ;\n" ;
print "}\n" ;
