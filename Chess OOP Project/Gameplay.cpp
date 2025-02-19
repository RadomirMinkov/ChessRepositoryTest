#include "Gameplay.h"
#include <iostream>

Gameplay::Gameplay()
{
}

Gameplay::~Gameplay()
{
}



bool Gameplay::parseFromLetter(String move, int& fromLetter)
{
    if (move[5] == 'a')
    {
        fromLetter = 0;
    }
    else if (move[5] == 'b')
    {
        fromLetter = 1;
    }
    else if (move[5] == 'c')
    {
        fromLetter = 2;
    }
    else if (move[5] == 'd')
    {
        fromLetter = 3;
    }
    else if (move[5] == 'e')
    {
        fromLetter = 4;
    }
    else if (move[5] == 'f')
    {
        fromLetter = 5;
    }
    else if (move[5] == 'g')
    {
        fromLetter = 6;
    }
    else
    {
        fromLetter = 7;
    }
    return true;
}

bool Gameplay::parseToLetter(String move, int& toLetter)
{
    if (move[8] == 'a')
    {
        toLetter = 0;
    }
    else if (move[8] == 'b')
    {
        toLetter = 1;
    }
    else if (move[8] == 'c')
    {
        toLetter = 2;
    }
    else if (move[8] == 'd')
    {
        toLetter = 3;
    }
    else if (move[8] == 'e')
    {
        toLetter = 4;
    }
    else if (move[8] == 'f')
    {
        toLetter = 5;
    }
    else if (move[8] == 'g')
    {
        toLetter = 6;
    }
    else
    {
        toLetter = 7;
    }
    return true;
}

bool Gameplay::parseFromNumber(String move, int& fromNumber)
{
    if (move[6] == '1')
    {
        fromNumber = 0;
    }
    else if (move[6] == '2')
    {
        fromNumber = 1;
    }
    else if (move[6] == '3')
    {
        fromNumber = 2;
    }
    else if (move[6] == '4')
    {
        fromNumber = 3;
    }
    else if (move[6] == '5')
    {
        fromNumber = 4;
    }
    else if (move[6] == '6')
    {
        fromNumber = 5;
    }
    else if (move[6] == '7')
    {
        fromNumber = 6;
    }
    else
    {
        fromNumber = 7;
    }
    return true;
}

bool Gameplay::parseToNumber(String move, int& toNumber)
{
    if (move[9] == '1')
    {
        toNumber = 0;
    }
    else if (move[9] == '2')
    {
        toNumber = 1;
    }
    else if (move[9] == '3')
    {
        toNumber = 2;
    }
    else if (move[9] == '4')
    {
        toNumber = 3;
    }
    else if (move[9] == '5')
    {
        toNumber = 4;
    }
    else if (move[9] == '6')
    {
        toNumber = 5;
    }
    else if (move[9] == '7')
    {
        toNumber = 6;
    }
    else
    {
        toNumber = 7;
    }
    return true;
}

bool Gameplay::checkStartSquare(Board board[8][8],int fromNumber,int fromLetter)
{
    if (board[fromNumber][fromLetter].piece == nullptr)
    {
        std::cout << "There's no piece at that location." << std::endl << std::endl;
        return false;
    }
    return true;
}

bool Gameplay::checkOwnership(Board board[8][8],int fromNumber,int fromLetter,int currentPlayer)
{
    if (board[fromNumber][fromLetter].piece != nullptr
        && board[fromNumber][fromLetter].piece->getPlayer() != currentPlayer)
    {
        std::cout << "That's not your piece!" << std::endl << std::endl;
        return false;
    }
    return true;
}

bool Gameplay::checkDestination(Board board[8][8],int toNumber,int toLetter,int currentPlayer)
{
    if (board[toNumber][toLetter].piece != nullptr
        && board[toNumber][toLetter].piece->getPlayer() == currentPlayer)
    {
        std::cout << "You already have a piece there." << std::endl;
        return false;
    }
    return true;
}

