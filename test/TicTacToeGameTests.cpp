#include "pch.h"
#include "../include/TicTacToeGame.h"
#include"MockHumanPlayer.h"
#include"MockComputerPlayer.h"
#include <memory>

class GameTests : public ::testing::Test {
    protected:
        std::unique_ptr<TicTacToeGame> game;
        std::unique_ptr<IPlayer> human;
        std::unique_ptr<IPlayer> computer;

        void SetUp() override {
            game.reset(new TicTacToeGame);
        }

        void TearDown() override {
            
        }
};
TEST_F(GameTests, testAssignPlayerNotNull) {
    try {
        human.reset(new MockHumanPlayer());
        game.get()->assignPlayer(std::move(human));
    }
    catch (std::invalid_argument& e) {
        std::cerr << e.what() << std::endl;
        FAIL();
    }
}

TEST_F(GameTests, testAssignPlayerNull) {
    human.reset();
    try {
        game.get()->assignPlayer(std::move(human));
    }
    catch (std::invalid_argument& e) {
        std::string message = e.what();
        EXPECT_EQ("Null player!", message);
    }
}

TEST_F(GameTests, testCheckEndNotOver) {
    EXPECT_EQ(-1, game.get()->checkEnd());
}
TEST_F(GameTests, testCheckEndOverWithXsBottomRow) {
    game.get()->modifyTile(2, 0, 'X');
    game.get()->modifyTile(2, 1, 'X');
    game.get()->modifyTile(2, 2, 'X');

    EXPECT_EQ(2, game.get()->checkEnd());
}

TEST_F(GameTests, testCheckEndOverWithOsBottomRow) {
    game.get()->modifyTile(2, 0, 'O');
    game.get()->modifyTile(2, 1, 'O');
    game.get()->modifyTile(2, 2, 'O');

    EXPECT_EQ(1, game.get()->checkEnd());
}
TEST_F(GameTests, testCheckEndOverWithXsMiddleColumn) {
    game.get()->modifyTile(0, 1, 'X');
    game.get()->modifyTile(1, 1, 'X');
    game.get()->modifyTile(2, 1, 'X');

    EXPECT_EQ(2, game.get()->checkEnd());
}

TEST_F(GameTests, testCheckEndOverWithOsMiddleColumn) {
    game.get()->modifyTile(0, 1, 'O');
    game.get()->modifyTile(1, 1, 'O');
    game.get()->modifyTile(2, 1, 'O');

    EXPECT_EQ(1, game.get()->checkEnd());
}

TEST_F(GameTests, testCheckEndOverWithOsDiagonalRight) {
    game.get()->modifyTile(0, 0, 'O');
    game.get()->modifyTile(1, 1, 'O');
    game.get()->modifyTile(2, 2, 'O');

    EXPECT_EQ(1, game.get()->checkEnd());
}

TEST_F(GameTests, testCheckEndOverWithXsDiagonalRight) {
    game.get()->modifyTile(0, 0, 'X');
    game.get()->modifyTile(1, 1, 'X');
    game.get()->modifyTile(2, 2, 'X');

    EXPECT_EQ(2, game.get()->checkEnd());
}

TEST_F(GameTests, testCheckEndOverWithDrawFullBoard) {
    human.reset(new MockHumanPlayer());
    computer.reset(new MockComputerPlayer());
    game.get()->assignPlayer(std::move(human));
    game.get()->assignPlayer(std::move(computer));
    for (int i = 0; i < 9; i++) {
        game.get()->endTurn();
    }
    
    EXPECT_EQ(0, game.get()->checkEnd());
}

TEST_F(GameTests, TestCreateBoardSize3) {
    game.get()->createBoard(3);
    std::vector<std::vector<char>> board = game.get()->getBoard();
    EXPECT_EQ(9, game.get()->getBoardSize());
    char letter;
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[i].size(); j++) {
            letter = board[i][j];
            EXPECT_EQ('N', letter);
        }
    }
}

TEST_F(GameTests, TestCreateBoardSize2) {
    try {
        game.get()->createBoard(2);
    }
    catch (std::invalid_argument& e) {
        std::string message = e.what();
        EXPECT_EQ("Invalid size.", message);
    }
}

TEST_F(GameTests, TestCreateBoardSize100) {
    try {
        game.get()->createBoard(100);
    }
    catch (std::invalid_argument& e) {
        std::string message = e.what();
        EXPECT_EQ("Invalid size.", message);
    }
}

