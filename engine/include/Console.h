#ifndef CONSOLE_H
#define CONSOLE_H

#include <string>

namespace Engine {
namespace Console {

/**
 * Namespace for terminal console operations
 * Provides terminal control using ANSI escape codes
 */

// Terminal initialization and cleanup
void init();        // Initialize terminal, hide cursor
void clear();       // Clear terminal
void reset();       // Reset terminal to default settings

// Cursor control
void hideCursor();  // Hide cursor
void showCursor();  // Show cursor

// Drawing functions
void drawPoint(int x, int y, char c);  // Draw character at (x,y)
void drawLine(int x1, int y1, int x2, int y2, char c);  // Draw line between two points
void drawRect(int x, int y, int width, int height, char c);  // Draw rectangle
void drawText(int x, int y, const std::string& text);  // Draw text

} // namespace Console
} // namespace Engine

#endif // CONSOLE_H
