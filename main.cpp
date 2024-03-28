#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

#include "Four_in_a_row.h"



using namespace std;



    int main() {
        //srand(static_cast<unsigned>(time(nullptr)));  // Seed for random number generation

        ConnectFourBoard connectFourBoard;
        Player* players[2];
        players[0] = new ConnectFourPlayer (1, 'X',connectFourBoard);

        int choice;
        cout << "Welcome to FCAI X-O Game. :)\n";
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


        return 0;
    }
