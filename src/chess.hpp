#ifndef CHESS_H
#define CHESS_H

#include "player.hpp"
#include "board.hpp"

#define NUM_PLAYERS 2
#define MAX_TURNS 100

class Chess
{
public:
	Color PlayGame();
private:
	Board board;
	Player players[NUM_PLAYERS];
};

#endif // CHESS_H