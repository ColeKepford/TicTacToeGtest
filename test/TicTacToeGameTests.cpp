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
            computer = &MockComputerPlayer();
            human = &MockHumanPlayer();
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
    std::vector<char, char> board = game.getBoard();
    EXPECT_EQ(9, board.size());
    char letter;
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board.size(); j++) {
            letter = board[i, j];
            EXPECT_EQ('N', letter);
        }
    }
}

TEST_F(GameTests, TestCreateBoardSize2) {
    try {
        game.createBoard(2);
    }
    catch (std::invalid_argument& e) {
        EXPECT_EQ("Invalid size.", e.what());
    }
}

TEST_F(GameTests, TestCreateBoardSize100) {
    try {
        game.createBoard(100);
    }
    catch (std::invalid_argument& e) {
        EXPECT_EQ("Invalid size.", e.what());
    }
}

TEST_F(GameTests, TestCreateBoardSizeZero) {
    try {
        game.createBoard(0);
    }
    catch (std::invalid_argument& e) {
        EXPECT_EQ("Invalid size.", e.what());
    }
}

TEST_F(GameTests, TestCreateBoardSizeNegative) {
    try {
        game.createBoard(-1);
    }
    catch (std::invalid_argument& e) {
        EXPECT_EQ("Invalid size.", e.what());
    }
}

TEST_F(GameTests, TestEndTurn1) {
    int turn = game.getTurn();
    int playerNum = game.getCurrentPlayerNum();
    game.endTurn();
    EXPECT_NE(turn, game.getTurn());
    EXPECT_NE(playerNum, game.getCurrentPlayerNum());
    EXPECT_EQ(2, game.getTurn());
}

TEST_F(GameTests, TestEndTurn2) {
    int turn = game.getTurn();
    int playerNum = game.getCurrentPlayerNum();
    game.endTurn();
    game.endTurn();
    EXPECT_NE(turn, game.getTurn());
    EXPECT_EQ(playerNum, game.getCurrentPlayerNum());
    EXPECT_EQ(3, game.getTurn());
}

TEST_F(GameTests, TestEndTurn3) {
    int turn = game.getTurn();
    int playerNum = game.getCurrentPlayerNum();
    game.endTurn();
    game.endTurn();
    game.endTurn();
    EXPECT_NE(turn, game.getTurn());
    EXPECT_NE(playerNum, game.getCurrentPlayerNum());
    EXPECT_EQ(2, game.getCurrentPlayerNum());
    EXPECT_EQ(4, game.getTurn());
}

TEST_F(GameTests, TestModifyTileValid) {
    try {
        game.modifyTile(1, 1, 'X');
        char X = game.getBoard()[1, 1];
        EXPECT_EQ('X', X);
    }
    catch (std::invalid_argument& e) {

    }
}

TEST_F(GameTests, TestModifyTileValid2) {
    try {
        game.modifyTile(2, 2, 'O');
        char O = game.getBoard()[1, 1];
        EXPECT_EQ('O', O);
    }
    catch (std::invalid_argument& e) {

    }
}

TEST_F(GameTests, TestModifyTileNegativeX) {
    try {
        game.modifyTile(-1, 2, 'O');
    }
    catch (std::invalid_argument& e) {
        EXPECT_EQ("Invalid coordinate.", e.what());
    }
}

TEST_F(GameTests, TestModifyTileNegativeY) {
    try {
        game.modifyTile(2, -1, 'O');
    }
    catch (std::invalid_argument& e) {
        EXPECT_EQ("Invalid coordinate.", e.what());
    }
}

TEST_F(GameTests, TestModifyTileTooLargeX) {
    try {
        game.modifyTile(5, 2, 'O');
    }
    catch (std::invalid_argument& e) {
        EXPECT_EQ("Invalid coordinate.", e.what());
    }
}

TEST_F(GameTests, TestModifyTileTooLargeY) {
    try {
        game.modifyTile(2, 5, 'O');
    }
    catch (std::invalid_argument& e) {
        EXPECT_EQ("Invalid coordinate.", e.what());
    }
}

TEST_F(GameTests, TestModifyTileInvalidChar) {
    try {
        game.modifyTile(2, 5, 'J');
    }
    catch (std::invalid_argument& e) {
        EXPECT_EQ("Invalid character.", e.what());
    }
}