bool Gameplay::handlePawnPlayer2(Board board[8][8],int fromNumber,int fromLetter, int toNumber,int toLetter,int rowDifference, int columnDifference)
{
    if (fromNumber != 1 && rowDifference <= -2)
    {
        std::cout << "Pawns can move 2 squares forward only in their first move" << std::endl;
        return false;
    }
    else if (fromNumber == 1 && rowDifference < -2)
    {
        std::cout << "Pawns can't move more than 2 squares forward their first move." << std::endl;
        return false;
    }
    else if (rowDifference >= 0)
    {
        std::cout << "Pawns can only move forward" << std::endl;
        return false;
    }
    else if (abs(columnDifference) > 1)
    {
        std::cout << "Pawns can't move more than one column forward" << std::endl;
        return false;
    }
    else if (abs(columnDifference) == 1
             && rowDifference == -1
             && board[toNumber][toLetter].piece == nullptr)
    {
        std::cout << "There must be an enemy piece on that position for you to move there." << std::endl;
        return false;
    }
    else if (rowDifference == -1
             && columnDifference == 0
             && board[toNumber][toLetter].piece != nullptr
             && board[toNumber][toLetter].piece->getPlayer() == 1)
    {
        std::cout << "An enemy piece is blocking your move!" << std::endl;
        return false;
    }
    else if (rowDifference == -1
             && abs(columnDifference) == 1
             && board[toNumber][toLetter].piece
             && board[toNumber][toLetter].piece->getPlayer() == 1)
    {
        std::cout << "You have taken the enemy's "
                  << board[toNumber][toLetter].piece->getName() << "!" << std::endl;
        if (board[toNumber][toLetter].piece->getName() == "King")
        {
            isKingDead = true;
        }
        board[toNumber][toLetter].piece = board[fromNumber][fromLetter].piece;
        board[fromNumber][fromLetter].piece = nullptr;
        return true;
    }
    else
    {
        std::cout << "Move successful!" << std::endl;
        board[toNumber][toLetter].piece = board[fromNumber][fromLetter].piece;
        board[fromNumber][fromLetter].piece = nullptr;
        return true;
    }
}

bool Gameplay::handlePawnPlayer1(Board board[8][8],int fromNumber,int fromLetter,int toNumber,int toLetter,int rowDifference,int columnDifference)
{
    if (fromNumber != 6 && rowDifference >= 2)
    {
        std::cout << "Pawns can move 2 squares forward only in their first move" << std::endl;
        return false;
    }
    else if (fromNumber == 6 && rowDifference > 2)
    {
        std::cout << "Pawns can't move more than 2 squares forward their first move." << std::endl;
        return false;
    }
    else if (rowDifference <= 0)
    {
        std::cout << "Pawns can only move forward" << std::endl;
        return false;
    }
    else if (abs(columnDifference) > 1)
    {
        std::cout << "Pawns can't move more than one column forward" << std::endl;
        return false;
    }
    else if (abs(columnDifference) == 1
             && rowDifference == 1
             && board[toNumber][toLetter].piece == nullptr)
    {
        std::cout << "There must be an enemy piece on that position for you to move there." << std::endl;
        return false;
    }
    else if (rowDifference == 1
             && columnDifference == 0
             && board[toNumber][toLetter].piece
             && board[toNumber][toLetter].piece->getPlayer() == 2)
    {
        std::cout << "An enemy piece is blocking your move!" << std::endl;
        return false;
    }
    else if (rowDifference == 1
             && abs(columnDifference) == 1
             && board[toNumber][toLetter].piece
             && board[toNumber][toLetter].piece->getPlayer() == 2)
    {
        std::cout << "You have taken the enemy's "
                  << board[toNumber][toLetter].piece->getName() << "!" << std::endl;
        if (board[toNumber][toLetter].piece->getName() == "King")
        {
            isKingDead = true;
        }
        board[toNumber][toLetter].piece = board[fromNumber][fromLetter].piece;
        board[fromNumber][fromLetter].piece = nullptr;
        return true;
    }
    else
    {
        std::cout << "Move successful!" << std::endl;
        board[toNumber][toLetter].piece = board[fromNumber][fromLetter].piece;
        board[fromNumber][fromLetter].piece = nullptr;
        return true;
    }
}

bool Gameplay::handlePawn(Board board[8][8],int fromNumber, int fromLetter,int toNumber,int toLetter,int rowDifference,int columnDifference,int currentPlayer)
{
    if (currentPlayer == 2)
    {
        return handlePawnPlayer2(board,fromNumber,fromLetter,toNumber,toLetter, rowDifference,columnDifference);
    }
    else
    {
        return handlePawnPlayer1(board,fromNumber,fromLetter,toNumber,toLetter,rowDifference,columnDifference);
    }
}

