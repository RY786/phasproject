#include "Board.h"
#include <iostream>
#include <cstdlib> // For rand() and srand()

using namespace std;
#define RED "\033[48;2;230;10;10m"
#define GREEN "\033[48;2;34;139;34m" /* Grassy Green (34,139,34) */
#define BLUE "\033[48;2;10;10;230m" 
#define PINK "\033[48;2;255;105;180m"
#define BROWN "\033[48;2;139;69;19m"
#define PURPLE "\033[48;2;128;0;128m"
#define ORANGE "\033[48;2;230;115;0m" /* Orange (230,115,0) */
#define WHITE "\033[48;2;255;255;255m" /* White (0,0,0) */
#define DARK_GREY "\033[48;2;64;64;64m" /* Dark Grey (64,64,64) */
#define RESET "\033[0m"

void Board::initializeBoard(int path1, int path2) {
    // Seed random number generator in your main function once
    initializeTiles(0, path1);
    initializeTiles(1, path2);
}

void Board::screenRewrite() {
    //This just overwrites the terminal so it is easier to read
    //From: https://stackoverflow.com/questions/47340610/c-overwrite-multiple-lines-that-were-previously-output-to-console
    printf("\033[2J");
    printf("\033[%d;%dH", 0, 0);
}

void Board::initializeTiles(int player_index, int path) {
    Tile temp;
    int green_count = 0;
    int total_tiles = _BOARD_SIZE;
    int randNum = rand() % 100;

    //Straight to Tanglewood Drive
    if(path == 1) {
        for (int i = 0; i < total_tiles; i++) {
            if (i == total_tiles - 1) {
                // Set the last tile as Orange for pride rock
                temp.color = 'O';
            }
            else if (i == 0) {
                // Set the initial tile as White
                temp.color = 'W'; 
            }
            else if (green_count < 20 && (rand() % (total_tiles - i) < 20 - green_count)) {
                //Ensure that there are at least 20 green tiles whilst still be randomly placed
                temp.color = 'G'; //lowercase g for green 
                green_count++;
            }
            //SPECIAL TILE DISTRIBUTION
            else {
                //Random assignment of the special tiles
                randNum = rand() % 100;
                if(randNum < 25) {
                    temp.tileType = "Challenge";
                    temp.color = 'R';
                }
                randNum = rand() % 100;
                if(i < 27) {
                    if(randNum < 25) {
                        temp.tileType = "Graveyard";
                        temp.color = 'X';
                    }
                    else if(randNum < 50) {
                        temp.tileType = "Hyena";
                        temp.color = 'U';
                    }
                }
                else {
                    if(randNum < 15) {
                        temp.tileType = "Graveyard";
                        temp.color = 'X';
                    }
                    else if(randNum < 30) {
                        temp.tileType = "Hyena";
                        temp.color = 'N';
                    }
                }
                randNum = rand() % 100;
                if(randNum < 20) {
                    temp.tileType = "Advisor";
                    temp.color = 'P';
                }
                randNum = rand() % 100;
                if(i < 27) {
                    if(randNum < 5) {
                        temp.tileType = "Oasis";
                        temp.color = 'B';
                    }
                }
                else {
                    if(randNum < 25) {
                        temp.tileType = "Oasis";
                        temp.color = 'B';
                    }
                }
            }
            // Assign the tile to the board for the specified lane
            _tiles[player_index][i] = temp;
        }
    }
    //Abandonded High School
    else {
        for (int i = 0; i < total_tiles; i++) {
            if (i == total_tiles - 1) {
                // Set the last tile as Orange for "Pride Rock"
                temp.color = 'O';
            }
            else if (i == 0) {
                // Set the initial tile as white
                temp.color = 'W'; 
            }
            else if (green_count < 30 && (rand() % (total_tiles - i) < 30 - green_count)) {
                //Ensure that there are at least 20 green tiles whilst still be randomly placed
                temp.color = 'G'; 
                green_count++;
            }
            //SPECIAL TILE DISTRIBUTION
            else {
                //Random assignment of the special tiles
                randNum = rand() % 100;
                if(i < 27) {
                    if(randNum < 20) {
                    temp.tileType = "Challenge";
                    temp.color = 'R';
                    }
                }
                else {
                    if(randNum < 30) {
                        temp.tileType = "Challenge";
                        temp.color = 'R';
                    }
                }
                randNum = rand() % 100;
                if(randNum < 25) {
                    temp.tileType = "Graveyard";
                    temp.color = 'X';
                }
                else if(randNum < 50) {
                    temp.tileType = "Hyena";
                    temp.color = 'N';
                }
                randNum = rand() % 100;
                if(randNum < 15) {
                    temp.tileType = "Advisor";
                    temp.color = 'P';
                }
                randNum = rand() % 100;
                if(i < 27) {
                    if(randNum < 25) {
                        temp.tileType = "Oasis";
                        temp.color = 'B';
                    }
                }
                else {
                    if(randNum < 15) {
                        temp.tileType = "Oasis";
                        temp.color = 'B';
                    }
                }
            }
            // Assign the tile to the board for the specified lane
            _tiles[player_index][i] = temp;
        }


    }

}

