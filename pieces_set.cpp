#include "pieces_set.h"
#include "piece.h"
#include <iostream>

//Static initialisation
Piece PiecesSet::piecesPool[21] = {
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
        piecesList.push_back(&piecesPool[i]);
    }
}

std::vector<Piece*> PiecesSet::getPiecesList() const{
    return piecesList;
}

std::vector<Piece*>::const_iterator PiecesSet::begin() const{
    return piecesList.cbegin();
}

std::vector<Piece*>::const_iterator PiecesSet::end() const{
    return piecesList.cend();
}

bool PiecesSet::ListIsEmpty() const{
    return piecesList.empty();
}

void PiecesSet::remove(Piece &pieceToRemove){
    int i=0;
    // find the element to remove in the list and remove it(by starting count to the first element and count each iteration)
    for (const Piece* p: piecesList) {
        if (p == &pieceToRemove) {
            piecesList.erase(piecesList.begin()+i);
            std::cout<<"Piece deleted"<<std::endl;
            return;
        }
        i++;
    }
    return;
}
