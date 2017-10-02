#ifndef PIECE_H
#define PIECE_H

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
};

#endif //PIECE_H