Board::Board() {
    //initalization
}
Board::Board(int player_count, int path1, int path2) {
    if (player_count > _MAX_PLAYERS) {
        _player_count = _MAX_PLAYERS;
    }
    else {
        _player_count = player_count;
    }
    // Initialize player position
    for (int i = 0; i < _player_count; i++) {
        _player_position[i] = 0;
    }
    // Initialize tiles
    initializeBoard(path1, path2);
}
bool Board::isPlayerOnTile(int player_index, int pos) {
    if (_player_position[player_index] == pos) {
        return true;
    }
    return false;
}
void Board::displayTile(int player_index, int pos) {
    // string space = " ";
    string color = "";
    int player = isPlayerOnTile(player_index, pos);
    // Template for displaying a tile: <line filler space> <color start> |<player symbol or blank space>| <reset color> <line filler space> <endl>
    // Determine color to display
    if (_tiles[player_index][pos].color == 'R')
    {
    color = RED;
    }
    else if (_tiles[player_index][pos].color == 'G')
    {
    color = GREEN;
    }
    else if (_tiles[player_index][pos].color == 'B')
    {
    color = BLUE;
    }
    else if (_tiles[player_index][pos].color == 'U')
    {
    color = PURPLE;
    }
    else if (_tiles[player_index][pos].color == 'N')
    {
    color = BROWN;
    }
    else if (_tiles[player_index][pos].color == 'P')
    {
    color = PINK;
    }
    else if (_tiles[player_index][pos].color == 'O')
    {
    color = ORANGE;
    }
    else if (_tiles[player_index][pos].color == 'W')
    {
    color = WHITE;
    }
    else if (_tiles[player_index][pos].color == 'X') {
        color = DARK_GREY;
    } 
    if (player == true)
    {
    cout << color << "|" << (player_index + 1) << "|" << RESET;
    }
    else
    {
    cout << color << "| |" << RESET;
    }
}
void Board::displayTrack(int player_index) {
    for (int i = 0; i < _BOARD_SIZE; i++) {
        displayTile(player_index, i);
    }
    cout << endl;
}

void Board::displayBoard() {
    for (int i = 0; i < 2; i++) {
        displayTrack(i);
        if (i == 0) {
            cout << endl; // Add an extra line between the two lanes
        }
    }
}
bool Board::movePlayer(int player_index, int movements) {
// Increment player position
    _player_position[player_index] += movements;
    if (_player_position[player_index] == _BOARD_SIZE - 1) {
    // Player reached last tile
        return true;
    }
    return false;
    }

int Board::getPlayerPosition(int player_index) const {
    if (player_index >= 0 && player_index <= _player_count) {
        return _player_position[player_index];
    }
    return -1;
}
