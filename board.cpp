#include "board.h"
#include "color.h"
#include "coordinate.h"
#include "pieces_set.h"

Board::Board() {
  for (int i=0; i<Board::SIZE; i++) {
    for (int j=0; j<Board::SIZE; j++) {
      this->playBoard[i][j] = Empty;
    }
  }
}

Color& Board::at(int x, int y) {
  return this->playBoard[Board::SIZE - 1 - x][y];
}

bool Board::canPlace(PiecesSet& piecesSet, Piece& piece, Placement& placement) {
  // 1. On regarde d'abord si le placement est dans le plateau
  if (!placement.isValid(&piece)) {
    return false;
  }

  // Dans le cas ou la liste de pieces du joueur est a sa taille maximale, cela veut dire qu'il n'a pas encore joué et que c'est donc le premier tour du jeu
  if (piecesSet.getPiecesList().size() == PiecesSet::SET_SIZE) {
    // On teste donc si la piece placée recouvre au moins un des 4 coins du plateau
    std::vector<Coordinate> targetPosition = placement.calculateTransformation(placement.calculatePosition(piece.getSquares()));
    Coordinate corners[4] = {
      {0, 0},
      {0, 19},
      {19, 0},
      {19, 19} 
    };

    for (const Coordinate& c : targetPosition) {
      for (int i = 0; i < 4; i++) {
        if (c.x == corners[i].x && c.y == corners[i].y) {
          if (this->at(c.x, c.y) == Empty) {
            return true;
          } else {
            return false;
          }
        }
      }
    }

    return false;
  } else {
    // Dans ce cas, on est plus au premier tour et les règles de base s'appliquent donc
    std::vector<Coordinate> targetPosition = placement.calculateTransformation(placement.calculatePosition(piece.getSquares()));

    // On vérifie d'abord si l'espace recouvert par la piece est disponible/vide
    for (const Coordinate& c : targetPosition) {
      if (this->at(c.x, c.y) != Empty) {
        return false;
      }
    }

    // On check les diagonales et côtés adjacents
    bool foundDiag = false;

    int dx[8] = {-1, -1, 1, 1, -1, 1, 0, 0};
    int dy[8] = {-1, 1, -1, 1, 0, 0, -1, 1};
    bool isDiagonal[8] = {true, true, true, true, false, false, false, false};

    for (const Coordinate& c : targetPosition) {
      for (int i = 0; i < 8; i++) {
        Coordinate n = {c.x + dx[i], c.y + dy[i]};

        if (n.x < 0 || n.x >= Board::SIZE || n.y < 0 || n.y >= Board::SIZE) {
          continue;
        }

        bool alreadyInTarget = false;
        for (const Coordinate& t : targetPosition) {
          if (n == t) {
            alreadyInTarget = true;
            break;
          }
        }

        if (alreadyInTarget) {
          continue;
        }

        if (this->at(n.x, n.y) == placement.getColor()) {
          if (isDiagonal[i]) {
            foundDiag = true;
          } else {
            return false; 
          }
        }
      }
    }

    if (!foundDiag) {
      return false;
    }

    return true;
  }

}