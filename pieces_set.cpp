#include "pieces_set.h"

//Static initialisation
Piece PiecesSet::all_pieces[21] = {
    // 1-square piece
    Piece({{0, 0}}),
    // 2-square piece
    Piece({{0, 0}, {1, 0}}),
    // 3-square pieces
    Piece({{0, 0}, {1, 0}, {2, 0}}),
    Piece({{0, 0}, {1, 0}, {0, 1}}),
    // 4-square pieces
    Piece({{0, 0}, {1, 0}, {2, 0}, {3, 0}}),
    Piece({{0, 0}, {1, 0}, {0, 1}, {1, 1}}),
    Piece({{0, 0}, {1, 0}, {2, 0}, {0, 1}}),
    Piece({{0, 0}, {1, 0}, {2, 0}, {1, 1}}),
    Piece({{0, 0}, {1, 0}, {1, 1}, {2, 1}}),
    // 5-square pieces
    Piece({{0, 0}, {1, 0}, {2, 0}, {3, 0}, {4, 0}}),
    Piece({{0, 0}, {1, 0}, {2, 0}, {3, 0}, {0, 1}}),
    Piece({{0, 0}, {1, 0}, {2, 0}, {3, 0}, {1, 1}}),
    Piece({{0, 0}, {1, 0}, {2, 0}, {0, 1}, {0, 2}}),
    Piece({{0, 0}, {1, 0}, {2, 0}, {1, 1}, {1, 2}}),
    Piece({{0, 1}, {1, 1}, {2, 1}, {0, 0}, {2, 2}}),
    Piece({{0, 1}, {1, 1}, {2, 1}, {0, 0}, {1, 2}}),
    Piece({{0, 1}, {1, 1}, {2, 1}, {1, 0}, {1, 2}}),
    Piece({{0, 0}, {1, 0}, {2, 0}, {0, 1}, {1, 1}}),
    Piece({{0, 0}, {1, 0}, {2, 0}, {2, 1}, {3, 1}}),
    Piece({{0, 0}, {1, 0}, {1, 1}, {2, 1}, {2, 2}}),
    Piece({{0, 0}, {1, 0}, {2, 0}, {0, 1}, {2, 1}})
};

PiecesSet::PiecesSet() {
    for (int i = 0; i < 21; i++) {
        list_piece[i] = &all_pieces[i];
    }
}

const Piece* PiecesSet::getPiece(int index) const {
    if (0<=index && index<=21){
        return list_piece[index];
    }
    else {
        return nullptr;
    }
}
