#include <CUnit/Basic.h>
#include "../includes/game.h"
#include "../includes/renderer.h"

bool quit = false;
bool running = false;
int offsetX = 0;
int offsetY = 0;
int cellSize = 10;

void test_handleEvents() {
    // Simulate SDL initialization
    initSDL();

    // Simulate a spacebar press to start the game
    SDL_Event event;
    event.type = SDL_KEYDOWN;
    event.key.keysym.sym = SDLK_SPACE;
    SDL_PushEvent(&event);

    handleEvents(&quit, &running, &offsetX, &offsetY, &cellSize);
    CU_ASSERT_TRUE(running);

    // Simulate another spacebar press to stop the game
    SDL_PushEvent(&event);
    handleEvents(&quit, &running, &offsetX, &offsetY, &cellSize);
    CU_ASSERT_FALSE(running);

    // Simulate an SDL_QUIT event
    event.type = SDL_QUIT;
    SDL_PushEvent(&event);
    handleEvents(&quit, &running, &offsetX, &offsetY, &cellSize);
    CU_ASSERT_TRUE(quit);

    closeSDL();
}

int main() {
    CU_initialize_registry();
    CU_pSuite suite = CU_add_suite("game_test_suite", 0, 0);

    CU_add_test(suite, "test_handleEvents", test_handleEvents);

    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();

    return 0;
}
