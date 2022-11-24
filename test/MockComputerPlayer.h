#pragma once
#ifndef INCLUDE_MOCKCOMPUTERPLAYER_H_
#define INCLUDE_MOCKCOMPUTERLAYER_H_
#include"../include/IPlayer.h"
#include"../include/IBoardGame.h"
class MockComputerPlayer : public IPlayer {
    public:
        MockComputerPlayer() {
        this->letter = 'O';
        this->playerNum = 2;
        this->type = "computer";
        }

        void clickTile(int x, int y, char letter, IBoardGame* game) {

        }

        char getLetter() {
            return NULL;
         }

        int getPlayerNum() {
            return NULL;
        }

        std::string getType() {
            return NULL;
        }
};
#endif