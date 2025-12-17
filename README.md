# C++ Terminal Game Engine 🎮

Modern C++ ile geliştirilmiş, terminal tabanlı oyunlar için oyun motoru. Concurrency, multithreading ve temiz C++ pratiklerini öğrenmek için ideal bir proje.

## 📋 Özellikler

- **Multithreading**: Ayrı update ve render thread'leri
- **Asenkron Input**: Klavye girişlerini ayrı thread'de dinleme
- **ANSI Terminal Kontrolü**: Renk ve cursor kontrolü
- **FPS Yönetimi**: Hedef FPS ayarlama ve gerçek zamanlı FPS gösterimi
- **Modüler Yapı**: Her oyun için tekrar kullanılabilir engine

## 🏗️ Proje Yapısı

```
Cpp-Game-Dev/
├── engine/                  # Game engine kütüphanesi
│   ├── include/            # Header dosyaları
│   │   ├── GameEngine.h    # Ana oyun döngüsü
│   │   ├── Console.h       # Terminal çizim fonksiyonları
│   │   ├── Cursor.h        # Cursor ve renk kontrolü
│   │   └── Input.h         # Asenkron input yönetimi
│   └── src/                # Implementation dosyaları
│       ├── GameEngine.cpp
│       ├── Console.cpp
│       ├── Cursor.cpp
│       └── Input.cpp
├── examples/               # Örnek oyunlar
│   └── snake_game.cpp     # Snake oyunu örneği
├── games/                  # Geliştirilen oyunlar
└── CMakeLists.txt         # Build yapılandırması
```

## 🚀 Başlangıç

### Gereksinimler

- C++17 uyumlu compiler (GCC 7+, Clang 5+, MSVC 2017+)
- CMake 3.15 veya üzeri
- Unix-like sistem (macOS, Linux) - ANSI terminal desteği için

### Derleme

```bash
# Proje dizinine git
cd Cpp-Game-Dev

# Build klasörü oluştur
mkdir build && cd build

# CMake ile configure et
cmake ..

# Derle
make

# Snake oyununu çalıştır
./examples/snake_game
```

### Hızlı Build (tek satır)

```bash
mkdir -p build && cd build && cmake .. && make && cd ..
```

## 🎮 Örnek Kullanım

### Basit Bir Oyun Oluşturma

```cpp
#include "GameEngine.h"

class MyGame : public Engine::GameEngine {
protected:
    void onInit() override {
        // Oyun başlatma kodu
    }
    
    void onUpdate(float deltaTime) override {
        // Oyun mantığı (input, fizik, vb.)
        if (input.hasInput()) {
            auto key = input.getKey();
            // Input işleme
        }
    }
    
    void onRender() override {
        // Çizim kodları
        Engine::Console::clear();
        Engine::Console::drawText(10, 10, "Hello Game!");
    }
    
    void onShutdown() override {
        // Temizlik işlemleri
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
// Terminal başlatma
Engine::Console::init();
Engine::Console::clear();

// Çizim fonksiyonları
Engine::Console::drawPoint(x, y, 'X');
Engine::Console::drawLine(x1, y1, x2, y2, '#');
Engine::Console::drawRect(x, y, width, height, '#');
Engine::Console::drawText(x, y, "Text");

// Cursor kontrolü
Engine::Console::hideCursor();
Engine::Console::showCursor();
```

### Cursor Namespace

```cpp
// Renk ayarlama
Engine::Cursor::setColor(Engine::Cursor::Color::BRIGHT_GREEN);
Engine::Cursor::setBackgroundColor(Engine::Cursor::Color::BG_BLACK);
Engine::Cursor::resetColor();

// Cursor hareketi
Engine::Cursor::moveTo(x, y);
Engine::Cursor::moveUp(n);
Engine::Cursor::moveDown(n);
```

### Input Sınıfı

```cpp
// Input kontrolü (GameEngine içinde hazır)
if (input.hasInput()) {
    auto key = input.getKey();
    
    switch (key) {
        case Engine::Input::Key::UP:
        case Engine::Input::Key::ARROW_UP:
            // Yukarı hareket
            break;
        case Engine::Input::Key::SPACE:
            // Space işleme
            break;
        case Engine::Input::Key::ESC:
            // Çıkış (otomatik olarak handle ediliyor)
            break;
    }
}
```

## 🎓 Öğrenme Konuları

Bu proje ile şu konuları öğrenebilirsiniz:

### C++ Temel Konular
- ✅ Sınıflar ve inheritance
- ✅ Virtual fonksiyonlar
- ✅ Namespaces
- ✅ Header/source dosya yapısı
- ✅ Smart pointers (ileride)
- ✅ STL containers (vector, deque, queue)

### Concurrency
- ✅ `std::thread` - Thread oluşturma
- ✅ `std::atomic` - Thread-safe değişkenler
- ✅ `std::mutex` - Mutual exclusion
- ✅ `std::lock_guard` - RAII lock yönetimi
- ✅ Thread'ler arası veri paylaşımı
- ⏳ `std::condition_variable` (gelecek)
- ⏳ `std::future` ve `std::promise` (gelecek)

### Game Development
- ✅ Game loop pattern
- ✅ Delta time kullanımı
- ✅ FPS yönetimi
- ✅ Input handling
- ✅ Rendering pipeline
- ⏳ Collision detection (gelecek)
- ⏳ Entity-Component System (gelecek)

## 📝 TODO

- [ ] Windows desteği (Windows Console API)
- [ ] Sound engine ekleme
- [ ] Sprite/ASCII art desteği
- [ ] Collision detection sistemi
- [ ] Entity-Component-System (ECS) mimarisi
- [ ] Save/Load sistemi
- [ ] Daha fazla örnek oyun (Tetris, Pong, Maze Runner)

## 🎮 Örnek Oyunlar

### Snake Game (Tamamlandı)
- WASD veya ok tuşları ile hareket
- Yiyecek topla, büyü
- Kendine veya duvara çarpma = game over
- Gerçek zamanlı skor ve FPS gösterimi

### Gelecek Oyunlar
- Tetris
- Pong
- Space Invaders
- Maze Runner
- Tower Defense

## 🤝 Katkıda Bulunma

Bu bir öğrenme projesidir. Yeni oyunlar, özellikler veya iyileştirmeler eklemek için:

1. Yeni oyunlar için `games/` klasöründe yeni klasör oluşturun
2. Engine iyileştirmeleri için `engine/` klasöründe değişiklik yapın
3. `examples/` klasörüne yeni örnekler ekleyin

## 📚 Kaynaklar

- [C++ Concurrency in Action](https://www.manning.com/books/c-plus-plus-concurrency-in-action-second-edition)
- [Game Programming Patterns](https://gameprogrammingpatterns.com/)
- [ANSI Escape Codes](https://en.wikipedia.org/wiki/ANSI_escape_code)

## 📄 Lisans

Bu proje eğitim amaçlıdır ve özgürce kullanılabilir.

## 🎯 Amaç

Bu projenin amacı:
- Modern C++ pratikleri öğrenmek
- Concurrency ve multithreading konularında deneyim kazanmak
- Oyun geliştirme temellerini anlamak
- GitHub üzerinde portfolio oluşturmak
- Temiz, okunabilir ve sürdürülebilir kod yazmayı öğrenmek
