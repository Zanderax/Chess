#ifndef PLAYER_H
#define PLAYER_H

#include "board.hpp"

enum Result
{
	CONTINUE,
	WIN,
	STALEMATE
};

class Player
{
public:
	Result PlayTurn( Board & board, Color color );
	Color _color;
};

#endif // PLAYER_H
