#include "../includes/game.h"
#include "../includes/renderer.h"
#include "../includes/grid.h"
#include <SDL2/SDL.h>

void handleEvents(bool *quit, bool *running, int *offsetX, int *offsetY, int *cellSize) {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            *quit = true;
        } else if (event.type == SDL_MOUSEBUTTONDOWN) {
            int x, y;
            SDL_GetMouseState(&x, &y);
            int gridX = (x + *offsetX) / *cellSize;
            int gridY = (y + *offsetY) / *cellSize;
            toggleCell(gridX, gridY, 0, 0);
        } else if (event.type == SDL_MOUSEWHEEL) {
            int mouseX, mouseY;
            SDL_GetMouseState(&mouseX, &mouseY);
            int oldCellSize = *cellSize;
            if (event.wheel.y > 0) {
                *cellSize += ZOOM_SPEED; // Increase cell size for zooming in
            } else if (event.wheel.y < 0) {
                if (*cellSize > 1) {
                    *cellSize -= ZOOM_SPEED; // Decrease cell size for zooming out
                }
            }
            // Adjust offsets to keep the zoom centered on the cursor
            *offsetX = *offsetX + (mouseX * (oldCellSize - *cellSize)) / oldCellSize;
            *offsetY = *offsetY + (mouseY * (oldCellSize - *cellSize)) / oldCellSize;
        } else if (event.type == SDL_KEYDOWN) {
            switch (event.key.keysym.sym) {
                case SDLK_SPACE:
                    *running = !*running;
                    break;
                case SDLK_UP:
                    *offsetY -= *cellSize;
                    break;
                case SDLK_DOWN:
                    *offsetY += *cellSize;
                    break;
                case SDLK_LEFT:
                    *offsetX -= *cellSize;
                    break;
                case SDLK_RIGHT:
                    *offsetX += *cellSize;
                    break;
            }
        } else if (event.type == SDL_WINDOWEVENT) {
            if (event.window.event == SDL_WINDOWEVENT_RESIZED) {
                SDL_SetWindowSize(window, event.window.data1, event.window.data2);
            }
        }
    }
}
