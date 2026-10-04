#include "player.h"
#include "color.h"
#include "piece.h"
#include "pieces_set.h"

Player::Player(){
    color = Empty;
}

Color Player::getColor() const{
    return color;
}

PiecesSet Player::getPlayerPieceList() const{
    return playerPieceList;
}

std::optional<Piece> Player::getLastPiecePlayed() const{
    return lastPiecePlayed;
}

void Player::play(Piece piece){
    playerPieceList.remove(piece);
    lastPiecePlayed = piece;
}
