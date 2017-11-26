#ifndef BOARD_H
#define BOARD_H

#include <stdio.h>
#include <vector>
#include <map>
#include <functional>
#include "piece.hpp"
#include "move.hpp"

#define RANK 		8
#define FFILE 	8

struct Position
{
	int rank;
	int ffile;
};

using Moves = std::vector<Move>;
using Positions = std::vector<Position>;
using ColorState = std::map<Color, bool>;

class Board
{
public:
	Board();
	Board( const Board & board );
	void NewGame();
	void PrintBoard();
	bool MakeMove( Move & move );
	Piece pieces[RANK][FFILE];
	void ValidMoves( Moves & moves, int rank, int ffile );
	Moves AllValidMoves( Color color );
	Positions ValidPieces( Color color );
	bool CanBeTaken( int r, int f, Color _color );
	bool IsInCheck( Color color );
	bool IsInMate( Color color );
	Board LookAhead( Move move );
	bool CanTakeSquare( int rank, int ffile, Color _color );
	bool CanKingCastle( Color _color );
	void SetSquare( int rank, int file, PieceType type, Color color );

private:
	void ClearBoard();
	void PrintRank( int rank );
	void PrintMoves( Moves moves );
	void CreatePlayer(Color color);

	ColorState _hasKingMoved;
	ColorState _hasKingRookMoved;
	ColorState _hasQueenRookMoved;
};

#endif //BOARD_H
