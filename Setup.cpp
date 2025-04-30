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
    cout << "Now, each player with choose a path. There are two paths available: Tanglewood Dr and Abandonded High School." << endl;
    cout << "Tanglewood Dr is the more challenging path with more obstacles on the way, but you will earn additional Phaspoints." << endl;
    cout << endl;
    cout << "Abandonded High School is the easier choice, and you will have an expert ghost advisor to help you along the way immediately, at the cost of Phaspoints." << endl;
    cout << "There will be a decrease in obstacles as well, but remember you have an initial setback with your points" << endl;
    cout << endl;


    //Write stuff here to take in chosen paths and then funnel them to the Board generation 
    cout << player1Name << ", choose your path wisely: \n (1) Tanglewood Dr \n (2) Abandonded High School" << endl;
    cin >> pathChoice1;
    bool valid = false;
    while(valid) {
        cout << "Invalid choice: Please choose (1) or (2): ";
        cin >> pathChoice1;
        if(pathChoice1 == 1 || pathChoice1 == 2) {
            valid = true;
        }
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

        //etc.
    }


}