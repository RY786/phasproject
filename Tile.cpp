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
            

            cout << "Yout lost 200 stamina due to tile" << endl;

            break;
        case 'B': //Binding tile
            c.setStamina(-200);
            cout << "Yout lost 200 stamina due to tile" << endl;
            break;
        case 'R': //Rest tile
            c.setStamina(-200);

            cout << "Yout lost 200 stamina due to tile" << endl;

            break;
        case 'S': //Salt trap tile
            c.setStamina(-200);

            cout << "Yout lost 200 stamina due to tile" << endl;

            break;
        case 'C': //Challenge tile
            c.setStamina(-200);

            cout << "Yout lost 200 stamina due to tile" << endl;

            break;
        default:
            break;
    }
    return c;
}


