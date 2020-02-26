#include "../include/Menu_functions.h"

const int NR_SELECTABLE_COLORS = 6;
const COLOR SELECTABLE_COLORS[NR_SELECTABLE_COLORS] = {TEXT_BLUE, TEXT_GREEN, TEXT_RED, TEXT_CYAN, TEXT_MAGENTA, TEXT_WHITE};

void None(FUNCTION_FORMAT) {}

void New_game(FUNCTION_FORMAT) {
    char junk[MAX_LENGTH];
    int player_pos, table_size;
    sscanf(cmd, "%s %d %d", junk, &player_pos, &table_size);

    context->game->Set(player_pos, table_size, context->settings->Get_difficulty());
    context->game->Set_color('X', SELECTABLE_COLORS[context->settings->Get_x_color()] | TEXT_INTENSITY);
    context->game->Set_color('O', SELECTABLE_COLORS[context->settings->Get_o_color()] | TEXT_INTENSITY);
    context->game->Start();
    context->menu_manager->Unstop();
}

void Push_menu(FUNCTION_FORMAT) {
    char filename[MAX_LENGTH], junk[MAX_LENGTH];
    sscanf(cmd, "%s %s", junk, filename); // Skip command name
    context->menu_manager->Push_menu(filename);
}

void Pop_menu(FUNCTION_FORMAT) {
    context->menu_manager->Pop_menu();
}

void Read_x_color(FUNCTION_FORMAT) {
    context->option->Set_color(SELECTABLE_COLORS[context->settings->Get_x_color()] | TEXT_INTENSITY);
}

void Change_x_color(FUNCTION_FORMAT) {
    int color = (context->settings->Get_x_color() + 1) % NR_SELECTABLE_COLORS;
    if (color == context->settings->Get_o_color()) {
        color = (color + 1) % NR_SELECTABLE_COLORS;
    }
    context->settings->Set_x_color(color);
    context->option->Set_color(SELECTABLE_COLORS[color] | TEXT_INTENSITY);
    context->settings->Save();
    context->game->Set_color('X', SELECTABLE_COLORS[color] | TEXT_INTENSITY);
}

void Read_o_color(FUNCTION_FORMAT) {
    context->option->Set_color(SELECTABLE_COLORS[context->settings->Get_o_color()] | TEXT_INTENSITY);
}

void Change_o_color(FUNCTION_FORMAT) {
    int color = (context->settings->Get_o_color() + 1) % NR_SELECTABLE_COLORS;
    if (color == context->settings->Get_x_color()) {
        color = (color + 1) % NR_SELECTABLE_COLORS;
    }
    context->settings->Set_o_color(color);
    context->option->Set_color(SELECTABLE_COLORS[color] | TEXT_INTENSITY);
    context->settings->Save();
    context->game->Set_color('O', SELECTABLE_COLORS[color] | TEXT_INTENSITY);
}

void Read_menu_color(FUNCTION_FORMAT) {
    context->option->Set_color(SELECTABLE_COLORS[context->settings->Get_menu_text_color()] | TEXT_INTENSITY);
}

void Change_menu_color(FUNCTION_FORMAT) {
    int color = (context->settings->Get_menu_text_color() + 1) % NR_SELECTABLE_COLORS;
    context->settings->Set_menu_text_color(color);
    context->option->Set_color(SELECTABLE_COLORS[color] | TEXT_INTENSITY);
    context->settings->Save();
    context->menu->Init(context);
}

void Change_difficulty(FUNCTION_FORMAT) {
    char junk[MAX_LENGTH];
    int difficulty;
    sscanf(cmd, "%s %d", junk, &difficulty);

    context->settings->Set_difficulty(difficulty);
    context->settings->Save();

    context->game->Set_difficulty(difficulty);

    Set_text_color(context->settings->Get_menu_text_color() | TEXT_INTENSITY);
    Draw_string(1, 0, "Difficulty changed!!");
    Set_text_color(TEXT_WHITE);
    Sleep(3 * DELAY_BETWEEN_DRAWS);
}

void Restart_game(FUNCTION_FORMAT) {
    context->game->Reset();
    context->menu_manager->Pop_menu();
    context->menu_manager->Stop();
}

void Exit_game(FUNCTION_FORMAT) {
    context->game->Exit();
    context->menu_manager->Pop_menu();
    context->menu_manager->Stop();
}

void Save_game(FUNCTION_FORMAT) {
    char save_file[MAX_LENGTH], table_size_str[MAX_LENGTH];
    sprintf(table_size_str, "%d", context->game->Get_table_size());

    strcpy(save_file, "saves/game");
    strcat(save_file, table_size_str);
    strcat(save_file, ".sav");

    context->game->Save(save_file);
    context->menu_manager->Pop_menu();
    context->menu_manager->Stop();
}

void Load_game(FUNCTION_FORMAT) {
    char save_file[MAX_LENGTH], table_size_str[MAX_LENGTH];
    sprintf(table_size_str, "%d", context->game->Get_table_size());

    strcpy(save_file, "saves/game");
    strcat(save_file, table_size_str);
    strcat(save_file, ".sav");

    context->game->Load(save_file, context->settings->Get_difficulty());
    context->menu_manager->Pop_menu();
    context->menu_manager->Stop();
}

void Load_game_clean(FUNCTION_FORMAT) {
    char junk[MAX_LENGTH], save_file[MAX_LENGTH], table_size_str[MAX_LENGTH];
    sscanf(cmd, "%s %s", junk, table_size_str);

    strcpy(save_file, "saves/game");
    strcat(save_file, table_size_str);
    strcat(save_file, ".sav");

    context->game->Load(save_file, context->settings->Get_difficulty());
    context->game->Set_color('X', SELECTABLE_COLORS[context->settings->Get_x_color()] | TEXT_INTENSITY);
    context->game->Set_color('O', SELECTABLE_COLORS[context->settings->Get_o_color()] | TEXT_INTENSITY);
    context->game->Start();
    context->menu_manager->Unstop();
}

void Stop_menu(FUNCTION_FORMAT) {
    context->menu_manager->Pop_menu();
    context->menu_manager->Stop();
    context->game->Toggle_redraw();
}
