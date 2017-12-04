#include "../src/board.hpp"

char digits[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9' };

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

TEST( BoardTest, SetSquare )
{
	Board board;

	board.SetSquare( 4, 5, PAWN, BLACK );
	
	ASSERT_EQ(board.pieces[4][5]._type, PAWN);
	ASSERT_EQ(board.pieces[4][5]._color, BLACK);
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

TEST( BoardTest, InCheckKnight )
{
	Board board;

	board.pieces[0][0]._color = WHITE;
	board.pieces[0][0]._type = KING;
	
	board.pieces[1][2]._color = BLACK;
	board.pieces[1][2]._type = KNIGHT;
	
	ASSERT_TRUE(board.IsInCheck(WHITE));
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

TEST( BoardTest, BlackQueenCastle )
{
	Board board;

	board.pieces[7][4]._color = BLACK;
	board.pieces[7][4]._type = KING;
	board.pieces[7][0]._color = BLACK;
	board.pieces[7][0]._type = ROOK;
	
	ASSERT_TRUE(board.CanQueenCastle(BLACK));
}

TEST( BoardTest, BlackQueenCastleBlocked )
{
	Board board;

	board.pieces[7][4]._color = BLACK;
	board.pieces[7][4]._type = KING;

	board.pieces[7][3]._color = BLACK;
	board.pieces[7][3]._type = QUEEN;

	board.pieces[7][0]._color = BLACK;
	board.pieces[7][0]._type = ROOK;
	
	ASSERT_FALSE(board.CanQueenCastle(BLACK));
}

TEST( BoardTest, BlackQueenCastleThroughCheck )
{
	Board board;
	
	board.SetSquare(7, 4, KING, BLACK);
	board.SetSquare(7, 0, ROOK, BLACK);
	board.SetSquare(6, 3, ROOK, WHITE);
	
	ASSERT_FALSE(board.CanQueenCastle(BLACK));
}

TEST( BoardTest, BlackQueenCastleOnlyTheRook )
{
	Board board;
	
	board.SetSquare(7, 4, KING, BLACK);
	board.SetSquare(7, 0, ROOK, BLACK);
	board.SetSquare(6, 1, ROOK, WHITE);
	
	ASSERT_TRUE(board.CanQueenCastle(BLACK));
}

TEST( BoardTest, BlackKingCastle )
{
	Board board;

	board.pieces[7][4]._color = BLACK;
	board.pieces[7][4]._type = KING;
	board.pieces[7][7]._color = BLACK;
	board.pieces[7][7]._type = ROOK;
	
	ASSERT_TRUE(board.CanKingCastle(BLACK));
}

TEST( BoardTest, BlackKingCastleBlocked )
{
	Board board;

	board.pieces[7][4]._color = BLACK;
	board.pieces[7][4]._type = KING;
	board.pieces[7][6]._color = BLACK;
	board.pieces[7][6]._type = KNIGHT;
	board.pieces[7][7]._color = BLACK;
	board.pieces[7][7]._type = ROOK;

	ASSERT_FALSE(board.CanKingCastle(BLACK));
}

TEST( BoardTest, BlackKingCastleThroughCheck )
{
	Board board;

	board.pieces[7][4]._color = BLACK;
	board.pieces[7][4]._type = KING;
	board.pieces[7][7]._color = BLACK;
	board.pieces[7][7]._type = ROOK;
	
	board.pieces[6][5]._color = WHITE;
	board.pieces[6][5]._type = ROOK;

	ASSERT_FALSE(board.CanKingCastle(BLACK));
}

TEST( BoardTest, WhiteKingCastle )
{
	Board board;

	board.pieces[0][4]._color = WHITE;
	board.pieces[0][4]._type = KING;
	board.pieces[0][7]._color = WHITE;
	board.pieces[0][7]._type = ROOK;
	
	ASSERT_TRUE(board.CanKingCastle(WHITE));
}

TEST( BoardTest, WhiteKingCastleBlocked )
{
	Board board;

	board.pieces[0][4]._color = WHITE;
	board.pieces[0][4]._type = KING;
	board.pieces[0][6]._color = WHITE;
	board.pieces[0][6]._type = KNIGHT;
	board.pieces[0][7]._color = WHITE;
	board.pieces[0][7]._type = ROOK;
	
	ASSERT_FALSE(board.CanKingCastle(WHITE));
}

TEST( BoardTest, WhiteKingCastleThroughCheck )
{
	Board board;

	board.pieces[0][4]._color = WHITE;
	board.pieces[0][4]._type = KING;
	board.pieces[1][6]._color = BLACK;
	board.pieces[1][6]._type = ROOK;
	board.pieces[0][7]._color = WHITE;
	board.pieces[0][7]._type = ROOK;
	
	ASSERT_FALSE(board.CanKingCastle(WHITE));
}

TEST( BoardTest, PrintBoard )
{
	testing::internal::CaptureStdout();

	Board board;
	board.PrintBoard();

	std::string expected;

	expected += "\x1B[3;J\x1B[H\x1B[2J";

	expected += " 01234567 \n";

	for(int j = 0; j < 4; ++j)
	{
		expected += digits[j*2];
		for(int i = 0; i < 4; ++i)
		{
			expected += "\x1B[4;1;41;39m \x1B[0m\x1B[4;1;40;39m \x1B[0m";
		}
		expected += "|\n";
		
		expected += digits[j*2+1];
		for(int i = 0; i < 4; ++i)
		{
			expected += "\x1B[4;1;40;39m \x1B[0m\x1B[4;1;41;39m \x1B[0m";
		}
		expected += "|\n";
		
	}
	
	expected += "+========+\n";
	
	std::string stdout = testing::internal::GetCapturedStdout();

	ASSERT_EQ( expected, stdout );
}

