#ifndef CHESS_H
#define CHESS_H

#include "player.hpp"
#include "board.hpp"

#define NUM_PLAYERS 2
#define MAX_TURNS 100

class Chess
{
public:
	void PlayGame();
private:
	Board board;
	Player players[];
};

#endif // CHESS_H