bool Gameplay::handleKing(Board board[8][8],int fromNumber,int fromLetter, int toNumber,int toLetter,int rowDifference,int columnDifference,int currentPlayer)
{
    if (abs(rowDifference) > 1 || abs(columnDifference) > 1)
    {
        std::cout << "Kings may only move one square" << std::endl;
        return false;
    }
    if (board[toNumber][toLetter].piece
        && board[toNumber][toLetter].piece->getPlayer() != currentPlayer)
    {
        std::cout << "You have taken the enemy's "
                  << board[toNumber][toLetter].piece->getName() << "!" << std::endl;
        if (board[toNumber][toLetter].piece->getName() == "King")
        {
            isKingDead = true;
        }
        board[toNumber][toLetter].piece = board[fromNumber][fromLetter].piece;
        board[fromNumber][fromLetter].piece = nullptr;
        return true;
    }
    else
    {
        std::cout << "Move successful!" << std::endl;
        board[toNumber][toLetter].piece = board[fromNumber][fromLetter].piece;
        board[fromNumber][fromLetter].piece = nullptr;
        return true;
    }
}

bool Gameplay::handleQueen(Board board[8][8],int fromNumber,int fromLetter,int toNumber,int toLetter,int rowDifference,int columnDifference,int currentPlayer)
{
    if (abs(rowDifference) != abs(columnDifference)
        && rowDifference != 0
        && columnDifference != 0)
    {
        std::cout << "Queens can move like rooks and bishops only" << std::endl;
        return false;
    }
    if (!checkQueenPath(board,fromNumber,fromLetter,toNumber, toLetter,rowDifference,columnDifference))
    {
        return false;
    }
    if (board[toNumber][toLetter].piece
        && board[toNumber][toLetter].piece->getPlayer() != currentPlayer)
    {
        std::cout << "You have taken the enemy's "
                  << board[toNumber][toLetter].piece->getName() << "!" << std::endl;
        if (board[toNumber][toLetter].piece->getName() == "King")
        {
            isKingDead = true;
        }
        board[toNumber][toLetter].piece = board[fromNumber][fromLetter].piece;
        board[fromNumber][fromLetter].piece = nullptr;
        return true;
    }
    else
    {
        std::cout << "Move successful!" << std::endl;
        board[toNumber][toLetter].piece = board[fromNumber][fromLetter].piece;
        board[fromNumber][fromLetter].piece = nullptr;
        return true;
    }
}

bool Gameplay::checkQueenPath(Board board[8][8],int fromNumber,int fromLetter,int toNumber, int toLetter,int rowDifference,int columnDifference)
{
    // The same checks that were originally in the Queen code
    if (rowDifference > 0 && columnDifference > 0)
    {
        for (int i = fromNumber - 1; i > toNumber; i--)
        {
            int a = fromLetter;
            for (a; a > toLetter; a--)
            {
                a--;
                if (board[i][a].piece != nullptr)
                {
                    std::cout << "There's a piece blocking your move!" << std::endl;
                    return false;
                }
                break;
            }
        }
    }
    else if (rowDifference < 0 && columnDifference < 0)
    {
        int a = fromLetter;
        for (int i = fromNumber + 1; i < toNumber; i++)
        {
            for (a; a < toLetter; a++)
            {
                a++;
                if (board[i][a].piece != nullptr)
                {
                    std::cout << "There's a piece blocking your move!" << std::endl;
                    return false;
                }
                break;
            }
        }
    }
    else if (rowDifference > 0 && columnDifference < 0)
    {
        int a = fromLetter;
        for (int i = fromNumber - 1; i > toNumber; i--)
        {
            a++;
            for (a; a < toLetter; a++)
            {
                if (board[i][a].piece != nullptr)
                {
                    std::cout << "There's a piece blocking your move!" << std::endl;
                    return false;
                }
                break;
            }
        }
    }
    else if (rowDifference < 0 && columnDifference > 0)
    {
        int a = fromNumber;
        for (int i = fromNumber + 1; i < toNumber; i++)
        {
            for (a; a > toLetter; a--)
            {
                a--;
                if (board[i][a].piece != nullptr)
                {
                    std::cout << "There's a piece blocking your move!" << std::endl;
                    return false;
                }
            }
        }
    }
    else if (rowDifference == 0 && columnDifference > 0)
    {
        for (int i = fromLetter - 1; i >= toLetter; i--)
        {
            if (board[fromNumber][i].piece != nullptr)
            {
                std::cout << "There's a piece blocking your move!" << std::endl;
                return false;
            }
        }
    }
    else if (rowDifference == 0 && columnDifference < 0)
    {
        for (int i = fromLetter + 1; i < toLetter; i++)
        {
            if (board[fromNumber][i].piece != nullptr)
            {
                std::cout << "There's a piece blocking your move!" << std::endl;
                return false;
            }
        }
    }
    else if (rowDifference > 0 && columnDifference == 0)
    {
        for (int i = fromNumber - 1; i > toNumber; i--)
        {
            if (board[i][fromLetter].piece != nullptr)
            {
                std::cout << "There's a piece blocking your move!" << std::endl;
                return false;
            }
        }
    }
    else if (rowDifference < 0 && columnDifference == 0)
    {
        for (int i = fromNumber + 1; i < toNumber; i++)
        {
            if (board[i][fromLetter].piece != nullptr)
            {
                std::cout << "There's a piece blocking your move!" << std::endl;
                return false;
            }
        }
    }
    return true;
}

