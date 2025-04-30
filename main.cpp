#include <iostream>
#include "Board.h"
#include "Setup.h"
#include "Spinner.h"
using namespace std;

int main() {
    /*
    The setup function sets up character selection, naming, and path selection. 
    It is defined and and attributed in setup.h and setup.cpp respectively
    It is ran once, will likely implement game loop and run it again to reset the game.
    */
    Setup initialize;
    Spinner spinner;
    initialize.setup();
    int movements;

    srand(time(0));
    int turn = 0;
    int choice;
    Board game(2, initialize.pathChoice1, initialize.pathChoice2);
    while(turn <= 54) {
        game.displayBoard();
        //Place holder movement info
        cout << "Press 1 to move, 0 to skip turn and stay in place: " << endl;
        cin >> choice; 
        //When moving, will call a randomChance function, effects vary depending on advisor
        if (choice == 1) {
            //0 is player1, 1 is player2
            movements = spinner.spin();
            cout << "You moved " << movements << endl;
            game.movePlayer(0, movements);
            game.screenRewrite();
        }
        else if(choice == 2) {
            movements = spinner.spin();
            cout << "You moved " << movements << endl;
            game.movePlayer(1, movements);
            game.screenRewrite();
        }
        turn++;
    }
    return 0;
}