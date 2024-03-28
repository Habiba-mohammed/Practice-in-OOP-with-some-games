
#include <iostream>
#include <iomanip>
#include"../BoardGame_Classes.hpp"
#include "Tic_Tac_Toe.h"
using namespace std;

Tic_Tac_Board::Tic_Tac_Board() {
    n_rows = n_cols = 5;
    board = new char * [n_rows];
    for (int i = 0; i < n_rows; ++i) {
        board[i] = new char[n_cols];
        for (int j = 0; j < n_cols; ++j) {
            board[i][j] = 0;
        }
    }
}

bool Tic_Tac_Board::update_board(int x, int y, char mark) {
    if (!(x < 0 || x > n_rows - 1 || y < 0 || y > n_cols - 1) && (board[x][y] == 0)) {
        board[x][y] = toupper(mark);
        n_moves++;
        return true;
    }
    else
        return false;
}

void Tic_Tac_Board::display_board() {
    for (int i = 0; i < n_rows; i++) {
        cout << "\n| ";
        for (int j = 0; j < n_cols; j++) {
            cout << "(" << i << "," << j << ")";
            cout << setw(2) << board [i][j] << " |";
        }
        cout << "\n-----------------------------------------------";
    }
    cout << endl;
}

bool Tic_Tac_Board::is_winner() {

    if (n_moves >= 24){
        for (int i = 0; i < n_rows; ++i) {
            for (int j = 0; j < n_cols; ++j) {
                // Main Diagonal
                for (int k : {-2,-1}) {
                    if ((i + k >= 0 && i + k < n_rows) && (j + k >= 0 && j + k < n_cols) && board[i][j] == board[i+k][j+k]){
                        if (board[i][j] == 'X'){
                            x_cnt++;
                        }else if (board[i][j] == 'O'){
                            o_cnt++;
                        }
                    }
                }
                update_scores();
                for (int k : {1,2}) {
                    if ((i + k >= 0 && i + k < n_rows) && (j + k >= 0 && j + k < n_cols) && board[i][j] == board[i+k][j+k]){
                        if (board[i][j] == 'X'){
                            x_cnt++;
                        }else if (board[i][j] == 'O'){
                            o_cnt++;
                        }
                    }
                }
                update_scores();
                for (int k : {-1,1}) {
                    if ((i + k >= 0 && i + k < n_rows) && (j + k >= 0 && j + k < n_cols) && board[i][j] == board[i+k][j+k]){
                        if (board[i][j] == 'X'){
                            x_cnt++;
                        }else if (board[i][j] == 'O'){
                            o_cnt++;
                        }
                    }
                }
                update_scores();
                // Other Diagonal
                for (int k : {-2,-1}) {
                    if ((i + k >= 0 && i + k < n_rows) && (j - k >= 0 && j - k < n_cols) && board[i][j] == board[i+k][j-k]){
                        if (board[i][j] == 'X'){
                            x_cnt++;
                        }else if (board[i][j] == 'O'){
                            o_cnt++;
                        }
                    }
                }
                update_scores();
                for (int k : {1,2}) {
                    if ((i + k >= 0 && i + k < n_rows) && (j - k >= 0 && j - k < n_cols) && board[i][j] == board[i+k][j-k]){
                        if (board[i][j] == 'X'){
                            x_cnt++;
                        }else if (board[i][j] == 'O'){
                            o_cnt++;
                        }
                    }
                }
                update_scores();
                for (int k : {-1,1}) {
                    if ((i + k >= 0 && i + k < n_rows) && (j - k >= 0 && j - k < n_cols) && board[i][j] == board[i+k][j-k]){
                        if (board[i][j] == 'X'){
                            x_cnt++;
                        }else if (board[i][j] == 'O'){
                            o_cnt++;
                        }
                    }
                }
                update_scores();
                // Horizontally
                for (int k : {-2,-1}) {
                    if ((j + k >= 0 && j + k < n_cols) && board[i][j] == board[i][j+k]){
                        if (board[i][j] == 'X'){
                            x_cnt++;
                        }else if (board[i][j] == 'O'){
                            o_cnt++;
                        }
                    }
                }
                update_scores();
                for (int k : {1,2}) {
                    if ((j + k >= 0 && j + k < n_cols) && board[i][j] == board[i][j+k]){
                        if (board[i][j] == 'X'){
                            x_cnt++;
                        }else if (board[i][j] == 'O'){
                            o_cnt++;
                        }
                    }
                }
                update_scores();
                for (int k : {-1,1}) {
                    if ((j + k >= 0 && j + k < n_cols) && board[i][j] == board[i][j+k]){
                        if (board[i][j] == 'X'){
                            x_cnt++;
                        }else if (board[i][j] == 'O'){
                            o_cnt++;
                        }
                    }
                }
                update_scores();
                // Vertically
                for (int k : {-2,-1}) {
                    if ((i + k >= 0 && i + k < n_rows) && board[i][j] == board[i+k][j]){
                        if (board[i][j] == 'X'){
                            x_cnt++;
                        }else if (board[i][j] == 'O'){
                            o_cnt++;
                        }
                    }
                }
                update_scores();
                for (int k : {1,2}) {
                    if ((i + k >= 0 && i + k < n_rows) && board[i][j] == board[i+k][j]){
                        if (board[i][j] == 'X'){
                            x_cnt++;
                        }else if (board[i][j] == 'O'){
                            o_cnt++;
                        }
                    }
                }
                update_scores();
                for (int k : {-1,1}) {
                    if ((i + k >= 0 && i + k < n_rows) && board[i][j] == board[i+k][j]){
                        if (board[i][j] == 'X'){
                            x_cnt++;
                        }else if (board[i][j] == 'O'){
                            o_cnt++;
                        }
                    }
                }
                update_scores();
            }
        }
        n_moves++;
    }
    return false;
}

bool Tic_Tac_Board::game_is_over() {
    if (!is_draw() && n_moves >= 24){
        cout <<"\nx: " << x_score << " o: " << o_score << "\n";
        if (x_score > o_score){
            cout << "Player 1 wins!\n";
        }else if (x_score < o_score){
            cout << "Player 2 wins!\n";
        }else{
            cout << "Draw!\n";
        }
    }

    return (n_moves >= 24);
}

bool Tic_Tac_Board::is_draw() {
    return (n_moves >= 24 && x_score == o_score);
}

void Tic_Tac_Board::update_scores() {
    if (x_cnt >= 2){
        x_score++;
    }
    x_cnt = 0;
    if (o_cnt >= 2){
        o_score++;
    }
    o_cnt = 0;
}
