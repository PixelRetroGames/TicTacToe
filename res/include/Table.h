#ifndef TABLE_H
#define TABLE_H

#define TABLE_SIZE_MAX 5

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <map>
#include "Utils.h"

#define MATRIX_FULL -1

class Table {
private:
    int size;
    char matrix[TABLE_SIZE_MAX][TABLE_SIZE_MAX];
    std::map<char, COLOR> color;

public:
    Table();
    void Set_size(int _size);
    void Clear();
    void Set(int x, int y, char ch);
    char Get(int x, int y);
    char Check_win();
    void Draw();
    bool Cursor_is_valid(int x, int y);
    void Set_color(char ch, COLOR _color);
    int Get_size();
    void Load(FILE *in);
    void Save(FILE *out);

private:
    char Check_win_line(int line);
    char Check_win_all_lines();

    char Check_win_column(int column);
    char Check_win_all_columns();

    char Check_win_first_diagonal();
    char Check_win_second_diagonal();
    char Check_win_all_diagonals();

    bool Check_matrix_full();
};

#endif // TABLE_H
