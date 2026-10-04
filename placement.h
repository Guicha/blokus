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
    Placement(const Transformation& transformation, const Coordinate& origin, const Color& color);
    std::vector<Coordinate> calculatePosition(std::vector<Coordinate> initialPosition);
    std::vector<Coordinate> calculateTransformation(std::vector<Coordinate> initialPosition);
    bool isValid(Piece* p); // avec ça on vérifie juste si les coordonnées sont dans le plateau ; on vérifie pas tout de suite si le placement est correct vis a vis des autres cases + ne pas implémenter la méthode "validate" de board car elle overlap celle la
    Color& getColor(); 
};

#endif // BLOKUS_PLACEMENT_H