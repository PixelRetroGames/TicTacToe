#include "../include/Player.h"

void Player::Handle_events() {
    keys[KEY_UP] = Get_key(VK_UP);
    keys[KEY_DOWN] = Get_key(VK_DOWN);
    keys[KEY_LEFT] = Get_key(VK_LEFT);
    keys[KEY_RIGHT] = Get_key(VK_RIGHT);
    keys[KEY_SELECT] = Get_key(VK_RETURN);
    Update();
}
