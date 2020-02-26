#ifndef SETTINGS_H
#define SETTINGS_H

#define SETTINGS_FILE "settings.bin"

#include <cstdio>

class Settings {
private:
    static Settings *instance;
    int difficulty, menu_text_color, x_color, o_color;

public:
    static Settings *Get_instance();

    void Set_difficulty(int _difficulty);
    void Set_menu_text_color(int _menu_text_color);
    void Set_x_color(int _x_color);
    void Set_o_color(int _o_color);

    int Get_difficulty();
    int Get_menu_text_color();
    int Get_x_color();
    int Get_o_color();

    int Save();
    int Load();

private:
    Settings() {}
};

#endif // SETTINGS_H