bool Gameplay::handleKnight(Board board[8][8],int fromNumber,int fromLetter, int toNumber,int toLetter,int rowDifference, int columnDifference,int currentPlayer)
{
    if (abs(rowDifference) * abs(columnDifference) != 2)
    {
        std::cout << "Knights can move only L-shape" << std::endl;
        return false;
    }
    if (board[toNumber][toLetter].piece
        && board[toNumber][toLetter].piece->getPlayer() != currentPlayer)
    {
        std::cout << "You have taken the enemy's "
                  << board[toNumber][toLetter].piece->getName() << "!" << std::endl;
        if (board[toNumber][toLetter].piece->getName() == "King")
        {
            isKingDead = true;
        }
        board[toNumber][toLetter].piece = board[fromNumber][fromLetter].piece;
        board[fromNumber][fromLetter].piece = nullptr;
        return true;
    }
    else
    {
        std::cout << "Move successful!" << std::endl;
        board[toNumber][toLetter].piece = board[fromNumber][fromLetter].piece;
        board[fromNumber][fromLetter].piece = nullptr;
        return true;
    }
}

bool Gameplay::handleBishop(Board board[8][8],int fromNumber,int fromLetter,int toNumber,int toLetter,int rowDifference,int columnDifference,int currentPlayer)
{
    if (abs(rowDifference) != abs(columnDifference))
    {
        std::cout << "Bishops can move only diagonally" << std::endl;
        return false;
    }
    if (!checkBishopPath(board, fromNumber,fromLetter, toNumber,toLetter,rowDifference,columnDifference))
    {
        return false;
    }
    if (board[toNumber][toLetter].piece
        && board[toNumber][toLetter].piece->getPlayer() != currentPlayer)
    {
        std::cout << "You have taken the enemy's "
                  << board[toNumber][toLetter].piece->getName() << "!" << std::endl;
        if (board[toNumber][toLetter].piece->getName() == "King")
        {
            isKingDead = true;
        }
        board[toNumber][toLetter].piece = board[fromNumber][fromLetter].piece;
        board[fromNumber][fromLetter].piece = nullptr;
        return true;
    }
    else
    {
        std::cout << "Move successful!" << std::endl;
        board[toNumber][toLetter].piece = board[fromNumber][fromLetter].piece;
        board[fromNumber][fromLetter].piece = nullptr;
        return true;
    }
}

