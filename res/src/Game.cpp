#include "../include/Game.h"

Game *Game::instance;

Game *Game::Get_instance() {
    if (instance == nullptr) {
        instance = new Game(2);
    }
    return instance;
}

Game::Game(int _number_of_players) {
    number_of_players = _number_of_players;
}

void Game::Clear() {
    Clear_players();
    Reset();
}

void Game::Clear_players() {
    for (int i = 0; i < number_of_players; i++) {
        delete players[i];
    }
    players.clear();
}

void Game::Reset() {
    table.Clear();
    Reset_cursor();
    winner = 0;
    current_player = 0;
    redraw = true;
}

void Game::Start() {
    quit = false;
    Reset_cursor();
    Draw();
    winner = 0;
    while (!quit && winner == 0) {
        Handle_events();
        winner = table.Check_win();
        if (redraw) {
            Draw();
            Sleep(DELAY_BETWEEN_DRAWS);
        }
    }

    if (!quit) {
        Print_winner();
    }

    Clear();
    Sleep(DELAY_BETWEEN_DRAWS);
}

void Game::Exit() {
    quit = true;
}

int Game::Load(char *filename, int difficulty) {
    FILE *in = fopen(filename, "rb");
    if (in == NULL) {
        fprintf(stderr, "Can't load from file %s!", filename);
        return 1;
    }

    table.Load(in);
    fread(&human_player_pos, sizeof(int), 1, in);
    Set_human_player(human_player_pos, difficulty);
    fread(&current_player, sizeof(int), 1, in);
    fclose(in);

    redraw = true;

    return 0;
}

int Game::Save(char *filename) {
    FILE *out = fopen(filename, "wb");
    if (out == NULL) {
        fprintf(stderr, "Can't save to file %s!", filename);
        return 1;
    }

    table.Save(out);
    fwrite(&human_player_pos, sizeof(int), 1, out);
    fwrite(&current_player, sizeof(int), 1, out);
    fclose(out);

    redraw = true;

    return 0;
}

void Game::Set(int _human_player_pos, int table_size, int difficulty) {
    Set_human_player(_human_player_pos, difficulty);
    table.Set_size(table_size);
}

void Game::Set_difficulty(int difficulty) {
    for (int i = 0; i < players.size(); i++) {
        if (i != human_player_pos) {
            delete players[i];
            players[i] = new AI(&cursor, &table, CHARS[i],
                                CHARS[(i + 1) % number_of_players], difficulty);
        }
    }
}

void Game::Set_human_player(int pos, int difficulty) {
    human_player_pos = pos;
    for (int i = 0; i < number_of_players; i++) {
        if (i == human_player_pos) {
            players.push_back(new Player(&cursor, &table, CHARS[i]));
        } else {
            players.push_back(new AI(&cursor, &table, CHARS[i],
                                     CHARS[(i + 1) % number_of_players], difficulty));
        }
    }
}

void Game::Set_color(char ch, COLOR color) {
    table.Set_color(ch, color);
}

void Game::Toggle_redraw() {
    redraw = true;
}

int Game::Get_table_size() {
    return table.Get_size();
}

void Game::Handle_events() {
    players[current_player]->Handle_events();
    redraw = players[current_player]->Get_redraw();
    if (players[current_player]->Get_selected()) {
        Update_current_player();
        Reset_cursor();
    }

    if (Get_key(VK_ESCAPE)) {
        Sleep(DELAY_BETWEEN_DRAWS);
        Menu_manager::Get_instance()->Push_menu("menus/game.menu");
        Menu_manager::Get_instance()->Start();
    }
}

void Game::Draw() {
    system("cls");
    table.Draw();
    cursor.Draw(table.Get(cursor.x, cursor.y));

    char temp[MAX_LENGTH] = {0};
    strcpy(temp, "Player ");
    temp[strlen(temp)] = players[current_player]->Get_char();
    strcat(temp, " , make a move!");
    Draw_string(0, 40, temp);
    redraw = false;
}

void Game::Update_current_player() {
    current_player++;
    current_player %= number_of_players;
}

void Game::Reset_cursor() {
    cursor.x = table.Get_size() / 2;
    cursor.y = table.Get_size() / 2;
}

void Game::Print_winner() {
    if (winner == MATRIX_FULL) {
        Draw_string(0, 40, "Draw!                  ");
    } else {
        char winner_str[MAX_LENGTH] = {0};
        winner_str[0] = winner;
        strcat(winner_str, " wins!!!               ");
        Draw_string(0, 40, winner_str);
    }
    Draw_string(1, 40, "Press ENTER to continue!");
    while (!Get_key(VK_RETURN));
}
