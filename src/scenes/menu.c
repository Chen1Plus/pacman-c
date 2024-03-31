#include "menu.h"

#include <raylib.h>

#include "../game.h"
#include "../utility.h"

static Text hint;
static Texture2D title;
static Button setBtn;

#define MENU_PNG(s) ("assets/menu/" #s ".png")

void menu_init() {
    hint  = new_text("PRESS <ENTER>");
    title = LoadTexture(MENU_PNG(title));
    setBtn =
        new_btn(MENU_PNG(settings), MENU_PNG(settings2), (Vec2){730.F, 20.F});
}

void menu_free() {
    UnloadTexture(title);
    free_btn(&setBtn);
}

void menu_update() {
    update_btn(&setBtn);

    if (IsKeyPressed(KEY_ENTER)) current_scene = &SCENE_GAME;
    if (setBtn.hovered && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
        current_scene = &SCENE_SETTINGS;
}

void menu_draw() {
    DrawTexture(title, SCREEN_W / 2 - title.width / 2,
                SCREEN_H / 2 - title.height * 2 / 3, WHITE);
    draw_text_centered(hint, (Vec2){SCREEN_W / 2.0, SCREEN_H - 150.0}, WHITE);
    draw_btn(&setBtn);
}