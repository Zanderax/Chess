#include "player.hpp"

void Player::PlayTurn( Board & board )
{
	board.MakeMove( 1, 0, 2, 0 );
}
