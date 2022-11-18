#pragma once
#ifndef INCLUDE_HUMANPLAYER_H_
#define INCLUDE_HUMANPLAYER_H_
#include "IPlayer.h"
#include "IBoardGame.h"
class HumanPlayer : private IPlayer {
    public:

        HumanPlayer(char letter, int playerNum, std::string type);

        void clickTile(int x, int y, char letter, IBoardGame* game);

        char getLetter();

        int getPlayerNum();

        std::string getType();
};
#endif