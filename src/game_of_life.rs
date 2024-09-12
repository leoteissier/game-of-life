use crate::cell::Cell;
use macroquad::prelude::*;
use std::collections::{HashSet, HashMap};
use std::time::{Duration, Instant};

const CELL_SIZE: f32 = 20.0; // Taille de base des cellules sans zoom
const SIMULATION_INTERVAL: Duration = Duration::from_millis(500); // Intervalle de 500ms entre chaque étape de simulation

pub struct GameOfLife {
    pub alive_cells: HashSet<Cell>,
    pub simulation_running: bool,
    pub offset: Vec2,
    pub zoom: f32,
    last_update: Instant, // Pour suivre le temps écoulé depuis la dernière mise à jour
}

impl GameOfLife {
    pub fn new() -> Self {
        Self {
            alive_cells: HashSet::new(),
            simulation_running: false,
            offset: vec2(0.0, 0.0),
            zoom: 1.0,
            last_update: Instant::now(),
        }
    }

    // Fonction pour dessiner la grille
    pub fn draw_grid(&self) {
        let screen_width = screen_width();
        let screen_height = screen_height();
        let scaled_cell_size = CELL_SIZE * self.zoom;

        // Dessiner les lignes verticales
        for x in (0..(screen_width as i32)).step_by(scaled_cell_size as usize) {
            draw_line(
                x as f32 - self.offset.x % scaled_cell_size,
                0.0,
                x as f32 - self.offset.x % scaled_cell_size,
                screen_height,
                1.0,
                GRAY,
            );
        }

        // Dessiner les lignes horizontales
        for y in (0..(screen_height as i32)).step_by(scaled_cell_size as usize) {
            draw_line(
                0.0,
                y as f32 - self.offset.y % scaled_cell_size,
                screen_width,
                y as f32 - self.offset.y % scaled_cell_size,
                1.0,
                GRAY,
            );
        }
    }

    // Fonction pour dessiner les cellules vivantes
    pub fn draw_cells(&self) {
        let scaled_cell_size = CELL_SIZE * self.zoom; // Assure que les cellules soient à la même échelle que la grille
        for cell in &self.alive_cells {
            let screen_x = (cell.x as f32 * scaled_cell_size) + self.offset.x;
            let screen_y = (cell.y as f32 * scaled_cell_size) + self.offset.y;
            draw_rectangle(screen_x, screen_y, scaled_cell_size, scaled_cell_size, BLACK);
        }
    }

    // Fonction pour ajouter ou retirer une cellule (lors d'un clic)
    pub fn toggle_cell(&mut self, mouse_pos: Vec2) {
        let scaled_cell_size = CELL_SIZE * self.zoom; // Ajuster en fonction du zoom
        let cell_x = ((mouse_pos.x - self.offset.x) / scaled_cell_size) as i32;
        let cell_y = ((mouse_pos.y - self.offset.y) / scaled_cell_size) as i32;
        let cell = Cell::new(cell_x, cell_y);
        if self.alive_cells.contains(&cell) {
            self.alive_cells.remove(&cell);
        } else {
            self.alive_cells.insert(cell);
        }
    }

    // Fonction qui applique les règles du jeu de la vie
    pub fn step_simulation(&mut self) {
        let mut new_alive_cells = HashSet::new();
        let mut neighbor_counts = HashMap::new();

        for &cell in &self.alive_cells {
            for dx in -1..=1 {
                for dy in -1..=1 {
                    if dx == 0 && dy == 0 {
                        continue;
                    }
                    let neighbor = Cell::new(cell.x + dx, cell.y + dy);
                    *neighbor_counts.entry(neighbor).or_insert(0) += 1;
                }
            }
        }

        for (cell, count) in neighbor_counts {
            if count == 3 || (count == 2 && self.alive_cells.contains(&cell)) {
                new_alive_cells.insert(cell);
            }
        }

        self.alive_cells = new_alive_cells;
    }

    // Fonction qui traite les entrées utilisateur
    pub fn process_input(&mut self) {
        // Démarrer ou arrêter la simulation avec la barre d'espace
        if is_key_pressed(KeyCode::Space) {
            self.simulation_running = !self.simulation_running;
        }

        // Déplacement avec les flèches
        if is_key_down(KeyCode::Right) {
            self.offset.x -= 10.0;
        }
        if is_key_down(KeyCode::Left) {
            self.offset.x += 10.0;
        }
        if is_key_down(KeyCode::Down) {
            self.offset.y -= 10.0;
        }
        if is_key_down(KeyCode::Up) {
            self.offset.y += 10.0;
        }

        // Zoom avec la molette
        let scroll = mouse_wheel().1;
        if scroll != 0.0 {
            self.zoom += scroll * 0.1;
            self.zoom = self.zoom.clamp(0.1, 10.0); // Limiter le zoom
        }

        // Ajouter ou retirer une cellule avec un clic gauche
        if is_mouse_button_pressed(MouseButton::Left) {
            let mouse_pos = mouse_position().into();
            self.toggle_cell(mouse_pos);
        }
    }

    // Fonction qui gère la mise à jour de la simulation à un intervalle défini
    pub fn update(&mut self) {
        if self.simulation_running && self.last_update.elapsed() >= SIMULATION_INTERVAL {
            self.step_simulation();
            self.last_update = Instant::now(); // Remettre à jour le timer
        }
    }
}
