/*
UVa problem # 10855 - Rotated Square
URL: https://uva.onlinejudge.org/external/108/10855.pdf
*/

//#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>

using namespace std;

const int N_LIMITS = 10001;

char bigSquare[N_LIMITS][N_LIMITS];
char smallSquareZero[N_LIMITS][N_LIMITS];
char smallSquareOne[N_LIMITS][N_LIMITS];
char smallSquareTwo[N_LIMITS][N_LIMITS];
char smallSquareThree[N_LIMITS][N_LIMITS];

int resultSet[] = {0, 0, 0, 0};

int N, M;

void printSquare(char square[N_LIMITS][N_LIMITS], int N)
{
	for (int i = 0; i < N; i++)
		cout << square[i] << endl;
}

void makeRotatedSmallSquares()
{
	for (int src_row = 0; src_row < M; src_row++)
	{
		for (int src_col = 0; src_col < M; src_col++)
		{
			smallSquareOne[src_col][M - 1 - src_row] = smallSquareZero[src_row][src_col];
		}
	}

	for (int src_row = 0; src_row < M; src_row++)
	{
		for (int src_col = 0; src_col < M; src_col++)
		{
			smallSquareTwo[src_col][M - 1 - src_row] = smallSquareOne[src_row][src_col];
		}
	}

	for (int src_row = 0; src_row < M; src_row++)
	{
		for (int src_col = 0; src_col < M; src_col++)
		{
			smallSquareThree[src_col][M - 1 - src_row] = smallSquareTwo[src_row][src_col];
		}
	}
}

int searchForMatch(int x, int y, char smallSquare[N_LIMITS][N_LIMITS])
{
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (bigSquare[x + i][y + j] != smallSquare[i][j]) {	return 0; }
		}
	}

	return 1;
}

void countMatch()
{	
	for (int i = 0; i < N - M + 1; i++)
	{
		for (int j = 0; j < N - M + 1; j++)
		{
			resultSet[0] += searchForMatch(i, j, smallSquareZero);	// 0
			resultSet[1] += searchForMatch(i, j, smallSquareOne);	// 90
			resultSet[2] += searchForMatch(i, j, smallSquareTwo);	// 180
			resultSet[3] += searchForMatch(i, j, smallSquareThree);	// 270
		}
	}
}

void reset()
{
	for (int i = 0; i < 4; i++)
		resultSet[i] = 0;
}

int main()
{
	while (scanf("%d%d\n", &N, &M) && N && M)
	{
		reset(); // Reset previous result

		for (int i = 0; i < N; i++)
		{
			cin.getline(bigSquare[i], N_LIMITS - 1);
		}

		for (int i = 0; i < M; i++)
		{
			cin.getline(smallSquareZero[i], N_LIMITS - 1);
		}

		makeRotatedSmallSquares(); //
		countMatch(); //
		printf("%d %d %d %d\n", resultSet[0], resultSet[1], resultSet[2], resultSet[3]);		
	}

	return 0;
}