bool Gameplay::checkBishopPath(Board board[8][8],int fromNumber,int fromLetter,int toNumber,int toLetter,int rowDifference,int columnDifference)
{
    if (rowDifference > 0 && columnDifference > 0)
    {
        int a = fromLetter;
        for (int i = fromNumber - 1; i > toNumber; i--)
        {
            for (a; a > toLetter; a--)
            {
                a--;
                if (board[i][a].piece != nullptr)
                {
                    std::cout << "There's a piece blocking your move!" << std::endl;
                    return false;
                }
                break;
            }
        }
    }
    else if (rowDifference < 0 && columnDifference < 0)
    {
        int a = fromLetter;
        for (int i = fromNumber + 1; i < toNumber; i++)
        {
            for (a; a < toLetter; a++)
            {
                a++;
                if (board[i][a].piece != nullptr)
                {
                    std::cout << "There's a piece blocking your move!" << std::endl;
                    return false;
                }
                break;
            }
        }
    }
    else if (rowDifference > 0 && columnDifference < 0)
    {
        int a = fromLetter;
        for (int i = fromNumber - 1; i > toNumber; i--)
        {
            a++;
            for (a; a < toLetter; a++)
            {
                if (board[i][a].piece != nullptr)
                {
                    std::cout << "There's a piece blocking your move!" << std::endl;
                    return false;
                }
                break;
            }
        }
    }
    else if (rowDifference < 0 && columnDifference > 0)
    {
        int a = fromLetter;
        for (int i = fromNumber + 1; i < toNumber; i++)
        {
            for (a; a > toLetter; a--)
            {
                a--;
                if (board[i][a].piece != nullptr)
                {
                    std::cout << "There's a piece blocking your move!" << std::endl;
                    return false;
                }
                break;
            }
        }
    }
    return true;
}

bool Gameplay::handleRook(Board board[8][8],int fromNumber,int fromLetter,int toNumber,int toLetter,int rowDifference,int columnDifference,int currentPlayer)
{
    if (rowDifference != 0 && columnDifference != 0)
    {
        std::cout << "Rooks can move only horizontal or vertical" << std::endl;
        return false;
    }
    if (!checkRookPath(board,fromNumber,fromLetter,toNumber,toLetter,rowDifference,columnDifference))
    {
        return false;
    }
    if (board[toNumber][toLetter].piece
        && board[toNumber][toLetter].piece->getPlayer() != currentPlayer)
    {
        std::cout << "You have taken the enemy's "
                  << board[toNumber][toLetter].piece->getName() << "!" << std::endl;
        if (board[toNumber][toLetter].piece->getName() == "King")
        {
            isKingDead = true;
        }
        board[toNumber][toLetter].piece = board[fromNumber][fromLetter].piece;
        board[fromNumber][fromLetter].piece = nullptr;
        return true;
    }
    else
    {
        std::cout << "Move successful!" << std::endl;
        board[toNumber][toLetter].piece = board[fromNumber][fromLetter].piece;
        board[fromNumber][fromLetter].piece = nullptr;
        return true;
    }
}

bool Gameplay::checkRookPath(Board board[8][8],int fromNumber,int fromLetter, int toNumber, int toLetter,int rowDifference, int columnDifference)
{
    if (rowDifference == 0 && columnDifference > 0)
    {
        for (int i = fromLetter - 1; i > toLetter; i--)
        {
            if (board[fromNumber][i].piece != nullptr)
            {
                std::cout << "There's a piece blocking your move!" << std::endl;
                return false;
            }
        }
    }
    else if (rowDifference == 0 && columnDifference < 0)
    {
        for (int i = fromLetter + 1; i < toLetter; i++)
        {
            if (board[fromNumber][i].piece != nullptr)
            {
                std::cout << "There's a piece blocking your move!" << std::endl;
                return false;
            }
        }
    }
    else if (rowDifference > 0 && columnDifference == 0)
    {
        for (int i = fromNumber - 1; i > toNumber; i--)
        {
            if (board[i][fromLetter].piece != nullptr)
            {
                std::cout << "There's a piece blocking your move!" << std::endl;
                return false;
            }
        }
    }
    else if (rowDifference < 0 && columnDifference == 0)
    {
        for (int i = fromNumber + 1; i < toNumber; i++)
        {
            if (board[i][fromLetter].piece != nullptr)
            {
                std::cout << "There's a piece blocking your move!" << std::endl;
                return false;
            }
        }
    }
    return true;
}

