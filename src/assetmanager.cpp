#include <iostream>
#include <vector>
#include <sstream>
#include "assetmanager.h"
#include "renderer.h"

AssetManager* AssetManager::s_instance = nullptr;

AssetManager::AssetManager() = default;

AssetManager::~AssetManager() {
    for (const auto& tex : m_textures) {
        if (tex.second != nullptr) {
            SDL_DestroyTexture(tex.second);
        }
    }
    m_textures.clear();
}


AssetManager* AssetManager::instance() {
    if (s_instance == nullptr) {
        s_instance = new AssetManager();
    }
    return s_instance;
}

void AssetManager::release() {
    delete s_instance;
    s_instance = nullptr;
}

SDL_Texture* AssetManager::getTexture(const std::string& filename) {
    std::string path = SDL_GetBasePath();
    path.append("assets/image/" + filename);

    std::cout << "Loading texture with key: " << path << std::endl;

    if (m_textures[path] == nullptr) {
        m_textures[path] = Renderer::loadTexture(path);
    }
    return m_textures[path];
}

// Expects key to be in the format "font_name, font_size"
TTF_Font* AssetManager::getFont(const std::string& filename, int size) {
    std::string key = filename;
    key.append("," + std::to_string(size));

    std::string path = SDL_GetBasePath();
    path.append("assets/font/" + filename);

    std::cout << "Loading font with key: " << key << std::endl;

    if (m_fonts[key] == nullptr) {
        m_fonts[key] = Renderer::loadFont(path, size);
    }
    return m_fonts[key];
}

SDL_Texture*
AssetManager::getTextTexture(const std::string& filename, int size, const std::string& text, SDL_Color color) {
    std::stringstream ss;
    ss << filename;
    ss << "," + std::to_string(size);
    ss << "," + text;
    ss << "," + std::to_string(color.r) + std::to_string(color.g) + std::to_string(color.b);
    std::string key = ss.str();

    std::cout << "Loading text texture with key: " << key << std::endl;

    if (m_textTextures[key] == nullptr) {
        m_textTextures[key] = Renderer::createTextTexture(filename, size, text, color);
    }
    return m_textTextures[key];
}



