#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>

using namespace std;

class Character {
private:
    string name;
    int age;
    int strength;
    int stamina;
    int wisdom;
    int phaspoints;

public:
    //cnstrct
    Character();
    Character(int character);

    //get
    string getName() const;
    int getAge() const;
    int getStrength() const;
    int getStamina() const;
    int getWisdom() const;
    int getPhaspoints() const;

    //setters
    void setAge(int newAge);
    void setStrength(int newStrength);
    void setStamina(int newStamina);
    void setWisdom(int newWisdom);
    void addPhaspoints(int newPhaspoints);

    //info funcs
    void displayStats() const;
    void printDescription(int character);
};

#endif // CHARACTER_H
