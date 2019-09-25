#include "render.h"

void    CS_Renderer::CS_loadScene(CS_Scene *scene)
{
    CS_renderScene = scene;
}

void    CS_Renderer::CS_loadRenderer(SDL_Renderer *render)
{
    CS_render = render;
}