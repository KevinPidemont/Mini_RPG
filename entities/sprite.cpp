#include "sprite.h"

//        Sprite(const TextureID& textureID, const SDL_Rect& srcRect, SDL_Point position = { 0, 0 });

Sprite::Sprite(const TextureID textureID, const SDL_Rect& srcRect, std::string name, SDL_Point position) : textureID(textureID), srcRect(srcRect) {
    this->position = position;
    this->name = name;
}

Sprite::~Sprite() {

}

const SDL_Rect& Sprite::getSrcRect() const {
    return this->srcRect;
}

SDL_Point Sprite::getPosition() {
    return this->position;
}

const TextureID& Sprite::getTextureID() {
    return this->textureID;
}