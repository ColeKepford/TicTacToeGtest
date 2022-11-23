/**
 * @file HumanPlayer.cpp
 * @author Adam Schlinker (adam.schlinker@uleth.ca)
 * @brief Source code for HumanPlayer class.
 * @version 0.1
 * @date 2022-11-22
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "HumanPlayer.h"

HumanPlayer::HumanPlayer(char letter, int playerNum, std::string type) {
    this->letter = letter;
    this->playerNum = playerNum;
    this->type = type;
}

void HumanPlayer::clickTile(int x, int y, char letter, IBoardGame* game) {
    game->modifyTile(x, y, letter);
}

char HumanPlayer::getLetter() {
    return this->letter;
}

int HumanPlayer::getPlayerNum() {
    return this->playerNum;
}

std::string HumanPlayer::getType() {
    return this->type;
}

void HumanPlayer::setLetter(char letter) {
    this->letter = letter;
}

void HumanPlayer::setPlayerNum(int num) {
    this->playerNum = num;
}
