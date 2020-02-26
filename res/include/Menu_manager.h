#ifndef MENU_MANAGER_H
#define MENU_MANAGER_H

#include <stack>
#include "Menu.h"
#include "Context.h"

class Menu_manager {
private:
    static Menu_manager *instance;

    std::stack<Menu> menus;
    Context context;
    std::map<std::string, COLOR> colors;
    std::map<std::string, Special_function> functions;
    bool stopped;

public:
    static Menu_manager *Get_instance();

    void Set(Game *game, Settings *settings);

    void Add_function(char *name, Special_function f);

    void Push_menu(char *filename);
    void Pop_menu();
    bool Is_empty();

    void Start();
    void Draw();
    void Handle_events();

    void Stop();
    void Unstop();

private:
    Menu_manager();
};

#endif // MENU_MANAGER_H
