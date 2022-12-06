/**
 * @file HumanPlayer.cpp
 * @author Adam Schlinker and Cole Kepford
 * @brief Source code for HumanPlayer class.
 * @version 1.0
 * @date 2022-12-05
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "HumanPlayer.h"
#include <stdexcept>

 /**
  * @brief Implemented default constructor for HumanPlayer
 */
HumanPlayer::HumanPlayer() {
    type = "human";
}

/**
 * @brief Implemented destructor
*/
HumanPlayer::~HumanPlayer() {

}

/**
 * @brief Implemented constructor for HumanPlayer using custom parameters
 *
 * @param letter The letter to be assinged to this player 'X' or 'O'
 * @param playerNum The number of this player X or O
 */
HumanPlayer::HumanPlayer(char iLetter, int playerNum) {
    if (iLetter == 'X' || iLetter == 'x' || iLetter == 'O' || iLetter == 'o') {
        letter = static_cast<char>(toupper(iLetter));
    }
    else {
        letter = 0;
        throw std::invalid_argument("Invalid letter");
    }
    this->playerNum = playerNum;
    this->type = "human";
}

/**
 * @brief Call modifyTile from game to check and modify a tile after it is clicked
 *
 * @param x The x position on the board
 * @param y The y position on the board
 * @param game The board which the game is played on
*/
void HumanPlayer::clickTile(int x, int y, std::shared_ptr<IBoardGame> game) {
    game.get()->modifyTile(x, y, letter);
}

/**
 * @brief Implemented get the letter of the player
 * @return Return the letter of the player
*/
char HumanPlayer::getLetter() {
    return this->letter;
}

/**
 * @brief Implemented get the player number of the player
 * @return Return the player number of the player
*/
int HumanPlayer::getPlayerNum() {
    return this->playerNum;
}

/**
 * @brief Implemented get the type of the player
 * @return Return the type of the player
*/
std::string HumanPlayer::getType() {
    return this->type;
}