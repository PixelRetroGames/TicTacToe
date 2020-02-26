#ifndef MENU_FUNCTIONS_H
#define MENU_FUNCTIONS_H

#include "Menu_manager.h"
#include "Game.h"
#include "Settings.h"

#define FUNCTION_FORMAT Context *context, char *cmd

void None(FUNCTION_FORMAT);

void New_game(FUNCTION_FORMAT);

void Push_menu(FUNCTION_FORMAT);
void Pop_menu(FUNCTION_FORMAT);
void Stop_menu(FUNCTION_FORMAT);

void Read_x_color(FUNCTION_FORMAT);
void Change_x_color(FUNCTION_FORMAT);
void Read_o_color(FUNCTION_FORMAT);
void Change_o_color(FUNCTION_FORMAT);
void Read_menu_color(FUNCTION_FORMAT);
void Change_menu_color(FUNCTION_FORMAT);

void Change_difficulty(FUNCTION_FORMAT);

void Restart_game(FUNCTION_FORMAT);
void Exit_game(FUNCTION_FORMAT);
void Save_game(FUNCTION_FORMAT);
void Load_game(FUNCTION_FORMAT);
void Load_game_clean(FUNCTION_FORMAT);

#endif // MENU_FUNCTIONS_H
