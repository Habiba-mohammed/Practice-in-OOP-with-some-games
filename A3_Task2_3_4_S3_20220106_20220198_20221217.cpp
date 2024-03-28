#include <iostream>
#include"BoardGame_Classes.hpp"
#include "./5x5_Tic_Tac_Toe/Tic_Tac_Toe.h"
#include "Pyramic_Tic_Tac_Toe.h"
#include "Four_in_a_row.h"
using namespace std;

void setGame1();
void setGame2();
void setGame3();
void setGame4();
int choice;

int main() {
    bool done = 0;
    int exit, game;
    cout << "Welcome to FCAI Games. :)\n";
    while (!done){
        cout << "What game would you like to play?\n";
        cout << "1. 3x3 Tic Tac Toe\n";
        cout << "2. Pyramid Tic Tac Toe\n";
        cout << "3. Four-in-a-row\n";
        cout << "4. 5x5 Tic Tac Toe\n";
        //setPlayer2(players, 3);
        cin >> game;
        switch (game) {
            case 1:
                setGame1();
                break;

            case 2:
                setGame2();
                break;
            case 3:
                setGame3();
                break;
            case 4:
                setGame4();
                break;
            default:
                break;
        }
        system ("cls");
        cout << "Would you like to play another game? Press 1 to exit and any number to continue.\n";
        cin >> exit;
        if (exit == 1){
            done = 1;
        }
    }

}

void setGame1(){
    Player* players[2];
    players[0] = new Player (1, 'x');
    cout << "Press 1 if you want to play with computer: ";
    cin >> choice;
    if (choice != 1)
        players[1] = new Player (2, 'o');
    else
        players[1] = new RandomPlayer ('o', 3);

    GameManager x_o_game (new X_O_Board(), players);
    x_o_game.run();
    system ("pause");
    delete players[0];
    delete players[1];
}
void setGame2(){
    Player* players[2];
    players[0] = new Player (1, 'x');
    cout << "Press 1 if you want to play with computer: ";
    cin >> choice;
    if (choice != 1)
        players[1] = new Player (2, '0');
    else
        players[1] = new Pyramid_Random_Player ('0');

    GameManager x_o_game (new Pyramid_X_O_Board, players);
    x_o_game.run();
    system ("pause");
    delete players[0];
    delete players[1];
}
void setGame3(){
    ConnectFourBoard connectFourBoard;
    Player* players[2];
    players[0] = new ConnectFourPlayer (1, 'X',connectFourBoard);
    cout << "Press 1 if you want to play with computer: ";
    cin >> choice;
    if(choice==1){
        players[1] = new ConnectFourRandomPlayer ('0', 6,7,connectFourBoard);
    }
    else{
        players[1]=new ConnectFourPlayer(2, '0',connectFourBoard);
    }

    GameManager connectFourGameManager(&connectFourBoard, players);
    connectFourGameManager.run();
    system ("pause");
    delete players[0];
    delete players[1];

}
void setGame4(){
    Player* players[2];
    players[0] = new Player (1, 'x');
    cout << "Press 1 if you want to play with computer: ";
    cin >> choice;
    if (choice != 1)
        players[1] = new Player (2, 'o');
    else
        players[1] = new RandomPlayer ('o', 5);

    GameManager tic_tac_game (new Tic_Tac_Board(), players);
    tic_tac_game.run();
    system ("pause");
    delete players[0];
    delete players[1];
}