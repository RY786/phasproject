#include "Spinner.h"
#include <cstdlib>
#include <ctime>

using namespace std;

Spinner::Spinner() {
    // Seed random number generator once
    srand(time(0));
}

int Spinner::spin() {
    forward = rand() % 6 + 1; // Returns a number between 1 and 6
    return forward;
}