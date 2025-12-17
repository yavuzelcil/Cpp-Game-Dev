#ifndef CONSOLE_H
#define CONSOLE_H

#include <string>

namespace Engine {
namespace Console {

/**
 * Terminal konsol işlemleri için namespace
 * ANSI escape kodları kullanarak terminal kontrolü sağlar
 */

// Terminal başlatma ve temizleme
void init();        // Terminal'i başlat, cursor'u gizle
void clear();       // Terminal'i temizle
void reset();       // Terminal'i varsayılan ayarlara döndür

// Cursor kontrolü
void hideCursor();  // Cursor'u gizle
void showCursor();  // Cursor'u göster

// Çizim fonksiyonları
void drawPoint(int x, int y, char c);  // (x,y) konumuna karakter çiz
void drawLine(int x1, int y1, int x2, int y2, char c);  // İki nokta arası çizgi
void drawRect(int x, int y, int width, int height, char c);  // Dikdörtgen çiz
void drawText(int x, int y, const std::string& text);  // Metin yaz

} // namespace Console
} // namespace Engine

#endif // CONSOLE_H
