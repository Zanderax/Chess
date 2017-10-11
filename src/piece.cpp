#include "piece.hpp"

#include <stdio.h>


Piece::Piece()
{
	_type = NONE;
	_color = WHITE;
}

char CharForPieceType( PieceType type )
{
	switch( type )
	{
		case NONE:
			return ' ';
		case PAWN:
			return 'P';
		case ROOK:
			return 'R';
		case KNIGHT:
			return 'N';
		case BISHOP:
			return 'B';
		case QUEEN:
			return 'Q';
		case KING:
			return 'K';
	}
	return 0;
}

int FGColorCode( Color color )
{
	switch( color )
	{
		case WHITE:
			return 39;
		case BLACK:
			return 30;
	}
	return 0;
}

int BGColorCode( Color color )
{
	switch( color )
	{
		case WHITE:
			return 41;
		case BLACK:
			return 40;
	}
	return 0;
}

void Piece::PrintPiece( Color squareColor )
{
	int fgColor = FGColorCode( _color );
	int bgColor = BGColorCode( squareColor );
	char type = CharForPieceType( _type ); 
	printf( "\033[4;1;%d;%dm%c\033[0m", bgColor, fgColor, type );
}

