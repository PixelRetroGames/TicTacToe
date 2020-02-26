#ifndef BASE_PLAYER_H
#define BASE_PLAYER_H

#include <bitset>
#include "Table.h"
#include "Cursor.h"
#include "Utils.h"

enum KEYS {
    KEY_UP,
    KEY_DOWN,
    KEY_LEFT,
    KEY_RIGHT,
    KEY_SELECT
};

class Base_player {
protected:
    bool selected = 0;
    bool redraw = 0;
    char ch;
    Cursor *cursor;
    Table *table;
    std::bitset<5> keys;

public:
    Base_player(Cursor *_cursor, Table *_table, char _ch);
    virtual ~Base_player() {}

    char Get_char();
    bool Get_selected();
    bool Get_redraw();

    void Update();
    virtual void Handle_events() {}
};

#endif // BASE_PLAYER_H
