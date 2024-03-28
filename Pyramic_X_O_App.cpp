// Class definition for XO_App class
// Author:  Mohammad El-Ramly
// Date:    10/10/2022
// Version: 1

#include <iostream>
#include"BoardGame_Classes.hpp"
#include "Pyramic_Tic_Tac_Toe.h"





using namespace std;

int main() {

    int choice;
    Player * players[2];
    players[0] = new Player (1, 'x');

    cout << "Welcome to FCAI X-O Game. :)\n";
    cout << "Press 1 if you want to play with computer: ";
    cin >> choice;
    if (choice != 1)
        players[1] = new Player (2, '0');
    else
        //Player pointer points to child
        players[1] = new Pyramid_Random_Player ('0');

    GameManager x_o_game (new Pyramid_X_O_Board, players);
    x_o_game.run();
    system ("pause");
}
