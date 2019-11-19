#include "keyControl.h"

CS_KeyControl::CS_KeyControl()
{
}

int    CS_KeyControl::loadEvenement(CS_Scene *scene)
{
    int eventLoop;

    scene = currentScene;
    len = scene->CS_querySceneLen() - 1;
    eventLoop = SDL_PollEvent(&event);
    type = event.type;
    return (eventLoop);
} // TODO

/* int     CS_KeyControl::getMouseActions(int& x, int& y)
{
    if (type == SDL_MOUSEMOTION)
    {
        mouse_x = event.motion.x;
        mouse_y = event.motion.y;
        x = mouse_x;
        y = mouse_y;
        // TODO
        return (CS_MOTION);
    }
    if (type == SDL_MOUSEBUTTONDOWN && keyPress == false)
    {
        keyPress = true;
        static_x = event.button.x;
        static_y = event.button.y;
        x = static_x;
        y = static_y;
        return (CS_MOUSE_DOWN);
    }
    else if (type == SDL_MOUSEBUTTONUP)
    {
        keyPress = false;
        return (CS_MOUSE_UP);
    }
    return (0);
}*/