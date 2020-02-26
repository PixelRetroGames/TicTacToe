#include "../include/AI.h"

void AI::Handle_events() {
    keys.reset();
    if (difficulty == 0) {
        Make_random_move();
    } else {
        Make_best_move();
    }
    Update();
    Sleep(AI_DELAY);
}

void AI::Set_difficulty(int _dificulty) {
    difficulty = _dificulty;
}

void AI::Move_to_pos() {
    if (pos_x == cursor->x && pos_y == cursor->y){
        keys[KEY_SELECT] = true;
        pos_x = -1;
    } else {
        int dx = pos_x - cursor->x;
        int dy = pos_y - cursor->y;
        if (dx != 0) {
            keys[dx > 0 ? KEY_DOWN : KEY_UP] = true;
        } else {
            keys[dy > 0 ? KEY_RIGHT : KEY_LEFT] = true;
        }
    }
}

void AI::Make_random_move() {
    if (pos_x == -1) {
        std::vector<std::pair<int, int>> free_positions;
        for (int i = 0; i < table->Get_size(); i++) {
            for (int j = 0; j < table->Get_size(); j++) {
                if (table->Get(i, j) == 0) {
                    free_positions.push_back(std::make_pair(i, j));
                }
            }
        }
        int r = rand() % free_positions.size();
        pos_x = free_positions[r].first;
        pos_y = free_positions[r].second;
        free_positions.clear();
    } else {
        Move_to_pos();
    }
}

void AI::Make_best_move() {
    if (pos_x == -1) {
        Find_best_move();
    } else {
        Move_to_pos();
    }
}

void AI::Find_best_move() {
    int best = -INT_MAX;
    Table temp_table = *table;

    for (int i = 0; i < temp_table.Get_size(); i++) {
        for (int j = 0; j < temp_table.Get_size(); j++) {
            if (temp_table.Get(i, j) == 0) {
                temp_table.Set(i, j, ch);
                int move_val = Minimax(&temp_table, 0, false);
                temp_table.Set(i, j, 0);

                if (move_val > best) {
                    pos_x = i;
                    pos_y = j;
                    best = move_val;
                }
            }
        }
    }
}

int AI::Minimax(Table *temp_table, int depth, bool is_max) {
    char winner = temp_table->Check_win();
    if (winner == ch) {
        return MAX_POINTS;
    } else if (winner == other_ch) {
        return -MAX_POINTS;
    } else if (winner == -1 || depth > MAX_DEPTH) {
        return 0;
    }

    int best = (is_max ? -1 : 1) * INT_MAX;
    for (int i = 0; i < temp_table->Get_size(); i++) {
        for (int j = 0; j < temp_table->Get_size(); j++) {
            if (temp_table->Get(i, j) == 0) {
                if (is_max) {
                    temp_table->Set(i, j, ch);
                    best = std::max(best,
                           Minimax(temp_table, depth + 1, !is_max));
                } else {
                    temp_table->Set(i, j, other_ch);
                    best = std::min(best,
                           Minimax(temp_table, depth + 1, !is_max));
                }
                temp_table->Set(i, j, 0);
            }
        }
    }

    return best;
}
