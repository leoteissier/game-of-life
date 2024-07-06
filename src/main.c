#include "../includes/renderer.h"
#include "../includes/grid.h"
#include "../includes/game.h"

int main(int argc, char *argv[]) {
    if (!initSDL()) {
        return 1;
    }

    initGrid();

    bool quit = false;
    bool running = false;
    int offsetX = 0;
    int offsetY = 0;
    int cellSize = CELL_SIZE;

    while (!quit) {
        handleEvents(&quit, &running, &offsetX, &offsetY, &cellSize);

        if (running) {
            updateGrid();
        }

        drawGrid(offsetX, offsetY, cellSize);
        SDL_Delay(DELAY_RENDER);
    }

    closeSDL();
    return 0;
}
