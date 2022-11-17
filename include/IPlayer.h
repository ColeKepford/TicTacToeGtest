#ifndef INCLUDE_IPLAYER_H_
#define INCLUDE_IPLAYER_H_

class IPlayer {
    public:
        char letter;
        int playerNum;
        enum type;

        virtual void clickTile(int x, int y, char letter) = 0;
};
#endif  // INCLUDE_IPLAYER_H_
