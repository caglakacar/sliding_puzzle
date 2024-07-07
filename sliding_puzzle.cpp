#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int askForNewGame(void);
void initalizeGameBoard(int a[][5]);
int isGameOver(int a[][5]);
void printBoard(int a[][5]);
int changeBoard(int a[][5], int response);
int askMovement();
int test(int a[][5]);

int main(void)
{
	time_t t=NULL;
	srand(time(&t));
	int gameBoard[5][5];
	int newgame=false;
	initalizeGameBoard(gameBoard);
	printBoard(gameBoard);

	while (!isGameOver(gameBoard) || newgame) {
		
		int response = askMovement();
		changeBoard(gameBoard, response);
		printBoard(gameBoard);
		if (isGameOver(gameBoard)) {
			system("cls");
			printf("Congragulations\n");
			newgame = askForNewGame();
			if (newgame) { printBoard(gameBoard); }
		}
	}


}
int test(int a[][5]) {

	int num = 1;
	int mix = 0;
	for (int i = 0;i < 5;i++) {

		for (int j = 0;j < 5;j++) {
			a[i][j] = num;
			num++;

		}

	}
	a[4][3] = 0;
	a[4][4] = 24;
	return 0;
}
int askForNewGame()
{
	printf("Do you want to play a new game?[0]-No and [1]-Yes ");
	int response;
	scanf("%d", &response);
	return response;
}

void initalizeGameBoard(int a[][5])
{
	int num = 1;
	int mix = 0;
	for (int i = 0;i < 5;i++) {
	
		for (int j = 0;j < 5;j++) {
			a[i][j] = num;
			num++;
		
		}
	
	}
	a[4][4] = 0;

	for (int i = 0;i < 50;i++) {
		int x = rand() % 5;
		int y = rand() % 5;
		int z = rand() % 5;
		int t = rand() % 5;

		mix = a[x][y];
		a[x][y] = a[z][t];
		a[z][t] = mix;

	}
	


}

int isGameOver(int a[][5])
{
	int i;
	int j;
	int check = 1;
	int x = true;
	for (i = 0; i < 5;i++)
	{
		for ( j = 0;j < 5;j++)
		{
			if (a[i][j] != check && (i!=4 || j!=4)) { x = false; break; }
			
			check++;
		}
	
	}

	return x;
}

void printBoard(int a[][5])
{
	

	for (int i = 0; i < 5;i++)
	{
		for (int j = 0;j < 5;j++)
		{
			if (a[i][j] == 0) { printf("XX "); }
			else { printf("%d ",a[i][j]); }
		}
		printf("\n");
	}

}

int changeBoard(int a[][5],int response)
{
	int x = 0;
	int y = 0;
	int d1=response/10;
	int d2 = response % 10;
	for (int i = 0;i < 5;i++) {

		for (int j = 0;j < 5;j++) {
			if (a[i][j] == 0) {
				x = i;
				y = j;
				break;
			}

		}

	}
	
	
	if (response ==0 ) {
		printf("Selected place is not valid!!\n\n");
	}

	else if ((d1 == x && d2 == (y - 1)) || (d1 == x && d2 == (y + 1)) || (d1 == (x + 1) && d2 == y) || (d1 == (x - 1) && d2 == y))
	{
		a[x][y] = a[d1][d2];
		a[d1][d2] = 0;
		
	}
	else {
		printf("Selected place is not acceptable!\n\n");
	
	}
	return 0;
}



int askMovement()
{
	printf("Please enter a  movement ");

	int response;

	scanf("%d", &response);

	if (response >= 60 || response % 10 >= 6 || response <=10 || response%10<1) {
		response = 0;
	}
	else { response -= 11; } // for set interval to 0-4
	return response;
}


