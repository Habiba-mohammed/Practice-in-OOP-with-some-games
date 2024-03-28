#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "Four_in_a_row.h"



using namespace std;

ConnectFourPlayer::ConnectFourPlayer(int order,char symbol, ConnectFourBoard& gameBoard)
        : Player(order,symbol), board(gameBoard) {};

void ConnectFourPlayer::get_move(int& x,int&y) {
    cout << "Player " << get_symbol()<<" "<<"("<<name<<")" <<", enter column (1-7): ";
    cin >> y;
    --y;  // Adjust for 0-based indexing
}



