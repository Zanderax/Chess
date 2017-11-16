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
	moves = board.pieces[5][6].GetMoves(&board);
	
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
	moves = board.pieces[5][6].GetMoves(&board);
	
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
	moves = board.pieces[5][6].GetMoves(&board);
	
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
	moves = board.pieces[5][6].GetMoves(&board);
	
	//Assert
	ASSERT_EQ( moves.size(), 0);
}

TEST( PieceTest, PawnMovesEnd )
{
	//Setup
	Board board;
	Moves moves;

	setUpBoard( board );

	board.pieces[0][6]._color = BLACK;
	board.pieces[0][6]._type = PAWN;	
	
	
	//Execute
	moves = board.pieces[0][6].GetMoves(&board);
	
	//Assert
	ASSERT_EQ( moves.size(), 0);
}

TEST( PieceTest, KingMoves )
{
	//Setup
	Board board;
	Moves moves;

	setUpBoard( board );

	board.pieces[5][6]._color = BLACK;
	board.pieces[5][6]._type = KING;	
	
	//Execute
	moves = board.pieces[5][6].GetMoves(&board);
	
	//Assert
	ASSERT_EQ( moves.size(), 8);
}

TEST( PieceTest, KingMovesTake )
{
	//Setup
	Board board;
	Moves moves;

	setUpBoard( board );

	board.pieces[5][6]._color = BLACK;
	board.pieces[5][6]._type = KING;	
	
	board.pieces[5][7]._type = PAWN;	
	
	//Execute
	moves = board.pieces[5][6].GetMoves(&board);
	
	//Assert
	ASSERT_EQ( moves.size(), 8);
}

TEST( PieceTest, KingMovesEdge )
{
	//Setup
	Board board;
	Moves moves;

	setUpBoard( board );

	board.pieces[5][7]._color = BLACK;
	board.pieces[5][7]._type = KING;	
	
	
	//Execute
	moves = board.pieces[5][7].GetMoves(&board);
	
	//Assert
	ASSERT_EQ( moves.size(), 5);
}

TEST( PieceTest, KingMovesCorner )
{
	//Setup
	Board board;
	Moves moves;

	setUpBoard( board );

	board.pieces[7][7]._color = BLACK;
	board.pieces[7][7]._type = KING;	
	
	
	//Execute
	moves = board.pieces[7][7].GetMoves(&board);
	
	//Assert
	ASSERT_EQ( moves.size(), 3);
}

TEST( PieceTest, RookMoves )
{
	//Setup
	Board board;
	Moves moves;

	setUpBoard( board );

	board.pieces[4][4]._color = BLACK;
	board.pieces[4][4]._type = ROOK;
	
	
	//Execute
	moves = board.pieces[4][4].GetMoves(&board);
	
	//Assert
	ASSERT_EQ( moves.size(), 14);
}

TEST( PieceTest, RookMovesBlocked )
{
	//Setup
	Board board;
	Moves moves;

	setUpBoard( board );

	board.pieces[4][4]._color = BLACK;
	board.pieces[4][4]._type = ROOK;
	
	board.pieces[4][5]._color = BLACK;
	board.pieces[4][5]._type = ROOK;
	
	board.pieces[5][4]._color = WHITE;
	board.pieces[5][4]._type = ROOK;
	//Execute
	moves = board.pieces[4][4].GetMoves(&board);

	//Assert
	ASSERT_EQ( moves.size(), 9);
}

TEST( PieceTest, BishopMoves )
{
	//Setup
	Board board;
	Moves moves;

	setUpBoard( board );

	board.pieces[4][4]._color = BLACK;
	board.pieces[4][4]._type = BISHOP;
	
	
	//Execute
	moves = board.pieces[4][4].GetMoves(&board);
	
	//Assert
	ASSERT_EQ( moves.size(), 13);
}

TEST( PieceTest, BishopMovesBlocked )
{
	//Setup
	Board board;
	Moves moves;

	setUpBoard( board );

	board.pieces[4][4]._color = BLACK;
	board.pieces[4][4]._type = BISHOP;
	
	board.pieces[5][5]._color = BLACK;
	board.pieces[5][5]._type = PAWN;
	
	board.pieces[3][3]._color = WHITE;
	board.pieces[3][3]._type = PAWN;
	
	//Execute
	moves = board.pieces[4][4].GetMoves(&board);
	
	//Assert
	ASSERT_EQ( moves.size(), 7);
}

TEST( PieceTest, BishopMovesCorner )
{
	//Setup
	Board board;
	Moves moves;

	setUpBoard( board );

	board.pieces[0][0]._color = BLACK;
	board.pieces[0][0]._type = BISHOP;
	
	
	//Execute
	moves = board.pieces[0][0].GetMoves(&board);
	
	//Assert
	ASSERT_EQ( moves.size(), 7);
}

TEST( PieceTest, BishopMovesEdge )
{
	//Setup
	Board board;
	Moves moves;

	setUpBoard( board );

	board.pieces[0][4]._color = BLACK;
	board.pieces[0][4]._type = BISHOP;
	
	
	//Execute
	moves = board.pieces[0][4].GetMoves(&board);
	
	//Assert
	ASSERT_EQ( moves.size(), 7);
}

TEST( PieceTest, KnightMoves )
{
	//Setup
	Board board;
	Moves moves;

	setUpBoard( board );

	board.pieces[4][4]._color = BLACK;
	board.pieces[4][4]._type = KNIGHT;
	
	
	//Execute
	moves = board.pieces[4][4].GetMoves(&board);
	
	//Assert
	ASSERT_EQ( moves.size(), 8);
}

TEST( PieceTest, KnightMovesCorner )
{
	//Setup
	Board board;
	Moves moves;

	setUpBoard( board );

	board.pieces[0][0]._color = BLACK;
	board.pieces[0][0]._type = KNIGHT;
	
	
	//Execute
	moves = board.pieces[0][0].GetMoves(&board);
	
	//Assert
	ASSERT_EQ( moves.size(), 2);
}

TEST( PieceTest, QueenMoves )
{
	//Setup
	Board board;
	Moves moves;

	setUpBoard( board );

	board.pieces[4][4]._color = BLACK;
	board.pieces[4][4]._type = QUEEN;
	
	
	//Execute
	moves = board.pieces[4][4].GetMoves(&board);
	
	//Assert
	ASSERT_EQ( moves.size(), 27);
}

TEST( PieceTest, QueenMovesCorner )
{
	//Setup
	Board board;
	Moves moves;

	setUpBoard( board );

	board.pieces[0][0]._color = BLACK;
	board.pieces[0][0]._type = QUEEN;
	
	
	//Execute
	moves = board.pieces[0][0].GetMoves(&board);
	
	//Assert
	ASSERT_EQ( moves.size(), 21);
}

TEST( PieceTest, QueenMovesBlocked )
{
	//Setup
	Board board;
	Moves moves;

	setUpBoard( board );

	board.pieces[4][4]._color = BLACK;
	board.pieces[4][4]._type = QUEEN;
	
	board.pieces[4][3]._color = BLACK;
	board.pieces[4][3]._type = PAWN;
	
	board.pieces[4][5]._color = WHITE;
	board.pieces[4][5]._type = PAWN;
	
	//Execute
	moves = board.pieces[4][4].GetMoves(&board);
	
	//Assert
	ASSERT_EQ( moves.size(), 21);
}
