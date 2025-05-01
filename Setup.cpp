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
#include "Menu.h"

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

int riddles() {
    ifstream file("riddles.txt");
    if (!file) {
        cout << "Error opening riddles.txt.\n";
        return 0;
    }

    string riddle1, riddle2, riddle3;
    getline(file, riddle1);
    getline(file, riddle2);
    getline(file, riddle3);
    file.close();

    string selected;
    int choice;

    srand(time(0));
    choice = rand() % 3;

    if (choice == 0) {
        selected = riddle1;
    }
    else if (choice == 1) {
        selected = riddle2;
    }
    else { 
        selected = riddle3;
    }
    int length = selected.length();
    int barIndex = -1;
    for (int i = 0; i < length; i++) {
        if (selected[i] == '|') {
            barIndex = i;
            break;
        }
    }

    string question = selected.substr(0, barIndex);
    string answer = selected.substr(barIndex + 1);

    cout << "\n🧠 RIDDLE TIME! 🧠\n";
    cout << question << "\nYour answer: ";

    string guess;
    cin.ignore();
    getline(cin, guess);

    // Lowercase both for comparison
    length = guess.length();
    for (int i = 0; i < length; i++) {
        guess[i] = tolower(guess[i]);
    }
    length = answer.length();
    for (int i = 0; i < length; i++) {
        answer[i] = tolower(answer[i]);
    }

    if (guess == answer) {
        cout << "Correct! +50 Phaspoints.\n";
        return 50;
    } else {
        cout << "Wrong! The answer was: " << answer << "\nYou lose 25 Phaspoints.\n";
        return -25;
    }
}

