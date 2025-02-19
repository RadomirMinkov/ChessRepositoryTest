#include <iostream>
#include "Board.h"
#include "Gameplay.h"
#include <string>
#include <cmath>
#include <Windows.h>
#include <fstream>

int main() {
	HWND console = GetConsoleWindow();
	RECT rectangle;
	const int WIDTH = 800;
	const int HEIGHT = 700;
	GetWindowRect(console, &rectangle);
	MoveWindow(console, rectangle.left, rectangle.top, WIDTH, HEIGHT, TRUE);
	Gameplay game;
	game.PlayGame();
}