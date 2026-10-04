#include "placement.h"
#include "board.h"
#include "coordinate.h"

std::vector<Coordinate> Placement::calculatePosition(Piece* p) {
  std::vector<Coordinate> targetPosition;
  for (Coordinate& c : *p) {
    targetPosition.push_back(c + this->origin);
  }
  return targetPosition;
}

std::vector<Coordinate> Placement::calculateTransformation(Piece* p) {
  std::vector<Coordinate> targetPosition;
  for (Coordinate& c : *p) {
    targetPosition.push_back(c * this->transformation);
  }
  return targetPosition;
}

bool Placement::isValid(Piece* p) {
  Piece tempPiece = Piece(*p);
  std::vector<Coordinate> targetPosition = calculatePosition(&tempPiece);
  tempPiece.setSquares(targetPosition);
  targetPosition = calculateTransformation(&tempPiece);

  if (targetPosition.back().x < Board::SIZE && targetPosition.back().y < Board::SIZE) {
    return true;
  } else {
    return false;
  }
}