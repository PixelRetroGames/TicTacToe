#include "../include/Menu_functions_link.h"

void Menu_functions_link(Menu_manager *manager) {
    const int number_of_functions = 17;
    const char *names[] =                {"NONE", "NEW_GAME", "PUSH_MENU",
    "POP_MENU", "READ_X_COLOR", "CHANGE_X_COLOR", "READ_O_COLOR", "CHANGE_O_COLOR",
    "READ_MENU_COLOR", "CHANGE_MENU_COLOR", "RESTART_GAME", "EXIT_GAME", "STOP_MENU",
    "SAVE_GAME", "LOAD_GAME", "LOAD_GAME_CLEAN", "CHANGE_DIFFICULTY"};

    const Special_function functions[] = { None ,  New_game  , Push_menu ,
     Pop_menu ,  Read_x_color,   Change_x_color ,  Read_o_color ,  Change_o_color ,
     Read_menu_color ,  Change_menu_color ,  Restart_game,   Exit_game ,  Stop_menu ,
     Save_game ,  Load_game ,  Load_game_clean ,  Change_difficulty};

    for (int i = 0; i < number_of_functions; i++) {
        manager->Add_function(names[i], functions[i]);
    }
}
