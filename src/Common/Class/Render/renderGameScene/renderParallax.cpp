#include "render.h"

void    renderHitBox(SDL_Renderer *render, SDL_Rect *rect)
{
    SDL_SetRenderDrawColor(render, 255, 0, 0, 255);
    SDL_RenderDrawRect(render, rect);
}

void    CS_Renderer::renderParallax(CS_Parallax *parallax)
{
    SDL_Rect    *scopeMain;
    SDL_Rect    *scopeSecond;
    SDL_Rect    *sizeMain;
    SDL_Rect    *sizeSecond;

    SDL_Texture *layerTexture;

    CS_Layer    *layer;
    int         len;
    int         i;

    len = parallax->QueryNbLayers();
    i = 0;
    while (i < len)
    {
        layer = parallax->QueryLayer(i);
        layerTexture = layer->QueryTexture();
        if (layer->secondScopeNeeded())
        {
            scopeMain = layer->QueryScopeMain();
            scopeSecond = layer->QueryScopeSecond();
            sizeMain = layer->QuerySizeMain();
            sizeSecond = layer->QuerySizeSecond();
            SDL_RenderCopy(render, layerTexture, scopeMain, sizeMain);
            SDL_RenderCopy(render, layerTexture, scopeSecond, sizeSecond);
        }
        else
        {
            scopeMain = layer->QueryScopeMain();
            sizeMain = layer->QuerySizeMain();
            SDL_RenderCopy(render, layerTexture, scopeMain, sizeMain);
        }
        i++;
    }
}
