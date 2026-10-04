#include "placement.h"
#include "board.h"
#include "coordinate.h"

Placement::Placement(const Transformation& transformation, const Coordinate& origin, const Color& color) :
  transformation{transformation},
  origin{origin},
  color{color}
{}

std::vector<Coordinate> Placement::calculatePosition(std::vector<Coordinate> initialPosition) {
  std::vector<Coordinate> targetPosition;
  for (Coordinate& c : initialPosition) {
    targetPosition.push_back(c + this->origin);
  }
  return targetPosition;
}

std::vector<Coordinate> Placement::calculateTransformation(std::vector<Coordinate> initialPosition) {
  std::vector<Coordinate> targetPosition;
  for (Coordinate& c : initialPosition) {
    targetPosition.push_back(c * this->transformation);
  }
  return targetPosition;
}

bool Placement::isValid(Piece* p) {
  std::vector<Coordinate> targetPosition = calculateTransformation(calculatePosition((*p).getSquares()));

  if (targetPosition.back().x < Board::SIZE && targetPosition.back().y < Board::SIZE) {
    return true;
  } else {
    return false;
  }
}

Color& Placement::getColor() {
  return this->color;
}