#ifndef INPUT_H
#define INPUT_H

#include <atomic>
#include <thread>
#include <queue>
#include <mutex>

namespace Engine {

/**
 * Asenkron input yönetimi için sınıf
 * Klavye girişlerini ayrı thread'de dinler
 */
class Input {
public:
    // Input tuşları
    enum class Key {
        NONE = 0,
        UP = 'w',
        DOWN = 's',
        LEFT = 'a',
        RIGHT = 'd',
        SPACE = ' ',
        ENTER = '\n',
        ESC = 27,
        ARROW_UP = 1000,
        ARROW_DOWN = 1001,
        ARROW_LEFT = 1002,
        ARROW_RIGHT = 1003
    };

    Input();
    ~Input();

    // Input sistemi başlat/durdur
    void start();
    void stop();

    // Input kontrolü
    bool hasInput() const;
    Key getKey();
    bool isKeyPressed(Key key) const;

private:
    std::atomic<bool> running;
    std::thread inputThread;
    std::queue<Key> keyQueue;
    mutable std::mutex queueMutex;

    void inputLoop();
    Key readKey();
    void enableRawMode();
    void disableRawMode();
};

} // namespace Engine

#endif // INPUT_H
