#include <stdio.h>

#define XSIZE 4
#define YSIZE 6
#define WINCON 3
#define PlayerCount 2

//TODO
//Character Selector
//Before the game starts. Each player chooses its symbol

int GetIndex(int x, int y)
{
	return XSIZE * (y)+(x);
}

void print_progress(char* arrptr)
{
	printf("\n");

	printf(" ");
	for (int i = 0; i < XSIZE; i++)
	{
		printf("   %d", i + 1);
	}
	printf("\n");

	for (int i = 0; i < YSIZE * 2 + 1; i++)
	{
		if (i % 2 == 0)
		{
			printf("  ");
			for (int j = 0; j < XSIZE; j++)
			{
				printf("|---");
			}
		}
		else
		{
			printf("%c ", 'A' + i / 2);
			for (int j = 0; j < XSIZE; j++)
			{
				printf("| %c ", *(arrptr + GetIndex((i / 2) , j)));
				//printf("| %d ",(((i / 2) * XSIZE) + j));
			}
		}
		printf("|\n");
	}

	printf("\n");
}

int check_win(char* arrptr, char symbol)
{
	//check horizental generic
	int hor_sym_cnt = 0;
	for (int i = 0; i < YSIZE; i++)
	{
		hor_sym_cnt = 0;
		for (int j = 0; j < XSIZE; j++)
		{
			if (*(arrptr + XSIZE * i + j) == symbol)
				hor_sym_cnt++;
			else
				hor_sym_cnt = 0;
			if (hor_sym_cnt == WINCON)
				return 1;
		}
	}

	//check vertical generic
	int ver_sym_cnt = 0;
	for (int i = 0; i < XSIZE; i++)
	{
		ver_sym_cnt = 0;
		for (int j = 0; j < YSIZE; j++)
		{
			if (*(arrptr + XSIZE * j + i) == symbol)
				ver_sym_cnt++;
			else
				ver_sym_cnt = 0;
			if (ver_sym_cnt == WINCON)
				return 1;
		}
	}

	//check diagonal generic
	for (int i = 0; i < YSIZE - 2; i++)
	{
		for (int j = 0; j < XSIZE - 2; j++)
		{
			if ((*(arrptr + XSIZE * (i + 1) + (j + 1)) == symbol) && (*(arrptr + XSIZE * (i + 2) + (j + 2)) == symbol))
				return 1;
		}
	}
	for (int i = 0; i < YSIZE - 2; i++)
	{
		for (int j = 2; j < XSIZE; j++)
		{
			if ((*(arrptr + XSIZE * (i + 1) + (j - 1)) == symbol) && (*(arrptr + GetIndex((j - 2), (i + 2))) == symbol))
				return 1;
		}
	}

	return 0;
}

void FillArray(char* arrptr)
{
	for (int i = 0; i < YSIZE; i++)
	{
		for (int j = 0; j < XSIZE; j++)
		{
			*(arrptr + i * XSIZE + j) = ' ';
		}
	}
}

/*
* It must take at least one player input.
* The win condition logic should be complete and correct.
* You must use 2d array for the tic-tac-teo board.
*/
int main()
{
	//Initialize
	char arr[YSIZE][XSIZE] = {0};
	int result = 0;
	int is_end = 0;
	char row = ' ';
	int int_row = 0;
	int col = 0;
	int cnt = 0;

	char* p = &arr[0][0];

	FillArray(p);

	//symbol selector

	//Game start
	while (!is_end)
	{
		//Print game progress
		print_progress(p);

		//Get user input
		if (cnt % 2 == 0)
		{
			printf("Player 1\n");
			printf("Enter the position(1 A): ");
		}
		else
		{
			printf("Player 2\n");
			printf("Enter the position(1 A): ");
		}

		scanf_s("%d %c", &col, &row);
		col -= 1;
		int_row = row - 'A';

		if (arr[int_row][col] != ' ')
		{
			printf("You entered same position. Select another position.\n");
			continue;
		}

		//Fill position with unique symbol
		if (cnt % 2 == 0)
		{
			arr[int_row][col] = 'O';
			result = check_win(p, arr[int_row][col]);
			if (result)
			{
				print_progress(p);
				printf("Player 1 Win!\n");
				is_end = 1;
			}
		}
		else
		{
			arr[int_row][col] = 'X';
			result = check_win(p, arr[int_row][col]);
			if (result)
			{
				print_progress(p);
				printf("Player 2 Win!\n");
				is_end = 1;
			}
		}
		cnt++;
	}
}