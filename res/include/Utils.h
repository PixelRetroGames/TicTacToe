#ifndef UTILS_H
#define UTILS_H

#include <conio.h>
#include <stdlib.h>
#include <windows.h>

#define DELAY_BETWEEN_DRAWS 150

enum COLOR {
    TEXT_BLUE=     FOREGROUND_BLUE,
    TEXT_GREEN=    FOREGROUND_GREEN,
    TEXT_RED=      FOREGROUND_RED,
    TEXT_CYAN=     TEXT_GREEN | TEXT_BLUE,
    TEXT_MAGENTA=  TEXT_RED | TEXT_BLUE,
    TEXT_YELLOW=   TEXT_RED | TEXT_GREEN,
    TEXT_WHITE=    TEXT_RED | TEXT_GREEN | TEXT_BLUE,
    TEXT_INTENSITY=FOREGROUND_INTENSITY,
    BG_BLUE=       BACKGROUND_BLUE,
    BG_GREEN=      BACKGROUND_GREEN,
    BG_RED=        BACKGROUND_RED,
    BG_CYAN=       BG_GREEN | BG_BLUE,
    BG_MAGENTA=    BG_RED | BG_BLUE,
    BG_YELLOW=     BG_RED | BG_GREEN,
    BG_WHITE=      BG_RED | BG_GREEN | BG_BLUE,
    BG_INTENSITY=  BACKGROUND_INTENSITY
};

void Remove_endline(char *s);

void Set_text_color(int color);

void Goto_xy(int x, int y);

void Draw_char(int x, int y, char ch);
void Draw_string(int x, int y, char *s);

bool Get_key(int key);

void Hide_cursor();

void Toggle_fullscreen();

#endif // UTILS_H

