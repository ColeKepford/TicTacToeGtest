#pragma once
#include "IPlayer.h"
#include "IBoardGame.h"

class HumanPlayer : public IPlayer {
  public:
    HumanPlayer(char letter, int playerNum, std::string type);

    void clickTile(int x, int y, char letter, IBoardGame* game);

    char getLetter();

    int getPlayerNum();

    std::string getType();

    void setLetter(char letter);

    void setPlayerNum(int num);
};
