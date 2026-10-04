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
    bool isValid(Piece* p); // avec ça on vérifie juste si les coordonnées sont dans le plateau ; on vérifie pas tout de suite si le placement est correct vis a vis des autres cases + ne pas implémenter la méthode "validate" de board car elle overlap celle la 
};

#endif // BLOKUS_PLACEMENT_H