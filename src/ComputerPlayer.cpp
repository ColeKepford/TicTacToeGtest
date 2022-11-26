#include "ComputerPlayer.h"
#include <list>
#include <vector>
#include <stdexcept>

ComputerPlayer::ComputerPlayer(char letter, int playerNum, std::string type, std::string difficulty) {
    if (letter == 'X' || letter == 'x' || letter == 'O' || letter == 'o') {
        this->letter = (char)toupper(letter);
    }
    else {
        this->letter = NULL;
        throw std::invalid_argument("Invalid letter");
    }
    this->playerNum = playerNum;

    if (type.compare("computer") == 0 || type.compare("Computer") == 0) {
        this->type = "computer";
    }
    else {
        this->type = "";
        throw std::invalid_argument("Invalid type");

    }
    this->difficulty = difficulty;
}

ComputerPlayer::ComputerPlayer() {

}

ComputerPlayer::~ComputerPlayer() {

}

void ComputerPlayer::clickTile(int x, int y, char letter, IBoardGame* game) {
    game->modifyTile(x, y, this->letter);
}

std::pair<int, int> ComputerPlayer::generateMove(IBoardGame* game) {
    std::vector<std::vector<char>> board = game->getBoard();
    std::vector<std::pair<int, int>> moves;
    std::vector<std::pair<int, int>>::iterator p = moves.end();
    if (this->difficulty == "easy") {
        //Calculate possible moves
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board.size(); j++) {
                //add as possible move if tile is null
                if (board[i][j] == 'N') {
                    moves.insert(p, std::pair<int, int>(i, j));
                }
            }
        }
        //Generate random possible move
        int moveIndex = rand() % moves.size();
        return moves[moveIndex];
    }
}

std::string ComputerPlayer::getDifficulty() {
    return this->difficulty;
}

char ComputerPlayer::getLetter() {
    return this->letter;
}

int ComputerPlayer::getPlayerNum() {
    return this->playerNum;
}

std::string ComputerPlayer::getType() {
    return this->type;
}
