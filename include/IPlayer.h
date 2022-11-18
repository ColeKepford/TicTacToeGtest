#pragma once
#ifndef INCLUDE_IPLAYER_H_
#define INCLUDE_IPLAYER_H_
#include <string>
#include "IBoardGame.h"

//forward declaration
class IBoardGame;

class IPlayer {
    public:
        char letter;
        int playerNum;
        std::string type;

        virtual void clickTile(int x, int y, char letter, IBoardGame *game) = 0;

        virtual char getLetter() = 0;

        virtual int getPlayerNum() = 0;

        virtual std::string getType() = 0;
};
#endif
