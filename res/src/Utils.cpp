#include "../include/Utils.h"

void Remove_endline(char *s) {
    int n = strlen(s);
    if (s[n - 1] == '\n') {
        s[n - 1] = '\0';
    }
}

void Set_text_color(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void Goto_xy(int x, int y) {
    COORD coord;
    coord.X = y;
    coord.Y = x;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void Draw_char(int x, int y, char ch) {
    Goto_xy(x, y);
    _putch(ch);
}

void Draw_string(int x, int y, char *s) {
    Goto_xy(x, y);
    _cprintf(s);
}

bool Get_key(int key) {
    return (GetAsyncKeyState(key) & 0x8000) > 0;
}

void Hide_cursor() {
    HANDLE hOut;
    CONSOLE_CURSOR_INFO ConCurInf;

    hOut = GetStdHandle(STD_OUTPUT_HANDLE);

    ConCurInf.dwSize = 10;
    ConCurInf.bVisible = FALSE;

    SetConsoleCursorInfo(hOut, &ConCurInf);
}

void Toggle_fullscreen() {
    keybd_event(VK_MENU,0x38,0,0);
    keybd_event(VK_RETURN,0x1c,0,0);
    keybd_event(VK_RETURN,0x1c,KEYEVENTF_KEYUP,0);
    keybd_event(VK_MENU,0x38,KEYEVENTF_KEYUP,0);
}


