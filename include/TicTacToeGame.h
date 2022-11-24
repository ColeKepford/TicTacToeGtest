#pragma once
#include "IBoardGame.h"

class TicTacToeGame : private IBoardGame {

    public:
        void assignPlayer(IPlayer* player);

        int checkEnd();

        void createBoard(int size);

        void endGame();

        void endTurn();

        bool modifyTile(int x, int y, char letter);

        std::vector<std::vector<char>> getBoard();

        int getBoardSize();

        int getCurrentPlayerNum();

        int getTurn();

        std::vector<IPlayer*> getPlayers();

        void setBoard(std::vector<std::vector<char>> board);

        void setPlayers(std::vector<IPlayer*> player);
};