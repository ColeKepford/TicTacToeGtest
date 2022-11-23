#include "pch.h"
#include "../include/TicTacToeGame.h"
#include "../include/HumanPlayer.h"
#include <string>

class PlayerTests :public::testing::Test {
    protected:
        HumanPlayer* player;
        char validLetters[4] = {'X', 'x', 'O', 'o'};
        int validPlayerNum[2] = {1, 2};
        std::string validType[2] = {"Human", "Computer"};

    void SetUp() override {
        player = new HumanPlayer();
    }

    void TearDown() override {
        player = NULL;
        delete player;
    }
};

TEST_F(PlayerTests, testAssignLetterX) {
    player.setLetter('X');
    EXPECT_THAT(validLetters, Contains(player->getLetter()));
}

TEST_F(PlayerTests, testAssignLetterO) {
    player.setLetter('O');
    EXPECT_THAT(validLetters, Contains(player->getLetter()));
}

TEST_F(PlayerTests, testAssignLetterInvalid) {
    player.setLetter('A');
    EXPECT_THAT(validLetters, Contains(player->getLetter()));
}

TEST_F(PlayerTests, testAssignLetterNULL) {
    player.setLetter(NULL);
    EXPECT_THAT(validLetters, Contains(player->getLetter()));
}

TEST_F(PlayerTests, testAssignPlayerNum1) {
    player.setPlayerNum(1);
    EXPECT_THAT(validPlayerNum, Contains(player->getPlayerNum()));
}

TEST_F(PlayerTests, testAssignPlayerNum2) {
    player.setPlayerNum(2);
    EXPECT_THAT(validPlayerNum, Contains(player->getPlayerNum()));
}

TEST_F(PlayerTests, testAssignPlayerNumInvalid) {
    player.setPlayerNum(42);
    EXPECT_THAT(validPlayerNum, Contains(player->getPlayerNum()));
}

TEST_F(PlayerTests, testAssignPlayerNumNULL) {
    player.setPlayerNum(NULL);
    EXPECT_THAT(validPlayerNum, Contains(player->getPlayerNum()));
}

TEST_F(PlayerTests, testAssignPlayerTypeHuman) {
    player.setType("Human");
    EXPECT_THAT(validType, Contains(player->getType()));
}
