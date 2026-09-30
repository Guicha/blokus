#ifndef BLOKUS_PLACEMENT_H
#define BLOKUS_PLACEMENT_H

#include "piece.h"
#include "transformation.h"
#include "coordinate.h"
#include "color.h"

class Placement {
  private:
    Transformation transformation;
    Coordinate origin;
    Color color;

  public:
    std::vector<Coordinate> calculatePosition(Piece* p);
    std::vector<Coordinate> calculateTransformation(Piece* p);
    bool isValid();
};

#endif // BLOKUS_PLACEMENT_H