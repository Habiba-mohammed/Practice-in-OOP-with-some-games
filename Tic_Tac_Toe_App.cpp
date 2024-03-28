#include <iostream>
#include"../BoardGame_Classes.hpp"
#include "Tic_Tac_Toe.h"
using namespace std;

int main() {
    int choice;
    Player* players[2];
    players[0] = new Player (1, 'x');

    cout << "Welcome to FCAI Tic_Tac_Toe Game. :)\n";
    cout << "Press 1 if you want to play with computer: ";
    cin >> choice;
    if (choice != 1)
        players[1] = new Player (2, 'o');
    else
        //Player pointer points to child
        players[1] = new RandomPlayer ('o', 5);

    GameManager tic_tac_game (new Tic_Tac_Board(), players);
    tic_tac_game.run();
    system ("pause");
}