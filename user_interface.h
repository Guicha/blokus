#ifndef BLOKUS_USERINTERFACE_H
#define BLOKUS_USERINTERFACE_H

#include <string>

#include "pieces_set.h"

class Board;

class UserInterface
{
public:
	virtual ~UserInterface() = default;
	virtual PiecesSet::PieceIterator getPiece(const PiecesSet& piecesSet) = 0;
	virtual Coordinate getPosition() = 0;
	virtual Transformation getTransformation(const Piece* piece = nullptr) = 0;
	virtual std::ostream& getMessageOutput() = 0;
	virtual void clearMessages() = 0;
	virtual void displayBoard(const Board& board) = 0;
};

#endif //BLOKUS_USERINTERFACE_H
