/**
 * @file IBoardGame.h
 * @author Cole Kepford (cole.kepford@uleth.ca)
 * @brief Interface for a player class.
 * @version 0.1
 * @date 2022-11-17
 *
 * @copyright Copyright (c) 2022
 *
 */
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
