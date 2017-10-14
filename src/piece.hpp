#ifndef PIECE_H
#define PIECE_H

#include <vector>
#include "move.hpp"

using Moves = std::vector<Move>;

enum PieceType
{
	NONE,
	PAWN,
	ROOK,
	KNIGHT,
	BISHOP,
	QUEEN,
	KING,
};

enum Color
{
	BLACK,
	WHITE
};


class Piece
{
public:
	Piece();
	void PrintPiece( Color squareColor );
	Color _color;
	PieceType _type;
	virtual Moves getMoves() { Moves moves; return moves; };
};

#endif //PIECE_H
