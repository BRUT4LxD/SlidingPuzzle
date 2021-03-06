// SlidingPuzzle.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <conio.h>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>

using namespace std;

void move();
void draw();
void replacePosition(int deltaX, int deltaY);
bool checkWin();
void getRandomBoard();

bool GAME_OVER = false;
int board[4][4] = { {1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16} };
int x = 3;
int y = 3;
int main()
{
	getRandomBoard();
	while (!checkWin()) {
		draw();
		move();
	}

	cout << "\n\n\n \t\t\t\t****GAME OVER****";
}

void draw() {
	system("cls");
	cout << "\n\n\n";
	for (int i = 0; i < 4; i++)
	{

		cout << "\t\t\t\t";
		for (int j = 0; j < 4; j++) {
			if (board[i][j] == 16)
				cout << "[ ]" << "\t";
			else
				cout << board[i][j] << "\t";
		}
		cout << endl;
	}
}

void move() {
	char currentMove = _getch();
	switch ((int)currentMove)
	{
			// up
		case 119:
			replacePosition(0, -1);
			return;

			// right
		case 100:
			replacePosition(1, 0);
			return;

			// down
		case 115:
			replacePosition(0, 1);
			return;

			// left
		case 97:
			replacePosition(-1, 0);
			return;

			//randomize board
		case 114:
			getRandomBoard();
			return;

	}
}
void replacePosition(int deltaX, int deltaY) {

	int prevx = x;
	int prevy = y;

	if (x + deltaX != 4 && x + deltaX != -1) x = x + deltaX;
	if (y + deltaY != 4 && y + deltaY != -1) y = y + deltaY;

	swap(board[prevy][prevx], board[y][x]);
}

bool checkWin() {
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++) 
			if (board[i][j] != i * 4 + j + 1) 
				return false;
	return true;
}
void getRandomBoard() {
	vector<int> numbers = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15 };

	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();

	shuffle(numbers.begin(), numbers.end(), std::default_random_engine(seed));
	numbers.push_back(16);
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			board[i][j] = numbers.back();
			numbers.pop_back();
		}
	}
	swap(board[0][0], board[3][3]);
	x = 3;
	y = 3;
}

