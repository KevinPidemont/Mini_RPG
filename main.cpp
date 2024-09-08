#include "engine/game_engine.h"
#include "engine/graphic_engine.h"

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

/**
 * Main program entry point.
 */
int main(int argc, char const *argv[])
{
    GraphicEngine* graphicEngine = new GraphicEngine();
    GameEngine* gameEngine = new GameEngine(graphicEngine);
    gameEngine->initialize("MiniRPG", WINDOW_WIDTH, WINDOW_HEIGHT);
    gameEngine->run();

    delete gameEngine;

    return 0;
}