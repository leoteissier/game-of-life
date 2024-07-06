#include <CUnit/Basic.h>
#include "../includes/grid.h"

void test_initGrid() {
    initGrid();
    for (int i = 0; i < GRID_WIDTH; i++) {
        for (int j = 0; j < GRID_HEIGHT; j++) {
            CU_ASSERT_FALSE(getCellState(i * CELL_SIZE, j * CELL_SIZE));
        }
    }
}

void test_toggleCell() {
    initGrid();
    toggleCell(0, 0, 0, 0);
    CU_ASSERT_TRUE(getCellState(0, 0));
    toggleCell(0, 0, 0, 0);
    CU_ASSERT_FALSE(getCellState(0, 0));
}

void test_updateGrid() {
    initGrid();
    toggleCell(1, 0, 0, 0);
    toggleCell(1, 1, 0, 0);
    toggleCell(1, 2, 0, 0);

    updateGrid();
    CU_ASSERT_TRUE(getCellState(0 * CELL_SIZE, 1 * CELL_SIZE));
    CU_ASSERT_TRUE(getCellState(1 * CELL_SIZE, 1 * CELL_SIZE));
    CU_ASSERT_TRUE(getCellState(2 * CELL_SIZE, 1 * CELL_SIZE));
}

void test_gridEdges() {
    initGrid();
    toggleCell(0, 0, 0, 0);
    updateGrid();
    CU_ASSERT_FALSE(getCellState(0 * CELL_SIZE, 0 * CELL_SIZE));
}

void test_stableConfiguration() {
    initGrid();
    toggleCell(1, 1, 0, 0);
    toggleCell(1, 2, 0, 0);
    toggleCell(2, 1, 0, 0);
    toggleCell(2, 2, 0, 0);

    updateGrid();
    CU_ASSERT_TRUE(getCellState(1 * CELL_SIZE, 1 * CELL_SIZE));
    CU_ASSERT_TRUE(getCellState(1 * CELL_SIZE, 2 * CELL_SIZE));
    CU_ASSERT_TRUE(getCellState(2 * CELL_SIZE, 1 * CELL_SIZE));
    CU_ASSERT_TRUE(getCellState(2 * CELL_SIZE, 2 * CELL_SIZE));
}

int main() {
    CU_initialize_registry();
    CU_pSuite suite = CU_add_suite("grid_test_suite", 0, 0);

    CU_add_test(suite, "test_initGrid", test_initGrid);
    CU_add_test(suite, "test_toggleCell", test_toggleCell);
    CU_add_test(suite, "test_updateGrid", test_updateGrid);
    CU_add_test(suite, "test_gridEdges", test_gridEdges);
    CU_add_test(suite, "test_stableConfiguration", test_stableConfiguration);

    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();

    return 0;
}