bool Gameplay::dispatchPieceMove(Board board[8][8],int fromNumber,int fromLetter,int toNumber,int toLetter,int rowDifference,int columnDifference,int currentPlayer)
{
    String pieceName = board[fromNumber][fromLetter].piece->getName();

    if (pieceName == "Pawn")
    {
        return handlePawn(board,fromNumber, fromLetter,toNumber,toLetter,rowDifference,columnDifference,currentPlayer);
    }
    else if (pieceName == "King")
    {
        return handleKing(board,fromNumber, fromLetter,toNumber,toLetter,rowDifference,columnDifference,currentPlayer);
    }
    else if (pieceName == "Queen")
    {
        return handleQueen(board,fromNumber,fromLetter,toNumber, toLetter,rowDifference, columnDifference,currentPlayer);
    }
    else if (pieceName == "Knight")
    {
        return handleKnight(board,fromNumber,fromLetter,toNumber, toLetter,rowDifference,columnDifference,currentPlayer);
    }
    else if (pieceName == "Bishop")
    {
        return handleBishop(board, fromNumber, fromLetter, toNumber,toLetter,rowDifference,columnDifference,currentPlayer);
    }
    else if (pieceName == "Rook")
    {
        return handleRook(board,fromNumber,fromLetter,toNumber,toLetter,rowDifference,columnDifference, currentPlayer);
    }
    return false;
}

bool Gameplay::canMove(String move,Board board[8][8], int currentPlayer)
{
    int fromLetter;
    int fromNumber;
    int toLetter;
    int toNumber;

    parseFromLetter(move, fromLetter);
    parseToLetter(move, toLetter);
    parseFromNumber(move, fromNumber);
    parseToNumber(move, toNumber);

    if (!checkStartSquare(board, fromNumber, fromLetter))
    {
        return false;
    }
    if (!checkOwnership(board, fromNumber, fromLetter, currentPlayer))
    {
        return false;
    }
    if (!checkDestination(board, toNumber, toLetter, currentPlayer))
    {
        return false;
    }

    int rowDifference = fromNumber - toNumber;
    int columnDifference = fromLetter - toLetter;

    return dispatchPieceMove(board, fromNumber,fromLetter,toNumber,toLetter,rowDifference,columnDifference,currentPlayer);
}

/*
void Gameplay::undo(String move,Board board[8][8]) {
	
}
*/

void Gameplay::FillBoard()
{ 
	for (int i = 0; i < 28; i++){
		for (int j = 0; j < 65; j++){
			gameField[i][j] = ' ';
		}
	}
}
void Gameplay::PaintBoard()
{
	for (int i = 3; i < 27; i++){
		for (int j = 7; j < 63; j++){
			if ((((i > 2 && i < 6) || (i > 8 && i < 12) || (i > 14 && i < 18) || (i > 20 && i < 24))
				&& ((j > 6 && j < 14) || (j > 20 && j < 28) || (j > 34 && j < 42) || (j > 48 && j < 56))) ||
				(((i > 5 && i < 9) || (i > 11 && i < 15) || (i > 17 && i < 21) || (i > 23 && i < 27))
					&& ((j > 13 && j < 21) || (j > 27 && j < 35) || (j > 41 && j < 49) || (j > 55 && j < 63))))
				gameField[i][j] = 219;
		}
	}
}
void Gameplay::PrintBorders() {
	for (int i = 3; i < 27; i++){
		gameField[i][5] = 186;
		gameField[i][64] = 186;
	}
	gameField[2][5] = 201;
	gameField[2][64] = 187;
	gameField[27][64] = 188;
	gameField[27][5] = 200;
	for (int j = 6; j < 64; j++){
		gameField[2][j] = 205;
		gameField[27][j] = 205;
	}
}
void Gameplay::PrintNumbering()
{
	int k = 0;

	for (int j = 10; j < 63; j += 7){
		gameField[1][j] = 65 + k;
		k++;

	}
	
	for (int i = 4; i < 27; i += 3){{
			gameField[i][3] = 41 + k;
			k++;
		}
	}
}
void Gameplay::FigureSpaceCleaning()
{
	//freeing space for figures
	for (int i = 4; i < 27; i += 3){
		for (int j = 10; j < 63; j += 7){
			gameField[i][j - 1] = '  ';
			gameField[i][j] = '  ';
			gameField[i][j + 1] = '  ';
		}
	}
}


void Gameplay::placePieceCharacterWhite(Board board[8][8], int Xcoordinate, int Ycoordinate, int row, int col)
{
    if (board[Xcoordinate][Ycoordinate].piece->getName() == "Pawn") {
        gameField[row][col] = 'P';
    }
    else if (board[Xcoordinate][Ycoordinate].piece->getName() == "King") {
        gameField[row][col] = 'K';
    }
    else if (board[Xcoordinate][Ycoordinate].piece->getName() == "Queen") {
        gameField[row][col] = 'Q';
    }
    else if (board[Xcoordinate][Ycoordinate].piece->getName() == "Rook") {
        gameField[row][col] = 'R';
    }
    else if (board[Xcoordinate][Ycoordinate].piece->getName() == "Knight") {
        gameField[row][col] = 'N';
    }
    else if (board[Xcoordinate][Ycoordinate].piece->getName() == "Bishop") {
        gameField[row][col] = 'B';
    }
}

