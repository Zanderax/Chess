#ifndef PIECE_H
#define PIECE_H

#include <vector>
#include "move.hpp"

using Moves = std::vector<Move>;

class Board;

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
	Piece( Color color, PieceType type, int rank, int ffile);
	void PrintPiece( Color squareColor );
	Color _color;
	PieceType _type;
	int _rank;
	int _ffile;
	Moves GetMoves(Board *board);
private:
	Moves GetPawnMoves(Board *board);
	Moves GetKingMoves(Board *board);
	Moves GetQueenMoves(Board *board);
	Moves GetBishopMoves(Board *board);
	Moves GetKnightMoves(Board *board);
	Moves GetRookMoves(Board *board);
};

#endif //PIECE_H
