#pragma once
#include "IPlayer.h"
#include "IBoardGame.h"
#include <string>

class ComputerPlayer : public IPlayer {
  public:
    ComputerPlayer(char letter, int playerNum, std::string type, std::string difficulty);

    void clickTile(int x, int y, char letter, IBoardGame* game);

    std::string getDifficulty();

    char getLetter();

    int getPlayerNum();

    std::string getType();

    void setLetter(char letter);

    void setPlayerNum();

  private:
    std::string difficulty;
};
