cmake_minimum_required(VERSION 3.20)
project(HopInvaders)

set(CMAKE_CXX_STANDARD 20)

add_executable(HopInvaders src/core/main.cpp src/core/game.cpp src/core/game.h src/core/window.cpp src/core/window.h src/core/sprite.cpp src/core/sprite.h src/core/renderer.cpp src/core/renderer.h src/core/player.cpp src/core/player.h src/core/events.h src/components/textcomponent.cpp src/components/textcomponent.h src/core/assetmanager.cpp src/core/assetmanager.h src/core/texture.cpp src/core/texture.h src/entity/bullet.cpp src/entity/bullet.h src/components/countingcomponent.cpp src/components/countingcomponent.h src/core/collider.cpp src/core/collider.h)
target_link_libraries(HopInvaders SDL2 SDL2_image SDL2_ttf)