#include "piece.hpp"
#include "board.hpp"
#include <stdio.h>

Piece::Piece()
{
	_type = NONE;
	_color = NO_COLOR;
	_rank = 0;
	_ffile = 0;
}

Piece::Piece(Color color, PieceType type, int rank, int ffile)
{
	_type = type;
	_color = color;
	_rank = rank;
	_ffile = ffile;
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
		case NO_COLOR:
			return 39;
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
		case NO_COLOR:
			return 41;
	}
	return 0;
}

void AddMove( Moves & moves, int sourceRank, int sourceFFile, int targetRank, int targetFFile)
{
	Move move( sourceRank, sourceFFile, targetRank, targetFFile);
	moves.push_back(move);
}

Moves Piece::GetPawnMoves(Board *board)
{
	Piece (*pieces)[8] = board->pieces;
	Moves moves;
	if( _color == WHITE )
	{
		if(_rank == 7)
		{
			return moves;
		}
		if( pieces[_rank + 1][_ffile]._type == NONE )
		{
			AddMove( moves, _rank, _ffile, _rank + 1, _ffile );
		}
		if( pieces[_rank + 1][_ffile + 1]._type != NONE &&
				pieces[_rank + 1][_ffile + 1]._color == BLACK &&
				_ffile != 7 )
		{
			AddMove( moves, _rank, _ffile, _rank + 1, _ffile + 1 );
		}
		if( pieces[_rank + 1][_ffile - 1]._type != NONE &&
				pieces[_rank + 1][_ffile - 1]._color == BLACK &&
				_ffile != 0)
		{
			AddMove( moves, _rank, _ffile, _rank + 1, _ffile - 1 );
		}
	}
	if( _color == BLACK )
	{
		if(_rank == 0)
		{
			return moves;
		}
		if( pieces[_rank - 1][_ffile]._type == NONE )
		{
			AddMove( moves, _rank, _ffile, _rank - 1, _ffile );
		}
		if( pieces[_rank - 1][_ffile + 1]._type != NONE &&
				pieces[_rank - 1][_ffile + 1]._color == WHITE )
		{
			AddMove( moves, _rank, _ffile, _rank - 1, _ffile + 1 );
		}
		if( pieces[_rank - 1][_ffile - 1]._type != NONE &&
				pieces[_rank - 1][_ffile - 1]._color == WHITE )
		{
			AddMove( moves, _rank, _ffile, _rank - 1, _ffile - 1 );
		}
	}
	return moves;
}

Moves Piece::GetKingMoves(Board * board)
{
	Piece (*pieces)[8] = board->pieces;
	Moves moves; 
	bool left, right, up, down;
	left = right = up = down = false;
	if(_rank != 0)
	{
		up = true;
	}
	if(_rank != 7)
	{
		down = true;
	}
	if(_ffile != 0)
	{
		left = true;
	}
	if(_ffile != 7)
	{
		right = true;
	}

	if(up && 
		(pieces[_rank - 1][_ffile]._color != _color ||
		 pieces[_rank - 1][_ffile]._type == NONE))
	{
		AddMove( moves, _rank, _ffile, _rank - 1, _ffile );
	}

	if(up && left && 
		(pieces[_rank - 1][_ffile - 1]._color != _color ||
		 pieces[_rank - 1][_ffile - 1]._type == NONE))
	{
		AddMove( moves, _rank, _ffile, _rank - 1, _ffile - 1 );
	}

	if(left && 
		(pieces[_rank][_ffile - 1]._color != _color ||
		 pieces[_rank][_ffile - 1]._type == NONE))
	{
		AddMove( moves, _rank, _ffile, _rank, _ffile - 1 );
	}

	if(left && down && 
		(pieces[_rank + 1][_ffile - 1]._color != _color ||
		 pieces[_rank + 1][_ffile - 1]._type == NONE))
	{
		AddMove( moves, _rank, _ffile, _rank + 1, _ffile );
	}

	if(down && 
		(pieces[_rank + 1][_ffile]._color != _color ||
		 pieces[_rank + 1][_ffile]._type == NONE))
	{
		AddMove( moves, _rank, _ffile, _rank + 1, _ffile );
	}

	if(down && right &&
		(pieces[_rank + 1][_ffile + 1]._color != _color ||
		 pieces[_rank + 1][_ffile + 1]._type == NONE))
	{
		AddMove( moves, _rank, _ffile, _rank + 1, _ffile + 1 );
	}

	if(right && 
		(pieces[_rank][_ffile + 1]._color != _color ||
		 pieces[_rank][_ffile + 1]._type == NONE))
	{
		AddMove( moves, _rank, _ffile, _rank, _ffile + 1 );
	}

	if(right && up &&
		(pieces[_rank - 1][_ffile + 1]._color != _color ||
		 pieces[_rank - 1][_ffile + 1]._type == NONE))
	{
		AddMove( moves, _rank, _ffile, _rank - 1, _ffile + 1 );
	}

	return moves; 
}

Moves Piece::GetQueenMoves(Board * board)
{
	Moves rookMoves = GetRookMoves(board);
	Moves moves = GetBishopMoves(board);
	moves.insert(moves.end(), rookMoves.begin(), rookMoves.end());
	return moves; 
}

