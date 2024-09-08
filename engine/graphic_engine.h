#ifndef GRAPHIC_ENGINE
#define GRAPHIC_ENGINE

#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include "../defs.h"

class GraphicEngine {
    public:
        GraphicEngine();
        ~GraphicEngine();

        void setRenderer(SDL_Renderer* renderer);

        /**
         * Load a texture located at the given path and associate it to the given id.
         * So it can later be manipulated.
         * 
         * @throws 
         * 
         * @param [in] textureID The texture's identifier. It must be unique. When the same id is provide multiple times, the previous loaded texture are override.
         * @param [in] filePath The file path to load.
         */
        void loadTextures(const TextureID& textureID, const std::string& filePath);

        void render(const TextureID& textureID);

        SDL_Texture* getTexture(const TextureID& textureID);
    private:
        SDL_Renderer* renderer;
        std::unordered_map<TextureID, SDL_Texture*> textures;
};

#endif