#include "board.hpp"
#include "board_printer.hpp"
#include "piece.hpp"
#include "move.hpp"

#include <stdlib.h>
#include <stdio.h>

#include <list>

void Board::ClearBoard()
{
	for(int r = 0; r < RANK; r++)
	{
		for(int f = 0; f < FFILE; f++)
		{
			pieces[r][f] = Piece(NO_COLOR, NONE, r,f );
		}
	}
}

Board::Board()
{
	ClearBoard();
	CreatePlayer(BLACK);
	CreatePlayer(WHITE);
}

Board::Board( const Board & board )
{
	ClearBoard();
	CreatePlayer(BLACK);
	CreatePlayer(WHITE);
	for(int r = 0; r < RANK; ++r)
	{
		for(int f = 0; f < FFILE; ++f)
		{
			pieces[r][f]._type = board.pieces[r][f]._type;
			pieces[r][f]._color = board.pieces[r][f]._color;
		}
	}
}

void Board::CreatePlayer(Color color)
{
	_hasKingMoved.emplace(color, false);
	_hasKingRookMoved.emplace(color, false);
	_hasQueenRookMoved.emplace(color, false);
}


void Board::NewGame()
{
	ClearBoard();
	
	for(int i = 0; i < 8; ++i)
	{
		pieces[0][i]._color = WHITE;
		pieces[1][i]._color = WHITE;
	}
	
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

void PrintFileNumbers()
{
	BoardPrinter::PrintFileNumbers();
}

void PrintEdge()
{
	BoardPrinter::PrintEdge();
}

void Board::PrintRank( int r )
{
	BoardPrinter::PrintRank( *this, r );
}

void Board::PrintBoard()
{
	system("clear");
	PrintFileNumbers();
	//PrintEdge();
	for(int i = 0; i < 8; ++i)
	{
		PrintRank(i);
	}
	PrintEdge();
}

void Board::SetSquare( int rank, int file, PieceType type, Color color )
{
	pieces[rank][file]._type = type;
	pieces[rank][file]._color = color;
}

bool Board::CanTakeSquare( int rank, int ffile, Color _color )
{
	return (rank >= 0 && rank < 8) && (ffile >= 0 && ffile < 8) &&
		(pieces[rank][ffile]._type == NONE 
		 ||	pieces[rank][ffile]._color != _color);
}

bool Board::MakeMove( Move & move ) 
{
	if( !move.IsValid() )
	{
		return false;
	}

	Piece * source = &pieces[move._sourceRank][move._sourceFFile];

	if(source->_type == NONE )
	{
		return false;
	}
	source->_rank = move._targetRank;
	source->_ffile = move._targetFFile;
	pieces[move._targetRank][move._targetFFile] = *source;
	pieces[move._sourceRank][move._sourceFFile] = Piece();
		
	
	source->_type = NONE;
	return true;
}

void Board::ValidMoves( Moves & moves, int rank, int file )
{
	auto newMoves = pieces[rank][file].GetMoves(this);
	moves.insert(std::end(moves), std::begin(newMoves), std::end(newMoves));
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

Moves Board::AllValidMoves( Color color )
{
	Moves moves;
	for(int r = 0; r < RANK; ++r)
	{
		for(int f = 0; f < FFILE; ++f)
		{
			if(pieces[r][f]._color == color)
			{
				ValidMoves( moves, r, f );
			}
		}
	}
	return moves;
}

void Board::PrintMoves( Moves moves )
{
	for(auto move : moves)
	{
		printf("Source - r=%d, f=%d : Target - r=%d, f=%d\n",
				move._sourceRank, move._sourceFFile,
				move._targetRank, move._targetFFile);
	}
}

bool Board::CanBeTaken( int r, int f, Color color )
{
	Moves moves;
	if(color == BLACK)
	{
		moves = AllValidMoves(WHITE);
	}
	if(color == WHITE)
	{
		moves = AllValidMoves(BLACK);
	}
	
	for(auto move : moves)
	{
		if(move._targetRank == r && 
				move._targetFFile == f &&
				pieces[move._sourceRank][move._sourceFFile]._color != color)
		{
			return true;
		}
	}
	return false;
}

bool Board::IsInCheck( Color color )
{
	for(int r = 0; r < RANK; ++r)
	{
		for(int f = 0; f < FFILE; ++f)
		{
			if(pieces[r][f]._type == KING &&
					pieces[r][f]._color == color &&
					CanBeTaken( r, f, color))
			{
				return true;				
			}
		}
	}
	return false;
}

bool Board::IsInMate( Color color )
{
	if(!IsInCheck(color))
	{
		return false;
	}

	Moves moves = AllValidMoves( color );

	for(auto move : moves)
	{
		Board board = LookAhead(move);
		if(!board.IsInCheck(color))
		{
			return false;
		}
	}
	return true;
}

Board Board::LookAhead( Move move )
{
	Board board( *this );
	board.MakeMove(move);
	return board;
}

bool Board::CanKingCastle(Color color)
{
	if(_hasKingMoved[color] || _hasKingRookMoved[color])
	{
		return false;
	}

	int r = 0;
	if(color == BLACK)
	{
		r = 7;
	}

	if(pieces[r][5]._type != NONE || pieces[r][6]._type != NONE )
	{
		return false;
	}

	if( CanBeTaken(r, 4, color) || 
			CanBeTaken(r, 5, color) ||
			CanBeTaken(r, 6, color))
	{
		return false;
	}

	return true;
}

bool Board::CanQueenCastle(Color color)
{
	int r = 0;
	if(color == BLACK)
	{
		r = 7;
	}
	
	if( CanBeTaken(r, 2, color) || 
			CanBeTaken(r, 3, color) ||
			CanBeTaken(r, 4, color))
	{
		return false;
	}

	if(pieces[r][1]._type != NONE || pieces[r][2]._type != NONE ||
	pieces[r][3]._type != NONE )
	{
		return false;
	}

	return true;
}
