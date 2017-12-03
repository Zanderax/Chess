#include "../src/board.hpp"
#include "../src/board_printer.hpp"

TEST( BoardPrinterTest, PrintEdge )
{
	testing::internal::CaptureStdout();
	
	BoardPrinter::PrintEdge();

	std::string stdout = testing::internal::GetCapturedStdout();

	ASSERT_EQ( "+========+\n", stdout );
}

TEST( BoardPrinterTest, PrintFileNumbers )
{
	testing::internal::CaptureStdout();
	
	BoardPrinter::PrintFileNumbers();

	std::string stdout = testing::internal::GetCapturedStdout();

	ASSERT_EQ( " 01234567 \n", stdout );
}

TEST( BoardPrinterTest, PrintRank )
{
	testing::internal::CaptureStdout();

	Board board;
	board.NewGame();

	BoardPrinter::PrintRank( board, 1 );
	
	std::string expected;

	expected += "1";
	for(int i = 0; i < 4; ++i)
	{
		expected += "\x1B[4;1;40;39mP\x1B[0m\x1B[4;1;41;39mP\x1B[0m";
	}
	expected += "|\n";

	std::string stdout = testing::internal::GetCapturedStdout();

	ASSERT_EQ( expected, stdout );
}

