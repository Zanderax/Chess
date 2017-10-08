#include <unistd.h>

#include "chess.hpp"


int main()
{
	Chess chess;
	chess.PlayGame();
}

void Chess::PlayGame()
{
	board.NewGame();
	board.PrintBoard();
	for(int i = 0; i < MAX_TURNS; ++i )
	{
		for(int i = 0; i < NUM_PLAYERS; ++i )
		{
			players[i].PlayTurn( board );
			board.PrintBoard();
			printf( "\nPlayer %d's turn.\n", i );
			usleep( 100000 );
		}
	}
}
