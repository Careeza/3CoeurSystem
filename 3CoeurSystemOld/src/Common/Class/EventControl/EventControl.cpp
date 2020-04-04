#include "keyControl.h"

CS_KeyControl::CS_KeyControl()
{
}

int    CS_KeyControl::loadEvenement(CS_Scene *sceneSource)
{
    int eventLoop;

    scene = sceneSource;
    len = scene->QuerySceneLen() - 1;
    eventLoop = SDL_PollEvent(&event);
    type = event.type;
    return (eventLoop);
}
