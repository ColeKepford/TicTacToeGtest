#ifndef INCLUDE_COMPUTERPLAYER_H_
#define INCLUDE_COMPUTERLAYER_H_
#include "IPlayer.h"
#include <string>
class ComputerPlayer : private IPlayer {
public:
    void clickTile(int x, int y, char letter);

    std::string getDifficulty();

    char getLetter();

    int getPlayerNum();

    std::string getType();

    void setLetter(char letter);

    void setPlayerNum();

private:
    std::string difficulty;
};
#endif