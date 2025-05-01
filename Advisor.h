#ifndef ADVISOR_H
#define ADIVSOR_H

using namespace std;

class Advisor {
private:
    string name;


public:
    //cnstrct
    Advisor();
    Advisor(int advisor);

    //get
    string getName() const;
    int getNum(string name) const;

    //info funcs
    void displayAdvisors();
    void displayStats() const;
    int applyEffects(int advisorNum);
};

#endif // CHARACTER_H
