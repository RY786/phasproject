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

    //info funcs
    void displayAdvisors();
    void displayStats() const;
};

#endif // CHARACTER_H
