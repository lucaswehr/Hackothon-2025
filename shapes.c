#include "Header.h"

int shapes(Cell board[][75], Marker currentMarker)
{
	char x = '\0';

	int* arrow = 0;
	
	char symbol = '\0';

	int shape = 0;

	printf("Would you like to add a pre-determined shape? (Y/N) ");

	scanf(" %c", &x);
	getchar();
	if (x == 'Y' || x == 'y')
	{
		printf("what shape would you like to make?\n");
		printf("1. Rectangle\n");
		printf("2. Circle\n");
		printf("3. Triangle\n");

		do {
			scanf("%d", &shape);
		} while (shape < 0 || shape > 3);

		if (shape == 1) {

			int length = 0, width = 0;
			Cell center = move_around_canvas(board, &currentMarker, &arrow);
			printf("Enter the Length:");
			do {
				scanf("%d", &length);
			} while (length < 0);
			printf("Enter the Width:");
			do {
				scanf("%d", &width);
			} while (width < 0);
				
			rectangle(board, currentMarker, length, width, center);
		}
		else if (shape == 3) {
			int height = 0, width = 0;
			Cell center = move_around_canvas(board, &currentMarker, &arrow);
			printf("Enter a height: ");
			do
			{
				scanf("%d", &height);
			} while (height < 0);
			printf("Enter a width: ");
			do
			{
				scanf("%d", &width);
			} while (width < 0);
			drawTriangle(center, height, width, currentMarker, board);
		}
		else if (shape == 2) {
			int radius = 0;
			Cell cursor = move_around_canvas(board, &currentMarker, &arrow);
			printf("\nEnter a radius: ");
			do {
				scanf("%d", &radius);
			} while (radius < 0);
			make_circle(board, radius, cursor, currentMarker);
		}
	}
	else if (x == 'N' || x == 'n')
	{
		printf("Would you like to add a line between two points? (Y/N) ");
		scanf(" %c", &x);
		getchar();
		if (x == 'Y' || x == 'y')
		{
			Cell point1 = move_around_canvas(board, &currentMarker, &arrow);
			Cell point2 = move_around_canvas(board, &currentMarker, &arrow);

			createLine(board, point1, point2, currentMarker);
		}
		else {

			printf("Would you like to add a specific point onto the canvas? (Y/N)");
			scanf(" %c", &x);
			getchar();

			if (x == 'Y' || x == 'y')
			{
				Cell cursor = { 0 };

				cursor = move_around_canvas(board, &currentMarker, &arrow);

				individual(cursor, board, currentMarker);

			}
			else {
				return 0;
			}
		}
	}
	return 1;
}

void rectangle(Cell board[][75], Marker currentMarker, int length, int width, Cell center)
{
	int* arrow = 0;
	int pointX = 0, pointY = 0;
	pointX = center.X;
	pointY = center.Y;

	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < length; j++)
		{
			if (pointX + i < 50 && pointY + j < 75)
			{
				board[pointX + i][pointY + j].symbol = currentMarker.symbol;
				board[pointX + i][pointY + j].color = currentMarker.color;
			}
		}
	}
	
}

void square(Cell board[][75], Marker currentMarker)
{
	char array[30];

	int length = 0, centerLength = 0, pointX = 0, pointY = 0;

	printf("Enter length and Width:");

	scanf("%d", &length);

	printf("Pick a point on the board to place the shape: (x,y)\n");

	scanf("%d", &pointX);
	scanf("%d", &pointY);

	int center = length / 2;

	for (int i = -center; i <= center; i++) {

		for (int j = -center; j <= center; j++)
		{
			int x = pointX + i;

			int y = pointY + j;

			if (x >= 0 && x < 74 && y >= 0 && y < 74) {

				if (i == -center || i == center || j == -center || j == center)
				{

					board[x][y].symbol = currentMarker.symbol;
					board[x][y].color = currentMarker.color;
				}

			}
		}
	}
}

