#ifndef BLOKUS_BOARD_H
#define BLOKUS_BOARD_H

#include "color.h"
#include "pieces_set.h"
#include "placement.h"

class Board {
  public:
    static const int SIZE = 20;
    Board();
    Color& at(int x, int y); // Fonction logique de placement dans la matrice comme s'il s'agissait d'un repère cartésien

  private:
    Color playBoard[SIZE][SIZE]; // Attention, la matrice est définie avec 0,0 en haut a gauche. Ne pas oublier d'utiliser la methode at() pour placer/calculer des positions afin de bien prendre en compte que la position 0,0 est en bas a gauche
    bool canPlace(PiecesSet& piecesSet, Piece& piece, Placement& placement);
    bool canPlay(PiecesSet& piecesSet, Color& color);
};

#endif //BLOKUS_BOARD_H
