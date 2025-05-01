#include <iostream>
#include <fstream>
#include <iomanip>
#include "Menu.h"


using namespace std;


void Menu::menu() {
    ifstream menu("menu.txt");
    string menuText;
    while(getline(menu, menuText)) {
        cout << menuText << endl;
    }   

}


void Menu::menu(int menuNum, string currentAdvisor, int phaspoints, int strength, int wisdom, int stamina, int age) {
    //setw is set width, helps with alignment 
    if(menuNum == 2) {
        cout << "🧾=========== PLAYER PROGRESS ===========🧾\n";
        cout << "| Phas Points  : [ " << setw(3) << phaspoints << " ]                 |\n";
        cout << "| Strength     : [ " << setw(3) << strength   << " ]                 |\n";
        cout << "| Stamina      : [ " << setw(3) << stamina    << " ]                 |\n";
        cout << "| Wisdom       : [ " << setw(3) << wisdom     << " ]                 |\n";
        cout << "|----------------------------------------|\n";
        cout << "| * Earn Phas Points by completing       |\n";
        cout << "|   challenges and making good choices.  |\n";
        cout << "| * Traits influence tile outcomes.      |\n";
        cout << "|________________________________________|\n\n";
    }
    else if(menuNum == 3) { //character informatoin
        cout << "🧝========= CHARACTER INFORMATION =========🧝\n";
        cout << "| Name     :   " << setw(15) << left << currentAdvisor << "           |\n";
        cout << "| Age      : [ " << setw(3)  << age  << " ]                     |\n";
        cout << "|----------------------------------------|\n";
        cout << "| * This is your in-game identity.       |\n";
        cout << "| * Age may affect story or tile logic.  |\n";
        cout << "|________________________________________|\n\n";
    }
    else if(menuNum == 4) { //advisor information
        cout << "🧙=========== ADVISOR PROFILE ============🧙\n";
        cout << "| Current Advisor : [ " << setw(15) << left << currentAdvisor << "]     |\n";
        cout << "|----------------------------------------|\n";
        cout << "| * Advisors grant bonuses based on      |\n";
        cout << "|   your tile landings or choices.       |\n";
        cout << "| * Each advisor changes your gameplay   |\n";
        cout << "|   style—choose wisely!                 |\n";
        cout << "|________________________________________|\n\n";
    }
    else if(menuNum == 5) { //position information
        cout << "🗺️=========== CURRENT POSITION ============🗺️\n";
        cout << "| Your marker is shown on the board.     |\n";
        cout << "| Current Tile Pos : [ " << setw(3) << phaspoints <<  " ]                |\n";
        cout << "|----------------------------------------|\n";
        cout << "| * Board positions affect tile types.   |\n";
        cout << "| * Some tiles grant buffs or effects.   |\n";
        cout << "|________________________________________|\n\n";
    }


}


