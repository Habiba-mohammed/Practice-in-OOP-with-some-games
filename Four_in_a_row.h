//
// Created by Abdelaziz Ali on 12/17/2023.
//
#ifndef NEW_FOLDER_4_FOUR_IN_A_ROW_H
#define NEW_FOLDER_4_FOUR_IN_A_ROW_H

#include "BoardGame_Classes.hpp"


class ConnectFourBoard : public Board {
public:
    ConnectFourBoard();
    bool update_board(int x, int y, char symbol) override;
    void display_board() override;
    bool is_winner() override;
    bool is_draw() override;
    bool game_is_over() override;
    char** get_board() const {
        return board;
    }
};
//------------------------------------------------------------------------------

class ConnectFourPlayer : public Player {
public:
    ConnectFourPlayer(int order, char symbol, ConnectFourBoard& gameBoard);
    void get_move(int &x, int &y) override;

private:
    ConnectFourBoard& board;
};
//-----------------------------------------------------------------------------------
class ConnectFourRandomPlayer : public Player {
private:
    int dimension_x; // for rows
    int dimension_y; //  for columns
    ConnectFourBoard& board;
public:
    ConnectFourRandomPlayer(char symbol, int dimension_x, int dimension_y,ConnectFourBoard& board);
    void get_move(int& x , int &y);
};



#endif //NEW_FOLDER_4_FOUR_IN_A_ROW_H
