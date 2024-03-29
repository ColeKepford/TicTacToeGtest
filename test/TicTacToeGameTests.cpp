/**
 * @file 
 * @author 
 * @brief 
 * @version 
 * @date 
 * 
 * @copyright Copyright (c) 2022
 */

#include <memory>
#include <vector>
#include <string>
#include <utility>

#include "../include/TicTacToeGame.h"
#include"MockHumanPlayer.h"
#include"MockComputerPlayer.h"
#include "./pch.h"

/**
 * @details Tests for TicTacToeGameTests class
*/
class GameTests : public ::testing::Test {
 protected:
    std::unique_ptr<TicTacToeGame> game;
    std::unique_ptr<IPlayer> human;
    std::unique_ptr<IPlayer> computer;

    void SetUp() override {
        game.reset(new TicTacToeGame);
    }

    void TearDown() override {}
};

/**
 * @brief Test to check player is not null
 * 
 * @param GameTests call the GameTests Class to be used
 * @param testAssignPlayerNotNull name of the test
*/
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

/**
 * @brief Test to check when player is null
 * 
 * @param GameTests call the GameTests Class to be used
 * @param testAssignPlayerNull name of the test
*/
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

/**
 * @brief Test to check when game is not over
 * 
 * @param GameTests call the GameTests Class to be used
 * @param testCheckEndNotOver name of the test
*/
TEST_F(GameTests, testCheckEndNotOver) {
    EXPECT_EQ(-1, game.get()->checkEnd());
}

/**
 * @brief Test to check win condition of X on bottom row
 * 
 * @param GameTests call the GameTests Class to be used
 * @param testCheckEndOverWithXsBottomRow name of the test
*/
TEST_F(GameTests, testCheckEndOverWithXsBottomRow) {
    game.get()->modifyTile(2, 0, 'X');
    game.get()->modifyTile(2, 1, 'X');
    game.get()->modifyTile(2, 2, 'X');

    EXPECT_EQ(2, game.get()->checkEnd());
}

/**
 * @brief Test to check win condition of O on bottom row
 * 
 * @param GameTests call the GameTests Class to be used
 * @param testCheckEndOverWithOsBottomRow name of the test
*/
TEST_F(GameTests, testCheckEndOverWithOsBottomRow) {
    game.get()->modifyTile(2, 0, 'O');
    game.get()->modifyTile(2, 1, 'O');
    game.get()->modifyTile(2, 2, 'O');

    EXPECT_EQ(1, game.get()->checkEnd());
}

/**
 * @brief Test to check win condition of X on middle row
 * 
 * @param GameTests call the GameTests Class to be used
 * @param testCheckEndOverWithXsMiddleColumn name of the test
*/
TEST_F(GameTests, testCheckEndOverWithXsMiddleColumn) {
    game.get()->modifyTile(0, 1, 'X');
    game.get()->modifyTile(1, 1, 'X');
    game.get()->modifyTile(2, 1, 'X');

    EXPECT_EQ(2, game.get()->checkEnd());
}

/**
 * @brief Test to check win condition of O on middle row
 * 
 * @param GameTests call the GameTests Class to be used
 * @param testCheckEndOverWithOsMiddleColumn name of the test
*/
TEST_F(GameTests, testCheckEndOverWithOsMiddleColumn) {
    game.get()->modifyTile(0, 1, 'O');
    game.get()->modifyTile(1, 1, 'O');
    game.get()->modifyTile(2, 1, 'O');

    EXPECT_EQ(1, game.get()->checkEnd());
}

/**
 * @brief Test to check win condition of O on diagonal right
 * 
 * @param GameTests call the GameTests Class to be used
 * @param testCheckEndOverWithOsDiagonalRight name of the test
*/
TEST_F(GameTests, testCheckEndOverWithOsDiagonalRight) {
    game.get()->modifyTile(0, 0, 'O');
    game.get()->modifyTile(1, 1, 'O');
    game.get()->modifyTile(2, 2, 'O');

    EXPECT_EQ(1, game.get()->checkEnd());
}

/**
 * @brief Test to check win condition of X on diagonal right
 * 
 * @param GameTests call the GameTests Class to be used
 * @param testCheckEndOverWithXsDiagonalRight name of the test
*/
TEST_F(GameTests, testCheckEndOverWithXsDiagonalRight) {
    game.get()->modifyTile(0, 0, 'X');
    game.get()->modifyTile(1, 1, 'X');
    game.get()->modifyTile(2, 2, 'X');

    EXPECT_EQ(2, game.get()->checkEnd());
}

/**
 * @brief Test to check draw with full board
 * 
 * @param GameTests call the GameTests Class to be used
 * @param testCheckEndOverWithDrawFullBoard name of the test
*/
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

