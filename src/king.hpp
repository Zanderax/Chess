#ifndef KING_H
#define KING_H

#include "piece.hpp"

class King : Piece
{
public:
	Moves getMoves() override;	
};

#endif // KING_H
