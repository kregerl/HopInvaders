cmake_minimum_required(VERSION 3.20)
project(HopInvaders)

set(CMAKE_CXX_STANDARD 20)

add_executable(HopInvaders src/main.cpp src/game.cpp src/game.h src/window.cpp src/window.h src/sprite.cpp src/sprite.h src/renderer.cpp src/renderer.h src/player.cpp src/player.h src/events.h src/textcomponent.cpp src/textcomponent.h src/assetmanager.cpp src/assetmanager.h src/texture.cpp src/texture.h src/bullet.cpp src/bullet.h)
target_link_libraries(HopInvaders SDL2 SDL2_image SDL2_ttf)