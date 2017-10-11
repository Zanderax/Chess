#include "player.hpp"
#include "move.hpp"

#include <stdlib.h>
#include <time.h>

bool Player::PlayTurn( Board & board, Color color )
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

	if( moves.size() > 0 )	
	{
		auto moveIndex = (int)rand() % moves.size();
		board.MakeMove( moves[moveIndex] );
		return true;
	}
	return false;
}

