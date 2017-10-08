#ifndef MOVE_H
#define MOVE_H

class Move
{
public:
	Move( int sourceRank, int sourceFFile, int targetRank, int targetFFile );
	bool IsValid();
	int _sourceRank;
	int _sourceFFile;
	int _targetRank;
	int _targetFFile;
};

#endif // MOVE_H
