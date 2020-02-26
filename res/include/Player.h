#ifndef PLAYER_H
#define PLAYER_H

#include "Base_player.h"

class Player : public Base_player {
public:
    Player(Cursor *_cursor, Table *_table, char _ch)
        : Base_player{_cursor, _table, _ch} {}
    void Handle_events();
};

#endif // PLAYER_H
