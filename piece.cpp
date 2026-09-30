#include "piece.h"
#include "coordinate.h"

Piece::Piece(const std::initializer_list<Coordinate>&& squares) :
  squares{[&squares] {
    std::vector<Coordinate> temp(squares);
    std::sort(temp.begin(), temp.end());
    return temp;
  }()}
{}

std::vector<Coordinate>::iterator Piece::begin() {
  return squares.begin();
}

std::vector<Coordinate>::iterator Piece::end() {
  return squares.end();
}


bool operator<(const Piece& p1, const Piece& p2) {
  return p1.squares < p2.squares;
}

bool operator==(const Piece& p1, const Piece& p2) {
  return p1.squares == p2.squares;
}

bool operator!=(const Piece& p1, const Piece& p2) {
	return !(p1 == p2);
}

bool operator<=(const Piece& p1, const Piece& p2) {
	return (p1 < p2) || (p1 == p2);
}

bool operator>(const Piece& p1, const Piece& p2) {
	return !(p1 < p2) && !(p1 == p2);
}

bool operator>=(const Piece& p1, const Piece& p2) {
	return !(p1 < p2) || (p1 == p2);
}