void Gameplay::placePieceCharacterBlack(Board board[8][8], int Xcoordinate, int Ycoordinate, int row, int col)
{
    if (board[Xcoordinate][Ycoordinate].piece->getName() == "Pawn") {
        gameField[row][col] = 'p';
    }
    else if (board[Xcoordinate][Ycoordinate].piece->getName() == "King") {
        gameField[row][col] = 'k';
    }
    else if (board[Xcoordinate][Ycoordinate].piece->getName() == "Queen") {
        gameField[row][col] = 'q';
    }
    else if (board[Xcoordinate][Ycoordinate].piece->getName() == "Rook") {
        gameField[row][col] = 'r';
    }
    else if (board[Xcoordinate][Ycoordinate].piece->getName() == "Knight") {
        gameField[row][col] = 'n';
    }
    else if (board[Xcoordinate][Ycoordinate].piece->getName() == "Bishop") {
        gameField[row][col] = 'b';
    }
}

void Gameplay::placePieceCharacter(Board board[8][8], int Xcoordinate, int Ycoordinate, int row, int col)
{
    if (board[Xcoordinate][Ycoordinate].piece == nullptr) {
        gameField[row][col] = ' ';
    }
    else if (board[Xcoordinate][Ycoordinate].piece->getPlayer() == 1) {
        placePieceCharacterWhite(board, Xcoordinate, Ycoordinate, row, col);
    }
    else if (board[Xcoordinate][Ycoordinate].piece->getPlayer() == 2) {
        placePieceCharacterBlack(board, Xcoordinate, Ycoordinate, row, col);
    }
}

int Gameplay::determineRow(int row, int R1, int R2, int R3, int R4, int R5, int R6, int R7, int R8)
{
    if (row == 0) return R1;
    else if (row == 1) return R2;
    else if (row == 2) return R3;
    else if (row == 3) return R4;
    else if (row == 4) return R5;
    else if (row == 5) return R6;
    else if (row == 6) return R7;
    else return R8;
}

int Gameplay::determineCol(int col, int C1, int C2, int C3, int C4, int C5, int C6, int C7, int C8)
{
    if (col == 0) return C1;
    else if (col == 1) return C2;
    else if (col == 2) return C3;
    else if (col == 3) return C4;
    else if (col == 4) return C5;
    else if (col == 5) return C6;
    else if (col == 6) return C7;
    else return C8;
}

void Gameplay::printAsciiBoard()
{
    for (int i = 0; i < 28; i++) {
        for (int j = 0; j < 65; j++) {
            std::cout << gameField[i][j];
        }
        std::cout << std::endl;
    }
}

void Gameplay::PlacePieces(Board board[8][8])
{
    const int R1 = 4;  const int C1 = 10;
    const int R2 = 7;  const int C2 = 17;
    const int R3 = 10; const int C3 = 24;
    const int R4 = 13; const int C4 = 31;
    const int R5 = 16; const int C5 = 38;
    const int R6 = 19; const int C6 = 45;
    const int R7 = 22; const int C7 = 52;
    const int R8 = 25; const int C8 = 59;

    int row, col;

    for (int i = 0; i < 8; i++) {
        row = determineRow(i, R1, R2, R3, R4, R5, R6, R7, R8);
        for (int j = 0; j < 8; j++) {
            col = determineCol(j, C1, C2, C3, C4, C5, C6, C7, C8);
            placePieceCharacter(board, i, j, row, col);
        }
    }
    printAsciiBoard();
}

void Gameplay::PrintBoard(Board board[8][8])
{
	FillBoard();
	PrintNumbering();
	PaintBoard();
	FigureSpaceCleaning();
	PrintBorders();
	PlacePieces(board);
}

