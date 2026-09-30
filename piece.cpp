#include "piece.h"

Piece::Piece(const std::initializer_list<Coordinate>&& squares) :
  squares{[&squares] {
    std::vector<Coordinate> temp(squares);
    std::sort(temp.begin(), temp.end());
    return temp;
  }()}
{}

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