void Setup::setup() {
    Board game(2, pathChoice1, pathChoice2);
    /*
    cout << "Welcome to the Circle of Death!" << endl;
    sleep_for(seconds(3));

    cout << "This is a Phasmophobia-themed spin on the classic Circle of Life game." << endl;
    sleep_for(seconds(3));

    cout << "Your goal is simple: whoever has more points wins." << endl;
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
    cout << "PLAYER 1: Choose your character (1-6): ";
    cin >> player1;
    Character char1(player1);
    char1.printDescription(player1);

   // sleep_for(seconds(3));

    cout << "PLAYER 2: Choose your character (1-6): ";
    cin >> player2;
    while(player2 == player1) {
        cout << "Character already chosen! Please choose another character: " << endl;
        cin >> player2;
    }
    Character char2(player2);
    char2.printDescription(player2);

    cout << "\nPress ENTER to continue...\n";
    cin.ignore(); //flush newline
    cin.get();    //wait for ENTER

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
    Advisor advisor1(1);
    Advisor advisor2(1);
    if(pathChoice1 == 1) {
        cout << "You chose Tanglewood Dr \n +100 Phaspoints \n No starting advisor" << endl;
        //+100 phaspoints
        char1.addPhaspoints(100);
        game.screenRewrite();
        
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
        Advisor tempAdvisor(advisorChoice1);
        advisor1 = tempAdvisor;
        cout << "You chose: " << advisor1.getName() << endl;
        int advisorNum = advisor1.getNum(advisor1.getName());
        switch(advisorNum) {
            case 1: // The Seer
                char1.setWisdom(advisor1.applyEffects(1));
                break;
        
            case 2: // The Warden
                char1.setStrength(advisor1.applyEffects(2));
                break;
        
            case 3: // The Whisperer
                char1.addPhaspoints(advisor1.applyEffects(3));
                break;
        
            case 4: // The Riftwalker
                char1.addPhaspoints(-100); //deduct 100 phaspoints
                char1.setStrength(advisor1.applyEffects(4));      //+6 strength
                break;
        
            case 5: // The Hollow Monk
                char1.setStamina(advisor1.applyEffects(5));
                break;
        
            default:
                cout << "Unknown advisor selected." << endl;
                break;
        }
        game.screenRewrite();
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
        game.screenRewrite();
        
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
        Advisor temp2(advisorChoice2);
        advisor2 = temp2;
        cout << "You chose: " << advisor2.getName() << endl;
        int advisorNum = advisor2.getNum(advisor2.getName());
        switch(advisorNum) {
            case 1: // The Seer
                char2.setWisdom(advisor2.applyEffects(1));
                break;
        
            case 2: // The Warden
                char2.setStrength(advisor2.applyEffects(2));
                break;
        
            case 3: // The Whisperer
                char2.addPhaspoints(advisor2.applyEffects(3));
                break;
        
            case 4: // The Riftwalker
                char2.addPhaspoints(-100); //deduct 100 phaspoints
                char2.setStrength(advisor2.applyEffects(4));      //+6 strength
                break;
        
            case 5: // The Hollow Monk
                char2.setStamina(advisor2.applyEffects(5));
                break;
        
            default:
                cout << "Unknown advisor selected." << endl;
                break;
        }
        //etc.
    }
    cout << "\nPress ENTER to start to the game...\n";
    cin.ignore(); //flush newline
    cin.get();    //wait for ENTER


    game.screenRewrite();

    Spinner spinner;
    Tile tile;
    Tile tile2;
    Menu menu;
    
    int movements;
    int turn = 0;
    int choice;
    char currentTile1;
    char currentTile2;
    bool isP1Turn = true;
    bool running = true;
    string moveOn;
    srand(time(0));

    while(running) {
        
        game.screenRewrite();
        if (isP1Turn) {
            cout << "🎮 " << player1Name << "'s Turn 🎮\n\n";
        } else {
            cout << "🎮 " << player2Name << "'s Turn 🎮\n\n";
        }
        
        game.displayBoard();
        menu.menu();

        cin >> choice; 
        
        //Checks to make sure that input is between 1 and 5
        while(choice > 5 && choice <= 0) {
            cout << "Please enter '1-5' to make a decision: ";
            cin >> choice;
        }
        
        //Displays submenu
        if (choice == 2) {
            //Show submenu after board + main menu
            if(isP1Turn) {
                menu.menu(2, "Temp", char1.getPhaspoints(), char1.getStrength(), char1.getWisdom(), char1.getStamina(), 0);

            }
            else {
                menu.menu(2, "Temp", char2.getPhaspoints(), char2.getStrength(), char2.getWisdom(), char2.getStamina(), 0);
            }
            cout << "\nPress ENTER to return to the main menu...\n";
            cin.ignore(); //flush newline
            cin.get();    //wait for ENTER
            continue;     //go back to top of loop to redraw screen/menu
        }
        if (choice == 3) {
            //Show submenu after board + main menu
            if(isP1Turn) {
                menu.menu(3, char1.getName(), 0, 0, 0, 0, char1.getAge());

            }
            else {
                menu.menu(3, char2.getName(), char2.getPhaspoints(), char2.getStrength(), char2.getWisdom(), char2.getStamina(), char2.getAge());
            }
            cout << "\nPress ENTER to return to the main menu...\n";
            cin.ignore(); //flush newline
            cin.get();    //wait for ENTER
            continue;     //go back to top of loop to redraw screen/menu
        }
        if (choice == 4) {
            //Show submenu after board + main menu
            if(isP1Turn) {
                menu.menu(5, "", game.getPlayerPosition(0), 0, 0, 0, 0);

            }
            else {
                menu.menu(5, "", game.getPlayerPosition(0), 0, 0, 0, 0);
            }
            cout << "\nPress ENTER to return to the main menu...\n";
            cin.ignore(); //flush newline
            cin.get();    //wait for ENTER
            continue;     //go back to top of loop to redraw screen/menu
        }
        if (choice == 5) {
            //Show submenu after board + main menu
            if(isP1Turn) {
                menu.menu(4, advisor1.getName(), 0, 0, 0, 0, 0);

            }
            else {
                menu.menu(4, advisor2.getName(), 0, 0, 0, 0, 0);
            }
            cout << "\nPress ENTER to return to the main menu...\n";
            cin.ignore(); //flush newline
            cin.get();    //wait for ENTER
            continue;     //go back to top of loop to redraw screen/menu
        }

        //When moving, will call a randomChance function, effects vary depending on advisor
        if(isP1Turn) {  

            if (choice == 1) {
                //0 is player1, 1 is player2
                if(game.getPlayerPosition(0) >= 52) { //check to see if pos >= 52, essentially ending game for p1
                    isP1Turn = false;
                    break;
                }
                movements = spinner.spin();
                game.movePlayer(0, movements);
                //game.screenRewrite();
                cout << "You moved [" << movements << "] spaces" << endl;
                currentTile1 = game.getTileInfo(game.getPlayerPosition(0), 0);
                char1 = tile.tileAttributes(char1, currentTile1);

                cout << "[STATS] 💪 STR: " << char1.getStrength() 
                    << " | ⚡ STA: " << char1.getStamina() 
                    << " | 🧠 WIS: " << char1.getWisdom() << endl;
                if(currentTile1 == 'R') {
                    cout << "You get an extra turn!" << endl;
                }
                else {
                    isP1Turn = false;
                }
                if (currentTile1 == 'A') {
                    cout << "Would you like to choose a new advisor? (y/n): ";
                    char decision;
                    cin >> decision;
                    cin.ignore();
                
                    if (decision == 'y') {
                        advisorInformation();
                
                        int advisorChoice1;
                        cout << "Choose an advisor (1-5): ";
                        cin >> advisorChoice1;
                
                        while (advisorChoice1 < 1 || advisorChoice1 > 5) {
                            cout << "Invalid choice: Please choose 1-5: ";
                            cin >> advisorChoice1;
                        }
                
                        Advisor tempAdvisor(advisorChoice1);
                        advisor1 = tempAdvisor; 
                
                        cout << "You chose: " << advisor1.getName() << endl;
                        int advisorNum = advisor1.getNum(advisor1.getName());
                        switch(advisorNum) {
                            case 1: // The Seer
                                char1.setWisdom(advisor1.applyEffects(1));
                                break;
                        
                            case 2: // The Warden
                                char1.setStrength(advisor1.applyEffects(2));
                                break;
                        
                            case 3: // The Whisperer
                                char1.addPhaspoints(advisor1.applyEffects(3));
                                break;
                        
                            case 4: // The Riftwalker
                                char1.addPhaspoints(-100); //deduct 100 phaspoints
                                char1.setStrength(advisor1.applyEffects(4));      //+6 strength
                                break;
                        
                            case 5: // The Hollow Monk
                                char1.setStamina(advisor1.applyEffects(5));
                                break;
                        
                            default:
                                cout << "Unknown advisor selected." << endl;
                                break;
                        }
                    } 
                    else {
                        cout << "Keeping your current advisor." << endl;
                    }
                }

            }
            if(currentTile1 == 'C') { //challenge/riddle tile
                int points = riddles();
                char1.addPhaspoints(points);
            }
            if(currentTile1 == 'S') {
                game.movePlayer(0, -3);
                cout << "You were sent back three tiles!" << endl;
            }
            cout << "\nPress ENTER to continue...\n";
            cin.ignore();
            cin.get();

        }
        else {
            if (choice == 1) {
                if(game.getPlayerPosition(1) >= 52) { //check to see if pos >= 52, essentially ending game for p1
                    isP1Turn = true;
                    break;
                }
                movements = spinner.spin(); //set movements amount based on random spin
                game.movePlayer(1, movements); //actually do the movement
                cout << "You moved " << movements << " spaces." << game.getPlayerPosition(1) << endl;
                currentTile2 = game.getTileInfo(game.getPlayerPosition(1), 1);
                char2 = tile2.tileAttributes(char2, currentTile2);
                cout << "[STATS] 💪 STR: " << char2.getStrength() 
                    << " | ⚡ STA: " << char2.getStamina() 
                    << " | 🧠 WIS: " << char2.getWisdom() << endl;   
                               
                if(currentTile2 == 'R') {
                    cout << "You get an extra turn!" << endl;
                }
                else {
                    isP1Turn = true;
                }
                if (currentTile2 == 'A') {
                    cout << "Would you like to choose a new advisor? (y/n): ";
                    char decision;
                    cin >> decision;
                
                    if (decision == 'y') {
                        advisorInformation();
                
                        int advisorChoice2;
                        cout << "Choose an advisor (1-5): ";
                        cin >> advisorChoice2;
                
                        while (advisorChoice2 < 1 || advisorChoice2 > 5) {
                            cout << "Invalid choice: Please choose 1-5: ";
                            cin >> advisorChoice2;
                        }
                
                        Advisor tempAdvisor(advisorChoice2);
                        advisor2 = tempAdvisor; 
                
                        cout << "You chose: " << advisor2.getName() << endl;
                        int advisorNum = advisor2.getNum(advisor2.getName());
                        switch(advisorNum) {
                            case 1: // The Seer
                                char2.setWisdom(advisor2.applyEffects(1));
                                break;
                        
                            case 2: // The Warden
                                char2.setStrength(advisor2.applyEffects(2));
                                break;
                        
                            case 3: // The Whisperer
                                char2.addPhaspoints(advisor2.applyEffects(3));
                                break;
                        
                            case 4: // The Riftwalker
                                char2.addPhaspoints(-100); //deduct 100 phaspoints
                                char2.setStrength(advisor2.applyEffects(4));      //+6 strength
                                break;
                        
                            case 5: // The Hollow Monk
                                char2.setStamina(advisor2.applyEffects(5));
                                break;
                        
                            default:
                                cout << "Unknown advisor selected." << endl;
                                break;
                        }
                    } 
                    else {
                        cout << "Keeping your current advisor." << endl;
                    }
                }


            }
            if(currentTile1 == 'C') { //challenge/riddle tile
                int points = riddles();
                char2.addPhaspoints(points);
            }
            if(currentTile1 == 'S') {
                game.movePlayer(1, -3);
                cout << "You were sent back three tiles!" << endl;
            }
            cout << "\nPress ENTER to continue...\n";
            cin.ignore();
            cin.get();
        }

        if(game.getPlayerPosition(0) >= 54 && game.getPlayerPosition(1) >= 54) {
            running = false;
        }
        turn++;
    }
    game.screenRewrite();

    string winner;
    if(char1.getPhaspoints() > char2. getPhaspoints()) {
        cout << "GAME OVER. WINNER: "  << player1Name <<  endl;
    }
    else {
        cout << "GAME OVER. WINNER: " << player2Name << endl;
        cout << "Player 1 Points: " << char1.getPhaspoints() << " | Player 2 Points: " << char2.getPhaspoints() << endl;
    }

}