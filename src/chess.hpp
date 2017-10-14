#ifndef CHESS_H
#define CHESS_H

#include "player.hpp"
#include "board.hpp"

#define NUM_PLAYERS 2
#define MAX_TURNS 100000

class Chess
{
public:
	void PlayManyGames( int numGames );
private:
	Color PlayGame( int gameNum );
	Board board;
	Player players[NUM_PLAYERS];
};

#endif // CHESS_H
