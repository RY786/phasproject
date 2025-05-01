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

std::string Advisor::getName() const {
    return name;  // Or whatever member variable stores the name
}

//general funcs