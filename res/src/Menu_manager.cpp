#include "../include/Menu_manager.h"

Menu_manager::Menu_manager() {
    colors["BLUE"] = TEXT_BLUE | TEXT_INTENSITY;
    colors["GREEN"] = TEXT_GREEN | TEXT_INTENSITY;
    colors["RED"] = TEXT_RED | TEXT_INTENSITY;
    colors["CYAN"] = TEXT_CYAN | TEXT_INTENSITY;
    colors["MAGENTA"] = TEXT_MAGENTA | TEXT_INTENSITY;
    colors["YELLOW"] = TEXT_YELLOW | TEXT_INTENSITY;
    colors["WHITE"] = TEXT_WHITE | TEXT_INTENSITY;
}

Menu_manager *Menu_manager::instance;

Menu_manager *Menu_manager::Get_instance() {
    if (instance == nullptr) {
        instance = new Menu_manager();
    }
    return instance;
}

void Menu_manager::Set(Game *game, Settings *settings) {
    context.menu_manager = instance;
    context.game = game;
    context.settings = settings;
}

void Menu_manager::Add_function(char *name, Special_function f) {
    functions[name] = f;
}

void Menu_manager::Push_menu(char *filename) {
    Menu menu;
    if (menu.Read(filename, &colors, &functions) != 0) {
        fprintf(stderr, "Can't push menu!\n");
        return;
    }
    menus.push(menu);
    context.menu = &menus.top();
    menus.top().Init(&context);
}

void Menu_manager::Pop_menu() {
    if (menus.empty()) {
        return;
    }

    menus.top().Clear();
    menus.pop();

    if (menus.empty()) {
        return;
    }

    context.menu = &menus.top();
    menus.top().Init(&context);
}

bool Menu_manager::Is_empty() {
    return menus.empty();
}

void Menu_manager::Start() {
    stopped = false;
    while (!menus.empty() && !stopped) {
        Handle_events();
        Draw();
    }

    if (!menus.empty()) {
        menus.top().Toggle_redraw();
    }
}

void Menu_manager::Draw() {
    if (menus.empty()) {
        return;
    }

    menus.top().Draw();
}

void Menu_manager::Handle_events() {
    if (menus.empty()) {
        return;
    }

    menus.top().Handle_events(&context);
}

void Menu_manager::Stop() {
    stopped = true;
}

void Menu_manager::Unstop() {
    stopped = false;
}
