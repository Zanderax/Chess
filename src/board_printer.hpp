#ifndef BOARD_PRINTER_H
#define BOARD_PRINTER_H

#include "board.hpp"

class BoardPrinter
{
public:
	void PrintEdge();	
	void PrintRank( const Board & board, int r );
};

#endif //BOARD_PRINTER_H
