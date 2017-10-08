#include "player.hpp"
#include "move.hpp"

void Player::PlayTurn( Board & board )
{
	Move move( 1, 0, 2, 0 );
	board.MakeMove( move );
}