void Gameplay::createWhitePawns()
{
    static Pawn wP1("Pawn", 1);
    static Pawn wP2("Pawn", 1);
    static Pawn wP3("Pawn", 1);
    static Pawn wP4("Pawn", 1);
    static Pawn wP5("Pawn", 1);
    static Pawn wP6("Pawn", 1);
    static Pawn wP7("Pawn", 1);
    static Pawn wP8("Pawn", 1);

    board[6][0].piece = &wP1;
    board[6][1].piece = &wP2;
    board[6][2].piece = &wP3;
    board[6][3].piece = &wP4;
    board[6][4].piece = &wP5;
    board[6][5].piece = &wP6;
    board[6][6].piece = &wP7;
    board[6][7].piece = &wP8;
}

void Gameplay::createWhiteMajors()
{
    static Rook   wR1("Rook",    1);
    static Rook   wR2("Rook",    1);
    static Knight wN1("Knight",  1);
    static Knight wN2("Knight",  1);
    static Bishop wB1("Bishop",  1);
    static Bishop wB2("Bishop",  1);
    static Queen  wQ("Queen",    1);
    static King   wK("King",     1);

    board[7][0].piece = &wR1;
    board[7][1].piece = &wN1;
    board[7][2].piece = &wB1;
    board[7][3].piece = &wQ;
    board[7][4].piece = &wK;
    board[7][5].piece = &wB2;
    board[7][6].piece = &wN2;
    board[7][7].piece = &wR2;
}

void Gameplay::createBlackPawns()
{
    static Pawn bP1("Pawn", 2);
    static Pawn bP2("Pawn", 2);
    static Pawn bP3("Pawn", 2);
    static Pawn bP4("Pawn", 2);
    static Pawn bP5("Pawn", 2);
    static Pawn bP6("Pawn", 2);
    static Pawn bP7("Pawn", 2);
    static Pawn bP8("Pawn", 2);

    board[1][0].piece = &bP1;
    board[1][1].piece = &bP2;
    board[1][2].piece = &bP3;
    board[1][3].piece = &bP4;
    board[1][4].piece = &bP5;
    board[1][5].piece = &bP6;
    board[1][6].piece = &bP7;
    board[1][7].piece = &bP8;
}

void Gameplay::createBlackMajors()
{
    static Rook   bR1("Rook",    2);
    static Rook   bR2("Rook",    2);
    static Knight bN1("Knight",  2);
    static Knight bN2("Knight",  2);
    static Bishop bB1("Bishop",  2);
    static Bishop bB2("Bishop",  2);
    static Queen  bQ("Queen",    2);
    static King   bK("King",     2);

    board[0][0].piece = &bR1;
    board[0][1].piece = &bN1;
    board[0][2].piece = &bB1;
    board[0][3].piece = &bQ;
    board[0][4].piece = &bK;
    board[0][5].piece = &bB2;
    board[0][6].piece = &bN2;
    board[0][7].piece = &bR2;
}

void Gameplay::createAllPieces()
{
    createWhitePawns();
    createWhiteMajors();
    createBlackPawns();
    createBlackMajors();
}


void Gameplay::showHelp(int& currPlayer)
{
    std::cout << "-----------------Help menu-----------------\n";
    std::cout << "Possible commands:\n"
              << "undo -> returns the game to the state before the last move.\n"
              << "exit -> exits the game.\n"
              << "move x1y1 x2y2 -> if possible, move the figure from (x1,y1) to (x2,y2)\n"
              << "example: move d2 d4\n";
    if (currPlayer == 1) currPlayer = 2; else currPlayer = 1;
}

void Gameplay::playerMoveLoop(int& currPlayer)
{
    String comand;
    while (true)
    {
        if (currPlayer == 1) 
			currPlayer = 2;
		else currPlayer = 1;
        PrintBoard(board);
        std::cout << "\nIt is Player " << currPlayer << " turn. Please enter your command:\n";
        std::cin >> comand;

        if (comand == "help") {
            showHelp(currPlayer);
        }
        else if (comand == "undo") {
            // not implemented
        }
        else if (comand == "exit") {
            break;
        }
        else {
            while (!isMoveCommandValid(comand)) {
                std::cin >> comand;
            }
            while (!canMove(comand, board, currPlayer) || !isMoveCommandValid(comand)) {
                std::cout << "Please enter your move again!\n";
                std::cin >> comand;
            }
        }
        if (isKingDead) {
            std::cout << "Player " << currPlayer << " wins!\n";
            break;
        }
    }
}

void Gameplay::PlayGame()
{
    createAllPieces();
    int currPlayer = 2;
    playerMoveLoop(currPlayer);
}