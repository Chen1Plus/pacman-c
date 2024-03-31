#include <raylib.h>

#include "game.h"
#include "utility.h"

int main(void) {
    // initialize raylib
    SetTraceLogLevel(LOG_WARNING);
    InitAudioDevice();
    InitWindow(SCREEN_W, SCREEN_H, "Pacman");
    SetTargetFPS(FPS);
    SetExitKey(KEY_NULL);

    // initialize game
    assets_init();
    scenes_init();

    // main loop
    while (!WindowShouldClose()) {
        current_scene->update();

        BeginDrawing();
        ClearBackground(BLACK);
        current_scene->draw();
        EndDrawing();
    }

    // free game
    scenes_free();
    assets_free();

    // unload raylib
    CloseWindow();
    CloseAudioDevice();
}
