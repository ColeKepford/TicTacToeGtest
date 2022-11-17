#include "pch.h"
#include "../include/TicTacToeGame.h"

class GameTests :public::testing::Test {
    protected:
        TicTacToeGame game;

        void SetUp() override {
            game = TicTacToeGame();
        }

        void TearDown() override {

        }
};

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

