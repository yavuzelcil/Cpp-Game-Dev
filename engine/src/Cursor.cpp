#include "Cursor.h"
#include <iostream>

namespace Engine {
namespace Cursor {

// Renk tanımları
namespace Color {
    const char* BLACK = "\033[0;30m";
    const char* RED = "\033[0;31m";
    const char* GREEN = "\033[0;32m";
    const char* YELLOW = "\033[0;33m";
    const char* BLUE = "\033[0;34m";
    const char* MAGENTA = "\033[0;35m";
    const char* CYAN = "\033[0;36m";
    const char* WHITE = "\033[0;37m";
    
    const char* BRIGHT_BLACK = "\033[1;30m";
    const char* BRIGHT_RED = "\033[1;31m";
    const char* BRIGHT_GREEN = "\033[1;32m";
    const char* BRIGHT_YELLOW = "\033[1;33m";
    const char* BRIGHT_BLUE = "\033[1;34m";
    const char* BRIGHT_MAGENTA = "\033[1;35m";
    const char* BRIGHT_CYAN = "\033[1;36m";
    const char* BRIGHT_WHITE = "\033[1;37m";
    
    const char* BG_BLACK = "\033[40m";
    const char* BG_RED = "\033[41m";
    const char* BG_GREEN = "\033[42m";
    const char* BG_YELLOW = "\033[43m";
    const char* BG_BLUE = "\033[44m";
    const char* BG_MAGENTA = "\033[45m";
    const char* BG_CYAN = "\033[46m";
    const char* BG_WHITE = "\033[47m";
    
    const char* RESET = "\033[0m";
}

void moveTo(int x, int y) {
    std::cout << "\033[" << y << ";" << x << "H" << std::flush;
}

void moveUp(int n) {
    std::cout << "\033[" << n << "A" << std::flush;
}

void moveDown(int n) {
    std::cout << "\033[" << n << "B" << std::flush;
}

void moveRight(int n) {
    std::cout << "\033[" << n << "C" << std::flush;
}

void moveLeft(int n) {
    std::cout << "\033[" << n << "D" << std::flush;
}

void setColor(const char* color) {
    std::cout << color << std::flush;
}

void setBackgroundColor(const char* color) {
    std::cout << color << std::flush;
}

void resetColor() {
    std::cout << Color::RESET << std::flush;
}

} // namespace Cursor
} // namespace Engine
