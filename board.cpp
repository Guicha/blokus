#include "board.h"
#include "color.h"

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