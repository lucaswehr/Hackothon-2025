#include "Header.h"

int main(void)
{
	Marker currentMarker = { 0 };
	Cell cursor; //= { 0, 0 ,'0' };
	Cell canvas[50][75];
	initial_board(canvas, '.');
	int* arrow = 0;
	int choice = 0;
	int breakOut = 0;
	choice = printMenu();
	while (choice != 3) 
	{
		print_board(canvas);
		breakOut = shapes(canvas);
		if (!breakOut)
		{
			break;
		}
	}
	while (choice != 3)
	{
		if (arrow == 0)
		{
			return 0;
		}
        print_board(canvas);

	}
		
	return 0;
}