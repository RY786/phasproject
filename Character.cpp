#include "Character.h"
#include <iostream>

using namespace std;

//constrcutor

Character::Character() {
}

Character::Character(int character) {
    switch (character) {
        case 1: // DEOGEN
            name = "Deogen";
            age = 90;
            strength = 3;
            stamina = 10;
            wisdom = 10;
            phaspoints = 200;
            break;
        case 2: // MIMIC
            name = "Mimic";
            age = 58;
            strength = 6;
            stamina = 6;
            wisdom = 6;
            phaspoints = 200;
            break;
        case 3: // SHADE
            name = "Shade";
            age = 12;
            strength = 2;
            stamina = 4;
            wisdom = 7;
            phaspoints = 200;
            break;
        case 4: // JINN
            name = "Jinn";
            age = 22;
            strength = 8;
            stamina = 6;
            wisdom = 7;
            phaspoints = 200;
            break;
        case 5: // HANTU
            name = "Hantu";
            age = 18;
            strength = 7;
            stamina = 5;
            wisdom = 4;
            phaspoints = 200;
            break;
        case 6: // THAYE
            name = "Thaye";
            age = 5;
            strength = 7;
            stamina = 7;
            wisdom = 8;
            phaspoints = 200;
            break;
        default:
            std::cout << "Invalid character selection!" << std::endl;
            break;
    }

}

//getters
string Character::getName() const {
    return name;
}

int Character::getAge() const {
    return age;
}

int Character::getStrength() const {
    return strength;
}

int Character::getStamina() const {
    return stamina;
}

int Character::getWisdom() const {
    return wisdom;
}

int Character::getPhaspoints() const {
    return phaspoints;
}

//setters
void Character::setAge(int newAge) {
    age += newAge;
}

void Character::setStrength(int newStrength) {
    strength += newStrength;
}

void Character::setStamina(int newStamina) {
    stamina += newStamina;
}

void Character::setWisdom(int newWisdom) {
    wisdom += newWisdom;
}

void Character::addPhaspoints(int newPhaspoints) {
    phaspoints += newPhaspoints;
}

//general functions 
void Character::displayStats() const {
    std::cout << "Name: " << name << "\n"
              << "Age: " << age << "\n"
              << "Strength: " << strength << "\n"
              << "Stamina: " << stamina << "\n"
              << "Wisdom: " << wisdom << "\n"
              << "Phaspoints: " << phaspoints << "\n";
}

void Character::printDescription(int character) {
    switch (character) {
        case 1:
            std::cout << "1) DEOGEN: The old, but wise ghost. Tried and trusted, it is a persistent and intelligent ghost, but lacks agility.\n";
            break;
        case 2:
            std::cout << "2) MIMIC: The deceptive, \"copycat\" ghost. Quite versatile, but does not have any particular strong-suit.\n";
            break;
        case 3:
            std::cout << "3) SHADE: The sneaky, cunning ghost. A smart, quiet ghost that can avoid confrontation, but lacks strength.\n";
            break;
        case 4:
            std::cout << "4) JINN: The aggressive ghost. Powerful and fast, but can be reckless under pressure.\n";
            break;
        case 5:
            std::cout << "5) HANTU: The frigid ghost. Strong and persistent in cold, but dull and sluggish otherwise.\n";
            break;
        case 6:
            std::cout << "6) THAYE: The aging ghost. Energetic and resilient when young, but weakens rapidly with age.\n";
            break;
        default:
            std::cout << "Invalid character selected.\n";
            break;
    }
}

