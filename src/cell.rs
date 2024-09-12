use std::hash::{Hash, Hasher};

#[derive(Clone, Copy, Debug)]
pub struct Cell {
    pub x: i32,
    pub y: i32,
}

impl Cell {
    pub fn new(x: i32, y: i32) -> Self {
        Self { x, y }
    }
}

// Implémentation de `PartialEq` et `Eq` pour utiliser `Cell` dans un HashSet.
impl PartialEq for Cell {
    fn eq(&self, other: &Self) -> bool {
        self.x == other.x && self.y == other.y
    }
}

impl Eq for Cell {}

// Implémentation de `Hash` pour utiliser `Cell` dans un HashSet.
impl Hash for Cell {
    fn hash<H: Hasher>(&self, state: &mut H) {
        self.x.hash(state);
        self.y.hash(state);
    }
}
