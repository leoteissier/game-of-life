#ifndef GAME_OF_LIFE_RENDERER_H
#define GAME_OF_LIFE_RENDERER_H

#include <SDL2/SDL.h>

bool initSDL();
void closeSDL();
void drawGrid(int offsetX, int offsetY, int cellSize);

extern SDL_Window *window;
extern SDL_Renderer *renderer;

#endif //GAME_OF_LIFE_RENDERER_H
