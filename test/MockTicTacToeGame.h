#pragma once
#include "../include/IBoardGame.h"
class MockTicTacToeGame : public IBoardGame {
	public:
		std::vector<std::vector<char>> board;

        void assignPlayer(IPlayer* player) {

        }

        int checkEnd() {
            return NULL;
        }

        void createBoard(int size) {
            std::vector<std::vector<char> > matrix(3);
            for (int i = 0; i < 3; i++) {
                matrix[i].resize(3);
            }
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
            return NULL;
        }

        int getTurn() {
            return NULL;
        }

        std::vector<IPlayer*> getPlayers() {
            return std::vector<IPlayer*>(2);
        }

        void setBoard(std::vector <std::vector<char>> board) {
            
        }

        void setPlayers(std::vector<IPlayer*> player) {

};
};