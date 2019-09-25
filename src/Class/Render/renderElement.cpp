#include "render.h"

void    disp_element(std::shared_ptr<CS_Element> element, SDL_Renderer *render)
{
    SDL_Texture     *texture;
    SDL_Rect        *size;

    texture = element->CS_queryElementTexture();
    size = element->CS_queryElementSize();
    SDL_RenderCopy(render, texture, NULL, size);
}

void    disp_text(CS_Police *text, SDL_Renderer *render)
{
    SDL_Texture     *texture;
    SDL_Rect        *size;

    texture = text->CS_queryTexte();
    size = text->querySize();
    SDL_RenderCopy(render, texture, NULL, size);
}

void    disp_border(CS_Border *border, SDL_Renderer *render)
{
    SDL_Texture     *texture;
    SDL_Rect        *size;

    texture = border->CS_queryTexture();
    size = border->CS_queryRectUp();
    SDL_RenderCopy(render, texture, NULL, size);
    size = border->CS_queryRectDown();
    SDL_RenderCopy(render, texture, NULL, size);
    size = border->CS_queryRectRight();
    SDL_RenderCopy(render, texture, NULL, size);
    size = border->CS_queryRectLeft();
    SDL_RenderCopy(render, texture, NULL, size);
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
            disp_element(element, CS_render);
            if (element->CS_haveText())
                disp_text(element->CS_queryText(), CS_render);
            if (element->CS_haveBorder()) 
                disp_border(element->CS_queryBorder(), CS_render);
        }
        i++;
    }
    if (CS_renderScene->CS_DispBrillance())
    {
        brillance = CS_renderScene->CS_queryBrillance();
        texture = brillance->CS_queryElementTexture();
        size = brillance->CS_queryElementSize();
        SDL_RenderCopy(CS_render, texture, NULL, size);
    }
    SDL_RenderPresent(CS_render);
}