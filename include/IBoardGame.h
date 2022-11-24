#pragma once
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

#include "IPlayer.h"
#include <vector>
//forward declaration
class IPlayer;

class IBoardGame {
public:
    std::vector<std::vector<char>> board;
    std::vector<IPlayer*> players;
    int turn;
    int currentPlayerNum;
    
    virtual void assignPlayer(IPlayer* player) = 0; 

    virtual int checkEnd() = 0;

    virtual void createBoard(int size) = 0; 

    virtual void endGame() = 0;

    virtual void endTurn() = 0;

    virtual bool modifyTile(int x, int y, char letter) = 0;

    virtual std::vector<std::vector<char>> getBoard() = 0;

    virtual int getCurrentPlayerNum() = 0;

    virtual int getTurn() = 0;

    virtual std::vector<IPlayer*> getPlayers() = 0;

    virtual void setBoard(std::vector <std::vector<char>> board) = 0;

    virtual void setPlayers(std::vector<IPlayer*> player) = 0;
};