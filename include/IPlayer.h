#pragma once
#include <string>
#include "IBoardGame.h"
#include <string>

// forward declaration
class IBoardGame;

class IPlayer {
  public:
    char letter;
    int playerNum;
    std::string type;

    virtual void clickTile(int x, int y, char letter, IBoardGame *game) = 0;

        virtual void clickTile(int x, int y, IBoardGame *game) = 0;

    virtual int getPlayerNum() = 0;

    virtual std::string getType() = 0;

    virtual void setLetter(char letter) = 0;
    
    virtual void setPlayerNum(int num) = 0;
};