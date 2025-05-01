#include <iostream>
#include "Tile.h"
#include "Character.h"
#include "Board.h"

using namespace std;

/*
A = Advisor
C = Challenge
R = Rest
S = Salt Trap
B = Binding
*/



Character Tile::tileAttributes(Character c, char currentTile) {
    // Initialize random seed
    srand(time(0));

    switch(currentTile) {
        case 'A': // Advisor tile
            c.setStamina(3);
            c.setStrength(3);
            cout << "You find a friendly ghost advisor! | +3 Stamina | +3 Strength |" << endl;
            break;
        case 'B': // Binding tile
            c.setStamina(-3);
            c.setStrength(-2);
            cout << "A ghost hunter uses a crucifix on you! : -3 Stamina | -2 Strength" << endl;
            break;
        case 'R': // Rest tile
            c.setStamina(2);
            c.setStrength(2);
            c.setWisdom(1);
            cout << "Finally, some peace and quiet: +2 Stamina | +2 Strength | +1 Wisdom | " << endl;
            break;
        case 'S': // Salt trap tile
            c.setStamina(-3);
            c.setStrength(-3);
            c.setWisdom(-3);
            cout << "You've been hit by a salt trap! : -3 Stamina | -3 Strength | -1 Wisdom |" << endl;
            break;
        case 'C': // Challenge tile
            cout << "A ghostly riddle is presented to you... " << endl;
            break;
        case 'G': // Regular green tile (random events 50% chance)
            {
                int randomChance = rand() % 2;  // Generate a random number between 0 and 1
                
                if(randomChance == 0) {  // 50% chance for random event
                    int randomEvent = rand() % 9;  // Generate another random number between 0 and 8

                    switch(randomEvent) {
                        case 0:
                            // Surprise Bonus (Positive Effect)
                            cout << "You found a hidden stash of Phaspoints! +50 Phaspoints!" << endl;
                            c.addPhaspoints(50);
                            break;
                        case 1:
                            // Strength Boost (Positive Effect)
                            cout << "A burst of energy! +5 Strength!" << endl;
                            c.setStrength(5);
                            break;
                        case 2:
                            // Wisdom Boost (Positive Effect)
                            cout << "A ghost whispers knowledge to you! +3 Wisdom!" << endl;
                            c.setWisdom(3);
                            break;
                        case 3:
                            // Stamina Boost (Positive Effect)
                            cout << "You feel revitalized! +4 Stamina!" << endl;
                            c.setStamina(4);
                            break;
                        case 4:
                            // Surprise Negative Effect 1
                            cout << "A ghost steals some of your Phaspoints! -30 Phaspoints!" << endl;
                            c.addPhaspoints(-30);
                            break;
                        case 5:
                            // Surprise Negative Effect 2
                            cout << "You are haunted by a ghost! -4 Strength!" << endl;
                            c.setStrength(-4);
                            break;
                        case 6:
                            // Surprise Negative Effect 3
                            cout << "A curse weakens you! -5 Stamina!" << endl;
                            c.setStamina(-5);
                            break;
                        case 7:
                            // Surprise Negative Effect 4
                            cout << "A ghost drains your mental energy! -3 Wisdom!" << endl;
                            c.setWisdom(-3);
                            break;
                        case 8:
                            // Surprise Negative Effect 5
                            cout << "You fall into a trap! -2 Strength | -2 Stamina!" << endl;
                            c.setStrength(-2);
                            c.setStamina(-2);
                            break;
                    }
                } else {
                    // No event, just a regular move
                    cout << "No event this time on this tile." << endl;
                }
            }
            break;
        default:
            break;
    }
    return c;
}
