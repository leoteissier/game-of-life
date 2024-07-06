#include <CUnit/Basic.h>
#include "../includes/renderer.h"

void test_initSDL() {
    CU_ASSERT_TRUE(initSDL());
    closeSDL();  // Ensure SDL is properly closed after initialization
}

void test_drawGrid() {
    initSDL();
    // Mock offsets and cell size for testing purposes
    int offsetX = 0;
    int offsetY = 0;
    int cellSize = 10;
    drawGrid(offsetX, offsetY, cellSize);
    // In a real test, you might capture the rendered output and verify it
    closeSDL();
}

int main() {
    CU_initialize_registry();
    CU_pSuite suite = CU_add_suite("renderer_test_suite", 0, 0);

    CU_add_test(suite, "test_initSDL", test_initSDL);
    CU_add_test(suite, "test_drawGrid", test_drawGrid);

    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();

    return 0;
}
