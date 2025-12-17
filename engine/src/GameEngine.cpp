#include "GameEngine.h"
#include <iostream>

namespace Engine {

GameEngine::GameEngine() 
    : running(false), currentFPS(0), targetFPS(60) {}

GameEngine::~GameEngine() {
    stop();
}

void GameEngine::run() {
    Console::init();
    input.start();
    
    onInit();
    
    running = true;
    
    // Update ve render thread'lerini başlat
    updateThread = std::thread(&GameEngine::updateLoop, this);
    renderThread = std::thread(&GameEngine::renderLoop, this);
    
    // Ana thread'de input kontrolü
    while (running) {
        if (input.isKeyPressed(Input::Key::ESC)) {
            stop();
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(16));
    }
    
    // Thread'lerin bitmesini bekle
    if (updateThread.joinable()) updateThread.join();
    if (renderThread.joinable()) renderThread.join();
    
    onShutdown();
    
    input.stop();
    Console::reset();
}

void GameEngine::stop() {
    running = false;
}

void GameEngine::setTargetFPS(int fps) {
    targetFPS = fps;
}

int GameEngine::getCurrentFPS() const {
    return currentFPS;
}

void GameEngine::updateLoop() {
    auto lastTime = std::chrono::high_resolution_clock::now();
    
    while (running) {
        auto currentTime = std::chrono::high_resolution_clock::now();
        float deltaTime = std::chrono::duration<float>(currentTime - lastTime).count();
        lastTime = currentTime;
        
        onUpdate(deltaTime);
        
        // Target FPS'e göre bekle
        int updateTime = static_cast<int>(1000.0f / targetFPS);
        std::this_thread::sleep_for(std::chrono::milliseconds(updateTime));
    }
}

void GameEngine::renderLoop() {
    auto lastTime = std::chrono::high_resolution_clock::now();
    int frameCount = 0;
    
    while (running) {
        auto currentTime = std::chrono::high_resolution_clock::now();
        frameCount++;
        
        // FPS hesapla (her saniye)
        auto elapsed = std::chrono::duration<float>(currentTime - lastTime).count();
        if (elapsed >= 1.0f) {
            currentFPS = frameCount;
            frameCount = 0;
            lastTime = currentTime;
        }
        
        onRender();
        
        // Target FPS'e göre bekle
        int renderTime = static_cast<int>(1000.0f / targetFPS);
        std::this_thread::sleep_for(std::chrono::milliseconds(renderTime));
    }
}

} // namespace Engine
