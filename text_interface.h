#ifndef BLOKUS_TEXT_INTERFACE_H
#define BLOKUS_TEXT_INTERFACE_H

#include <ostream>
#include <string>
#include <array>

#include "color.h"
#include "user_interface.h"
#include "transformation.h"

class TextInterface : public UserInterface
{
private:
	std::istream& m_is;
	std::ostream& m_os;

	std::u16string printPiece(const Piece& piece, int index);
	std::u16string printPiece(const Piece& piece, const Transformation& t, int idx);

	std::string readLine();
	static bool onlySpacesAfter(const std::string& line, size_t pos);

public:
	TextInterface(std::istream& input, std::ostream& output);
	PiecesSet::PieceIterator getPiece(const PiecesSet& piecesSet, Color color) override;
	Coordinate getPosition() override;
	Transformation getTransformation(const Piece* piece, Color color) override;
	std::ostream& getMessageOutput() override;
	virtual void clearMessages() override;
	void displayBoard(const Board& board) override;
};


#endif //BLOKUS_TEXT_INTERFACE_H
