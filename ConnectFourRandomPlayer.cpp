#include <iostream>
#include "Four_in_a_row.h"



ConnectFourRandomPlayer::ConnectFourRandomPlayer(char symbol, int dimension_x, int dimension_y,ConnectFourBoard& board)
        :Player(symbol),dimension_x(dimension_x),dimension_y(dimension_y),board(board) {
    name = "Random Computer Player";
    cout << "My names is " << name << endl;
    cout<<endl;
}

void ConnectFourRandomPlayer::get_move(int& x,int&y) {
    srand(static_cast<unsigned int>(time(0)));
    x = (int) (rand()% dimension_x);
    y = (int) (rand()% dimension_y);
}
