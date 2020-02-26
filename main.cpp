#include "res/include/Menu_functions_link.h"
#include <cstdio>

int main() {
    Hide_cursor();
    freopen("log.txt", "wt", stderr);

    Settings::Get_instance()->Load();

    Menu_functions_link(Menu_manager::Get_instance());
    Menu_manager::Get_instance()->Set(Game::Get_instance(), Settings::Get_instance());
    Menu_manager::Get_instance()->Push_menu("menus/main_menu.menu");
    Menu_manager::Get_instance()->Start();

    return 0;
}
