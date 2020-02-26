#ifndef MENU_H
#define MENU_H

#include <vector>
#include "Menu_option.h"
#include "Utils.h"

class Menu {
private:
    std::vector<Menu_option> options;
    int number_of_options, current_option;
    char title[MAX_LENGTH];
    int x, y;
    bool redraw;

public:
    Menu();
    int Read(char *filename, std::map<std::string, COLOR> *colors,
             std::map<std::string, Special_function> *functions);
    void Clear();
    void Init(Context *context);
    void Handle_events(Context *context);
    void Draw();
    void Toggle_redraw();
};

#endif // MENU_H
