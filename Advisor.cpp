#include <iostream>
#include <fstream>
#include "Advisor.h"

using namespace std;


Advisor::Advisor() {

}

Advisor::Advisor(int advisorNum) {
    switch (advisorNum) {
        case 1: // THE SEER
            name = "The Seer";
            break;
        case 2: // THE WARDEN
            name = "The Warden";
            break;
        case 3: // THE WHISPERER
            name = "The Whisperer";
            break;
        case 4: // THE RIFTWALKER
            name = "The Riftwalker";
            break;
        case 5: // THE HOLLOW MONK
            name = "The Hollow Monk";
            break;
        default:
            std::cout << "Invalid advisor selection!" << std::endl;
            break;
    }
}

string Advisor::getName() const {
    return name;  // Or whatever member variable stores the name
}

int Advisor::getNum(string name) const {

    if (name == "The Seer") {
        return 1;
    } else if (name == "The Warden") {
        return 2;
    } else if (name == "The Whisperer") {
        return 3;
    } else if (name == "The Riftwalker") {
        return 4;
    } else if (name == "The Hollow Monk") {
        return 5;
    } else {
        return -1; // invalid or unknown name
    }
}

//general funcs

int Advisor::applyEffects(int advisorNum) {
    int strengthEffect = 5;
    int staminaEffect = 3; 
    int pointsEffect = 100;
    int wisdomEffect = 3;
    int strength2Effect = 7;

    switch (advisorNum) {
        case 1: // THE SEER
            return wisdomEffect;
            break;
        case 2: // THE WARDEN
            return strengthEffect;
            break;
        case 3: // THE WHISPERER
            return pointsEffect;
            break;
        case 4: // THE RIFTWALKER
            return strength2Effect;
            break;
        case 5: // THE HOLLOW MONK
            return staminaEffect;
            break;
        default:
            return 0;
            break;
    }

}