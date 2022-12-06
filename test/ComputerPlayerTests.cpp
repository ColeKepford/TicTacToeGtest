/**
 * @file 
 * @author 
 * @brief 
 * @version 
 * @date 
 * 
 * @copyright Copyright (c) 2022
 */

#include <string>

#include "../include/TicTacToeGame.h"
#include "../include/ComputerPlayer.h"
#include "MockTicTacToeGame.h"
#include "pch.h"

/**
 * @details Tests for ComputerPlayer class
*/
class ComputerPlayerTests :public::testing::Test {
 protected:
    ComputerPlayer player;
    std::unique_ptr<MockTicTacToeGame> game;

    void SetUp() override {
        game.reset(new MockTicTacToeGame());
    }

    void TearDown() override {}
};

/**
 * @brief Test to check letter = X
 * 
 * @param ComputerPlayerTests call the ComputerPlayer Class to be used
 * @param testLetterX name of the test
*/
TEST_F(ComputerPlayerTests, testLetterX) {
    player = ComputerPlayer('X', 2, "easy");
    EXPECT_EQ('X', player.getLetter());
}

/**
 * @brief Test to check letter = O
 * 
 * @param ComputerPlayerTests call the ComputerPlayer Class to be used
 * @param testLetterO name of the test
*/
TEST_F(ComputerPlayerTests, testLetterO) {
    player = ComputerPlayer('O', 2, "easy");
    EXPECT_EQ('O', player.getLetter());
}

/**
 * @brief Test to check letter = x
 * 
 * @param ComputerPlayerTests call the ComputerPlayer Class to be used
 * @param testLetterx name of the test
*/
TEST_F(ComputerPlayerTests, testLetterx) {
    player = ComputerPlayer('x', 2, "easy");
    EXPECT_EQ('X', player.getLetter());
}

/**
 * @brief Test to check letter = o
 * 
 * @param ComputerPlayerTests call the ComputerPlayer Class to be used
 * @param testLettero name of the test
*/
TEST_F(ComputerPlayerTests, testLettero) {
    player = ComputerPlayer('O', 2, "easy");
    EXPECT_EQ('O', player.getLetter());
}

/**
 * @brief Test to check invalid letter = A
 * 
 * @param ComputerPlayerTests call the ComputerPlayer Class to be used
 * @param testInvalidLetterA name of the test
*/
TEST_F(ComputerPlayerTests, testInvalidLetterA) {
    try {
        player = ComputerPlayer('A', 2, "easy");
    }
    catch (std::invalid_argument& e) {
        EXPECT_STREQ("Invalid letter", e.what());
    }
}

/**
 * @brief Test to check invalid letter = % 
 * 
 * @param ComputerPlayerTests call the ComputerPlayer Class to be used
 * @param testInvalidLetter name of the test
*/
TEST_F(ComputerPlayerTests, testInvalidLetter) {
    try {
        player = ComputerPlayer('%', 2, "easy");
    }
    catch (std::invalid_argument& e) {
        std::string message = e.what();
        EXPECT_EQ("Invalid letter", message);
    }
}

/**
 * @brief Test to check invalid char = %
 * 
 * @param ComputerPlayerTests call the ComputerPlayer Class to be used
 * @param testInvalidLetterChar name of the test
*/
TEST_F(ComputerPlayerTests, testInvalidLetterChar) {
    try {
        player = ComputerPlayer('%', 2, "easy");
    }
    catch (std::invalid_argument& e) {
        std::string message = e.what();
        EXPECT_EQ("Invalid letter", message);
    }
}

/**
 * @brief Test to click tile
 * 
 * @param ComputerPlayerTests call the ComputerPlayer Class to be used
 * @param testClickTile name of the test
*/
TEST_F(ComputerPlayerTests, testClickTile) {
    player = ComputerPlayer('X', 2, "easy");
    std::shared_ptr<IBoardGame> game(new MockTicTacToeGame());
    player.clickTile(1, 1, game);
    EXPECT_EQ(game.get()->getBoard()[1][1], player.getLetter());
}

