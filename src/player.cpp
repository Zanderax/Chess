#include "player.hpp"
#include "move.hpp"

#include <stdlib.h>
#include <time.h>

Result Player::PlayTurn( Board & board, Color color )
{
	srand(time(nullptr));

	Positions positions = board.ValidPieces( color );

	Moves moves;
	for(unsigned int i = 0; i < positions.size(); ++i )
	{
 		board.ValidMoves( moves, positions[i].rank, positions[i].ffile );
	}
	for(unsigned int i = 0; i < moves.size(); ++i )
	{
		printf("Move %d. r=%d f=%d : r=%d f=%d\n", i, moves[i]._sourceRank, moves[i]._sourceFFile, moves[i]._targetRank, moves[i]._targetFFile );
	}

	if( moves.size() == 0 )	
	{
		return STALEMATE;
	}

	Color otherColor = BLACK;

	if(color == BLACK)
	{
		otherColor = WHITE;
	}
	int moveIndex = 0;
	do
	{
		moveIndex = (int)rand() % moves.size();
	} while(board.LookAhead(moves[moveIndex]).IsInCheck(color));

	board.MakeMove( moves[moveIndex] );
	if(board.IsInMate(otherColor))
	{
		return WIN;
	}

	return CONTINUE;
}

