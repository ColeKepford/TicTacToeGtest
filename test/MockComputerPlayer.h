#pragma once
#ifndef INCLUDE_MOCKCOMPUTERPLAYER_H_
#define INCLUDE_MOCKCOMPUTERLAYER_H_
#include"../include/IPlayer.h"
#include"../include/IBoardGame.h"
class MockComputerPlayer : public IPlayer {
    void clickTile(int x, int y, char letter, IBoardGame* game) {

    }

    char getLetter() {

     }

    int getPlayerNum() {

    }

    std::string getType() {

    }

    void setLetter(char letter) {

    }

    void setPlayerNum() {

    }
};
#endif