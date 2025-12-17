#include "Input.h"
#include <unistd.h>
#include <termios.h>
#include <sys/select.h>

namespace Engine {

static struct termios orig_termios;

Input::Input() : running(false) {}

Input::~Input() {
    stop();
}

void Input::start() {
    if (!running) {
        running = true;
        enableRawMode();
        inputThread = std::thread(&Input::inputLoop, this);
    }
}

void Input::stop() {
    if (running) {
        running = false;
        if (inputThread.joinable()) {
            inputThread.join();
        }
        disableRawMode();
    }
}

bool Input::hasInput() const {
    std::lock_guard<std::mutex> lock(queueMutex);
    return !keyQueue.empty();
}

Input::Key Input::getKey() {
    std::lock_guard<std::mutex> lock(queueMutex);
    if (keyQueue.empty()) {
        return Key::NONE;
    }
    Key key = keyQueue.front();
    keyQueue.pop();
    return key;
}

bool Input::isKeyPressed(Key key) const {
    std::lock_guard<std::mutex> lock(queueMutex);
    std::queue<Key> tempQueue = keyQueue;
    while (!tempQueue.empty()) {
        if (tempQueue.front() == key) {
            return true;
        }
        tempQueue.pop();
    }
    return false;
}

void Input::inputLoop() {
    while (running) {
        Key key = readKey();
        if (key != Key::NONE) {
            std::lock_guard<std::mutex> lock(queueMutex);
            keyQueue.push(key);
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }
}

Input::Key Input::readKey() {
    fd_set readfds;
    FD_ZERO(&readfds);
    FD_SET(STDIN_FILENO, &readfds);
    
    struct timeval tv;
    tv.tv_sec = 0;
    tv.tv_usec = 10000; // 10ms timeout
    
    int result = select(STDIN_FILENO + 1, &readfds, nullptr, nullptr, &tv);
    
    if (result <= 0) {
        return Key::NONE;
    }
    
    char c;
    if (read(STDIN_FILENO, &c, 1) != 1) {
        return Key::NONE;
    }
    
    // Arrow keys (ESC [ A/B/C/D)
    if (c == 27) {
        char seq[2];
        if (read(STDIN_FILENO, &seq[0], 1) != 1) return Key::ESC;
        if (read(STDIN_FILENO, &seq[1], 1) != 1) return Key::ESC;
        
        if (seq[0] == '[') {
            switch (seq[1]) {
                case 'A': return Key::ARROW_UP;
                case 'B': return Key::ARROW_DOWN;
                case 'C': return Key::ARROW_RIGHT;
                case 'D': return Key::ARROW_LEFT;
            }
        }
        return Key::ESC;
    }
    
    return static_cast<Key>(c);
}

void Input::enableRawMode() {
    tcgetattr(STDIN_FILENO, &orig_termios);
    
    struct termios raw = orig_termios;
    raw.c_lflag &= ~(ECHO | ICANON);
    raw.c_cc[VMIN] = 0;
    raw.c_cc[VTIME] = 1;
    
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);
}

void Input::disableRawMode() {
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &orig_termios);
}

} // namespace Engine
