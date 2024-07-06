
# Game of Life

This project is an implementation of Conway's Game of Life using C and SDL2. It features a graphical interface with a grid where users can click on cells to toggle their state (alive or dead), move around the grid, and start or stop the simulation.

## Features

- Graphical interface with SDL2
- Click on cells to toggle between alive and dead states
- Move around the grid using arrow keys
- Start and stop the simulation with the spacebar
- Zoom in and out with the mouse scroll wheel
- Infinite grid
- Resizable window
- Cells with white borders for better visualization

## Requirements

- C compiler (GCC recommended)
- CMake (version 3.28 or higher)
- SDL2 library

## Installation

### Installing SDL2

#### On Debian/Ubuntu:
```sh
sudo apt-get install libsdl2-dev
```

#### On macOS (Homebrew):
```sh
brew install sdl2
```

#### On Arch Linux:
```sh
sudo pacman -S sdl2
```

### Cloning the Repository
Clone this repository to your local machine:
```sh
git clone https://github.com/yourusername/game-of-life.git
cd game-of-life
```

### Building the Project

1. Create a build directory:
```sh
mkdir build
cd build
```

2. Run CMake to configure the project:
```sh
cmake ..
```

3. Build the project using `make`:
```sh
make
```

## Running the Program

After building the project, you can run the executable:
```sh
./game_of_life
```

## Usage

- **Mouse Click:** Toggle the state of a cell between alive and dead.
- **Arrow Keys:** Move around the grid.
- **Spacebar:** Start and stop the simulation.
- **Mouse Scroll Wheel:** Zoom in and out.

## Project Structure

```
game-of-life/
│
├── includes/
│   ├── grid.h
│   ├── renderer.h
│   └── game.h
│
├── src/
│   ├── main.c
│   ├── grid.c
│   ├── renderer.c
│   └── game.c
│
├── tests/
│   ├── test_grid.c
│   ├── test_renderer.c
│   └── test_game.c
│
├── assets/
│   └── (any images or resources if needed)
│
├── cmake/
│   └── FindCUnit.cmake
│
├── .github/
│   └── workflows/
│       └── ci.yml
│
├── CMakeLists.txt
└── README.md
```

## Contributing

If you would like to contribute to this project, feel free to fork the repository and submit a pull request with your improvements.

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for more details.

## Acknowledgments

- [SDL2](https://www.libsdl.org/) for providing a simple and powerful multimedia library.
- Conway's Game of Life, a cellular automaton devised by the British mathematician John Horton Conway.
