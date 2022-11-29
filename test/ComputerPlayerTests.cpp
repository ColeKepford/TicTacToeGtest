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
        player = &ComputerPlayer('X', 2, "easy");
    }

    void TearDown() override {
    }
};

TEST_F(PlayerTests, testLetterX) {
    player = &ComputerPlayer('X', 2, "easy");
    EXPECT_EQ('X', player->getLetter());
}

TEST_F(PlayerTests, testLetterO) {
    player = &ComputerPlayer('O', 2, "easy");
    EXPECT_EQ('O', player->getLetter());
}

TEST_F(PlayerTests, testLetterx) {
    player = &ComputerPlayer('x', 2, "easy");
    EXPECT_EQ('X', player->getLetter());
}

TEST_F(PlayerTests, testLettero) {
    player = &ComputerPlayer('O', 2, "easy");
    EXPECT_EQ('O', player->getLetter());
}

TEST_F(PlayerTests, testInvalidLetterA) {
    try {
        player = &ComputerPlayer('A', 2, "easy");
    }
    catch (std::invalid_argument& e) {
        EXPECT_STREQ("Invalid letter", e.what());
    }
}

TEST_F(PlayerTests, testInvalidLetter) {
    try {
        player = &ComputerPlayer('%', 2, "easy");
    }
    catch (std::invalid_argument& e) {
        std::string message = e.what();
        EXPECT_EQ("Invalid letter", message);
    }
}

TEST_F(PlayerTests, testInvalidLetterChar) {
    try {
        player = &ComputerPlayer('%', 2, "easy");
    }
    catch (std::invalid_argument& e) {
        std::string message = e.what();
        EXPECT_EQ("Invalid letter", message);
    }
}

TEST_F(PlayerTests, testClickTile) {
    ComputerPlayer *player2 = new ComputerPlayer('X', 2, "easy");
    MockTicTacToeGame* game2 = new MockTicTacToeGame();
    player2->clickTile(1, 1, game2);
    EXPECT_EQ(game2->getBoard()[1][1], 'X');
    delete player2;
    delete game2;
}

TEST_F(PlayerTests, testGetMethods) {
    ComputerPlayer* player2 = new ComputerPlayer('O', 1, "easy");
    EXPECT_EQ('O', player2->getLetter());
    EXPECT_EQ(1, player2->getPlayerNum());
    EXPECT_EQ("computer", player2->getType());
    EXPECT_EQ("easy", player2->getDifficulty());
    delete player2;
}