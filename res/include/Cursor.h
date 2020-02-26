#ifndef CURSOR_H
#define CURSOR_H

#include "Utils.h"

#define CELL_HEIGHT 3
#define CELL_WIDTH 5

class Cursor {
public:
    int x, y;

public:
    void Draw(char ch);
};

#endif // CURSOR_H
