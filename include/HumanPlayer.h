#ifndef INCLUDE_HUMANPLAYER_H_
#define INCLUDE_HUMANPLAYER_H_
#include "IPlayer.h"
class HumanPlayer : private IPlayer {
    public:
        void clickTile(int x, int y, char letter);

        char getLetter();

        int getPlayerNum();

        std::string getType();

        void setLetter(char letter);

        void setPlayerNum();
};
#endif