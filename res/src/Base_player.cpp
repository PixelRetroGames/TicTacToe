#include "../include/Base_player.h"

Base_player::Base_player(Cursor *_cursor, Table *_table, char _ch) {
    cursor = _cursor;
    table = _table;
    ch = _ch;
}

char Base_player::Get_char() {
    return ch;
}

bool Base_player::Get_selected() {
    return selected;
}

bool Base_player::Get_redraw() {
    return redraw;
}

void Base_player::Update() {
    selected = false;
    redraw = false;
    int dx = 0, dy = 0;
    if (keys[KEY_UP]) {
        dx = -1;
    } else if (keys[KEY_DOWN]) {
        dx = 1;
    } else if (keys[KEY_LEFT]) {
        dy = -1;
    } else if (keys[KEY_RIGHT]) {
        dy = 1;
    } else if (keys[KEY_SELECT]) {
        if (table->Get(cursor->x, cursor->y) == 0) {
            table->Set(cursor->x, cursor->y, ch);
            redraw = true;
            selected = true;
        }
    }

    if ((dx != 0 || dy != 0) &&
        table->Cursor_is_valid(cursor->x + dx, cursor->y + dy)) {
        cursor->x += dx;
        cursor->y += dy;
        redraw = true;
    }
}
