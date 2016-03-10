#include <stdio.h>	//for printf function
#include "screen.h"

void clearScreen(void){
	printf("\033[2J"); //\033: octal escape sequence, [2J: clear entire screen
	fflush(stdout);	//flush info for Putty, no if local
}
void gotoxy(short x, short y){
	printf("\033[%d;%dH", y, x);	//x for column, y for row, ]H: maove cursor to upperleft
	fflush(stdout);
}
void setColors(short fg, short bg){
	printf("\033[%d;%dm", fg, bg);	//]m: stop character
	fflush(stdout);
}
void resetColors(){
	printf("\033[0m");	//reset to default color
	fflush(stdout);
}
void dispBar(short x, short y, short bottom){
	int i;
	for(i=y; i<bottom; i++){
		gotoxy(x, i);
		printf("%s", BAR);
	}
	fflush(stdout);
}
