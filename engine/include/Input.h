#ifndef INPUT_H
#define INPUT_H

#include <atomic>
#include <thread>
#include <queue>
#include <mutex>

namespace Engine {

/**
 * Class for asynchronous input management
 * Listens to keyboard input in a separate thread
 */
class Input {
public:
    // Input keys
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

    // Start/stop input system
    void start();
    void stop();

    // Input control
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
