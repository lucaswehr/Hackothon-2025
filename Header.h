
#define _CRT_SECURE_NO_WARNINGS

#define BLUE "\x1b[34;44m" 

#define YELLOW "\x1b[33;43m"

#define WHITE "\x1b[37;47m"

#define LIGHTBLUE "\x1b[36;46m"

#define PURPLE "\x1b[35;45m"

#define RED "\x1b[31;41m"

#define GREEN "\x1b[32;42m"

#define BLACK "\x1b[30;40m"

#define RESET "\x1b[0m" 

#define RED1 "\033[0;31m"

#define GREEN1 "\033[0;32m"

#define YELLOW1 "\033[0;33m"

#define BLUE1 "\033[0;34m"

#define CONSOLE_WIDTH 120

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <conio.h>


typedef struct cell {
	int X;
	int Y;
	char symbol;
	int color;
}Cell;

typedef struct marker
{
	char symbol;
	int color;
}Marker;

//FUNC
int get_arrow_input();
int printMenu();
void printInstructions();
Marker setMarker();

//SHAPES
int shapes(Cell board[][75]);
void make_circle(Cell canvas[][75], int radius, Cell center, Marker currentMarker);
void rectangle(Cell board[][75], Marker currentMarker, int length, int width, Cell center);
void square(Cell board[][75], Marker currentMarker);
void drawTriangle(Cell center, int height, int width, Marker currentMarker, Cell board[][75]);
void drawLine(int x0, int y0, int x1, int y1, Marker currentMarker, Cell board[][75]);



//DISPLAY
void print_board(Cell array[][75]);
void initial_board(Cell array[][75], char symbol);
Cell move_around_canvas(Cell canvas[][75], Marker *currentMarker, int *arrow);
void individual(Cell curser, Cell board[][75], Marker currentMarker);
void createLine(Cell board[][75], Cell cursor1, Cell cursor2, Marker currentMarker);
void center_text(const char* text);
void printToFile(FILE* file, Cell board[][75]);
void parseFile(FILE* file, Cell board[][75]);



//MATH


