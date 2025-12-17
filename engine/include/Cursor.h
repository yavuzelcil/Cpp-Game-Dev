#ifndef CURSOR_H
#define CURSOR_H

#include <string>

namespace Engine {
namespace Cursor {

/**
 * Terminal cursor kontrolü ve renklendirme için namespace
 * ANSI renk kodları ve cursor pozisyon kontrolü
 */

// Renk tanımlamaları
namespace Color {
    // Ön plan renkleri
    extern const char* BLACK;
    extern const char* RED;
    extern const char* GREEN;
    extern const char* YELLOW;
    extern const char* BLUE;
    extern const char* MAGENTA;
    extern const char* CYAN;
    extern const char* WHITE;
    
    // Parlak renkler
    extern const char* BRIGHT_BLACK;
    extern const char* BRIGHT_RED;
    extern const char* BRIGHT_GREEN;
    extern const char* BRIGHT_YELLOW;
    extern const char* BRIGHT_BLUE;
    extern const char* BRIGHT_MAGENTA;
    extern const char* BRIGHT_CYAN;
    extern const char* BRIGHT_WHITE;
    
    // Arka plan renkleri
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

// Cursor hareket fonksiyonları
void moveTo(int x, int y);      // Cursor'u (x,y) konumuna taşı
void moveUp(int n);             // n satır yukarı
void moveDown(int n);           // n satır aşağı
void moveRight(int n);          // n sütun sağa
void moveLeft(int n);           // n sütun sola

// Renk fonksiyonları
void setColor(const char* color);           // Ön plan rengini ayarla
void setBackgroundColor(const char* color); // Arka plan rengini ayarla
void resetColor();                          // Renkleri sıfırla

} // namespace Cursor
} // namespace Engine

#endif // CURSOR_H
