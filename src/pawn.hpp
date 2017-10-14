#ifndef PAWN_H
#define PAWN_H

#include "piece.hpp"

class Pawn : Piece
{
public:
	Moves getMoves() override;	
};

#endif // PAWN_H
