#include "board.hpp"
#include "piece.hpp"
#include <stdlib.h>
#include <stdio.h>

void Board::ClearBoard()
{
	for(int r = 0; r < RANK; r++)
	{
		for(int f = 0; f < FFILE; f++)
		{
			pieces[r][f]._type = NONE;
			pieces[r][f]._color = WHITE;
		}
	}
}

Board::Board()
{
	ClearBoard();
	NewGame();
}

void Board::NewGame()
{
	for(int i = 0; i < 8; ++i)
	{
		pieces[6][i]._color = BLACK;
		pieces[7][i]._color = BLACK;
	}

	pieces[0][0]._type = ROOK;
	pieces[0][1]._type = KNIGHT;
	pieces[0][2]._type = BISHOP;
	pieces[0][3]._type = QUEEN;
	pieces[0][4]._type = KING;
	pieces[0][5]._type = BISHOP;
	pieces[0][6]._type = KNIGHT;
	pieces[0][7]._type = ROOK;


	pieces[7][0]._type = ROOK;
	pieces[7][1]._type = KNIGHT;
	pieces[7][2]._type = BISHOP;
	pieces[7][3]._type = QUEEN;
	pieces[7][4]._type = KING;
	pieces[7][5]._type = BISHOP;
	pieces[7][6]._type = KNIGHT;
	pieces[7][7]._type = ROOK;
	
	for(int i = 0; i < 8; ++i)
	{
		pieces[1][i]._type = PAWN;
		pieces[6][i]._type = PAWN;
	}
}

void PrintEdge()
{
	printf("+");
	for(int i = 0; i < 8; ++i)
	{
		printf("=");
	}
	printf("+");
	printf("\n");
}

void Board::PrintRank( int r )
{
	r++;r--;
	printf("|");
	if( r%2 == 0 )
	{
		for(int f = 0; f < 8; f+=2)
		{
			pieces[r][f].PrintPiece( WHITE );
			pieces[r][f+1].PrintPiece( BLACK );
		}
	}
	if( r%2 != 0 )
	{
		for(int f = 0; f < 8; f+=2)
		{
			pieces[r][f].PrintPiece( BLACK );
			pieces[r][f+1].PrintPiece( WHITE );
		}
	}
	printf("|");
	printf("\n");
}

void Board::PrintBoard()
{
	if(system("CLS")) system("clear");
	PrintEdge();
	for(int i = 0; i < 8; ++i)
	{
		PrintRank(i);
	}
	PrintEdge();
}

bool Board::MakeMove( int sourceRank, int sourceFFile, int targetRank, int targetFFile )
{
	
	if( sourceRank > 7 || sourceRank < 0 ||
	sourceFFile > 7 || sourceFFile < 0 ||
	targetRank > 7 || targetRank < 0 ||
	targetFFile > 7 || targetFFile < 0 )
	{
		return false;
	}

	if(pieces[sourceRank][sourceFFile]._type == NONE )
	{
		return false;
	}
	
	pieces[targetRank][targetFFile]._type = pieces[sourceRank][sourceFFile]._type;
	pieces[targetRank][targetFFile]._color = pieces[sourceRank][sourceFFile]._color;

	pieces[sourceRank][sourceFFile]._type = NONE;
	return true;
}