/**
 * @brief Test to check all the getters
 * 
 * @param ComputerPlayerTests call the ComputerPlayer Class to be used
 * @param testGetMethods name of the test
*/
TEST_F(ComputerPlayerTests, testGetMethods) {
    player = ComputerPlayer('O', 1, "easy");
    EXPECT_EQ('O', player.getLetter());
    EXPECT_EQ(1, player.getPlayerNum());
    EXPECT_EQ("computer", player.getType());
    EXPECT_EQ("easy", player.getDifficulty());
}

/**
 * @brief Test to call a move on an empty board
 * 
 * @param ComputerPlayerTests call the ComputerPlayer Class to be used
 * @param testGenerateMoveEmptyBoard name of the test
*/
TEST_F(ComputerPlayerTests, testGenerateMoveEmptyBoard) {
    
    player = ComputerPlayer('X', 1, "easy");
    MockTicTacToeGame* game2 = new MockTicTacToeGame();
    std::pair<int, int> move = player.generateMove(game2);
    bool inRange = false;
    if (move.first >= 0 && move.first <= 2 && move.second >= 0 && move.second <= 2) {
        inRange = true;
    }
    EXPECT_EQ(true, inRange);
    delete game2;
}

/**
 * @brief Test to call a move when the top row is full 
 * 
 * @param ComputerPlayerTests call the ComputerPlayer Class to be used
 * @param testGenerateMoveTopRowFull name of the test
*/
TEST_F(ComputerPlayerTests, testGenerateMoveTopRowFull) {

    player = ComputerPlayer('X', 1, "easy");
    MockTicTacToeGame* game2 = new MockTicTacToeGame();
    game2->board[0][0] = 'X';
    game2->board[0][1] = 'X';
    game2->board[0][0] = 'O';
    std::pair<int, int> move = player.generateMove(game2);
    bool validMove = false;
    if (game2->board[move.first][move.second] == 'N') {
        validMove = true;
    }
    EXPECT_EQ(true, validMove);
    delete game2;
}

/**
 * @brief Test to call a move when the middle row is full 
 * 
 * @param ComputerPlayerTests call the ComputerPlayer Class to be used
 * @param testGenerateMoveMiddleRowFull name of the test
*/
TEST_F(ComputerPlayerTests, testGenerateMoveMiddleRowFull) {

    player = ComputerPlayer('X', 1, "easy");
    MockTicTacToeGame* game2 = new MockTicTacToeGame();
    game2->board[1][0] = 'X';
    game2->board[1][1] = 'X';
    game2->board[1][0] = 'O';
    std::pair<int, int> move = player.generateMove(game2);
    bool validMove = false;
    if (game2->board[move.first][move.second] == 'N') {
        validMove = true;
    }
    EXPECT_EQ(true, validMove);
    delete game2;
}

/**
 * @brief Test to call a move when the bottom row is full 
 * 
 * @param ComputerPlayerTests call the ComputerPlayer Class to be used
 * @param testGenerateMoveBottomRowFull name of the test
*/
TEST_F(ComputerPlayerTests, testGenerateMoveBottomRowFull) {

    player = ComputerPlayer('X', 1, "easy");
    MockTicTacToeGame* game2 = new MockTicTacToeGame();
    game2->board[2][0] = 'X';
    game2->board[2][1] = 'X';
    game2->board[2][0] = 'O';
    std::pair<int, int> move = player.generateMove(game2);
    bool validMove = false;
    if (game2->board[move.first][move.second] == 'N') {
        validMove = true;
    }
    EXPECT_EQ(true, validMove);
    delete game2;
}

/**
 * @brief Test to call a move when the middle column is full 
 * 
 * @param ComputerPlayerTests call the ComputerPlayer Class to be used
 * @param testGenerateMoveMiddleColumnFull name of the test
*/
TEST_F(ComputerPlayerTests, testGenerateMoveMiddleColumnFull) {

    player = ComputerPlayer('X', 1, "easy");
    MockTicTacToeGame* game2 = new MockTicTacToeGame();
    game2->board[0][1] = 'X';
    game2->board[1][1] = 'X';
    game2->board[2][1] = 'O';
    std::pair<int, int> move = player.generateMove(game2);
    bool validMove = false;
    if (game2->board[move.first][move.second] == 'N') {
        validMove = true;
    }
    EXPECT_EQ(true, validMove);
    delete game2;
}
