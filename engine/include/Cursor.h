#ifndef CURSOR_H
#define CURSOR_H

#include <string>

namespace Engine {
namespace Cursor {

/**
 * Namespace for terminal cursor control and coloring
 * ANSI color codes and cursor position control
 */

// Color definitions
namespace Color {
    // Foreground colors
    extern const char* BLACK;
    extern const char* RED;
    extern const char* GREEN;
    extern const char* YELLOW;
    extern const char* BLUE;
    extern const char* MAGENTA;
    extern const char* CYAN;
    extern const char* WHITE;
    
    // Bright colors
    extern const char* BRIGHT_BLACK;
    extern const char* BRIGHT_RED;
    extern const char* BRIGHT_GREEN;
    extern const char* BRIGHT_YELLOW;
    extern const char* BRIGHT_BLUE;
    extern const char* BRIGHT_MAGENTA;
    extern const char* BRIGHT_CYAN;
    extern const char* BRIGHT_WHITE;
    
    // Background colors
    extern const char* BG_BLACK;
    extern const char* BG_RED;
    extern const char* BG_GREEN;
    extern const char* BG_YELLOW;
    extern const char* BG_BLUE;
    extern const char* BG_MAGENTA;
    extern const char* BG_CYAN;
    extern const char* BG_WHITE;
    
    extern const char* RESET;
}

// Cursor movement functions
void moveTo(int x, int y);      // Move cursor to (x,y) position
void moveUp(int n);             // Move n lines up
void moveDown(int n);           // Move n lines down
void moveRight(int n);          // Move n columns right
void moveLeft(int n);           // Move n columns left

// Color functions
void setColor(const char* color);           // Set foreground color
void setBackgroundColor(const char* color); // Set background color
void resetColor();                          // Reset colors

} // namespace Cursor
} // namespace Engine

#endif // CURSOR_H
