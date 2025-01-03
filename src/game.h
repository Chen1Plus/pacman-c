#ifndef GAME_H
#define GAME_H

#include <stdbool.h>

#include "scenes.h"

// ============   Basic Game Info   ============
#define SCREEN_W 800
#define SCREEN_H 800
#define FPS 60

// ===============  Game States  ===============
extern Scene *current_scene;
extern bool game_end;

#endif  // GAME_H