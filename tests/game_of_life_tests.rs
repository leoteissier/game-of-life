use game_of_life::game_of_life::GameOfLife;
use game_of_life::cell::Cell;
use macroquad::prelude::*;

#[test]
fn test_toggle_cell() {
    let mut game = GameOfLife::new();
    
    // Ajouter une cellule
    game.toggle_cell(vec2(0.0, 0.0));
    assert!(game.alive_cells.contains(&Cell::new(0, 0)));
    
    // Supprimer la même cellule
    game.toggle_cell(vec2(0.0, 0.0));
    assert!(!game.alive_cells.contains(&Cell::new(0, 0)));
}

#[test]
fn test_simulation_rules() {
    let mut game = GameOfLife::new();
    
    // Placer un "clignotant" (oscillateur) : trois cellules alignées horizontalement
    game.alive_cells.insert(Cell::new(1, 0));
    game.alive_cells.insert(Cell::new(1, 1));
    game.alive_cells.insert(Cell::new(1, 2));

    // Simulation étape 1 : le clignotant doit devenir vertical
    game.step_simulation();
    assert!(game.alive_cells.contains(&Cell::new(0, 1)));
    assert!(game.alive_cells.contains(&Cell::new(1, 1)));
    assert!(game.alive_cells.contains(&Cell::new(2, 1)));
    
    // Simulation étape 2 : le clignotant doit redevenir horizontal
    game.step_simulation();
    assert!(game.alive_cells.contains(&Cell::new(1, 0)));
    assert!(game.alive_cells.contains(&Cell::new(1, 1)));
    assert!(game.alive_cells.contains(&Cell::new(1, 2)));
}

#[test]
fn test_cell_survival() {
    let mut game = GameOfLife::new();
    
    // Créer un carré de cellules vivantes
    game.alive_cells.insert(Cell::new(0, 0));
    game.alive_cells.insert(Cell::new(0, 1));
    game.alive_cells.insert(Cell::new(1, 0));
    game.alive_cells.insert(Cell::new(1, 1));

    // Simulation étape 1 : le carré reste stable
    game.step_simulation();
    assert!(game.alive_cells.contains(&Cell::new(0, 0)));
    assert!(game.alive_cells.contains(&Cell::new(0, 1)));
    assert!(game.alive_cells.contains(&Cell::new(1, 0)));
    assert!(game.alive_cells.contains(&Cell::new(1, 1)));
}
