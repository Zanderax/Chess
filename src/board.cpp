#include "board.hpp"
#include "piece.hpp"
#include "move.hpp"

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
	NewGame();
}

void Board::NewGame()
{
	ClearBoard();
	for(int i = 0; i < 8; ++i)
	{
		pieces[6][i]._color = BLACK;
		pieces[7][i]._color = BLACK;
	}
	/*
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
	*/
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

bool Board::MakeMove( Move & move ) 
{
	if( !move.IsValid() )
	{
		return false;
	}

	Piece * source = &pieces[move._sourceRank][move._sourceFFile];
	Piece * target = &pieces[move._targetRank][move._targetFFile];

	if(source->_type == NONE )
	{
		return false;
	}
	
	target->_type = source->_type;
	target->_color = source->_color;

	source->_type = NONE;
	return true;
}

void AddMove( Moves & moves, int sourceRank, int sourceFFile, int targetRank, int targetFFile )
{
	Move move( sourceRank, sourceFFile, targetRank, targetFFile );
	moves.push_back( move );
}

void Board::PawnMoves( Moves & moves, int rank, int file, Color color )
{
	if( rank == 7 || rank == 0 )
	{
		return;
	}
	if( color == WHITE )
	{
		if( pieces[rank + 1][file]._type == NONE )
		{
			AddMove( moves, rank, file, rank + 1, file );
		}
		if( pieces[rank + 1][file + 1]._type != NONE &&
				pieces[rank + 1][file + 1]._color == BLACK &&
				file != 7 )
		{
			AddMove( moves, rank, file, rank + 1, file + 1 );
		}
		if( pieces[rank + 1][file - 1]._type != NONE &&
				pieces[rank + 1][file - 1]._color == BLACK &&
				file != 0)
		{
			AddMove( moves, rank, file, rank + 1, file - 1 );
		}
	}
	if( color == BLACK )
	{
		if( pieces[rank - 1][file]._type == NONE )
		{
			AddMove( moves, rank, file, rank - 1, file );
		}
		if( pieces[rank - 1][file + 1]._type != NONE &&
				pieces[rank - 1][file + 1]._color == WHITE )
		{
			AddMove( moves, rank, file, rank - 1, file + 1 );
		}
		if( pieces[rank - 1][file - 1]._type != NONE &&
				pieces[rank - 1][file - 1]._color == WHITE )
		{
			AddMove( moves, rank, file, rank - 1, file - 1 );
		}
	}
}

void Board::ValidMoves( Moves & moves, int rank, int file )
{
	auto type = pieces[rank][file]._type;
	auto color = pieces[rank][file]._color;
	switch(type)
	{
		case NONE:
			return;
		case PAWN:
			return PawnMoves( moves, rank, file, color );
		default:
			return;
	}
}

Positions Board::ValidPieces( Color color )
{
	Positions positions;
	for(int r = 0; r < RANK; ++r)
	{
		for(int f = 0; f < FFILE; ++f)
		{
			if(pieces[r][f]._color == color && 
					pieces[r][f]._type != NONE)
			{
				positions.push_back( Position{r,f} );
			}
		}
	}
	return positions;
}
