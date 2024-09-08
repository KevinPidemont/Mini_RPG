#include "game_engine.h"
#include "graphic_engine.h"

/**
 * Associate a texture id for a given asset.
 */
const std::unordered_map<TextureID, std::string> assets = {
    { 0x01, "assets/character_1.png" },
    { 0x02, "assets/character_2.png" }
};

GameEngine::GameEngine(GraphicEngine* const graphicEngine) {
    window = nullptr;
    renderer = nullptr;
    this->graphicEngine = graphicEngine;
}

GameEngine::~GameEngine() {
    if (renderer) SDL_DestroyRenderer(renderer);
    if (window) SDL_DestroyWindow(window);

    IMG_Quit();
    SDL_Quit();
    delete graphicEngine;
}

void GameEngine::initialize(const std::string& title, const int width, const int height) {
    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "[DEBUG] > %s", SDL_GetError());
        throw std::runtime_error("Fail to initialize the game engine! Error -> " + std::string(SDL_GetError()));
    }

    // Initialize the SDL image module
    if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG)) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "[DEBUG] > %s", IMG_GetError());
        SDL_Quit();
        throw std::runtime_error("Fail to initialize the game engine! Error -> " + std::string(IMG_GetError()));
    }

    // Initiliaze the window and renderer
    if (SDL_CreateWindowAndRenderer(width, height, SDL_WINDOW_SHOWN, &window, &renderer) < 0) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "[DEBUG] > %s", SDL_GetError());
        IMG_Quit();
        SDL_Quit();
        throw std::runtime_error("Fail to initialize the game engine! Error -> " + std::string(SDL_GetError()));
    }

    SDL_SetWindowTitle(window, title.c_str());
    graphicEngine->setRenderer(renderer);
}

void GameEngine::run() {
    SDL_Event event;

    isRunning = true;

    for (auto const& asset : assets) {
        const int id = asset.first;
        std::cout << std::to_string(id) << std::endl;
        sprites.push_back(Sprite(id, {0, 0, 32, 32}, "Sprite " + std::to_string(id)));
        graphicEngine->loadTextures(id, asset.second);
    }

    while (isRunning) {
        // TODO done here for now so we have an easy way to close the window, but should lay in a separate class
        // Capture any event
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_QUIT:
                    isRunning = false;
                    break;
            }
        }


        SDL_RenderClear(renderer);

        for (int i = 0; i < sprites.size(); i++) {
            SDL_Rect destRect = {0, i * 132, 100, 100};
            Sprite sprite = sprites[i];
            std::cout << "i = " << i << ", sprite = " << sprite.name << ", textureID = " << std::to_string(sprite.getTextureID()) << std::endl;
            SDL_RenderCopy(renderer, graphicEngine->getTexture(sprite.getTextureID()), &sprite.getSrcRect(), &destRect);
        }

        SDL_RenderPresent(renderer);
        SDL_Delay(100);
    }
}