void make_circle(Cell canvas[][75], int radius, Cell center, Marker currentMarker) 

{
		int decision = 3 - (2 * radius);
		Cell circle = { 0, radius, '\0' };

		while (circle.X <= circle.Y) {
			
			for (int i = center.X - circle.X; i <= center.X + circle.X; i++) {
				if (i >= 0 && i < 50) {  
					if (center.Y + circle.Y < 75) {
						canvas[i][center.Y + circle.Y].symbol = currentMarker.symbol;
						canvas[i][center.Y + circle.Y].color = currentMarker.color;
					}
					if (center.Y - circle.Y >= 0) {
						canvas[i][center.Y - circle.Y].symbol = currentMarker.symbol;
						canvas[i][center.Y - circle.Y].color = currentMarker.color;
					}
				}
			}
			for (int i = center.X - circle.Y; i <= center.X + circle.Y; i++) {
				if (i >= 0 && i < 50) {  
					if (center.Y + circle.X < 75) {
						canvas[i][center.Y + circle.X].symbol = currentMarker.symbol;
						canvas[i][center.Y + circle.X].color = currentMarker.color;
					}
					if (center.Y - circle.X >= 0) {
						canvas[i][center.Y - circle.X].symbol = currentMarker.symbol;
						canvas[i][center.Y - circle.X].color = currentMarker.color;
					}
				}
			}

			if (decision < 0) {
				decision = decision + 4 * circle.X + 6;
				circle.X++;
			}
			else {
				decision = decision + 4 * (circle.X - circle.Y) + 10;
				circle.X++;
				circle.Y--;
			}
		}
}

void drawTriangle(Cell center, int height, int width, Marker currentMarker, Cell board[][75])
{
	int point1X = 0, point1Y = 0, point2X = 0, point2Y = 0, point3X = 0, point3Y = 0; //these represent three points of the triangle

	point1Y = center.X;
	point1X = center.Y + height / 2;

	point2Y = center.X - width / 2;
	point2X = center.Y - height / 2;

	point3Y = center.X + width / 2;
	point3X = center.Y - height / 2;

	drawLine(point1X, point1Y, point2X, point2Y, currentMarker, board);
	drawLine(point2X, point2Y, point3X, point3Y, currentMarker, board);
	drawLine(point3X, point3Y, point1X, point1Y, currentMarker, board);
}

void drawLine(int x0, int y0, int x1, int y1, Marker currentMarker, Cell board[][75])
{
	int dx = abs(x1 - x0);
	int dy = abs(y1 - y0); //absolute values of the change of x and y
	int sx = (x0 < x1) ? 1 : -1; //determines direction for x
	int sy = (y0 < y1) ? 1 : -1; //determines direction for y
	int err = dx - dy;

	while (1) //infinite loop, will be broken later in the loop
	{
		if (x0 >= 0 && x0 < 75 && y0 >= 0 && y0 < 50)
		{
			board[y0][x0].symbol = currentMarker.symbol;
			board[y0][x0].color = currentMarker.color;
		}
		if (x0 == x1 && y0 == y1)
		{
			break; //breaks loop because endpoint has been reached
		}
		int e2 = 2 * err; //Double error value

		if (e2 > -dy)  // Move in x direction if needed
		{
			err -= dy;
			x0 += sx;
		}
		if (e2 < dx) // Move in y direction if needed
		{
			err += dx;
			y0 += sy;
		}
	}
}


void individual(Cell curser, Cell board[][75], Marker currentMarker)
{

	board[curser.X][curser.Y].symbol = currentMarker.symbol;

	board[curser.X][curser.Y].color = currentMarker.color;

	
}


void createLine(Cell board[][75], Cell cursor1, Cell cursor2, Marker currentMarker)
{
	int x1 = cursor1.Y;
	int y1 = cursor1.X;

	int x2 = cursor2.Y;
	int y2 = cursor2.X;

	drawLine(x1, y1, x2, y2, currentMarker, board);
}
