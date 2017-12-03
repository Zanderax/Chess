#include "board_printer.hpp" 

#include "piece.hpp"

#include <stdio.h>

void BoardPrinter::PrintFileNumbers()
{
	printf( " 01234567 \n");
}

void BoardPrinter::PrintEdge()
{
	printf("+");
	for(int i = 0; i < 8; ++i)
	{
		printf("=");
	}
	printf("+");
	printf("\n");
}

void BoardPrinter::PrintRank( const Board& board, int r )
{
	Piece pieces[8][8] = board.pieces;
	r++;r--;
	printf("%d", r);
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
