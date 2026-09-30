#ifndef BLOKUS_PLACEMENT_H
#define BLOKUS_PLACEMENT_H

#include "transformation.h"
#include "coordinate.h"
#include "color.h"

class Placement {
  private:
    Transformation transformation;
    Coordinate origin;
    Color color;

  public:
    bool isValid();
};

#endif // BLOKUS_PLACEMENT_H