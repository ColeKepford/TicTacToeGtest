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
#include "pch.h"
#include "../include/HumanPlayer.h"
#include "MockTicTacToeGame.h"

/**
 * @details Tests for HumanPlayer class
*/
class HumanPlayerTests :public::testing::Test {
protected:
    HumanPlayer player;
    void SetUp() override {
    }

    void TearDown() override {
    }
};

/**
 * @brief Test to check letter = X
 * 
 * @param HumanPlayerTests call the HumanPlayer Class to be used
 * @param testLetterX name of the test
*/
TEST_F(HumanPlayerTests, testLetterX) {
    HumanPlayer player = HumanPlayer('X', 2);
    EXPECT_EQ('X', player.getLetter());
}

/**
 * @brief Test to check letter = O
 * 
 * @param HumanPlayerTests call the HumanPlayer Class to be used
 * @param testLetterO name of the test
*/
TEST_F(HumanPlayerTests, testLetterO) {
    HumanPlayer player = HumanPlayer('O', 2);
    EXPECT_EQ('O', player.getLetter());
}

/**
 * @brief Test to check letter = x
 * 
 * @param HumanPlayerTests call the HumanPlayer Class to be used
 * @param testLetterx name of the test
*/
TEST_F(HumanPlayerTests, testLetterx) {
    HumanPlayer player = HumanPlayer('x', 2);
    EXPECT_EQ('X', player.getLetter());
}

/**
 * @brief Test to check letter = o
 * 
 * @param HumanPlayerTests call the HumanPlayer Class to be used
 * @param testLettero name of the test
*/
TEST_F(HumanPlayerTests, testLettero) {
    HumanPlayer player = HumanPlayer('O', 2);
    EXPECT_EQ('O', player.getLetter());
}

/**
 * @brief Test to check invalid letter = A
 * 
 * @param HumanPlayerTests call the HumanPlayer Class to be used
 * @param testInvalidLetterA name of the test
*/
TEST_F(HumanPlayerTests, testInvalidLetterA) {
    try {
        player = HumanPlayer('A', 2);
    }
    catch (std::invalid_argument& e) {
        EXPECT_STREQ("Invalid letter", e.what());
    }
}

/**
 * @brief Test to check invalid letter = %
 * 
 * @param HumanPlayerTests call the HumanPlayer Class to be used
 * @param testInvalidLetter name of the test
*/
TEST_F(HumanPlayerTests, testInvalidLetter) {
    try {
        player = HumanPlayer('%', 2);;
    }
    catch (std::invalid_argument& e) {
        std::string message = e.what();
        EXPECT_EQ("Invalid letter", message);
    }
}

/**
 * @brief Test to check invalid char = %
 * 
 * @param HumanPlayerTests call the HumanPlayer Class to be used
 * @param testInvalidLetterChar name of the test
*/
TEST_F(HumanPlayerTests, testInvalidLetterChar) {
    try {
        player = HumanPlayer('%', 2);
    }
    catch (std::invalid_argument& e) {
        std::string message = e.what();
        EXPECT_EQ("Invalid letter", message);
    }
}

/**
 * @brief Test to click tile
 * 
 * @param HumanPlayerTests call the HumanPlayer Class to be used
 * @param testClickTile name of the test
*/
TEST_F(HumanPlayerTests, testClickTile) {
    player = HumanPlayer('X', 2);
    std::shared_ptr<IBoardGame> game(new MockTicTacToeGame());
    player.clickTile(1, 1, game);
    EXPECT_EQ(game.get()->getBoard()[1][1], 'X');
}

/**
 * @brief Test to check all the getters
 * 
 * @param HumanPlayerTests call the HumanPlayer Class to be used
 * @param testGetMethods name of the test
*/
TEST_F(HumanPlayerTests, testGetMethods) {
    HumanPlayer player2 = HumanPlayer('O', 1);
    EXPECT_EQ('O', player2.getLetter());
    EXPECT_EQ(1, player2.getPlayerNum());
    EXPECT_EQ("human", player2.getType());
}