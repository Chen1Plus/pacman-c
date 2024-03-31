#ifndef SCENES_H
#define SCENES_H

typedef struct {
    char *name;
    // basic functions
    void (*init)();
    void (*update)();
    void (*draw)();
    void (*free)();
} Scene;

void scenes_init();
void scenes_free();

extern Scene SCENE_GAME;
extern Scene SCENE_MENU;
extern Scene SCENE_SETTINGS;

#endif  // SCENES_H