#pragma once
#include "../include/IBoardGame.h"
class MockTicTacToeGame : public IBoardGame {
	public:
		std::vector<std::vector<char>> board;

        MockTicTacToeGame() {
            createBoard(9);
        }

        void assignPlayer(IPlayer* player) {

        }

        int checkEnd() {
            return NULL;
        }

        void createBoard(int size) {
            std::vector<std::vector<char>> matrix
                { { 'N', 'N', 'N'},
                { 'N', 'N', 'N'},
                { 'N', 'N', 'N'}};
            board = matrix;
       }

       void endGame() {

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

        int getCurrentPlayerNum() {
            return -1;
        }

        int getTurn() {
            return -1;
        }

        std::pair<IPlayer*, IPlayer*> getPlayers() {
            return std::pair<IPlayer*, IPlayer*>(nullptr, nullptr);
        }

        void setBoard(std::vector <std::vector<char>> board) {
            
        }

        void setPlayers(std::pair<IPlayer*, IPlayer*> i_player) {

};
};