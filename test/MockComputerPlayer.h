#pragma once
#include"../include/IPlayer.h"
#include"../include/IBoardGame.h"
class MockComputerPlayer : public IPlayer {
public:
    MockComputerPlayer() {
    letter = 'O';
    playerNum = 2;
    type = "computer";
    }

    void clickTile(int x, int y, std::shared_ptr<IBoardGame> game) {

    }

    char getLetter() {
        return letter;
    }

    int getPlayerNum() {
        return playerNum;
    }

    std::string getType() {
        return type;
    }

    void setLetter(char letter) {

    }

    void setPlayerNum() {

    }
};