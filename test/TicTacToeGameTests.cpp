#include "pch.h"
#include "../include/TicTacToeGame.h"
#include"MockHumanPlayer.h"
#include"MockComputerPlayer.h"

class GameTests :public::testing::Test {
    protected:
        TicTacToeGame game;
        MockHumanPlayer* human;
        MockComputerPlayer* computer;

        void SetUp() override {
            game = TicTacToeGame();
            human = &MockHumanPlayer();
            computer = &MockComputerPlayer();
        }

        void TearDown() override {

        }
};
TEST_F(GameTests, testAssignPlayerNotNull) {
    try {
        game.assignPlayer(human);
    }
    catch (std::invalid_argument& e) {
        std::cerr << e.what() << std::endl;
        FAIL();
    }
}

TEST_F(GameTests, testAssignPlayerNull) {
    human = 0L;//value of null in c++
    try {
        game.assignPlayer(human);
    }
    catch (std::invalid_argument& e) {
        std::cerr << e.what() << std::endl;
        EXPECT_EQ("Player is null.", e.what());
    }
}

TEST_F(GameTests, testCheckEndNotOver) {
    EXPECT_EQ(-1, game.checkEnd());
}

TEST_F(GameTests, testCheckEndOverWithXs) {
    game.getBoard()[0, 1] = 'X';
    game.getBoard()[1, 1] = 'X';
    game.getBoard()[2, 1] = 'X';

    EXPECT_EQ(1, game.checkEnd());
}

TEST_F(GameTests, testCheckEndOverWithOs) {
    game.getBoard()[0, 1] = 'O';
    game.getBoard()[1, 1] = 'O';
    game.getBoard()[2, 1] = 'O';

    EXPECT_EQ(1, game.checkEnd());
}

TEST_F(GameTests, testCheckEndOverWithDraw) {
    //Column 1
    game.getBoard()[0, 0] = 'O';
    game.getBoard()[1, 0] = 'O';
    game.getBoard()[2, 0] = 'X';
    //Column2
    game.getBoard()[0, 1] = 'X';
    game.getBoard()[1, 1] = 'X';
    game.getBoard()[2, 1] = 'O';
    //Column3
    game.getBoard()[0, 2] = 'O';
    game.getBoard()[1, 2] = 'X';
    game.getBoard()[2, 2] = 'X';

    EXPECT_EQ(0, game.checkEnd());
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

