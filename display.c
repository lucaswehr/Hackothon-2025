#include "Header.h"

void initial_board(Cell array[][75], char symbol) {

	//move row count
	for (int i = 0; i < 50; i++)
	{
		//move column count
		for (int j = 0; j < 75; j++)
		{
			array[i][j].symbol = symbol;
			array[i][j].X = i;
			array[i][j].Y = j;
		}
	}
}


void print_board(Cell array[][75])
{
	printf("---------------------------------------------------------------------------------------------------------------------------------------------------------\n");

	for (int i = 0; i < 50; i++)
	{
		printf("%-2d ", i);
		for (int j = 0; j < 75; j++)
		{
			if (array[i][j].symbol == '.') {
				printf("%c ", array[i][j].symbol);
			}
			else
			{
				switch (array[i][j].color)
				{
				case 1:
					printf(RED "%c " RESET, array[i][j].symbol);
					break;
				case 2:
					printf(YELLOW "%c " RESET, array[i][j].symbol);
					break;
				case 3:
					printf(GREEN "%c " RESET, array[i][j].symbol);
					break;
				case 4:
					printf(BLUE "%c " RESET, array[i][j].symbol);
					break; 
				case 5:
					printf(LIGHTBLUE "%c " RESET, array[i][j].symbol);
					break;
				case 6:
					printf(PURPLE "%c " RESET, array[i][j].symbol);
					break;
				case 7:
					printf(BLACK "%c " RESET, array[i][j].symbol);
					break;
				case 8: 
					printf(WHITE "%c " RESET, array[i][j].symbol);
					break;
				default:
					printf("%c ", array[i][j].symbol);
					break;
				}
			}
		}
		putchar('\n');
	}
	printf("---------------------------------------------------------------------------------------------------------------------------------------------------------\n");
	printf("Color List: 1. Red 2. Yellow 3. Green 4. Blue 5. Light Blue 6. Purple 7. Black 8. White 9. Default\n");
	printf("---------------------------------------------------------------------------------------------------------------------------------------------------------\n");
	printf("W: Up A: Left S: Down D: Right Q: Quit P: Place M: Marker L: Load Canvas U: Upload Canvas\n");
	printf("---------------------------------------------------------------------------------------------------------------------------------------------------------\n");
}

