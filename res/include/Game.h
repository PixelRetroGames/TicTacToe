#ifndef GAME_H
#define GAME_H

#include <vector>
#include "Player.h"
#include "AI.h"
#include "Cursor.h"
#include "Menu_manager.h"

const char CHARS[] = {"XO"};

class Game {
private:
    static Game *instance;
    Table table;
    Cursor cursor;
    std::vector<Base_player*> players;

    bool quit, redraw;
    int human_player_pos;
    int number_of_players = 2;
    int current_player = 0;
    char winner = 0;

public:
    static Game *Get_instance();

    void Clear();
    void Clear_players();
    void Reset();

    void Start();
    void Exit();

    int Load(char *filename, int difficulty);
    int Save(char *filename);

    void Set(int _human_player_pos, int table_size, int difficulty);
    void Set_difficulty(int difficulty);
    void Set_human_player(int pos, int difficulty);
    void Set_color(char ch, COLOR color);
    void Toggle_redraw();

    int Get_table_size();

private:
    Game(int _number_of_players);

    void Handle_events();
    void Draw();
    void Update_current_player();
    void Reset_cursor();
    void Print_winner();
};

#endif // GAME_H
