#include "../src/piece.hpp"

class Board
{
	public:
		Piece pieces[8][8];
};

TEST( PieceTest, PawnMoves )
{
	//Setup
	Board board;
	Moves moves;

	for(int i = 0; i < 8; ++i)
	{
		for(int j = 0; j < 8; ++j)
		{
			board.pieces[i][j]._color = WHITE;
			board.pieces[i][j]._type = NONE;	
		}
	}

	//board.pieces[5][6]._color = BLACK;
	//board.pieces[5][6]._type = PAWN;	

	//Execute
	moves = board.pieces[5][6].GetPawnMoves(&board);
	
	//Assert
	ASSERT_EQ( moves.size(), 1);
}
