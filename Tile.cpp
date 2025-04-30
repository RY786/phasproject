#include <iostream>
#include "Tile.h"
#include "Character.h"

using namespace std;

/*
A = Advisor
C = Challenge
R = Rest
S = Salt Trap
B = Binding
*/



Character Tile::tileAttributes(Character c, char currentTile) {
    switch(currentTile) {
        case 'A': //Advisor tile
            c.setStamina(3);
            c.setStrength(3);
            cout << "You find a friendly ghost advisor! | +3 Stamina | +3 Strength |" << endl;

            break;
        case 'B': //Binding tile
            c.setStamina(-3);
            c.setStrength(-2);
            cout << "A ghost hunter uses a crucifix on you! : -3 Stamina | -2 Strength" << endl;
            break;
        case 'R': //Rest tile
            c.setStamina(2);
            c.setStrength(2);
            c.setWisdom(1);

            cout << "Finally, some peace and quiet: +2 Stamina | +2 Strength | +1 Wisdom | " << endl;

            break;
        case 'S': //Salt trap tile
            c.setStamina(-3);
            c.setStrength(-3);
            c.setWisdom(-3);

            cout << "You've been hit by a salt trap! : -3 Stamina | -3 Strength | -1 Wisdom |" << endl;
            break;
        case 'C': //Challenge tile
            cout << "A ghostly riddle is presented to you... " << endl;
        default:
            break;
    }
    return c;
}


