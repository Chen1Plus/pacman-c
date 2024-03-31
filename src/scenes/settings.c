#include "settings.h"

#include "../game.h"
#include "../utility.h"

static Text title;
static Text hint;

void settings_init() {
    title = new_text("SETTINGS");
    hint  = new_text("PRESS <ESC> TO RETURN");
}

void settings_update() {
    if (IsKeyPressed(KEY_ESCAPE)) current_scene = &SCENE_MENU;
}

void settings_draw() {
    draw_text_centered(title, (Vec2){SCREEN_W / 2.0, 150.F}, WHITE);
    draw_text_centered(hint, (Vec2){SCREEN_W / 2.0, SCREEN_H - 150.0}, WHITE);
}

void settings_free() {}