/**
 * @file HumanPlayer.h
 * @author Adam Schlinker & Cole Kepford
 * @brief Class for a human player in a board game
 * @version 1.0
 * @date 2022-12-05
 *
 * @copyright Copyright (c) 2022
 */

#pragma once

#include <string>
#include <memory>

#include "IPlayer.h"
#include "IBoardGame.h"

 /**
  * @details Class for HumanPlayer object
  */
class HumanPlayer : public IPlayer {
 public:
    /**
     * @brief Default constructor for HumanPlayer
    */
    HumanPlayer();

    /**
     * @brief Destructor for HumanPlayer
    */
    ~HumanPlayer();

    /**
     * @brief Consturctor for HumanPlayer using custom parameters
     *
     * @param letter The letter to be assinged to this player 'X' or 'O'
     * @param playerNum The number of this player X or X
    */
    HumanPlayer(char letter, int playerNum);

    /**
     * @brief Method to click a tile on the board
     *
     * @param x The x position on the board
     * @param y The y position on the board
     * @param game The board which the game is played on
    */
    void clickTile(int x, int y, std::shared_ptr<IBoardGame> game);

    /**
     * @brief Get the letter of the player
     * @return Return the letter of the player
    */
    char getLetter();

    /**
     * @brief Get the player number
     * @return Return the player number
    */
    int getPlayerNum();

    /**
     * @brief Get the type of player
     * @return Return the type of player
    */
    std::string getType();
};
