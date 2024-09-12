use macroquad::prelude::*;
use game_of_life::game_of_life::GameOfLife;

#[macroquad::main("Game of Life")]
async fn main() {
    let mut game = GameOfLife::new();

    loop {
        clear_background(WHITE);

        game.process_input();
        game.update(); // Met à jour la simulation à un intervalle régulier

        game.draw_grid();
        game.draw_cells();

        next_frame().await;
    }
}
