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
	void NewGame();
	void PrintBoard();
	bool MakeMove( Move & move );
	Piece pieces[RANK][FFILE];
	void ValidMoves( Moves & moves, int rank, int ffile );
	Positions ValidPieces( Color color );	

private:
	void ClearBoard();
	void PrintRank( int rank );
};

#endif //PIECE_H
