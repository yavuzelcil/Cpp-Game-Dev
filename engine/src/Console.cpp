#include "Console.h"
#include <iostream>
#include <cmath>

namespace Engine {
namespace Console {

void init() {
    clear();
    hideCursor();
}

void clear() {
    std::cout << "\033[2J" << std::flush;
    std::cout << "\033[H" << std::flush;
}

void reset() {
    std::cout << "\033[0m" << std::flush;
    showCursor();
}

void hideCursor() {
    std::cout << "\033[?25l" << std::flush;
}

void showCursor() {
    std::cout << "\033[?25h" << std::flush;
}

void drawPoint(int x, int y, char c) {
    std::cout << "\033[" << y << ";" << x << "H" << c << std::flush;
}

void drawLine(int x1, int y1, int x2, int y2, char c) {
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int sx = (x1 < x2) ? 1 : -1;
    int sy = (y1 < y2) ? 1 : -1;
    int err = dx - dy;

    while (true) {
        drawPoint(x1, y1, c);
        
        if (x1 == x2 && y1 == y2) break;
        
        int e2 = 2 * err;
        if (e2 > -dy) {
            err -= dy;
            x1 += sx;
        }
        if (e2 < dx) {
            err += dx;
            y1 += sy;
        }
    }
}

void drawRect(int x, int y, int width, int height, char c) {
    // Üst ve alt kenarlar
    for (int i = 0; i < width; i++) {
        drawPoint(x + i, y, c);
        drawPoint(x + i, y + height - 1, c);
    }
    
    // Sol ve sağ kenarlar
    for (int i = 0; i < height; i++) {
        drawPoint(x, y + i, c);
        drawPoint(x + width - 1, y + i, c);
    }
}

void drawText(int x, int y, const std::string& text) {
    std::cout << "\033[" << y << ";" << x << "H" << text << std::flush;
}

} // namespace Console
} // namespace Engine
