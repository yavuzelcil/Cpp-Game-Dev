#ifndef GAME_ENGINE_H
#define GAME_ENGINE_H

#include "Console.h"
#include "Cursor.h"
#include "Input.h"
#include <atomic>
#include <chrono>
#include <thread>

namespace Engine {

/**
 * Class that manages the main game loop
 * Manages update and render threads
 */
class GameEngine {
public:
    GameEngine();
    virtual ~GameEngine();

    // Game loop
    void run();
    void stop();

    // FPS control
    void setTargetFPS(int fps);
    int getCurrentFPS() const;

protected:
    // Functions to be overridden in derived classes
    virtual void onInit() = 0;
    virtual void onUpdate(float deltaTime) = 0;
    virtual void onRender() = 0;
    virtual void onShutdown() = 0;

    Input input;

private:
    std::atomic<bool> running;
    std::atomic<int> currentFPS;
    int targetFPS;
    
    std::thread updateThread;
    std::thread renderThread;

    void updateLoop();
    void renderLoop();
};

} // namespace Engine

#endif // GAME_ENGINE_H
