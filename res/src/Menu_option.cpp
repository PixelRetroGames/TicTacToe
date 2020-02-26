#include "../include/Menu_option.h"

void Menu_option::Read(FILE *in, std::map<std::string, COLOR> *colors,
          std::map<std::string, Special_function> *functions) {
    fgets(text, MAX_LENGTH, in);
    Remove_endline(text);
    fscanf(in, "%d%d ", &x, &y);

    char color_name[MAX_LENGTH], init_function_name[MAX_LENGTH], on_select_function_name[MAX_LENGTH];
    fgets(color_name, MAX_LENGTH, in);
    Remove_endline(color_name);
    std::string str = color_name;
    if (colors->count(str) != 0) {
        color = (*colors)[str];
    } else {
        fprintf(stderr, "Can't link color %s to option %s!\n", color_name, text);
        color = TEXT_WHITE;
    }

    fgets(init_function_command, MAX_LENGTH, in);
    Remove_endline(init_function_command);
    sscanf(init_function_command, "%s", init_function_name);
    str = init_function_name;
    if (functions->count(str) != 0) {
        init_function = (*functions)[str];
    } else {
        fprintf(stderr, "Can't link init_function %s to option %s!\n",
                init_function_name, text);
        init_function = nullptr;
    }

    fgets(on_select_function_command, MAX_LENGTH, in);
    Remove_endline(on_select_function_command);
    sscanf(on_select_function_command, "%s", on_select_function_name);
    str = on_select_function_name;
    if (functions->count(str) != 0) {
        on_select_function = (*functions)[str];
    } else {
        fprintf(stderr, "Can't link on_select_function %s to option %s!\n",
                on_select_function_name, text);
        on_select_function = nullptr;
    }
    fscanf(in, " ");
}

void Menu_option::Clear() {
    memset(text, 0, MAX_LENGTH);
    memset(init_function_command, 0, MAX_LENGTH);
    memset(on_select_function_command, 0, MAX_LENGTH);
    x = y = 0;
    init_function = on_select_function = nullptr;
    color = TEXT_WHITE;
}

void Menu_option::Init(Context *context) {
    if (init_function != nullptr) {
        init_function(context, init_function_command);
    }
}

void Menu_option::Select(Context *context) {
    if (on_select_function != nullptr) {
        on_select_function(context, on_select_function_command);
    }
}

void Menu_option::Set_color(COLOR _color) {
    color = _color;
}

void Menu_option::Draw(bool selected) {
    if (selected) {
        Set_text_color(color | BG_INTENSITY);
    } else {
        Set_text_color(color);
    }

    Draw_string(x, y, text);

    Set_text_color(TEXT_WHITE);
}
