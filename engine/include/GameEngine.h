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
 * Ana oyun döngüsünü yöneten sınıf
 * Update ve render thread'lerini yönetir
 */
class GameEngine {
public:
    GameEngine();
    virtual ~GameEngine();

    // Oyun döngüsü
    void run();
    void stop();

    // FPS kontrolü
    void setTargetFPS(int fps);
    int getCurrentFPS() const;

protected:
    // Alt sınıflarda override edilecek fonksiyonlar
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
