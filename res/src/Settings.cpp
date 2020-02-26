#include "../include/Settings.h"

Settings *Settings::instance;

Settings *Settings::Get_instance() {
    if (instance == nullptr) {
        instance = new Settings;
    }
    return instance;
}

void Settings::Set_difficulty(int _difficulty) {
    difficulty = _difficulty;
}

void Settings::Set_menu_text_color(int _menu_text_color) {
    menu_text_color = _menu_text_color;
}

void Settings::Set_x_color(int _x_color) {
    x_color = _x_color;
}

void Settings::Set_o_color(int _o_color) {
    o_color = _o_color;
}

int Settings::Get_difficulty() {
    return difficulty;
}

int Settings::Get_menu_text_color() {
    return menu_text_color;
}

int Settings::Get_x_color() {
    return x_color;
}

int Settings::Get_o_color() {
    return o_color;
}

int Settings::Save() {
    FILE *out = fopen(SETTINGS_FILE, "wb");
    if (out == NULL) {
        fprintf(stderr, "Can't save settings to file %s!\n", SETTINGS_FILE);
        return 1;
    }

    fwrite(this, sizeof(Settings), 1, out);
    fclose(out);
    return 0;
}

int Settings::Load() {
    FILE *in = fopen(SETTINGS_FILE, "rb");
    if (in == NULL) {
        fprintf(stderr, "Can't open settings file %s!\n", SETTINGS_FILE);
        return 1;
    }

    fread(this, sizeof(Settings), 1, in);
    fclose(in);
    return 0;
}
