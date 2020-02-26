#ifndef MENU_OPTION_H
#define MENU_OPTION_H

#define MAX_LENGTH 256

#include <cstring>
#include <string>
#include <map>

#include "Utils.h"
#include "Context.h"

struct Context;

typedef void (*Special_function)(Context*, char*);

class Menu_option {
private:
    char text[MAX_LENGTH];
    int x, y;
    COLOR color;
    char init_function_command[MAX_LENGTH], on_select_function_command[MAX_LENGTH];
    Special_function init_function;
    Special_function on_select_function;

public:
    void Read(FILE *in, std::map<std::string, COLOR> *colors,
              std::map<std::string, Special_function> *functions);

    void Clear();

    void Init(Context *context);
    void Select(Context *context);

    void Set_color(COLOR _color);

    void Draw(bool selected);
};

#endif // MENU_OPTION_H
