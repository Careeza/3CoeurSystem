#include "render.h"

SDL_Texture     *CS_Renderer::QueryScreen()
{
    return (screen);
}

SDL_Texture     *CS_Renderer::QueryScreenSave()
{
    return (screenSave);
}

SDL_Renderer    *CS_Renderer::QueryRender()
{
    return (render);
}
