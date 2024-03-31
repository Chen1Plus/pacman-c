#ifndef UTILITY_H
#define UTILITY_H

#include <raylib.h>

// simplify Vector2 from raylib
#define Vec2 Vector2

typedef enum { UP, DOWN, LEFT, RIGHT } Direction;

// ===============   Object: Text   ===============
//    for constant text to be displayed centered
//           (font: MENU_FT, size: 32)
typedef struct {
    const char *str;
    Vec2 size;
} Text;
// ------------------------------------------------
Text new_text(const char *str);
void draw_text_centered(Text text, Vec2 pos, Color tint);

// ===============  Object: Button  ===============
typedef struct {
    bool hovered;
    Rectangle rect;
    Texture2D img;
    Texture2D img_hover;
} Button;
// ------------------------------------------------
Button new_btn(const char *img, const char *img_h, Vec2 pos);
void free_btn(Button *btn);
void draw_btn(Button *btn);
void update_btn(Button *btn);

// ===============   Global Assets   ===============
void assets_init();
void assets_free();
// -------------------------------------------------
extern Font MENU_FT;
extern Sound BGM;

#endif