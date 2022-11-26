#include <string>
#include "pch.h"
#include "../include/TicTacToeGame.h"
#include "../include/ComputerPlayer.h"
#include "MockTicTacToeGame.h"

class PlayerTests :public::testing::Test {
protected:
    ComputerPlayer* player;
    MockTicTacToeGame* game;
    char validLetters[4] = { 'X', 'x', 'O', 'o' };
    int validPlayerNum[2] = { 1, 2 };
    std::string validType[2] = { "Human", "Computer" };

    void SetUp() override {
        player = &ComputerPlayer('X', 2, "computer","easy");
    }

    void TearDown() override {
        
    }
};

TEST_F(PlayerTests, testLetterX) {
    player = &ComputerPlayer('X', 2, "computer", "easy");
    EXPECT_EQ('X', player->getLetter());
}

TEST_F(PlayerTests, testLetterO) {
    player = &ComputerPlayer('O', 2, "computer", "easy");
    EXPECT_EQ('O', player->getLetter());
}

TEST_F(PlayerTests, testLetterx) {
    player = &ComputerPlayer('x', 2, "computer", "easy");
    EXPECT_EQ('X', player->getLetter());
    EXPECT_EQ("computer", player->getDifficulty());
}

TEST_F(PlayerTests, testLettero) {
    player = &ComputerPlayer('O', 2, "computer", "easy");
    EXPECT_EQ('O', player->getLetter());
}

TEST_F(PlayerTests, testInvalidLetterA) {
    try {
        player = &ComputerPlayer('A', 2, "computer", "easy");
    }
    catch (std::invalid_argument& e) {
        EXPECT_STREQ("Invalid letter", e.what());
    }
}

TEST_F(PlayerTests, testInvalidLetter) {
    try {
        player = &ComputerPlayer('%', 2, "computer", "easy");
    }
    catch (std::invalid_argument& e) {
        std::string message = e.what();
        EXPECT_EQ("Invalid letter", message);
    }
}

TEST_F(PlayerTests, testInvalidLetterChar) {
    try {
        player = &ComputerPlayer('%', 2, "computer", "easy");
    }
    catch (std::invalid_argument& e) {
        std::string message = e.what();
        EXPECT_EQ("Invalid letter", message);
    }
}

TEST_F(PlayerTests, testValidType) {
    player = &ComputerPlayer('X', 2, "Computer", "easy");
    EXPECT_EQ("computer", player->getType());
}

TEST_F(PlayerTests, testInvalidType) {
    try {
        player = &ComputerPlayer('X', 2, "Human", "easy");
    }
    catch (std::invalid_argument& e) {
        EXPECT_STREQ("Invalid type", e.what());
    }
}

TEST_F(PlayerTests, testInvalidTypeSandwich) {
    try {
        player = &ComputerPlayer('X', 2, "Sandwich", "easy");
    }
    catch (std::invalid_argument& e) {
        EXPECT_STREQ("Invalid type", e.what());
    }
}

TEST_F(PlayerTests, testClickTile) {
    player->clickTile(1, 1, player->getLetter(), game);
    EXPECT_EQ(game->getBoard()[1][1], 'X');
}