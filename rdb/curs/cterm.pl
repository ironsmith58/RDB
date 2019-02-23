#! /local/bin/perl

do 'cdefs.pl'  || die "cterm.pl can't include cdefs.pl\n" ;
do 'curcon.pl' || die "cterm.pl can't include curcon.pl\n" ;

sub curFlush
  { $oldpipe = $| ;
    $| = 1 ;
    print "" ;
    $| = $oldpipe ;
  }

sub frefresh { &refresh ; &curFlush if $flushOn ; }

sub ch2str
  { local($c) = shift ;
    if ( (31 < $c) && ($c < 128) )
      { return(sprintf("%c", $c)) ; }
    elsif ( defined $curkey{$c} )
      { return($curkey{$c}) ; }
    else
      { return($c) ; }
  }

sub getchint { return &ch2str(&getch) ; }

sub safeCterm { $safeCterm = 1 ; }

sub startCterm
  { pipe(CURIN,PERLOUT) || die "cterm.pl can\'t create pipe CURIN/PERLOUT" ; 
    pipe(PERLIN,CUROUT) || die "cterm.pl can\'t create pipe PERLIN/CUROUT" ; 

    $ctermPid = fork ;

    if ( $safeCterm ? ( $ctermPid != 0 ) : ( $ctermPid == 0 ) )
      { close(PERLIN)  || die "cterm.pl can\'t close PERLIN" ;
        close(PERLOUT) || die "cterm.pl can\'t close PERLOUT" ;
        exec('cterm',fileno(CURIN),fileno(CUROUT),@_) ;
        die 'cterm.pl can\'t exec cterm' ;
      }
    else
      { close(CURIN)  || die "cterm.pl can\'t close CURIN" ;
        close(CUROUT) || die "cterm.pl can\'t close CUROUT" ;
        open(SAVESTDIN, "<&STDIN")  || die 'cterm.pl can\'t save STDIN' ;
        open(SAVESTDOUT,">&STDOUT") || die 'cterm.pl can\'t save STDOUT' ;
        open(STDIN, "<&PERLIN")     || die 'cterm.pl can\'t redirect STDIN' ;
        open(STDOUT,">&PERLOUT")    || die 'cterm.pl can\'t redirect STDOUT' ;
	$preCtermPipe = $| ;
	$preCtermSelect = select(STDOUT) ;
        $| = 0 ;
	$flushOn = 0 ;
      }
  }

sub finishCterm
  { &quitcterm ;
    close(PERLOUT) ;
    sleep 1 ;
    close(PERLIN) ;
    open(STDIN, "<&SAVESTDIN")  || die 'cterm.pl can\'t reredirect STDIN' ;
    open(STDOUT,">&SAVESTDOUT") || die 'cterm.pl can\'t reredirect STDOUT' ;
    close(SAVESTDIN) ;
    close(SAVESTDOUT) ;
    select($preCtermSelect) ;
    $| = $preCtermPipe ;
  }

1;
