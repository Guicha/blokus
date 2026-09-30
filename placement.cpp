#include "placement.h"
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

bool Placement::isValid() {
  return true;
}