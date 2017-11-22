#include "../src/board.hpp"

TEST( BoardTest, NewGame)
{
	Board board;
	board.NewGame();

	for(int i = 0; i < 8; ++i)
	{
		ASSERT_EQ(board.pieces[0][i]._color, WHITE);
		ASSERT_EQ(board.pieces[1][i]._color, WHITE);
		ASSERT_EQ(board.pieces[6][i]._color, BLACK);
		ASSERT_EQ(board.pieces[7][i]._color, BLACK);
	}
	
	ASSERT_EQ(board.pieces[0][0]._type, ROOK);
	ASSERT_EQ(board.pieces[0][1]._type, KNIGHT);
	ASSERT_EQ(board.pieces[0][2]._type, BISHOP);
	ASSERT_EQ(board.pieces[0][3]._type, QUEEN);
	ASSERT_EQ(board.pieces[0][4]._type, KING);
	ASSERT_EQ(board.pieces[0][5]._type, BISHOP);
	ASSERT_EQ(board.pieces[0][6]._type, KNIGHT);
	ASSERT_EQ(board.pieces[0][7]._type, ROOK);

	ASSERT_EQ(board.pieces[7][0]._type, ROOK);
	ASSERT_EQ(board.pieces[7][1]._type, KNIGHT);
	ASSERT_EQ(board.pieces[7][2]._type, BISHOP);
	ASSERT_EQ(board.pieces[7][3]._type, QUEEN);
	ASSERT_EQ(board.pieces[7][4]._type, KING);
	ASSERT_EQ(board.pieces[7][5]._type, BISHOP);
	ASSERT_EQ(board.pieces[7][6]._type, KNIGHT);
	ASSERT_EQ(board.pieces[7][7]._type, ROOK);
	
	for(int i = 0; i < 8; ++i)
	{
		ASSERT_EQ(board.pieces[1][i]._type, PAWN);
		ASSERT_EQ(board.pieces[6][i]._type, PAWN);
	}
}

TEST( BoardTest, InCheck )
{
	Board board;

	board.pieces[0][0]._color = WHITE;
	board.pieces[0][0]._type = KING;

	board.pieces[0][1]._color = BLACK;
	board.pieces[0][1]._type = QUEEN;

	ASSERT_TRUE(board.IsInCheck(WHITE));
}

TEST( BoardTest, NotInCheck )
{
	Board board;

	board.pieces[0][0]._color = WHITE;
	board.pieces[0][0]._type = KING;
	
	ASSERT_FALSE(board.IsInCheck(WHITE));
}

TEST( BoardTest, InCheckMate )
{
	Board board;

	board.pieces[0][0]._color = WHITE;
	board.pieces[0][0]._type = KING;
	
	board.pieces[1][1]._color = BLACK;
	board.pieces[1][1]._type = QUEEN;

	board.pieces[0][1]._color = BLACK;
	board.pieces[0][1]._type = QUEEN;

	ASSERT_TRUE(board.IsInMate(WHITE));
}

TEST( BoardTest, NotInCheckMate )
{
	Board board;

	board.pieces[0][0]._color = WHITE;
	board.pieces[0][0]._type = KING;
	
	ASSERT_FALSE(board.IsInMate(WHITE));
}
