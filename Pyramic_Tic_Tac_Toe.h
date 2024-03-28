//
// Created by Dell on 12/17/2023.
//

#ifndef SRC_PYRAMIC_TIC_TAC_TOE_H
#define SRC_PYRAMIC_TIC_TAC_TOE_H

#include"BoardGame_Classes.hpp"

class Pyramid_X_O_Board:public Board {
public:
    Pyramid_X_O_Board();
    bool update_board (int x, int y, char mark);
    void display_board();
    bool is_winner();
    bool is_draw();
    bool game_is_over();
};

class Pyramid_Random_Player : public Player {

public:
    // Take a symbol and pass it to parent
    Pyramid_Random_Player (char symbol);
    // Generate a random move
    void get_move(int& x, int& y);
};


#endif //SRC_PYRAMIC_TIC_TAC_TOE_H
