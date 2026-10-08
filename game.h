#ifndef BLOKUS_GAME_H
#define BLOKUS_GAME_H

#include <vector>

#include "board.h"
#include "player.h"
#include "user_interface.h"

class Game
{
private:
    Board board;
    Player players[4];
    int turn;
    UserInterface& userinterface;

    Player* findPlayer(Color color);

public:
    Game(UserInterface& ui);
    void nextTurn();
    bool isFinished();
    int computeScore(Color color);
    std::vector<Color> winners();
    	void playTurn(Color color);
    	int remainingPieces(Color color);

};

#endif //BLOKUS_GAME_H
