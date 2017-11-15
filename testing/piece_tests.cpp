#include "../src/piece.hpp"

class Board
{
	public:
		Piece pieces[8][8];
};

void setUpBoard( Board & board )
{
	for(int i = 0; i < 8; ++i)
	{
		for(int j = 0; j < 8; ++j)
		{
			board.pieces[i][j]._rank = i;
			board.pieces[i][j]._ffile = j;
			board.pieces[i][j]._color = WHITE;
			board.pieces[i][j]._type = NONE;	
		}
	}
}

TEST( PieceTest, PawnMoves )
{
	//Setup
	Board board;
	Moves moves;

	setUpBoard( board );

	board.pieces[5][6]._color = BLACK;
	board.pieces[5][6]._type = PAWN;	

	//Execute
	moves = board.pieces[5][6].GetPawnMoves(&board);
	
	//Assert
	ASSERT_EQ( moves.size(), 1);
}

TEST( PieceTest, PawnMovesSingleTake )
{
	//Setup
	Board board;
	Moves moves;

	setUpBoard( board );

	board.pieces[5][6]._color = BLACK;
	board.pieces[5][6]._type = PAWN;	

	board.pieces[4][5]._type = PAWN;

	//Execute
	moves = board.pieces[5][6].GetPawnMoves(&board);
	
	//Assert
	ASSERT_EQ( moves.size(), 2);
}

TEST( PieceTest, PawnMovesDoubleTake )
{
	//Setup
	Board board;
	Moves moves;

	setUpBoard( board );

	board.pieces[5][6]._color = BLACK;
	board.pieces[5][6]._type = PAWN;	
	
	board.pieces[4][5]._type = PAWN;
	board.pieces[4][7]._type = PAWN;

	//Execute
	moves = board.pieces[5][6].GetPawnMoves(&board);
	
	//Assert
	ASSERT_EQ( moves.size(), 3);
}

TEST( PieceTest, PawnMovesBlocked )
{
	//Setup
	Board board;
	Moves moves;

	setUpBoard( board );

	board.pieces[5][6]._color = BLACK;
	board.pieces[5][6]._type = PAWN;	
	
	board.pieces[4][6]._type = PAWN;

	//Execute
	moves = board.pieces[5][6].GetPawnMoves(&board);
	
	//Assert
	ASSERT_EQ( moves.size(), 0);
}
