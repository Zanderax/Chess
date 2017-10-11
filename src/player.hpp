#ifndef PLAYER_H
#define PLAYER_H

#include "board.hpp"

class Player
{
public:
	bool PlayTurn( Board & board, Color color );
	Color _color;
};

#endif // PLAYER_H