/**
 * @brief Test to create board of size 3
 * 
 * @param GameTests call the GameTests Class to be used
 * @param testCreateBoardSize3 name of the test
*/
TEST_F(GameTests, testCreateBoardSize3) {
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

/**
 * @brief Test to create board of invalid size
 * 
 * @param GameTests call the GameTests Class to be used
 * @param testCreateBoardSize2 name of the test
*/
TEST_F(GameTests, testCreateBoardSize2) {
    try {
        game.get()->createBoard(2);
    }
    catch (std::invalid_argument& e) {
        std::string message = e.what();
        EXPECT_EQ("Invalid size.", message);
    }
}

/**
 * @brief Test to create board of invalid size
 * 
 * @param GameTests call the GameTests Class to be used
 * @param testCreateBoardSize100 name of the test
*/
TEST_F(GameTests, testCreateBoardSize100) {
    try {
        game.get()->createBoard(100);
    }
    catch (std::invalid_argument& e) {
        std::string message = e.what();
        EXPECT_EQ("Invalid size.", message);
    }
}

/**
 * @brief Test to create board of invalid size
 * 
 * @param GameTests call the GameTests Class to be used
 * @param testCreateBoardSizeZero name of the test
*/
TEST_F(GameTests, testCreateBoardSizeZero) {
    try {
        game.get()->createBoard(0);
    }
    catch (std::invalid_argument& e) {
        std::string message = e.what();
        EXPECT_EQ("Invalid size.", message);
    }
}

/**
 * @brief Test to create board of invalid negative size
 * 
 * @param GameTests call the GameTests Class to be used
 * @param testCreateBoardSizeNegative name of the test
*/
TEST_F(GameTests, testCreateBoardSizeNegative) {
    try {
        game.get()->createBoard(-1);
    }
    catch (std::invalid_argument& e) {
        std::string message = e.what();
        EXPECT_EQ("Invalid size.", message);
    }
}

/**
 * @brief Test to check end turn
 * 
 * @param GameTests call the GameTests Class to be used
 * @param testEndTurn1 name of the test
*/
TEST_F(GameTests, testEndTurn1) {
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

/**
 * @brief Test to check end turn
 * 
 * @param GameTests call the GameTests Class to be used
 * @param testEndTurn2 name of the test
*/
TEST_F(GameTests, testEndTurn2) {
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

/**
 * @brief Test to check end turn
 * 
 * @param GameTests call the GameTests Class to be used
 * @param testEndTurn3 name of the test
*/
TEST_F(GameTests, testEndTurn3) {
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

/**
 * @brief Test to modify tile when valid
 * 
 * @param GameTests call the GameTests Class to be used
 * @param testModifyTileValid name of the test
*/
TEST_F(GameTests, testModifyTileValid) {
    try {
        game.get()->modifyTile(1, 1, 'X');
        char X = game.get()->getBoard()[1][1];
        EXPECT_EQ('X', X);
    }
    catch (std::invalid_argument& e) {
        std::cout << e.what();
    }
}

/**
 * @brief Test to modify tile when valid
 * 
 * @param GameTests call the GameTests Class to be used
 * @param testModifyTileValid2 name of the test
*/
TEST_F(GameTests, testModifyTileValid2) {
    try {
        game.get()->modifyTile(2, 2, 'O');
        char O = game.get()->getBoard()[2][2];
        EXPECT_EQ('O', O);
    }
    catch (std::invalid_argument& e) {
        std::cout << e.what();
    }
}

/**
 * @brief Test to modify tile when invalid
 * 
 * @param GameTests call the GameTests Class to be used
 * @param testModifyTileNegativeX name of the test
*/
TEST_F(GameTests, testModifyTileNegativeX) {
    try {
        game.get()->modifyTile(-1, 2, 'O');
    }
    catch (std::invalid_argument& e) {
        std::string message = e.what();
        EXPECT_EQ("Invalid coordinate.", message);
    }
}

/**
 * @brief Test to modify tile when invalid
 * 
 * @param GameTests call the GameTests Class to be used
 * @param testModifyTileNegativeY name of the test
*/
TEST_F(GameTests, testModifyTileNegativeY) {
    try {
        game.get()->modifyTile(2, -1, 'O');
    }
    catch (std::invalid_argument& e) {
        std::string message = e.what();
        EXPECT_EQ("Invalid coordinate.", message);
    }
}

/**
 * @brief Test to modify tile when invalid
 * 
 * @param GameTests call the GameTests Class to be used
 * @param testModifyTileTooLargeX name of the test
*/
TEST_F(GameTests, testModifyTileTooLargeX) {
    try {
        game.get()->modifyTile(5, 2, 'O');
    }
    catch (std::invalid_argument& e) {
        std::string message = e.what();
        EXPECT_EQ("Invalid coordinate.", message);
    }
}

/**
 * @brief Test to modify tile when invalid
 * 
 * @param GameTests call the GameTests Class to be used
 * @param testModifyTileTooLargeY name of the test
*/
TEST_F(GameTests, testModifyTileTooLargeY) {
    try {
        game.get()->modifyTile(2, 5, 'O');
    }
    catch (std::invalid_argument& e) {
        std::string message = e.what();
        EXPECT_EQ("Invalid coordinate.", message);
    }
}

/**
 * @brief Test to modify tile when invalid
 * 
 * @param GameTests call the GameTests Class to be used
 * @param testModifyTileInvalidChar name of the test
*/
TEST_F(GameTests, testModifyTileInvalidChar) {
    try {
        game.get()->modifyTile(2, 1, 'J');
    }
    catch (std::invalid_argument& e) {
        std::string message = e.what();
        EXPECT_EQ("Invalid character.", message);
    }
}
