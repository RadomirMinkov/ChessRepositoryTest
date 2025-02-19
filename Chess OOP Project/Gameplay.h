#pragma once
#include "Board.h"
#include "Pawn.h"
#include "Rook.h"
#include "Knight.h"
#include "Bishop.h"
#include "Queen.h"
#include "King.h"

class Gameplay {
public:
	Board board[8][8];
	char gameField[28][65];
	bool isKingDead = false;
	Gameplay();
	~Gameplay();
	void PlayGame();
	bool isMoveCommandValid(String move);
	bool canMove(String move, Board board[8][8], int currentPlayer);
	void FillBoard();
	void PaintBoard();
	void PrintBorders();
	void PrintNumbering();
	void FigureSpaceCleaning();
	void PlacePieces(Board board[8][8]);
	void PrintBoard(Board board[8][8]);
	int determineCol(int j, int C1, int C2, int C3, int C4, int C5, int C6, int C7, int C8);
	int determineRow(int i, int R1, int R2, int R3, int R4, int R5, int R6, int R7, int R8);
	void printAsciiBoard();
	void placePieceCharacter(Board board[8][8], int i, int j, int row, int col);\
	void placePieceCharacterWhite(Board board[8][8], int i, int j, int row, int col);
	void placePieceCharacterBlack(Board board[8][8], int i, int j, int row, int col);
	void playerMoveLoop(int& currPlayer);
	void showHelp(int& currPlayer);
	void createAllPieces();
	void createWhitePawns();
	void createWhiteMajors();
	void createBlackPawns();
	void createBlackMajors();
	bool handlePawnPlayer1(Board board[8][8],int fromNumber,int fromLetter,int toNumber,int toLetter,int rowDifference,int columnDifference);
	bool parseFromLetter(String move, int& fromLetter);
	bool parseToLetter(String move, int& toLetter);
	bool parseFromNumber(String move, int& fromNumber);
	bool parseToNumber(String move, int& toNumber);
	bool checkStartSquare(Board board[8][8],int fromNumber,int fromLetter);
	bool checkDestination(Board board[8][8],int toNumber,int toLetter,int currentPlayer);
	bool checkOwnership(Board board[8][8],int fromNumber,int fromLetter,int currentPlayer);
	bool checkBishopPath(Board board[8][8],int fromNumber,int fromLetter,int toNumber,int toLetter,int rowDifference,int columnDifference);
	bool handleBishop(Board board[8][8],int fromNumber,int fromLetter,int toNumber,int toLetter,int rowDifference,int columnDifference,int currentPlayer);
	bool handleKnight(Board board[8][8],int fromNumber,int fromLetter, int toNumber,int toLetter,int rowDifference, int columnDifference,int currentPlayer);
	bool handleRook(Board board[8][8],int fromNumber,int fromLetter,int toNumber,int toLetter,int rowDifference,int columnDifference,int currentPlayer);
	bool checkQueenPath(Board board[8][8],int fromNumber,int fromLetter,int toNumber, int toLetter,int rowDifference,int columnDifference);
	bool handleQueen(Board board[8][8],int fromNumber,int fromLetter,int toNumber,int toLetter,int rowDifference,int columnDifference,int currentPlayer);
	bool handlePawn(Board board[8][8],int fromNumber, int fromLetter,int toNumber,int toLetter,int rowDifference,int columnDifference,int currentPlayer);
	bool handleKing(Board board[8][8],int fromNumber,int fromLetter, int toNumber,int toLetter,int rowDifference,int columnDifference,int currentPlayer);
	bool handlePawnPlayer2(Board board[8][8],int fromNumber,int fromLetter, int toNumber,int toLetter,int rowDifference, int columnDifference);
	bool checkRookPath(Board board[8][8],int fromNumber,int fromLetter, int toNumber, int toLetter,int rowDifference, int columnDifference);
	bool dispatchPieceMove(Board board[8][8],int fromNumber,int fromLetter,int toNumber,int toLetter,int rowDifference,int columnDifference,int currentPlayer);
	//void undo(String move, Board board[8][8]);

};


