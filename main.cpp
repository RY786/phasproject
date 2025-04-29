#include <iostream>
#include "Board.h"
#include "Setup.h"
using namespace std;

int main() {
    /*
    The setup function sets up character selection, naming, and path selection. 
    It is defined and and attributed in setup.h and setup.cpp respectively
    It is ran once, will likely implement game loop and run it again to reset the game.
    */
    Setup initialize;
    initialize.setup();


    srand(time(0));
    int turn = 0;
    int choice;
    Board game(2);
    while(turn <= 54) {
        game.displayBoard();
        //Place holder movement info
        cout << "Press 1 to move, 0 to skip turn and stay in place: " << endl;
        cin >> choice; 
        //When moving, will call a randomChance function, effects vary depending on advisor
        if (choice == 1) {
            //0 is player1, 1 is player2
            game.movePlayer(0);
            game.screenRewrite();
        }
        else if(choice == 2) {
            game.movePlayer(1);
            game.screenRewrite();
        }
        turn++;
    }
    return 0;
}