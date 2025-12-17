# C++ Terminal Game Engine 🎮

A modern C++ game engine for terminal-based games. Perfect for learning C++, concurrency, multithreading, and clean coding practices.

## 📋 Features

- **Multithreading**: Separate update and render threads
- **Asynchronous Input**: Keyboard input handling in separate thread
- **ANSI Terminal Control**: Color and cursor management
- **FPS Management**: Target FPS setting and real-time FPS display
- **Modular Architecture**: Reusable engine for every game

## 🏗️ Project Structure

```
Cpp-Game-Dev/
├── engine/                  # Game engine library
│   ├── include/            # Header files
│   │   ├── GameEngine.h    # Main game loop
│   │   ├── Console.h       # Terminal drawing functions
│   │   ├── Cursor.h        # Cursor and color control
│   │   └── Input.h         # Asynchronous input management
│   └── src/                # Implementation files
│       ├── GameEngine.cpp
│       ├── Console.cpp
│       ├── Cursor.cpp
│       └── Input.cpp
├── examples/               # Example games
│   └── snake_game.cpp     # Snake game example
├── games/                  # Developed games
└── CMakeLists.txt         # Build configuration
```

## 🚀 Getting Started

### Requirements

- C++17 compatible compiler (GCC 7+, Clang 5+, MSVC 2017+)
- CMake 3.15 or higher
- Unix-like system (macOS, Linux) - for ANSI terminal support

### Building

```bash
# Navigate to project directory
cd Cpp-Game-Dev

# Create build directory
mkdir build && cd build

# Configure with CMake
cmake ..

# Build
make

# Run snake game
./examples/snake_game
```

### Quick Build (one-liner)

```bash
mkdir -p build && cd build && cmake .. && make && cd ..
```

## 🎮 Example Usage

### Creating a Simple Game

```cpp
#include "GameEngine.h"

class MyGame : public Engine::GameEngine {
protected:
    void onInit() override {
        // Game initialization code
    }
    
    void onUpdate(float deltaTime) override {
        // Game logic (input, physics, etc.)
        if (input.hasInput()) {
            auto key = input.getKey();
            // Handle input
        }
    }
    
    void onRender() override {
        // Drawing code
        Engine::Console::clear();
        Engine::Console::drawText(10, 10, "Hello Game!");
    }
    
    void onShutdown() override {
        // Cleanup
    }
};

int main() {
    MyGame game;
    game.setTargetFPS(60);
    game.run();
    return 0;
}
```

## 🎯 Engine API

### Console Namespace

```cpp
// Terminal initialization
Engine::Console::init();
Engine::Console::clear();

// Drawing functions
Engine::Console::drawPoint(x, y, 'X');
Engine::Console::drawLine(x1, y1, x2, y2, '#');
Engine::Console::drawRect(x, y, width, height, '#');
Engine::Console::drawText(x, y, "Text");

// Cursor control
Engine::Console::hideCursor();
Engine::Console::showCursor();
```

### Cursor Namespace

```cpp
// Color setting
Engine::Cursor::setColor(Engine::Cursor::Color::BRIGHT_GREEN);
Engine::Cursor::setBackgroundColor(Engine::Cursor::Color::BG_BLACK);
Engine::Cursor::resetColor();

// Cursor movement
Engine::Cursor::moveTo(x, y);
Engine::Cursor::moveUp(n);
Engine::Cursor::moveDown(n);
```

### Input Class

```cpp
// Input handling (available in GameEngine)
if (input.hasInput()) {
    auto key = input.getKey();
    
    switch (key) {
        case Engine::Input::Key::UP:
        case Engine::Input::Key::ARROW_UP:
            // Move up
            break;
        case Engine::Input::Key::SPACE:
            // Handle space
            break;
        case Engine::Input::Key::ESC:
            // Exit (handled automatically)
            break;
    }
}
```

## 🎓 Learning Topics

This project covers the following topics:

### C++ Fundamentals
- ✅ Classes and inheritance
- ✅ Virtual functions
- ✅ Namespaces
- ✅ Header/source file structure
- ✅ Smart pointers (upcoming)
- ✅ STL containers (vector, deque, queue)

### Concurrency
- ✅ `std::thread` - Thread creation
- ✅ `std::atomic` - Thread-safe variables
- ✅ `std::mutex` - Mutual exclusion
- ✅ `std::lock_guard` - RAII lock management
- ✅ Inter-thread data sharing
- ⏳ `std::condition_variable` (upcoming)
- ⏳ `std::future` and `std::promise` (upcoming)

### Game Development
- ✅ Game loop pattern
- ✅ Delta time usage
- ✅ FPS management
- ✅ Input handling
- ✅ Rendering pipeline
- ⏳ Collision detection (upcoming)
- ⏳ Entity-Component System (upcoming)

## 📝 TODO

- [ ] Windows support (Windows Console API)
- [ ] Add sound engine
- [ ] Sprite/ASCII art support
- [ ] Collision detection system
- [ ] Entity-Component-System (ECS) architecture
- [ ] Save/Load system
- [ ] More example games (Tetris, Pong, Maze Runner)

## 🎮 Example Games

### Snake Game (Completed)
- Move with WASD or arrow keys
- Collect food to grow
- Hit yourself or wall = game over
- Real-time score and FPS display

### Upcoming Games
- Tetris
- Pong
- Space Invaders
- Maze Runner
- Tower Defense

## 🤝 Contributing

This is a learning project. To add new games, features, or improvements:

1. Create a new folder in `games/` for new games
2. Make changes in `engine/` for engine improvements
3. Add new examples to `examples/`

## 📚 Resources

- [C++ Concurrency in Action](https://www.manning.com/books/c-plus-plus-concurrency-in-action-second-edition)
- [Game Programming Patterns](https://gameprogrammingpatterns.com/)
- [ANSI Escape Codes](https://en.wikipedia.org/wiki/ANSI_escape_code)

## 📄 License

This project is for educational purposes and can be used freely.

## 🎯 Goals

The goals of this project:
- Learn modern C++ practices
- Gain experience with concurrency and multithreading
- Understand game development fundamentals
- Build a portfolio on GitHub
- Learn to write clean, readable, and maintainable code
