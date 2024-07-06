#ifndef GAME_OF_LIFE_GRID_H
#define GAME_OF_LIFE_GRID_H

#define GRID_WIDTH 50
#define GRID_HEIGHT 50
#define CELL_SIZE 20

void initGrid();
void toggleCell(int x, int y, int offsetX, int offsetY);
void updateGrid();
bool getCellState(int x, int y);

#endif //GAME_OF_LIFE_GRID_H
