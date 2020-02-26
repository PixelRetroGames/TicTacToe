#ifndef AI_H
#define AI_H

#include <vector>
#include "Base_player.h"

#define AI_DELAY 200
#define MAX_POINTS 20
#define MAX_DEPTH 3

class AI : public Base_player {
private:
    int difficulty;
    int pos_x, pos_y;
    char other_ch;

public:
    AI(Cursor *_cursor, Table *_table, char _ch, char _other_ch, int _difficulty)
        : Base_player{_cursor, _table, _ch}, pos_x{-1}, pos_y{-1},
          difficulty{_difficulty}, other_ch{_other_ch} {}

    void Handle_events();
    void Set_difficulty(int _dificulty);

private:
    void Move_to_pos();
    void Make_random_move();
    void Make_best_move();
    void Find_best_move();
    int Minimax(Table *temp_table, int depth, bool is_max);
};

#endif // AI_H
