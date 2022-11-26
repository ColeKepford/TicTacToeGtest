#include "IPlayer.h"
#include "IBoardGame.h"
#include "TicTacToeGame.h"
#include "ComputerPlayer.h"
#include "HumanPlayer.h"
#include <iostream>

/*
* Empty main class to check if project compiles
*/
int main(int argc, char** argv) {
    ComputerPlayer player = ComputerPlayer('X', 2, "computer", "easy");
    std::cout << "\n\n\n\n\nLETTER: " + player.getLetter();
    return 0;
}