#include "move.hpp"

Move::Move( int sourceRank, int sourceFFile, int targetRank, int targetFFile )
{
	_sourceRank = sourceRank;
	_sourceFFile = sourceFFile;
	_targetRank = targetRank;
	_targetFFile = targetFFile;
}

bool Move::IsValid()
{
	return _sourceRank <= 7 && _sourceRank >= 0 &&
	_sourceFFile <= 7 && _sourceFFile >= 0 &&
	_targetRank <= 7 && _targetRank >= 0 &&
	_targetFFile <= 7 && _targetFFile >= 0;
}
