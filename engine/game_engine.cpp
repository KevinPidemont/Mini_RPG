#include "game_engine.h"

GameEngine::GameEngine() {
    window = nullptr;
    renderer = nullptr;
}

GameEngine::~GameEngine() {
    if (renderer) SDL_DestroyRenderer(renderer);
    if (window) SDL_DestroyWindow(window);

    IMG_Quit();
    SDL_Quit();
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
}

void GameEngine::run() {
    SDL_Event event;

    isRunning = true;
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

        

        SDL_RenderPresent(renderer);
    }
}