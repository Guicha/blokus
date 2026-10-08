#include "game.h"
#include <ostream>

Game::Game(UserInterface& ui)
    : board()
    , players{ Player(Blue), Player(Yellow), Player(Red), Player(Green) }
    , turn(0)
    , userinterface(ui)
{
}

Player* Game::findPlayer(Color color){
    for (Player& player : players) {
        if (player.getColor() == color) {
            return &player;
        }
    }
    return nullptr;
}

void Game::nextTurn(){
    turn = (turn + 1) % 4;
}

// Nombre de pièces encore disponibles pour un joueur
int Game::remainingPieces(Color color){
    Player* player = findPlayer(color);
    if (player == nullptr) {
        return 0;
    }
    return player->getPlayerPieceList().size();
}

bool Game::isFinished(){
    for (Player& player : players) {
        Color color = player.getColor();
        PiecesSet pieces = player.getPlayerPieceList();
        if (board.canPlay(pieces, color)) {
            return false;
        }
    }
    return true;
}

int Game::computeScore(Color color){
    Player* player = findPlayer(color);
    if (player == nullptr) {
        return 0;
    }

    PiecesSet remainingPieces = player->getPlayerPieceList();

    if (remainingPieces.listIsEmpty()) {
        auto lastPiece = player->getLastPiecePlayed();
        bool finishedWithMonomino = lastPiece.has_value()
                                  && lastPiece->getSquares().size() == 1;
        return finishedWithMonomino ? 15 : 10;
    }

    int score = 0;
    for (Piece* piece : remainingPieces.getPiecesList()) {
        score -= static_cast<int>(piece->getSquares().size());
    }
    return score;
}

// Renvoie tous les joueurs ayant le score maximal
std::vector<Color> Game::winners(){
    std::vector<Color> winners;
    int bestScore = computeScore(players[0].getColor());
    for (int i = 0 ; i < 4 ; i++) {
        Color color = players[i].getColor();
        int score = computeScore(color);
        if (score > bestScore) {
            bestScore = score;
            winners.clear();
            winners.push_back(color);
        } else if (score == bestScore) {
            winners.push_back(color);
        }
    }
    return winners;
}

void Game::playTurn(Color color){
    Player* player = findPlayer(color);

    userinterface.getMessageOutput()
        << "==== NOUVEAU TOUR : C'est au tour du joueur " << color << " ====\n";

    PiecesSet piecesForCheck = player->getPlayerPieceList();
    if (!board.canPlay(piecesForCheck, color)) {
        userinterface.getMessageOutput()
            << "Ce joueur ne peut plus jouer, tour passe.\n";
        return;
    }

    bool placed = false;
    while (!placed) {
        userinterface.displayBoard(board);

        // Copie des pièces disponibles pour l'interface et la validation
        PiecesSet availablePieces = player->getPlayerPieceList();
        PiecesSet::PieceIterator pieceIt = userinterface.getPiece(availablePieces, color);
        if (pieceIt == availablePieces.end()) {
            userinterface.getMessageOutput() << "Numéro de pièce invalide, recommencez.\n";
            continue;
        }
        Piece& piece = **pieceIt; // *pieceIt -> Piece* ; ** -> Piece&

        Transformation transformation = userinterface.getTransformation(&piece, color);
        Coordinate origin = userinterface.getPosition();

        std::string error = board.place(availablePieces, piece, transformation, origin, color);

        if (error.empty()) {
            // Pose validée par le plateau si aucun message n'est renvoyé
            player->play(piece);
            placed = true;
        } else {
            userinterface.getMessageOutput() << error << "\n";
        }
    }

    userinterface.clearMessages();
}
