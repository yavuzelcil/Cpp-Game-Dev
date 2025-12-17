cmake_minimum_required(VERSION 3.15)
project(CppGameEngine VERSION 1.0.0 LANGUAGES CXX)

# C++17 standardı
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Engine kütüphanesi
file(GLOB ENGINE_SOURCES "engine/src/*.cpp")
file(GLOB ENGINE_HEADERS "engine/include/*.h")

add_library(GameEngine STATIC ${ENGINE_SOURCES} ${ENGINE_HEADERS})

target_include_directories(GameEngine PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}/engine/include
)

# Threading desteği
find_package(Threads REQUIRED)
target_link_libraries(GameEngine PUBLIC Threads::Threads)

# Compiler uyarıları
if(MSVC)
    target_compile_options(GameEngine PRIVATE /W4)
else()
    target_compile_options(GameEngine PRIVATE -Wall -Wextra -Wpedantic)
endif()

# Examples için fonksiyon
function(add_game GAME_NAME)
    add_executable(${GAME_NAME} ${ARGN})
    target_link_libraries(${GAME_NAME} PRIVATE GameEngine)
    target_include_directories(${GAME_NAME} PRIVATE 
        ${CMAKE_CURRENT_SOURCE_DIR}/engine/include
    )
endfunction()

# Örnek oyunları ekle
add_subdirectory(examples)
