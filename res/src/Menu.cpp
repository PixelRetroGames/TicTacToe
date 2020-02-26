#include "../include/Menu.h"

Menu::Menu() {
    number_of_options = 0;
    current_option = 0;
    redraw = true;
}

int Menu::Read(char *filename, std::map<std::string, COLOR> *colors,
               std::map<std::string, Special_function> *functions) {
    FILE *in = fopen(filename, "rt");
    if (in == NULL) {
        fprintf(stderr, "Can't open %s!\n", filename);
        return 1;
    }

    fgets(title, MAX_LENGTH, in);
    Remove_endline(title);
    fscanf(in, "%d%d", &x, &y);
    fscanf(in, "%d ", &number_of_options);
    Menu_option option;
    for (int i = 0; i < number_of_options; i++) {
        option.Read(in, colors, functions);
        options.push_back(option);
    }

    fclose(in);
    return 0;
}

void Menu::Clear() {
    for (int i = 0; i < number_of_options; i++) {
        options[i].Clear();
    }
    options.clear();

    number_of_options = 0;
    current_option = 0;
}

void Menu::Init(Context *context) {
    for (int i = 0; i < number_of_options; i++) {
        context->option = &options[i];
        options[i].Init(context);
    }
}

void Menu::Handle_events(Context *context) {
    if (Get_key(VK_UP) && current_option > 0) {
        redraw = true;
        current_option--;
    } else if (Get_key(VK_DOWN) && current_option < number_of_options - 1) {
        redraw = true;
        current_option++;
    } else if (Get_key(VK_RETURN)) {
        redraw = true;
        context->option = &options[current_option];
        Sleep(DELAY_BETWEEN_DRAWS);
        options[current_option].Select(context);
    }
}

void Menu::Draw() {
    if (!redraw) {
        return;
    }

    system("cls");
    Draw_string(x, y, title);
    for (int i = 0; i < number_of_options; i++) {
        options[i].Draw(i == current_option);
    }

    Sleep(DELAY_BETWEEN_DRAWS);

    redraw = false;
}

void Menu::Toggle_redraw() {
    redraw = true;
}
