#include <iostream>
#include <fstream>
#include <thread>
#include <chrono>
#include "Setup.h"
#include "Board.h"
#include "Character.h"

using namespace std;
using namespace chrono;
using namespace this_thread;

void Setup::setup() {
    Board f;

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



    //Print out the contents of "characters.txt"
    ifstream characters("characters.txt");
    string characterText;
    int player1, player2;
    cout << "PLAYER 1: What's your name?: ";
    cin >> player1Name;
    f.screenRewrite();
    cout << "PLAYER 2: What's your name?: ";
    cin >> player2Name;
    f.screenRewrite();
    while(getline(characters, characterText)) {
        cout << characterText << endl;
    }
    cout << "PLAYER 1: Choose your character (1-5)" << endl;
    cin >> player1;
    Character char1(player1);
    char1.printDescription(player1);
    sleep_for(seconds(3));

    cout << "PLAYER 2: Choose your character (1-5): ";
    cin >> player2;
    while(player2 == player1) {
        cout << "Character already chosen! Please choose another character: " << endl;
        cin >> player2;
    }
    Character char2(player2);
    char2.printDescription(player2);
    sleep_for(seconds(5));
    f.screenRewrite();
    //Write stuff here to take in chosen paths and then funnel them to the Board generation 
    if(pathChoice == 1) {
        //-5,000 Pride Point
        //etc.

        //select advisor dialogue:
    }
    if(pathChoice == 2) {
        //+5,000 Pride Points
        //etc.

        
    }


}