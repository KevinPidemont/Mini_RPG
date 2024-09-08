#ifndef GRAPHIC_OBJECT
#define GRAPHIC_OBJECT

#include <SDL.h>

class GraphicObject {
    public:
        virtual ~GraphicObject() = default;

        virtual const SDL_Rect& getSrcRect() const = 0;

        virtual SDL_Point getPosition() = 0;
};

#endif