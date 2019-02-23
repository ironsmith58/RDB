# names of programs used and compiler flags

CC=/usr/5bin/cc
CFLAGS=-O
LFLAGS=-lcurses
LDFLAGS='-lcurses -ltermcap'
NROFF=nroff
TROFF=lroff
PERL=perl

# directories where the stuff gets installed

BINDIR=/usr/staff/bin
BINMODE=755
PERLLIB=/local/usr/lib/perl
LIBMODE=755

# constants used by edit.c

EDIT_RIGHT=-DEDIT_RIGHT=6
EDIT_LEFT=-DEDIT_LEFT=2
BEEP=-DBEEP=beep

# no editing beyond this line

PLS=cterm.pl cdefs.pl curcon.pl
OBJ=cterm.o cursesXt.o cdefs.o edit.o
MISC=Makefile README cterm.1 try1 try2
SOU=defs.h edit.c cterm.c cursesXt.c cursesXt.h
GEN=cdefs.in cdefs.in.SUN cdefs.mk cdefs.types curcon.in curcon.mk cterm.pl

ALL=${MISC} ${SOU} ${GEN}
CTERM=cterm.2.1
ARCH=escudo.cs.ruu.nl
SHELL=/bin/sh
COMPRESS=/usr/ucb/compress

all: cterm curcon.pl
cterm: cterm.o cursesXt.o edit.o cdefs.o
	${CC} ${CFLAGS} -o cterm cterm.o cursesXt.o edit.o cdefs.o ${LFLAGS}
cterm.o: cterm.c defs.h
	${CC} ${CFLAGS} -c cterm.c
cursesXt.o: cursesXt.c cursesXt.h defs.h
	${CC} ${CFLAGS} -c cursesXt.c
cdefs.o: cdefs.c cursesXt.h defs.h
	${CC} ${CFLAGS} -c cdefs.c
edit.o: edit.c defs.h
	${CC} ${CFLAGS} ${EDIT_RIGHT} ${EDIT_LEFT} ${BEEP} -c edit.c
cdefs.c: cdefs.in
	${PERL} cdefs.mk
curcon.pl: curcon
	./curcon > curcon.pl
curcon: curcon.c
	${CC} ${CFLAGS} ${EDIT_RIGHT} ${EDIT_LEFT} -o curcon curcon.c
curcon.c: curcon.in
	${PERL} curcon.mk
cterm.1.nr: cterm.1
	${NROFF} -man cterm.1 > cterm.1.nr
cterm.1.tr: cterm.1
	${TROFF} -man cterm.1 > cterm.1.tr
install: all
	cp cterm ${BINDIR}
	chmod ${BINMODE} ${BINDIR}/cterm
	cp ${PLS} ${PERLLIB}
	cd ${PERLLIB} ; chmod ${LIBMODE} ${PLS}
	@echo 'install man page by hand'
man: cterm.1.tr cterm.1.nr
clean:
	rm -f ${OBJ} core cdefs.c curcon.c curcon
realclean: clean
	rm -f cterm cdefs.pl curcon.pl cterm.1.nr cterm.1.tr
	rm -f cterm.shar cterm.shar.Z
cterm.shar.Z: shar
shar: realclean
	shar -o cterm.shar ${ALL}
	${COMPRESS} -v cterm.shar
arch: shar
	rcp cterm.shar.Z ${ARCH}:/users/ftp/UNIX/${CTERM}.shar.Z
	rsh ${ARCH} chmod 644 /users/ftp/UNIX/${CTERM}.shar.Z
backup: shar
	cp cterm.shar.Z ../back/${CTERM}.shar.Z
show: cterm.1.nr
	col < cterm.1.nr | more
wc: realclean
	wc *
