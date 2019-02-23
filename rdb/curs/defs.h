#define BUFSIZE 20480
#define BUFSIZE2 10240
#define SEP 28

#define MAXNUMWINDOWS 100
#define MAXQUITEDIT 1000
#define REDRAW_INT '\014'
#define OPTX_INT '\030'

#define LOGAPPL   0
#define LOGCURS1  1
#define LOGCURS2  2

extern FILE *OUT ;
extern WINDOW *windows[] ;
extern int optX, hasWin ;

extern int saveWindow() ;
extern void unsaveWindow() ;
extern void initWindows() ;
extern void redraw() ;

extern char *nextStr()  ;
extern int nextChr() ;
extern int nextInt()  ;

extern void emptyQuitEdit() ;
extern int addQuitEdit() ;

extern void emptyLeftEdit() ;
extern int addLeftEdit() ;

extern void emptyRightEdit() ;
extern int addRightEdit() ;

extern void (*(funtab[]))() ;
