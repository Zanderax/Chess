#ifndef BOARD_H
#define BOARD_H

#include <stdio.h>
#include <vector>
#include "piece.hpp"
#include "move.hpp"

#define RANK 		8
#define FFILE 	8

struct Position
{
	int rank;
	int ffile;
};

using Moves = std::vector<Move>;
using Positions = std::vector<Position>;

class Board
{
public:
	Board();
	Board( const Board & board );
	void NewGame();
	void PrintBoard();
	bool MakeMove( Move & move );
	Piece pieces[RANK][FFILE];
	void ValidMoves( Moves & moves, int rank, int ffile );
	Moves AllValidMoves( Color color );
	Positions ValidPieces( Color color );
	bool CanBeTaken( int r, int f, Color _color );
	bool IsInCheck( Color color);
	bool IsInMate( Color color);
	Board LookAhead( Move move );

private:
	void ClearBoard();
	void PrintRank( int rank );
	void PrintMoves( Moves moves );
};

#endif //PIECE_H