TEST_F(GameTests, TestCreateBoardSizeZero) {
    try {
        game.get()->createBoard(0);
    }
    catch (std::invalid_argument& e) {
        std::string message = e.what();
        EXPECT_EQ("Invalid size.", message);
    }
}

TEST_F(GameTests, TestCreateBoardSizeNegative) {
    try {
        game.get()->createBoard(-1);
    }
    catch (std::invalid_argument& e) {
        std::string message = e.what();
        EXPECT_EQ("Invalid size.", message);
    }
}

TEST_F(GameTests, TestEndTurn1) {
    human.reset(new MockHumanPlayer());
    computer.reset(new MockComputerPlayer());
    game.get()->assignPlayer(std::move(human));
    game.get()->assignPlayer(std::move(computer));
    int turn = game.get()->getTurn();
    char letter = game.get()->getCurrentLetter();
    game.get()->endTurn();
    EXPECT_NE(turn, game.get()->getTurn());
    EXPECT_NE(letter, game.get()->getCurrentLetter());
    EXPECT_EQ(2, game.get()->getTurn());
}

TEST_F(GameTests, TestEndTurn2) {
    human.reset(new MockHumanPlayer());
    computer.reset(new MockComputerPlayer());
    game.get()->assignPlayer(std::move(human));
    game.get()->assignPlayer(std::move(computer));
    int turn = game.get()->getTurn();
    char letter = game.get()->getCurrentLetter();
    game.get()->endTurn();
    game.get()->endTurn();
    EXPECT_NE(turn, game.get()->getTurn());
    EXPECT_EQ(letter, game.get()->getCurrentLetter());
    EXPECT_EQ(3, game.get()->getTurn());
}

TEST_F(GameTests, TestEndTurn3) {
    human.reset(new MockHumanPlayer());
    computer.reset(new MockComputerPlayer());
    game.get()->assignPlayer(std::move(human));
    game.get()->assignPlayer(std::move(computer));
    int turn = game.get()->getTurn();
    char letter = game.get()->getCurrentLetter();
    game.get()->endTurn();
    game.get()->endTurn();
    game.get()->endTurn();
    EXPECT_NE(turn, game.get()->getTurn());
    EXPECT_NE(letter, game.get()->getCurrentLetter());
    EXPECT_EQ('O', game.get()->getCurrentLetter());
    EXPECT_EQ(4, game.get()->getTurn());
}

TEST_F(GameTests, TestModifyTileValid) {
    try {
        game.get()->modifyTile(1, 1, 'X');
        char X = game.get()->getBoard()[1][1];
        EXPECT_EQ('X', X);
    }
    catch (std::invalid_argument& e) {
        std::cout << e.what();
    }
}

TEST_F(GameTests, TestModifyTileValid2) {
    try {
        game.get()->modifyTile(2, 2, 'O');
        char O = game.get()->getBoard()[2][2];
        EXPECT_EQ('O', O);
    }
    catch (std::invalid_argument& e) {
        std::cout << e.what();
    }
}

TEST_F(GameTests, TestModifyTileNegativeX) {
    try {
        game.get()->modifyTile(-1, 2, 'O');
    }
    catch (std::invalid_argument& e) {
        std::string message = e.what();
        EXPECT_EQ("Invalid coordinate.", message);
    }
}

TEST_F(GameTests, TestModifyTileNegativeY) {
    try {
        game.get()->modifyTile(2, -1, 'O');
    }
    catch (std::invalid_argument& e) {
        std::string message = e.what();
        EXPECT_EQ("Invalid coordinate.", message);
    }
}

TEST_F(GameTests, TestModifyTileTooLargeX) {
    try {
        game.get()->modifyTile(5, 2, 'O');
    }
    catch (std::invalid_argument& e) {
        std::string message = e.what();
        EXPECT_EQ("Invalid coordinate.", message);
    }
}

TEST_F(GameTests, TestModifyTileTooLargeY) {
    try {
        game.get()->modifyTile(2, 5, 'O');
    }
    catch (std::invalid_argument& e) {
        std::string message = e.what();
        EXPECT_EQ("Invalid coordinate.", message);
    }
}

TEST_F(GameTests, TestModifyTileInvalidChar) {
    try {
        game.get()->modifyTile(2, 1, 'J');
    }
    catch (std::invalid_argument& e) {
        std::string message = e.what();
        EXPECT_EQ("Invalid character.", message);
    }
}