#ifndef BOARD_H
#define BOARD_H

#include <stdio.h>
#include "piece.hpp"
#include "move.hpp"

#define RANK 		8
#define FFILE 	8

class Board
{
public:
	Board();
	void NewGame();
	void PrintBoard();
	bool MakeMove( Move & move );

private:
	Piece pieces[RANK][FFILE];
	void ClearBoard();
	void PrintRank( int rank );
};

#endif //PIECE_H
