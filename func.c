#include "Header.h"

int printMenu()
{
	char* message0 = BLUE1 "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" RESET;
	char* message1 = "Welcome to the";
	char* message7 = RED1 "            ---------------------------------" RESET;
	char* message2 = RED1 "            IMAGINATION STATION" RESET;
	char* message8 = RED1 "            ---------------------------------" RESET;
	char* message3 = GREEN1 "            1. USER MANUAL\n" RESET;
	char* message4 = BLUE1 "             2. OPEN CANVAS\n" RESET;
	char* message5 = YELLOW1 "           3. EXIT\n" RESET;
	char* message6 = "Please Enter Your Selection:";
	char *message9 = BLUE1 "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" RESET;
	int option = 0;
	do {
	system("cls");
	center_text(message0);
	center_text(message1);
    center_text(message7);
	center_text(message2);
	center_text(message8);
	center_text(message3);
	center_text(message4);
	center_text(message5);
	center_text(message6);
	center_text(message9);
		scanf("%d", &option);
		if (option == 1) {
			system("cls");
			printInstructions();
			system("pause");
		}
	} while (option > 3 || option < 0);

	return option;
}

void center_text(const char* text) 
{
	int length = strlen(text);

	int padding = (120 - length) / 2;

	for (int i = 0; i < padding; i++) {
		printf(" ");
	}
	printf("%s\n", text);
}


void printInstructions()
{
	printf("Welcome to IMAGINAITON STATION, your new FAVORITE command line art canvas!\n");
	printf("You will first be prompted to either add a shape, a line, or color a single cell\n");
	printf("After answering the prompt you will choose a Marker (Key M), consisting of a symbol and color\n");
	printf("If you choose to add a shape, you will use your cursor to find a center point, then enter other values required for the shape\n");
	printf("If you choose to draw a line, you will choose two points with your cursor, which will then be connected\n");
	printf("If you decide to fill a single cell, you wil use your cursor to select a singular cell\n");
	printf("If you say no to all three prompts, then the program will finish and exit\n");
	printf("To draw on the canvas, you can move your cursor around, by using the W, A, S, and D keys.\n");
	printf("The inputs go as follows:\nW = Up\nA = Left\nS = Down\nD = Right\nQ = Exit\nP = Place\nM = Marker\nL = Load Canvas\nU = Upload Canvas\n");
	printf("The colors also go as follows:\n1. Red\n2. Yellow\n3. Green\n4. Blue\n5. Light Blue\n6. Purple\n7. Black\n8. White\n9. Default\n");
	printf("To quit the function while adding to the canvas enter Q\n");
	printf("To place on the cell the cursor is hovering over, press P\n");
	printf("To access your marker, press M\n");
	printf("To load a saved canvas, press L\n");
	printf("To upload and save a canvas, press U\n\n\n");
	printf("THAT'S IT, NOW GO LET YOUR IMAGINATION RUN FREE\n");

	system("pause");
	system("cls");
}

Marker setMarker()
{
	Marker newMarker;
	printf("Enter new symbol: ");
	getchar();
	scanf(" %c", &newMarker.symbol);
	getchar();
	printf("Enter new color:");
	scanf("%d", &newMarker.color);

	return newMarker;
}

int get_arrow_input()
{
	//printf("Press an WASD key to move and P to place (use Q to exit):\n");
	//initilize input
	char input = '\0';

	//Get and verify user input
	do {
		input = _getch();
	} while (input != 'w' && input != 'W' && input != 'a' && input != 'A' && input != 's' && input != 'S' && input != 'd' && input != 'D' && input != 'Q' && input != 'q' && input != 'P' && input != 'p' && input != 'm' && input != 'M' && input != 'l' && input != 'L' && input != 'u' && input != 'U');

	//return a direction int
	if (input == 'Q' || input == 'q') {
		return 0;
	}
	else if (input == 'w' || input == 'W') {
		return 1;
	}
	else if (input == 's' || input == 'S') {
		return 2;
	}
	else if (input == 'd' || input == 'D') {
		return 3;
	}
	else if (input == 'a' || input == 'A') {
		return 4;
	}
	else if (input == 'p' || input == 'P') {
		return 5;
	}
	else if (input == 'm' || input == 'M') {
		return 6;
	}
	else if (input == 'l' || input == 'L') {
		return 7;
	}
	else if (input == 'u' || input == 'U') {
		return 8;
	}
}
Cell move_around_canvas(Cell canvas[][75], Marker* currentMarker, int* arrow) 
{

	char* temp = '\0';
	Cell cursor = { 0,0,'+' };
	do {
		temp = canvas[cursor.X][cursor.Y].symbol;
		canvas[cursor.X][cursor.Y].symbol = '+';
		print_board(canvas);
		canvas[cursor.X][cursor.Y].symbol = temp;
		*arrow = get_arrow_input();
		if (*arrow == 1) {
			cursor.X--;
		}
		else if (*arrow == 2) {
			cursor.X++;
		}
		else if (*arrow == 3) {
			cursor.Y++;
		}
		else if (*arrow == 4) {
			cursor.Y--;
		}
		else if (*arrow == 6)
		{
			*currentMarker = setMarker();
		}
		else if (*arrow == 7)
		{
			FILE* inputStream = fopen("canvasData.csv", "r");
			parseFile(inputStream, canvas);
			fclose(inputStream);
		}
		else if (*arrow == 8)
		{
			FILE* outputStream = fopen("canvasData.csv", "w");
			printToFile(outputStream, canvas);
			fclose(outputStream);
		}
		system("cls");
		if (cursor.X < 0) {
			cursor.X = 0;
		}
		if (cursor.X > 49) {
			cursor.X = 49;
		}
		if (cursor.Y < 0) {
			cursor.Y = 0;
		}
		if (cursor.Y > 74) {
			cursor.Y = 74;
		}
	} while (*arrow != 0 && *arrow != 5);

	return cursor;
}


void parseFile(FILE* file, Cell board[][75])
{
	char line[50];
	char* token;

	while (fgets(line, sizeof(line), file) != NULL)
	{
		token = strtok(line, ",");
		int x = atoi(token);
		token = strtok(NULL, ",");
		int y = atoi(token);
		token = strtok(NULL, ",");
		char symbol = token[0];
		token = strtok(NULL, ",");
		int color = atoi(token);
		board[x][y].X = x;
		board[x][y].Y = y;
		board[x][y].symbol = symbol;
		board[x][y].color = color;
	}
}

void printToFile(FILE* file, Cell board[][75])
{
	for (int i = 0; i < 50; i++)
	{
		for (int j = 0; j < 75; j++)
		{
			fprintf(file, "%d,%d,%c,%d\n", board[i][j].X, board[i][j].Y, board[i][j].symbol, board[i][j].color);
		}
	}
}

