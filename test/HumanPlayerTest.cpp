#include "pch.h"
#include "../include/TicTacToeGame.h"
#include "MockHumanPlayer.h"
#include "MockComputerPlayer.h"
#include <string>

class PlayerTests :public::testing::Test {
    protected:
        MockHumanPlayer* player;
        char validLetters[4] = {'X', 'x', 'O', 'o'};
        int validPlayerNum[2] = {1, 2};
        string validType[2] = {"Human", "Computer"};

    void SetUp() override {
        player = &MockHumanPlayer;
    }

    void TearDown() override {
        player = NULL;
    }
}

TEST_F(PlayerTests, testAssignLetterX) {
    player.setLetter('X');
    EXPECT_THAT(validLetters, Contains(player.getLetter()));
}

TEST_F(PlayerTests, testAssignLetterO) {
    player.setLetter('O');
    EXPECT_THAT(validLetters, Contains(player.getLetter()));
}

TEST_F(PlayerTests, testAssignLetterInvalid) {
    player.setLetter('A');
    EXPECT_THAT(validLetters, Contains(player.getLetter()));
}

TEST_F(PlayerTests, testAssignLetterNULL) {
    player.setLetter(NULL);
    EXPECT_THAT(validLetters, Contains(player.getLetter()));
}

TEST_F(PlayerTests, testAssignPlayerNum1) {
    player.setPlayerNum(1);
    EXPECT_THAT(validPlayerNum, Contains(player.getPlayerNum()));
}

TEST_F(PlayerTests, testAssignPlayerNum2) {
    player.setPlayerNum(2);
    EXPECT_THAT(validPlayerNum, Contains(player.getPlayerNum()));
}

TEST_F(PlayerTests, testAssignPlayerNumInvalid) {
    player.setPlayerNum(42);
    EXPECT_THAT(validPlayerNum, Contains(player.getPlayerNum()));
}

TEST_F(PlayerTests, testAssignPlayerNumNULL) {
    player.setPlayerNum(NULL);
    EXPECT_THAT(validPlayerNum, Contains(player.getPlayerNum()));
}

TEST_F(PlayerTests, testAssignPlayerTypeHuman) {
    player.setType("Human");
    EXPECT_THAT(validType, Contains(player.getType()));
}

TEST_F(PlayerTests, testAssignPlayerTypeComputer) {
    player.setType("Computer");
    EXPECT_THAT(validType, Contains(player.getType()));
}

TEST_F(PlayerTests, testAssignPlayerTypeInvalid) {
    player.setType("Fish");
    EXPECT_THAT(validType, Contains(player.getType()));
}

TEST_F(PlayerTests, testAssignPlayerTypeNULL) {
    player.setType(NULL);
    EXPECT_THAT(validType, Contains(player.getType()));
}