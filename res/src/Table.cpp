#include "../include/Table.h"

Table::Table() {
    Clear();
}

void Table::Set_size(int _size) {
    size = _size;
}

void Table::Clear() {
    memset(matrix, 0, TABLE_SIZE_MAX * TABLE_SIZE_MAX * sizeof(char));
}

void Table::Set(int x, int y, char ch) {
    if (!Cursor_is_valid(x, y)) {
        fprintf(stderr, "Can't set %c, invalid position (%d, %d)\n", ch, x, y);
    } else {
        matrix[x][y] = ch;
    }
}

char Table::Get(int x, int y) {
    if (!Cursor_is_valid(x, y)) {
        return -1;
    }
    return matrix[x][y];
}

void Table::Draw() {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size - 1; j++) {
            printf("     |");
        }
        printf("\n");
        for (int j = 0; j < size; j++) {
            printf("  ");
            if (matrix[i][j] != 0) {
                Set_text_color(color[matrix[i][j]]);
                printf("%c", matrix[i][j]);
            } else {
                printf(" ");
            }
            printf("  ");

            Set_text_color(TEXT_WHITE);
            if (j < size - 1) {
                printf("|");
            }
        }
        if (i < size - 1) {
            printf("\n");
            for (int j = 0; j < size - 1; j++) {
                printf("_____|");
            }
            printf("_____\n");
        }
    }
    printf("\n");
    for (int j = 0; j < size - 1; j++) {
        printf("     |");
    }
    printf("\n");
}

char Table::Check_win() {
    char ch = 0;

    ch = Check_win_all_lines();
    if (ch != 0) {
        return ch;
    }

    ch = Check_win_all_columns();
    if (ch != 0) {
        return ch;
    }

    ch = Check_win_all_diagonals();
    if (ch != 0) {
        return ch;
    }

    if (Check_matrix_full()) {
        return MATRIX_FULL;
    }

    return 0;
}

char Table::Check_win_line(int line) {
    if (!Cursor_is_valid(line, 0)) {
        return 0;
    }

    int column = 1;
    while (column < size && matrix[line][column] == matrix[line][column - 1]) {
        column++;
    }

    if (column == size) {
        return matrix[line][0];
    } else {
        return 0;
    }
}

char Table::Check_win_all_lines() {
    for (int line = 0; line < size; line++) {
        char ch = Check_win_line(line);
        if (ch != 0) {
            return ch;
        }
    }
    return 0;
}

char Table::Check_win_column(int column) {
    if (!Cursor_is_valid(0, column)) {
        return 0;
    }

    int line = 1;
    while (line < size && matrix[line][column] == matrix[line - 1][column]) {
        line++;
    }

    if (line == size) {
        return matrix[0][column];
    } else {
        return 0;
    }
}

char Table::Check_win_all_columns() {
    for (int column = 0; column < size; column++) {
        char ch = Check_win_column(column);
        if (ch != 0) {
            return ch;
        }
    }
    return 0;
}

char Table::Check_win_first_diagonal() {
    int i = 1;
    while (i < size && matrix[i][i] == matrix[i - 1][i - 1]) {
        i++;
    }
    if (i == size) {
        return matrix[0][0];
    } else {
        return 0;
    }
}

char Table::Check_win_second_diagonal() {
    int i = 1;
    while (i < size && matrix[i][size - i - 1] == matrix[i - 1][size - i]) {
        i++;
    }
    if (i == size) {
        return matrix[0][size - 1];
    } else {
        return 0;
    }
}

char Table::Check_win_all_diagonals() {
    char ch = 0;

    ch = Check_win_first_diagonal();
    if (ch != 0) {
        return ch;
    }

    ch = Check_win_second_diagonal();
    if (ch != 0) {
        return ch;
    }

    return 0;
}

bool Table::Check_matrix_full() {
    bool full = true;
    for (int i = 0; i < size && full; i++) {
        for (int j = 0; j < size && full; j++) {
            if (matrix[i][j] == 0) {
                full = false;
            }
        }
    }
    return full;
}

bool Table::Cursor_is_valid(int x, int y) {
    return (x >= 0 && x < size) && (y >= 0 && y < size);
}

void Table::Set_color(char ch, COLOR _color) {
    color[ch] = _color;
}

int Table::Get_size() {
    return size;
}

void Table::Load(FILE *in) {
    fread(&size, sizeof(int), 1, in);
    fread(&matrix, sizeof(char), TABLE_SIZE_MAX * TABLE_SIZE_MAX, in);
}

void Table::Save(FILE *out) {
    fwrite(&size, sizeof(int), 1, out);
    fwrite(&matrix, sizeof(char), TABLE_SIZE_MAX * TABLE_SIZE_MAX, out);
}
