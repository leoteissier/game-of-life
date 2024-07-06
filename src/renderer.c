#include "../includes/renderer.h"
#include "../includes/grid.h"

SDL_Window *window = NULL;
SDL_Renderer *renderer = NULL;

bool initSDL() {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        fprintf(stderr, "Could not initialize SDL: %s\n", SDL_GetError());
        return false;
    }

    window = SDL_CreateWindow("Jeu de la Vie", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_RESIZABLE);
    if (!window) {
        fprintf(stderr, "Could not create window: %s\n", SDL_GetError());
        SDL_Quit();
        return false;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        SDL_DestroyWindow(window);
        fprintf(stderr, "Could not create renderer: %s\n", SDL_GetError());
        SDL_Quit();
        return false;
    }

    return true;
}

void closeSDL() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void drawGrid(int offsetX, int offsetY, int cellSize) {
    int windowWidth, windowHeight;
    SDL_GetWindowSize(window, &windowWidth, &windowHeight);

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
    SDL_RenderClear(renderer);

    for (int i = 0; i < windowWidth; i += cellSize) {
        for (int j = 0; j < windowHeight; j += cellSize) {
            int gridX = (i + offsetX) / cellSize;
            int gridY = (j + offsetY) / cellSize;

            if (getCellState(gridX * cellSize, gridY * cellSize)) {
                SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
                SDL_Rect cellRect = { i, j, cellSize, cellSize };
                SDL_RenderFillRect(renderer, &cellRect);
            }

            // Draw the cell border
            SDL_SetRenderDrawColor(renderer, 200, 200, 200, SDL_ALPHA_OPAQUE);
            SDL_Rect borderRect = { i, j, cellSize, cellSize };
            SDL_RenderDrawRect(renderer, &borderRect);
        }
    }

    SDL_RenderPresent(renderer);
}
