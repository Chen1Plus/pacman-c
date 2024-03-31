#include "scenes.h"

#include "scenes/game.h"
#include "scenes/menu.h"
#include "scenes/settings.h"

Scene SCENE_GAME = {.name   = "Game",
                    .init   = game_init,
                    .update = game_update,
                    .draw   = game_draw,
                    .free   = game_free};

Scene SCENE_MENU = {.name   = "Menu",
                    .init   = menu_init,
                    .update = menu_update,
                    .draw   = menu_draw,
                    .free   = menu_free};

Scene SCENE_SETTINGS = {.name   = "Settings",
                        .init   = settings_init,
                        .update = settings_update,
                        .draw   = settings_draw,
                        .free   = settings_free};

void scenes_init() {
    SCENE_GAME.init();
    SCENE_MENU.init();
    SCENE_SETTINGS.init();
}

void scenes_free() {
    SCENE_GAME.free();
    SCENE_MENU.free();
    SCENE_SETTINGS.free();
}