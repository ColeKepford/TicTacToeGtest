/**
 * @file IBoardGame.h
 * @author Adam Schlinker (adam.schlinker@uleth.ca)
 * @brief Interface for a 2D board game class.
 * @version 0.1
 * @date 2022-11-13
 *
 * @copyright Copyright (c) 2022
 *
 */

#ifndef INCLUDE_IBOARDGAME_H_
#define INCLUDE_IBOARDGAME_H_

#include "IPlayer.h"
#include <vector>

class IBoardGame {
  public:
    virtual std::vector<char> createBoard(int size) = 0;

    virtual bool modifyTile(int x, int y, char letter) = 0;

    virtual void assignPlayer(IPlayer* player) = 0;

    virtual int checkEnd() = 0;

    virtual void endTurn() = 0;

    virtual void endGame() = 0;

    // destructor?
};
#endif  // INCLUDE_IBOARDGAME_H_
