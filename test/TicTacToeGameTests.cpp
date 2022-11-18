#include "pch.h"
#include "../include/TicTacToeGame.h"
#include"../include/HumanPlayer.h"
#include"../include/ComputerPlayer.h"

class GameTests :public::testing::Test {
    protected:
        TicTacToeGame game;
        HumanPlayer human;
        ComputerPlayer computer;

        void SetUp() override {
            game = TicTacToeGame();
            human = 
        }

        void TearDown() override {

        }
};
TEST_F(GameTests, testAssignPlayerNotNull) {
    game.assignPlayer()
}
TEST_F(GameTests, TestCreateBoardSize3) {
    game.createBoard(3);
    EXPECT_EQ(9, game.getBoard().size());
}

TEST_F(GameTests, TestCreateBoardSize100) {
    game.createBoard(10);
    EXPECT_EQ(100, game.getBoard().size());
}

TEST_F(GameTests, TestCreateBoardSizeZero) {
    game.createBoard(0);
    EXPECT_EQ(0, game.getBoard().size());
}

TEST_F(GameTests, TestCreateBoardSizeNegative) {
    game.createBoard(-1);
    EXPECT_EQ(0, game.getBoard().size());
}

TEST_F(GameTests, TestModifyTileValid) {

}

