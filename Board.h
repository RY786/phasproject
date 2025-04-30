#ifndef BOARD_H
#define BOARD_H
#include "Tile.h"

class Board
{
private:
    static const int _BOARD_SIZE = 52;
    Tile _tiles[2][_BOARD_SIZE];
    static const int _MAX_PLAYERS = 2;
    int _player_count;
    int _player_position[_MAX_PLAYERS];
    void displayTile(int player_index, int pos);
    void initializeTiles(int player_index, int path);
    bool isPlayerOnTile(int player_index, int pos);
public:
    Board();
    Board(int player_count, int path1, int path2);
    void displayTrack(int player_index);
    void initializeBoard(int path1, int path2);
    void displayBoard();
    void screenRewrite();
    bool movePlayer(int player_index, int movements);
    int getPlayerPosition(int player_index) const;
    char getTileInfo(int pos);
};
#endif

