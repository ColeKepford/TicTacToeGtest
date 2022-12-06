#pragma once
#include "../include/IBoardGame.h"
class MockTicTacToeGame : public IBoardGame {
	public:
		std::vector<std::vector<char>> board;

        MockTicTacToeGame() {
            createBoard(9);
        }

        void assignPlayer(std::unique_ptr<IPlayer> player) {

        }

        int checkEnd() {
            return -5;
        }

        void createBoard(int size) {
            std::vector<std::vector<char>> matrix
                { { 'N', 'N', 'N'},
                { 'N', 'N', 'N'},
                { 'N', 'N', 'N'}};
            board = matrix;
       }

        void endTurn() {

        }

        bool modifyTile(int x, int y, char letter) {
            board[x][y] = letter;
            return true;
        }

        std::vector<std::vector<char>> getBoard() {
            return board;
        }

        int getBoardSize() {
            return 9;
        }

        char getCurrentLetter() {
            return 'N';
        }

        int getTurn() {
            return -1;
        }

        void setBoard(std::vector <std::vector<char>> board) {
            
        }

        void setPlayers(std::pair<std::unique_ptr<IPlayer>, std::unique_ptr<IPlayer>> i_players) {

        }


};