#pragma once
#ifndef INCLUDE_MOCKHUMANPLAYER_H_
#define INCLUDE_MOCKHUMANLAYER_H_
#include"../include/IPlayer.h"
#include"../include/IBoardGame.h"
class MockHumanPlayer : public IPlayer {
    public:
        int clickCounter = 0;
        
        MockHumanPlayer() {
            IPlayer:letter = 'X';
            IPLayer:playerNum = 1;
            IPlayer:type = "human";
        }
        
        
        void clickTile(int x, int y, char letter, IBoardGame* game) {
            if (clickCounter == 0) {
                game->modifyTile(1, 1, letter);
            }
            else if (clickCounter == 1) {
                game->modifyTile(0, 1, letter);
            }

            else if (clickCounter == 2) {
                game->modifyTile(2, 1, letter);
            }
            clickCounter++;
        }

        char getLetter() {
            
        }

        int getPlayerNum() {

        }

        std::string getType() {

        }

        void setLetter(char letter) {

        }

        void setPlayerNum() {

        }
};
#endif
