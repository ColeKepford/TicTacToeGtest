#include <string>
#include "pch.h"
#include "../include/TicTacToeGame.h"
#include "../include/ComputerPlayer.h"
#include "MockTicTacToeGame.h"

class PlayerTests :public::testing::Test {
protected:
    ComputerPlayer player;
    MockTicTacToeGame game;

    void SetUp() override {
    }

    void TearDown() override {
    }
};

TEST_F(PlayerTests, testLetterX) {
    player = ComputerPlayer('X', 2, "easy");
    EXPECT_EQ('X', player.getLetter());
}

TEST_F(PlayerTests, testLetterO) {
    player = ComputerPlayer('O', 2, "easy");
    EXPECT_EQ('O', player.getLetter());
}

TEST_F(PlayerTests, testLetterx) {
    player = ComputerPlayer('x', 2, "easy");
    EXPECT_EQ('X', player.getLetter());
}

TEST_F(PlayerTests, testLettero) {
    player = ComputerPlayer('O', 2, "easy");
    EXPECT_EQ('O', player.getLetter());
}

TEST_F(PlayerTests, testInvalidLetterA) {
    try {
        player = ComputerPlayer('A', 2, "easy");
    }
    catch (std::invalid_argument& e) {
        EXPECT_STREQ("Invalid letter", e.what());
    }
}

TEST_F(PlayerTests, testInvalidLetter) {
    try {
        player = ComputerPlayer('%', 2, "easy");
    }
    catch (std::invalid_argument& e) {
        std::string message = e.what();
        EXPECT_EQ("Invalid letter", message);
    }
}

TEST_F(PlayerTests, testInvalidLetterChar) {
    try {
        player = ComputerPlayer('%', 2, "easy");
    }
    catch (std::invalid_argument& e) {
        std::string message = e.what();
        EXPECT_EQ("Invalid letter", message);
    }
}

TEST_F(PlayerTests, testClickTile) {
    player = ComputerPlayer('X', 2, "easy");
    MockTicTacToeGame * game2 = new MockTicTacToeGame();
    player.clickTile(1, 1, game2);
    EXPECT_EQ(game2->getBoard()[1][1], 'X');
    delete game2;
}

TEST_F(PlayerTests, testGetMethods) {
    player = ComputerPlayer('O', 1, "easy");
    EXPECT_EQ('O', player.getLetter());
    EXPECT_EQ(1, player.getPlayerNum());
    EXPECT_EQ("computer", player.getType());
    EXPECT_EQ("easy", player.getDifficulty());
}