#pragma once
#ifndef INCLUDE_TICTACTOEGAME_H_
#define INCLUDE_TICTACTOEGAME_H_
#include "IBoardGame.h"

class TicTacToeGame : private IBoardGame {

    public:
        void assignPlayer(IPlayer* player);

        int checkEnd();

        void createBoard(int size);

        void endGame();

        void endTurn();

        bool modifyTile(int x, int y, char letter);

        std::vector<char, char> getBoard();

        int getCurrentPlayerNum();

        int getTurn();

        std::vector<IPlayer*> getPlayers();

        void setBoard(std::vector<int> board);

        void setPlayers(std::vector<IPlayer*> player);
};
#endif