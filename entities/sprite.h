#ifndef SPRITE
#define SPRITE

#include "graphic_object.h"
#include "../defs.h"
#include <iostream>

class Sprite : public GraphicObject {
    public:
        Sprite(const TextureID textureID, const SDL_Rect& srcRect, std::string name, SDL_Point position = { 0, 0 });
        ~Sprite();

        SDL_Point getPosition() override;

        const SDL_Rect& getSrcRect() const override;

        const TextureID& getTextureID();

        std::string name;
    private:
        const TextureID textureID;
        const SDL_Rect& srcRect;
        SDL_Point position;
};

#endif