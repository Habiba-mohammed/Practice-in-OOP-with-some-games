

#ifndef CS213_A3_OBJECT_ORIENTED_PROGRAMMING_TIC_TAC_TOE_H
#define CS213_A3_OBJECT_ORIENTED_PROGRAMMING_TIC_TAC_TOE_H

#include"../BoardGame_Classes.hpp"
using namespace std;

class Tic_Tac_Board : public Board{
public:
    Tic_Tac_Board();
    bool update_board (int x, int y, char mark);
    void display_board();
    bool game_is_over();
    bool is_winner();
    bool is_draw();
    void update_scores();
    int x_score = 0;
    int o_score = 0;
    int x_cnt = 0;
    int o_cnt = 0;


};



#endif //CS213_A3_OBJECT_ORIENTED_PROGRAMMING_TIC_TAC_TOE_H
