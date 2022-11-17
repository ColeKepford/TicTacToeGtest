#include "pch.h"
#include "../include/TicTacToeGame.h"

class GameTests :public::testing::Test {
    protected:
        TicTacToeGame game;
        std::vector<int> board;

        void SetUp() override {

        }

        void TearDown() override {

        }
};

TEST_F(GameTests, TestCreateBoardSize3) {
    game = TicTacToeGame();
    board = game.createBoard(3);
    EXPECT_EQ(9, board.size());
}

TEST_F(GameTests, TestCreateBoardSize100) {
    TicTacToeGame game = TicTacToeGame();
    std::vector<int> board = game.createBoard(10);
    EXPECT_EQ(100, board.size());
}

TEST_F(GameTests, TestCreateBoardSizeZero) {
    TicTacToeGame game = TicTacToeGame();
    std::vector<int> board = game.createBoard(0);
    EXPECT_EQ(0, board.size());
}

TEST_F(GameTests, TestCreateBoardSizeNegative) {
    game = TicTacToeGame();
    board = game.createBoard(-1);
    EXPECT_EQ(0, board.size());
}

TEST_F(GameTests, TestModifyTileValid) {

}

