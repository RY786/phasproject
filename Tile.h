#ifndef TILE_H
#define TILE_H


#include <string>
#include "Character.h"
using namespace std;

struct Tile {
    Character tileAttributes(Character tempC, char currentTile);
    char color;
    char tileType;
};

#endif //TILE_H