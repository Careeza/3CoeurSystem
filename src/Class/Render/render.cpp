#include "render.h"

void    CS_Renderer::CS_loadScene(CS_Scene *scene)
{
    CS_renderScene = scene;
}

void    CS_Renderer::CS_loadRenderer(SDL_Renderer *render)
{
    CS_render = render;
}

void    CS_Renderer::CS_dispScene()
{
    int                                         i;
    int                                         len;
    std::shared_ptr<CS_Element>                 element;
    CS_Element                                  *brillance;
    SDL_Texture                                 *texture;
    SDL_Rect                                    *size;

    i = 0;
    len = CS_renderScene->CS_querySceneLen();
    while (i < len)
    {
        element = CS_renderScene->CS_querySingleElement(i);
        if (element->CS_isElementDisp())
        {
            texture = element->CS_queryElementTexture();
            size = element->CS_queryElementSize();
            SDL_RenderCopy(CS_render, texture, NULL, size);
        }
        i++;
    }
    if (CS_renderScene->CS_DispBrillance())
    {
        brillance = CS_renderScene->CS_queryBrillance();
        texture = brillance->CS_queryElementTexture();
        size = brillance->CS_queryElementSize();
        SDL_RenderCopy(CS_render, texture, NULL, size);
//        std::cout << size->w << std::endl;
    }
    SDL_RenderPresent(CS_render);
}