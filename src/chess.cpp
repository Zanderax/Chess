#include <unistd.h>
#include <iostream>
#include "chess.hpp"


int main()
{
	Chess chess;
	int blackWins = 0;
	int whiteWins = 0;
	for(int i = 0; i < 10; ++i)
	{
		Color color;
		color = chess.PlayGame();
		if(color == BLACK)
		{
			printf("Black Wins\n");
			++blackWins;
		}
		else
		{
			printf("White Wins\n");
			++whiteWins;
		}
		printf("Score - Black:%d White:%d", blackWins, whiteWins);
		getchar();
	}
	printf("Black Wins = %d, White Wins =%d\n", blackWins, whiteWins );
}

Color Chess::PlayGame()
{
	board.NewGame();
	board.PrintBoard();
	players[0]._color = WHITE; 
	players[1]._color = BLACK; 
	
	for(int i = 0; i < MAX_TURNS; ++i )
	{
		for(int i = 0; i < NUM_PLAYERS; ++i )
		{
			board.PrintBoard();
			printf( "\nPlayer %d's turn.\n", i );
			Color color = WHITE;
			if(i%2 != 0)
			{
				color = BLACK;
			}
			bool result = players[i].PlayTurn( board, color );
			if(!result)
			{
				if(color == WHITE)
				{
					return BLACK;
				}
				return WHITE;
			}
			//getchar();
			//usleep( 5000000 );
		}
	}
	return WHITE;
}
