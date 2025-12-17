#include "GameEngine.h"
#include <vector>
#include <deque>

/**
 * Simple Snake game example
 * Move with WASD or arrow keys
 * ESC to exit
 */

struct Point {
    int x, y;
    bool operator==(const Point& other) const {
        return x == other.x && y == other.y;
    }
};

class SnakeGame : public Engine::GameEngine {
public:
    SnakeGame() : score(0), gameOver(false) {}

protected:
    void onInit() override {
        // Game field dimensions
        width = 40;
        height = 20;
        
        // Start snake in center
        snake.clear();
        snake.push_back({width / 2, height / 2});
        
        // Place first food
        spawnFood();
        
        // Initial direction
        direction = {1, 0};
        
        score = 0;
        gameOver = false;
    }
    
    void onUpdate(float deltaTime) override {
        if (gameOver) return;
        
        // Input handling
        if (input.hasInput()) {
            auto key = input.getKey();
            switch (key) {
                case Engine::Input::Key::UP:
                case Engine::Input::Key::ARROW_UP:
                    if (direction.y == 0) direction = {0, -1};
                    break;
                case Engine::Input::Key::DOWN:
                case Engine::Input::Key::ARROW_DOWN:
                    if (direction.y == 0) direction = {0, 1};
                    break;
                case Engine::Input::Key::LEFT:
                case Engine::Input::Key::ARROW_LEFT:
                    if (direction.x == 0) direction = {-1, 0};
                    break;
                case Engine::Input::Key::RIGHT:
                case Engine::Input::Key::ARROW_RIGHT:
                    if (direction.x == 0) direction = {1, 0};
                    break;
                default:
                    break;
            }
        }
        
        // Move snake (every 0.15 seconds)
        moveTimer += deltaTime;
        if (moveTimer >= 0.15f) {
            moveTimer = 0.0f;
            moveSnake();
        }
    }
    
    void onRender() override {
        Engine::Console::clear();
        
        // Draw frame
        Engine::Cursor::setColor(Engine::Cursor::Color::BRIGHT_WHITE);
        Engine::Console::drawRect(1, 1, width + 2, height + 2, '#');
        
        // Draw snake
        Engine::Cursor::setColor(Engine::Cursor::Color::BRIGHT_GREEN);
        for (const auto& segment : snake) {
            Engine::Console::drawPoint(segment.x + 2, segment.y + 2, 'O');
        }
        
        // Draw head differently
        Engine::Cursor::setColor(Engine::Cursor::Color::BRIGHT_YELLOW);
        Engine::Console::drawPoint(snake.front().x + 2, snake.front().y + 2, '@');
        
        // Draw food
        Engine::Cursor::setColor(Engine::Cursor::Color::BRIGHT_RED);
        Engine::Console::drawPoint(food.x + 2, food.y + 2, '*');
        
        // Score
        Engine::Cursor::setColor(Engine::Cursor::Color::BRIGHT_CYAN);
        Engine::Console::drawText(width / 2, height + 4, 
            "Score: " + std::to_string(score));
        
        // FPS
        Engine::Console::drawText(width - 10, height + 4, 
            "FPS: " + std::to_string(getCurrentFPS()));
        
        // Game Over message
        if (gameOver) {
            Engine::Cursor::setColor(Engine::Cursor::Color::BRIGHT_RED);
            Engine::Console::drawText(width / 2 - 5, height / 2, "GAME OVER!");
            Engine::Console::drawText(width / 2 - 8, height / 2 + 1, 
                "Press ESC to exit");
        }
        
        Engine::Cursor::resetColor();
    }
    
    void onShutdown() override {
        Engine::Console::clear();
        Engine::Console::drawText(1, 1, "Thanks for playing!");
        Engine::Console::drawText(1, 2, "Final Score: " + std::to_string(score));
        Engine::Cursor::moveTo(1, 4);
    }

private:
    std::deque<Point> snake;
    Point food;
    Point direction;
    int width, height;
    int score;
    bool gameOver;
    float moveTimer = 0.0f;
    
    void moveSnake() {
        // New head position
        Point newHead = snake.front();
        newHead.x += direction.x;
        newHead.y += direction.y;
        
        // Wall collision check
        if (newHead.x < 0 || newHead.x >= width || 
            newHead.y < 0 || newHead.y >= height) {
            gameOver = true;
            return;
        }
        
        // Self collision check
        for (const auto& segment : snake) {
            if (newHead == segment) {
                gameOver = true;
                return;
            }
        }
        
        // Add head
        snake.push_front(newHead);
        
        // Food eating check
        if (newHead == food) {
            score += 10;
            spawnFood();
        } else {
            // Remove tail (no growth)
            snake.pop_back();
        }
    }
    
    void spawnFood() {
        do {
            food.x = rand() % width;
            food.y = rand() % height;
        } while (isSnakeAt(food));
    }
    
    bool isSnakeAt(const Point& p) const {
        for (const auto& segment : snake) {
            if (segment == p) return true;
        }
        return false;
    }
};

int main() {
    SnakeGame game;
    game.setTargetFPS(60);
    game.run();
    return 0;
}
