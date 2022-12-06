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

#include <string>
#include <memory>

#include"../include/IPlayer.h"
#include"../include/IBoardGame.h"

/**
 * @details Mock class used for testing purposes
*/
class MockComputerPlayer : public IPlayer {
 public:
    /**
     * @brief Mock constructor
    */
    MockComputerPlayer() {
    letter = 'O';
    playerNum = 2;
    type = "computer";
    }

    /**
     * @brief Mock click tile method
     * 
     * @param x the x position on the board
     * @param y the y position on the board
     * @param game the board itself
    */
    void clickTile(int x, int y, std::shared_ptr<IBoardGame> game) {}

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
    void setLetter(char letter) {}

    /**
     * @brief Set the number of the player
    */
    void setPlayerNum() {}
};
