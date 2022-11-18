#include "ComputerPlayer.h"
#include <list>
#include <vector>

ComputerPlayer::ComputerPlayer(char letter, int playerNum, std::string type, std::string difficulty) {
    this->letter = letter;
    this->playerNum = playerNum;
    this->type = type;
    this->difficulty = difficulty;
}

void ComputerPlayer::clickTile(int x, int y, char letter, IBoardGame* game) {
    game->modifyTile(x, y, this->letter);
}

std::pair<int, int> ComputerPlayer::generateMove(IBoardGame* game) {
    std::vector<char, char> board = game->getBoard();
    std::vector<std::pair<int, int>> moves;
    std::vector<std::pair<int, int>>::iterator p = moves.end();
    if (this->difficulty == "easy") {
        //Calculate possible moves
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board.size(); j++) {
                //add as possible move if tile is null
                if (board[i, j] == 'N') {
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
