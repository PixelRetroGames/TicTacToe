#include "../include/Cursor.h"

void Cursor::Draw(char ch) {
    if (ch == 0) {
        Set_text_color(BACKGROUND_GREEN);
    } else {
        Set_text_color(BACKGROUND_RED);
    }

    Draw_string(x * CELL_HEIGHT, y * (CELL_WIDTH + 1), "     ");
    Draw_string((x + 1) * CELL_HEIGHT - 1, y * (CELL_WIDTH + 1), "     ");
    for (int i = 1; i < CELL_HEIGHT - 1; i++) {
        Draw_char(x * CELL_HEIGHT + i, y * (CELL_WIDTH + 1), ' ');
        Draw_char(x * CELL_HEIGHT + i, (y + 1) * (CELL_WIDTH + 1) - 2, ' ');
    }
    Goto_xy(0, 0);
    Set_text_color(TEXT_WHITE);
}
