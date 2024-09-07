#ifndef GAME_ENGINE
#define GAME_ENGINE

#include <SDL.h>
#include <SDL_image.h>
#include <iostream>

class GameEngine {
    public:
        GameEngine();
        ~GameEngine();

        /**
         * Initialize all the SDL modules.
         * 
         * @throws std::runtime_error Thrown when a module fail to initialize.
         * 
         * @param [in] title The window's title.
         * @param [in] width The window's width.
         * @param [in] height The window's height.
         */
        void initialize(const std::string& title, const int width, const int height);

        /**
         * Start the game loop.
         * The loop run indefinitely until `isRunning` become false.
         */
        void run();

        /**
         * Initialze all the SDL modules.
         * 
         * @param [out] window 
         */
        //void initialize(SDL_Window* window, SDL_Renderer* renderer);

        /**
         * Destroy and clear all resources used by SDL modules.
         * This means, this method should be the last call. Any method call that required the window or renderer object will fail.
         * 
         * @param [in] window The pointer to the current window object.
         * @param [in] renderer The pointer to the current renderer.
         */
        //void quit(SDL_Window* window, SDL_Renderer* renderer);

        /**
         * Start the game loop.
         * The loop run indefinitely until `isRunning`
         */
        //void run();
    private:
        SDL_Window* window;
        SDL_Renderer* renderer;
        bool isRunning;
};

#endif