#include <iostream>
#include <fstream>
#include <thread>
#include <chrono>
#include "Setup.h"
#include "Board.h"
#include "Character.h"
#include "Advisor.h"
#include "Tile.h"
#include "Spinner.h"

using namespace std;
using namespace chrono;
using namespace this_thread;

void advisorInformation() {
    ifstream advisors("advisor.txt");
    string advisorText;
    while(getline(advisors, advisorText)) {
        cout << advisorText << endl;
    }
}

void Setup::setup() {
    Board game(2, pathChoice1, pathChoice2);
    /*
    cout << "Welcome to the Circle of Death!" << endl;
    sleep_for(seconds(3));

    cout << "This is a Phasmophobia-themed spin on the classic Circle of Life game." << endl;
    sleep_for(seconds(3));

    cout << "Your goal is simple: reach 1000 Pride Points before your opponent." << endl;
    sleep_for(seconds(3));

    cout << "Beware! There will be obstacles on your journey..." << endl;
    sleep_for(seconds(3));

    cout << "Traps, tricky environments, and other dangers await to slow you down." << endl;
    sleep_for(seconds(3));

    cout << "Navigate wisely, may the best win..." << endl;
    sleep_for(seconds(3));
    f.screenRewrite();
    */


    //Print out the contents of "characters.txt"
    ifstream characters("characters.txt");
    string characterText;
    int player1, player2;
    cout << "PLAYER 1: What's your name?: ";
    cin >> player1Name;
    game.screenRewrite();
    cout << "PLAYER 2: What's your name?: ";
    cin >> player2Name;
    game.screenRewrite();
    while(getline(characters, characterText)) {
        cout << characterText << endl;
    }
    cout << "PLAYER 1: Choose your character (1-5)" << endl;
    cin >> player1;
    Character char1(player1);
    char1.printDescription(player1);
   // sleep_for(seconds(3));

    cout << "PLAYER 2: Choose your character (1-5): ";
    cin >> player2;
    while(player2 == player1) {
        cout << "Character already chosen! Please choose another character: " << endl;
        cin >> player2;
    }
    Character char2(player2);
    char2.printDescription(player2);
    //sleep_for(seconds(5));
    game.screenRewrite();
    cout << "Now, each player with choose a path. There are two paths available: Tanglewood Dr and Abandonded High School." << endl;
    cout << "Tanglewood Dr is the more challenging path with more obstacles on the way, but you will earn additional Phaspoints." << endl;
    cout << endl;
    cout << "Abandonded High School is the easier choice, and you will have an expert ghost advisor to help you along the way immediately, at the cost of Phaspoints." << endl;
    cout << "There will be a decrease in obstacles as well, but remember you have an initial setback with your points" << endl;
    cout << endl;


    //Write stuff here to take in chosen paths and then funnel them to the Board generation 
    cout << player1Name << ", choose your path wisely:\n"
     << " (1) Tanglewood Dr\n"
     << " (2) Abandoned High School\n";
    cin >> pathChoice1;

    while (pathChoice1 != 1 && pathChoice1 != 2) {
        cout << "Invalid choice: Please choose (1) or (2): ";
        cin >> pathChoice1;
    }
    if(pathChoice1 == 1) {
        cout << "You chose Tanglewood Dr \n +100 Phaspoints \n No starting advisor" << endl;
        //+100 phaspoints
        char1.addPhaspoints(100);
        
        //etc.
        //select advisor dialogue:
        

    }
    else if(pathChoice1 == 2) {
        cout << "You chose Abandoned High School \n -100 Phaspoints \n You get a starting advisor" << endl;
        //-100 Phaspoints
        char1.addPhaspoints(-100);
        advisorInformation();
        cout << endl << "Choose a starting advisor from the list above" << endl;
        int advisorChoice1;
        cin >> advisorChoice1;
        while(advisorChoice1 < 1 || advisorChoice1 > 5) {
            cout << "Invalid choice: Please choose 1-5: ";
            cin >> pathChoice1;
        }
        Advisor advisor1(advisorChoice1);
        //etc.
    }

    //Write stuff here to take in chosen paths and then funnel them to the Board generation 
    cout << player2Name << ", choose your path wisely:\n"
     << " (1) Tanglewood Dr\n"
     << " (2) Abandoned High School\n";
    cin >> pathChoice2;

    while (pathChoice2 != 1 && pathChoice2 != 2) {
        cout << "Invalid choice: Please choose (1) or (2): ";
        cin >> pathChoice2;
    }
    if(pathChoice2 == 1) {
        cout << "You chose Tanglewood Dr \n +100 Phaspoints \n No starting advisor" << endl;
        //+100 phaspoints
        char2.addPhaspoints(100);
        
        //etc.
        //select advisor dialogue:
    }
    else if(pathChoice2 == 2) {
        cout << "You chose Abandoned High School \n -100 Phaspoints \n You get a starting advisor" << endl;
        //-100 Phaspoints
        char2.addPhaspoints(-100);
        advisorInformation();
        cout << endl << "Choose a starting advisor from the list above" << endl;
        int advisorChoice2;
        cin >> advisorChoice2;
        while(advisorChoice2 < 1 || advisorChoice2 > 5) {
            cout << "Invalid choice: Please choose 1-5: ";
            cin >> pathChoice1;
        }
        Advisor advisor2(advisorChoice2);
        //etc.
    }
    game.screenRewrite();

    Spinner spinner;
    Tile tile;
    
    int movements;
    int turn = 0;
    int choice;
    char currentTile;
    bool isP1Turn = true;
    string moveOn;
    srand(time(0));

    while(turn <= 54) {
        game.displayBoard();
        //Place holder movement info
        cout << "Press 1 and ENTER to make your move" << endl;
        cin >> choice; 
        while(choice != 1) {
            cout << "Please enter '1' to cast out your move: ";
            cin >> choice;
        }
        //When moving, will call a randomChance function, effects vary depending on advisor
        if(isP1Turn) {  
            if (choice == 1) {
                //0 is player1, 1 is player2
                movements = spinner.spin();
                game.movePlayer(0, movements);
                game.screenRewrite();
                cout << player1Name << "'s move!" << endl;
                cout << "You moved " << movements << " spaces." << endl;
                cout << "POS: " << game.getPlayerPosition(0) << endl;
                currentTile = game.getTileInfo(game.getPlayerPosition(0));
                cout << "Current Tile Type: " << currentTile << endl;
                char1 = tile.tileAttributes(char1, currentTile);

                cout << char1.getStamina() << endl;
                if(currentTile == 'A') {
                    cout << "You get an extra turn!" << endl;
                }
                else {
                    isP1Turn = false;
                }

            }
        }
        else {
            if (choice == 1) {
                movements = spinner.spin();
                game.movePlayer(1, movements);
                game.screenRewrite();
                cout << player2Name << "'s move!" << endl;
                cout << "You moved " << movements << " spaces." << endl;
                cout << "POS: " << game.getPlayerPosition(1) << endl;
                currentTile = game.getTileInfo(game.getPlayerPosition(1));
                cout << "Current Tile Type: " << currentTile << endl;
                char2 = tile.tileAttributes(char2, currentTile);
                cout << char2.getStamina() << endl;
                if(currentTile == 'A') {
                    cout << "You get an extra turn!" << endl;
                }
                else {
                    isP1Turn = true;
                }

            }
        }
        turn++;
    }

}