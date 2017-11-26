#include <gtest/gtest.h>

#include "piece_tests.cpp"
#include "board_tests.cpp"
#include "board_printer_tests.cpp"

int main(int argc, char **argv)
{
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
