#ifndef CONTEXT_H
#define CONTEXT_H

class Game;
class Menu_manager;
class Menu;
class Menu_option;
class Settings;

struct Context {
    Menu_manager *menu_manager;
    Menu *menu;
    Menu_option *option;
    Game *game;
    Settings *settings;
};

#endif // CONTEXT_H
