
//
// Created by Dell on 12/17/2023.
//

#include <iostream>
#include <iomanip>
#include"BoardGame_Classes.hpp"
#include"Pyramic_Tic_Tac_Toe.h"


using namespace std;

Pyramid_X_O_Board::Pyramid_X_O_Board(){
    n_rows=3;
    n_cols=5;
    board=new char*[n_rows];
    for(int i{0};i<n_rows;i++){
        board[i]=new char[n_cols];
        for(int j{0};j<n_cols;j++){
            board[i][j]=0;
        }
    }

}

bool Pyramid_X_O_Board:: update_board (int x, int y, char mark)
{
    // Only update if move is valid
    if ((x==0&&y==2||x==1&&y>=1 &&y<4||x==2 &&y>=0&&y<=4 ) && (board[x][y] == 0)) {
        board[x][y] = toupper(mark);
        n_moves++;
        return true;
    } else
        return false;
}







void Pyramid_X_O_Board::display_board() {
    // Display a pyramid-like pattern using specific elements
    int row=3;
    cout << "Pyramid Pattern:\n";
    for (int i = 0; i < 3; i++) {
        cout << setw((3 - i) * 6);  // Adjust spacing based on row number
        for (int j = 2 - i; j < row; j++) {
            cout << "(" << i << "," << j << ")";
            cout << setw(2)<<board[i][j] ;
        }
        row++;

        cout << '\n';
    }

}



bool Pyramid_X_O_Board:: is_winner(){
    // Herizontally (^_^)
    if( (board[1][1]==board[1][2] &&board[1][2]==board[1][3] && board[1][1]!=0 )||
        ( board[2][0]==board[2][1] &&board[2][1]==board[2][2] && board[2][0]!=0)||
        (board[2][1]==board[2][2] &&board[2][2]==board[2][3] &&board[2][1]!=0) ||
        (board[2][2]==board[2][3] &&board[2][3]==board[2][4] &&  board[2][2]!=0)){
        return true;
    }
        //diagonal
    else if( (board[0][2]==board[1][3] &&board[1][3]==board[2][4]&&board[0][2]!=0 )||
             (board[0][2]==board[1][1] && board[1][1]==board[2][0] && board[0][2]!=0) )
        return true;
    else if(board[0][2]==board[1][2] &&board[1][2]==board[2][2] &&board[0][2]!=0)
        return true;
    else
        return false ;

}
bool Pyramid_X_O_Board::is_draw(){
    return (n_moves == 9 && !is_winner());

}
bool Pyramid_X_O_Board::game_is_over(){
    return is_winner()||is_draw();

}
 Pyramid_Random_Player :: Pyramid_Random_Player(char symbol)
: Player(symbol){
    name="Random Computer Player";
    cout<<"My name is " <<name<<endl;
    cout<<endl;
}
void Pyramid_Random_Player :: get_move(int&x , int &y){
    x=  (int) (rand() % 5);
    y = (int) (rand() % 3);
}

