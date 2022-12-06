/**
 * @file 
 * @author 
 * @brief 
 * @version 
 * @date 
 * 
 * @copyright Copyright (c) 2022
 */

#pragma once

#include"../include/IPlayer.h"
#include"../include/IBoardGame.h"

/**
 * @details Mock class used for testing purposes
*/
class MockHumanPlayer : public IPlayer {
 public:
    int clickCounter = 0;
    /**
     * @brief Mock constructor
    */
    MockHumanPlayer() {
    letter = 'X';
    playerNum = 1;
    type = "human";
    }

    /**
     * @brief Mock click tile method
     * 
     * @param x the x position on the board
     * @param y the y position on the board
     * @param game the board itself
    */
    void clickTile(int x, int y, std::shared_ptr<IBoardGame> game) {
        if (clickCounter == 0) {
            game->modifyTile(1, 1, letter);
        } else if (clickCounter == 1) {
            game->modifyTile(0, 1, letter);
        } else if (clickCounter == 2) {
            game->modifyTile(2, 1, letter);
        }
        clickCounter++;
    }

    /**
     * @brief Get the letter
     * 
     * @return Return the letter
    */
    char getLetter() {
        return letter;
    }

    /**
     * @brief Get the player number
     * 
     * @return Return the player number
    */
    int getPlayerNum() {
        return playerNum;
    }

    /**
     * @brief Get the type of player
     * 
     * @return Returnt the type of player
    */
    std::string getType() {
        return type;
    }

    /**
     * @brief Set the letter of the player
     * 
     * @param letter Used to specify letter
    */
    void setLetter(char letter) {

    }

    /**
     * @brief Set the number of the player
    */
    void setPlayerNum() {

    }
};
