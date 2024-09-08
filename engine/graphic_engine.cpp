#include "graphic_engine.h"

GraphicEngine::GraphicEngine() {}

GraphicEngine::~GraphicEngine() {}

void GraphicEngine::setRenderer(SDL_Renderer* renderer) {
    if (renderer == nullptr) {
        throw std::invalid_argument("The provided renderer must point to a valid renderer!");
    }

    this->renderer = renderer;
}

void GraphicEngine::loadTextures(const TextureID& textureID, const std::string& filePath) {
    SDL_Surface* surface = IMG_Load(filePath.c_str());

    if (surface == nullptr) {
        throw std::invalid_argument("Fail to load the texture from " + filePath);
    }

    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);

    if (texture == nullptr) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "[DEBUG] > %s", SDL_GetError());
        throw std::runtime_error(("Fail to create the texture (" + std::to_string(textureID) + "). Error -> " + SDL_GetError()));
    }

    textures[textureID] = texture;
}

SDL_Texture* GraphicEngine::getTexture(const TextureID& textureID) {
    return textures[textureID];
}

void GraphicEngine::render(const TextureID& textureID) {
    std::cout << "render" << std::endl;
}