
#include"../include/IPlayer.h"
#include"../include/IBoardGame.h"
class MockHumanPlayer : private IPlayer {
    public:
        int clickCounter = 0;
        char letter = 'X';
        void clickTile(int x, int y, char letter, IBoardGame* game) {
            if (clickCounter == 0) {
                game->modifyTile(1,1,)
            }
        }
};