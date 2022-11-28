#pragma once
#include "IPlayer.h"
#include "IBoardGame.h"
class HumanPlayer : private IPlayer {
    public:
        HumanPlayer();

class HumanPlayer : public IPlayer {
  public:
    HumanPlayer();

    HumanPlayer(char letter, int playerNum, std::string type);

    void clickTile(int x, int y, char letter, IBoardGame* game);

    char getLetter();

        std::string getType();
};
