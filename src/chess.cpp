#include <unistd.h>
#include <iostream>
#include <string>
#include "chess.hpp"

#define NUM_GAMES 10

int main( int argc, char *argv[] )
{
	int numGames = NUM_GAMES;
	
	if(argc>1)
	{
		numGames = atoi(argv[1]);
	}
	
	printf( "Playing %d games. Press any key to start.", numGames );
	getchar();
	Chess chess;
	chess.PlayManyGames( numGames );
}

void Chess::PlayManyGames( int numGames )
{
	int blackWins = 0;
	int whiteWins = 0;
	for(int i = 0; i < numGames; ++i)
	{
		Color color;
		color = this->PlayGame(i);
		if(color == BLACK)
		{
			printf("Black Wins\n");
			++blackWins;
		}
		else if(color == WHITE)
		{
			printf("White Wins\n");
			++whiteWins;
		}
		printf("Score - Black:%d White:%d", blackWins, whiteWins);
		//getchar();
	}
	printf("\nBlack Wins = %d, White Wins = %d\n", blackWins, whiteWins );
}

Color Chess::PlayGame( int gameNum )
{
	board.NewGame();
	board.PrintBoard();
	players[0]._color = WHITE; 
	players[1]._color = BLACK; 
	
	for(int i = 0; i < MAX_TURNS; ++i )
	{
		for(int j = 0; j < NUM_PLAYERS; ++j )
		{
			board.PrintBoard();
			printf( "\nGameNum = %d\nPlayer %d's turn.\nTurn = %d\n",gameNum, j, i );
			Color color = WHITE;
			if(j%2 != 0)
			{
				color = BLACK;
			}
			Result result = players[i].PlayTurn( board, color );
			if(result == WIN)
			{
				return players[i]._color;
			}
			if(result == STALEMATE)
			{
				return NO_COLOR;
			}
			getchar();
			//usleep( 5000000 );
		}
	}
	return WHITE;
}
