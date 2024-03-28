#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "Four_in_a_row.h"





using namespace std;
ConnectFourBoard::ConnectFourBoard() {
    n_rows = 6;
    n_cols = 7;
    board=new char*[n_rows];
    for(int i{0};i<n_rows;i++){
        board[i]=new char[n_cols];
        for(int j{0};j<n_cols;j++){
            board[i][j]='-';
        }
    }
}


bool ConnectFourBoard::update_board(int x, int y, char symbol) {
    // Check if the move is within the board boundaries and the selected column is not full
    bool found=false;
    if (y >= 0 && y < n_cols ) {
        // Find the lowest empty row in the selected column
        int row;
        for (row = n_rows - 1; row >= 0; --row) {
            if (board[row][y] == '-') {
                found = true;
                break;
            }
        }

        // Make the move
        if (found) {
            board[row][y] = symbol;
            n_moves++;
            return true;
        }
    }
    cout<<"Invalid input\n";
    return false;

}



void ConnectFourBoard::display_board() {
    for (int i = 0; i < n_rows; ++i) {
        for (int j = 0; j < n_cols; ++j) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    cout<<"------------------------------------------------------\n";
}

bool ConnectFourBoard::is_winner() {
    // Check horizontally
    for (int i = 0; i < n_rows; ++i) {
        for (int j = 0; j <= n_cols - 4; ++j) {
            if (board[i][j] != '-' &&
                board[i][j] == board[i][j + 1] &&
                board[i][j] == board[i][j + 2] &&
                board[i][j] == board[i][j + 3]) {
                return true;
            }
        }
    }

    // Check vertically
    for (int i = 0; i <= n_rows - 4; ++i) {
        for (int j = 0; j < n_cols; ++j) {
            if (board[i][j] != '-' &&
                board[i][j] == board[i + 1][j] &&
                board[i][j] == board[i + 2][j] &&
                board[i][j] == board[i + 3][j]) {
                return true;
            }
        }
    }

    // Check diagonally (top-left to bottom-right)
    for (int i = 0; i <= n_rows - 4; ++i) {
        for (int j = 0; j <= n_cols - 4; ++j) {
            if (board[i][j] != '-' &&
                board[i][j] == board[i + 1][j + 1] &&
                board[i][j] == board[i + 2][j + 2] &&
                board[i][j] == board[i + 3][j + 3]) {
                return true;
            }
        }
    }

    // Check diagonally (top-right to bottom-left)
    for (int i = 0; i <= n_rows - 4; ++i) {
        for (int j = n_cols - 1; j >= 3; --j) {
            if (board[i][j] != '-' &&
                board[i][j] == board[i + 1][j - 1] &&
                board[i][j] == board[i + 2][j - 2] &&
                board[i][j] == board[i + 3][j - 3]) {
                return true;
            }
        }
    }

    return false;
}

bool ConnectFourBoard::is_draw() {
    return (n_moves == n_rows * n_cols) && !is_winner();
}

bool ConnectFourBoard::game_is_over() {
    return is_winner() || is_draw();
}

