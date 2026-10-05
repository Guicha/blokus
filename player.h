#ifndef BLOKUS_PLAYER_H
#define BLOKUS_PLAYER_H

#include "color.h"
#include "pieces_set.h"
#include <optional>

class Player
{
private:
    PiecesSet playerPieceList;
    Color color;
    std::optional<Piece> lastPiecePlayed;

public:
    explicit Player(Color color);

    PiecesSet getPlayerPieceList() const;
    Color getColor() const;
    std::optional<Piece> getLastPiecePlayed() const;

    void play(Piece piece);
};

#endif //BLOKUS_PLAYER_H
