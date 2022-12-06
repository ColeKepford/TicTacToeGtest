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

#include "../include/IBoardGame.h"

/**
 * @details Mock class for testing purposes
*/
class MockTicTacToeGame : public IBoardGame {
 public:
	std::vector<std::vector<char>> board;

    /**
     * @brief Mock constructor
    */
    MockTicTacToeGame() {
        createBoard(9);
    }

    /**
     * @brief Assign player to letters and numbers
     * 
     * @param player The player to assign
    */
    void assignPlayer(std::unique_ptr<IPlayer> player) {
    }

    /**
     * @brief Check if the game over
     * 
     * @return Return a integer to denote the state of the game
    */
    int checkEnd() {
        return -5;
    }
    
    /**
     * @brief Create a board given a size
     * 
     * @param size The size of the board
    */
    void createBoard(int size) {
        std::vector<std::vector<char>> matrix
            { { 'N', 'N', 'N'},
            { 'N', 'N', 'N'},
            { 'N', 'N', 'N'}};
        board = matrix;
    }

    /**
     * @brief End the current players turn
    */
    void endTurn() {
    }

    /**
     * @brief Modify the specified tile
     * 
     * @param x The x position on the board
     * @param y The y position on the board
     * @param letter The letter to put in the board
    */
    bool modifyTile(int x, int y, char letter) {
        board[x][y] = letter;
        return true;
    }

    /**
     * @brief Get the current board
     * 
     * @return Return the current board
    */
    std::vector<std::vector<char>> getBoard() {
        return board;
    }

    /**
     * @brief Get the board size
     * 
     * @return Return the size of the board
    */
    int getBoardSize() {
        return 9;
    }

    /**
     * @brief Get the current letter
     * 
     * @return Return the current letter
    */
    char getCurrentLetter() {
        return 'N';
    }

    /**
     * @brief Get the current turn counter
     * 
     * @return Return the current turn counter
    */
    int getTurn() {
        return -1;
    }

    /**
     * @brief Set the current board to a given board
     * 
     * @param board The board to replace the current board
    */
    void setBoard(std::vector <std::vector<char>> board) {}
    /**
     * @brief Set the current players
     * 
     * @param i_players The current players
    */
    void setPlayers(std::pair<std::unique_ptr<IPlayer>, std::unique_ptr<IPlayer>> i_players) {}
};
