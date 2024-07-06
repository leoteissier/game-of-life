#include "../includes/grid.h"

static bool grid[GRID_WIDTH][GRID_HEIGHT];

void initGrid() {
    for (int i = 0; i < GRID_WIDTH; i++) {
        for (int j = 0; j < GRID_HEIGHT; j++) {
            grid[i][j] = false;
        }
    }
}

void toggleCell(int gridX, int gridY, int offsetX, int offsetY) {
    if (gridX >= 0 && gridX < GRID_WIDTH && gridY >= 0 && gridY < GRID_HEIGHT) {
        grid[gridX][gridY] = !grid[gridX][gridY];
    }
}

void updateGrid() {
    bool newGrid[GRID_WIDTH][GRID_HEIGHT] = { false };

    for (int i = 0; i < GRID_WIDTH; i++) {
        for (int j = 0; j < GRID_HEIGHT; j++) {
            int aliveNeighbors = 0;

            for (int dx = -1; dx <= 1; dx++) {
                for (int dy = -1; dy <= 1; dy++) {
                    if (dx == 0 && dy == 0) continue;

                    int nx = i + dx;
                    int ny = j + dy;

                    if (nx >= 0 && nx < GRID_WIDTH && ny >= 0 && ny < GRID_HEIGHT) {
                        if (grid[nx][ny]) aliveNeighbors++;
                    }
                }
            }

            if (grid[i][j]) {
                newGrid[i][j] = aliveNeighbors == 2 || aliveNeighbors == 3;
            } else {
                newGrid[i][j] = aliveNeighbors == 3;
            }
        }
    }

    for (int i = 0; i < GRID_WIDTH; i++) {
        for (int j = 0; j < GRID_HEIGHT; j++) {
            grid[i][j] = newGrid[i][j];
        }
    }
}

bool getCellState(int x, int y) {
    int gridX = x / CELL_SIZE;
    int gridY = y / CELL_SIZE;
    if (gridX >= 0 && gridX < GRID_WIDTH && gridY >= 0 && gridY < GRID_HEIGHT) {
        return grid[gridX][gridY];
    }
    return false;
}
