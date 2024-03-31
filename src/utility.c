#include "utility.h"

Font MENU_FT;
Sound BGM;

Text new_text(const char *str) {
    return (Text){
        .str  = str,
        .size = MeasureTextEx(MENU_FT, str, (float)MENU_FT.baseSize, 2)};
}

void draw_text_centered(Text text, Vec2 pos, Color tint) {
    DrawTextEx(MENU_FT, text.str,
               (Vec2){pos.x - text.size.x / 2.0F, pos.y - text.size.y / 2.0F},
               (float)MENU_FT.baseSize, 2, tint);
}

Button new_btn(const char *img, const char *img_h, Vec2 pos) {
    Button btn = {.img = LoadTexture(img), .img_hover = LoadTexture(img_h)};
    btn.rect   = (Rectangle){pos.x, pos.y, btn.img.width, btn.img.height};

    if (btn.img.width != btn.img_hover.width ||
        btn.img.height != btn.img_hover.height)
        TraceLog(LOG_WARNING, "Button images have different sizes");

    return btn;
}

void free_btn(Button *btn) {
    UnloadTexture(btn->img);
    UnloadTexture(btn->img_hover);
}

void draw_btn(Button *btn) {
    DrawTexture(btn->hovered ? btn->img_hover : btn->img, (int)btn->rect.x,
                (int)btn->rect.y, WHITE);
}

void update_btn(Button *btn) {
    btn->hovered = CheckCollisionPointRec(GetMousePosition(), btn->rect);
}

void assets_init() {
    MENU_FT = LoadFontEx("assets/monaspace_krypton.ttf", 30, 0, 250);
    BGM     = LoadSound("assets/sounds/theme.ogg");
}

void assets_free() {
    UnloadFont(MENU_FT);
    UnloadSound(BGM);
}