Moves Piece::GetKnightMoves(Board & board )
{
	Moves moves;

	if(board.CanTakeSquare(_rank - 2, _ffile - 1, _color ))
	{
		AddMove( moves, _rank, _ffile, _rank - 2, _ffile - 1);
	}
	if(board.CanTakeSquare(_rank - 2, _ffile + 1, _color))
	{
		AddMove( moves, _rank, _ffile, _rank - 2, _ffile + 1);
	}
	if(board.CanTakeSquare(_rank + 2, _ffile - 1, _color))
	{
		AddMove( moves, _rank, _ffile, _rank + 2, _ffile - 1);
	}
	if(board.CanTakeSquare(_rank + 2, _ffile + 1, _color))
	{
		AddMove( moves, _rank, _ffile, _rank + 2, _ffile + 1);
	}
	if(board.CanTakeSquare(_rank - 1, _ffile - 2, _color))
	{
		AddMove( moves, _rank, _ffile, _rank - 1, _ffile - 2);
	}
	if(board.CanTakeSquare(_rank + 1, _ffile - 2, _color))
	{
		AddMove( moves, _rank, _ffile, _rank + 1, _ffile - 2);
	}
	if(board.CanTakeSquare(_rank - 1, _ffile + 2, _color))
	{
		AddMove( moves, _rank, _ffile, _rank - 1, _ffile + 2);
	}
	if(board.CanTakeSquare(_rank + 1, _ffile + 2, _color))
	{
		AddMove( moves, _rank, _ffile, _rank + 1, _ffile + 2);
	}

	return moves; 
}

Moves Piece::GetBishopMoves(Board * board )
{
	Piece (*pieces)[8] = board->pieces;
	Moves moves;

	int f = _ffile;
	int r = _rank;
	while( r > 0 && f > 0 )
	{
		r--;
		f--;
		if(pieces[r][f]._type != NONE)
		{
			if(pieces[r][f]._color != _color)
			{
				AddMove( moves, _rank, _ffile, r, f );
			}
			break;
		}
		AddMove( moves, _rank, _ffile, r, f );
	}

	f = _ffile;
	r = _rank;
	while( r > 0 && f < 7 )
	{
		r--;
		f++;
		if(pieces[r][f]._type != NONE)
		{
			if(pieces[r][f]._color != _color)
			{
				AddMove( moves, _rank, _ffile, r, f );
			}
			break;
		}
		AddMove( moves, _rank, _ffile, r, f );
	}

	f = _ffile;
	r = _rank;
	while( r < 7 && f > 0 )
	{
		r++;
		f--;
		if(pieces[r][f]._type != NONE)
		{
			if(pieces[r][f]._color != _color)
			{
				AddMove( moves, _rank, _ffile, r, f );
			}
			break;
		}
		AddMove( moves, _rank, _ffile, r, f );
	}

	f = _ffile;
	r = _rank;
	while( r < 7 && f < 7 )
	{
		r++;
		f++;
		if(pieces[r][f]._type != NONE)
		{
			if(pieces[r][f]._color != _color)
			{
				AddMove( moves, _rank, _ffile, r, f );
			}
			break;
		}
		AddMove( moves, _rank, _ffile, r, f );
	}

	return moves; 
}

Moves Piece::GetRookMoves(Board * board )
{
	Piece (*pieces)[8] = board->pieces;
	Moves moves; 
	int tempRank = _rank;
	while(tempRank > 0)
	{
		tempRank--;
		if(pieces[tempRank][_ffile]._type != NONE)
		{
			if(pieces[tempRank][_ffile]._color != _color)
			{
				AddMove( moves, _rank, _ffile, tempRank, _ffile );
			}
			break;
		}
		AddMove( moves, _rank, _ffile, tempRank, _ffile );
	}
	
	tempRank = _rank;
	while(tempRank < 7)
	{
		tempRank++;
		if(pieces[tempRank][_ffile]._type != NONE)
		{
			if(pieces[tempRank][_ffile]._color != _color)
			{
				AddMove( moves, _rank, _ffile, tempRank, _ffile );
			}
			break;
		}
		AddMove( moves, _rank, _ffile, tempRank, _ffile );
	}

	int tempFFile = _ffile;
	while(tempFFile > 0)
	{
		tempFFile--;
		if(pieces[_rank][tempFFile]._type != NONE)
		{
			if(pieces[_rank][tempFFile]._color != _color)
			{
				AddMove( moves, _rank, _ffile, _rank, tempFFile );
			}
			break;
		}
		AddMove( moves, _rank, _ffile, _rank, tempFFile );
	}
	
	tempFFile = _ffile;
	while(tempFFile < 7)
	{
		tempFFile++;
		if(pieces[_rank][tempFFile]._type != NONE)
		{
			if(pieces[_rank][tempFFile]._color != _color)
			{
				AddMove( moves, _rank, _ffile, _rank, tempFFile );
			}
			break;
		}
		AddMove( moves, _rank, _ffile, _rank, tempFFile );
	}

	return moves; 
}

void Piece::PrintPiece( Color squareColor )
{
	int fgColor = FGColorCode( _color );
	int bgColor = BGColorCode( squareColor );
	char type = CharForPieceType( _type ); 
	printf( "\033[4;1;%d;%dm%c\033[0m", bgColor, fgColor, type );
}

Moves Piece::GetMoves(Board * board)
{
	switch(_type)
	{
		case PAWN:
			return GetPawnMoves(board);
			break;
		case KING:
			return GetKingMoves(board);
			break;
		case QUEEN:
			return GetQueenMoves(board);
			break;
		case BISHOP:
			return GetBishopMoves(board);
			break;
		case KNIGHT:
			return GetKnightMoves(*board);
			break;
		case ROOK:
			return GetRookMoves(board);
			break;
		default:
			Moves moves; 
			return moves; 
			break;
	}
}

