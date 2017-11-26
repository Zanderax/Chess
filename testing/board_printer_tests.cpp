#include "../src/board.hpp"
#include "../src/board_printer.hpp"

TEST( BoardPrinterTest, PrintEdge )
{
	testing::internal::CaptureStdout();
	
	BoardPrinter printer;
	printer.PrintEdge();

	std::string stdout = testing::internal::GetCapturedStdout();

	ASSERT_EQ( stdout, "+========+\n" );
}

TEST( BoardPrinterTest, PrintRank )
{
	testing::internal::CaptureStdout();

	Board board;
	board.NewGame();
	
	BoardPrinter printer;
	printer.PrintRank( board, 1 );

	std::string expected;

	expected += "|";
	for(int i = 0; i < 4; ++i)
	{
		expected += "\x1B[4;1;40;39mP\x1B[0m\x1B[4;1;41;39mP\x1B[0m";
	}
	expected += "|\n";
	
	std::string stdout = testing::internal::GetCapturedStdout();

	ASSERT_EQ( stdout, expected );
}
