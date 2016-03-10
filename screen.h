//const declare
enum FGCOLOR {BLACK=30,RED,GREEN,YELLOW,BLUE,MAGENTA,CYAN,WHITE};	//user-defined data, values start with 30 and up
#define bg(a) (a+10)	//function definition, values start with 40 and up
#define BAR "\u2590"	//C code for right half block

//function definition
void clearScreen(void);
void gotoxy(short x, short y);
void setColors(short fg, short bg);
void dispBar(short x, short y, short bottom);
void resetColors();
