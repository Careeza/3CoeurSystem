Q#include "render.h"

void    disp_element(std::shared_ptr<CS_Element> element, SDL_Renderer *render)
{
    SDL_Texture     *texture;
    SDL_Rect        *size;

    texture = element->QueryElementTexture();
    size = element->QueryElementSize();
    SDL_RenderCopy(render, texture, NULL, size);
}

void    disp_text(std::shared_ptr<CS_Element> element, SDL_Renderer *render)
{
    SDL_Texture     *texture;
    SDL_Rect        *size;
    CS_Police       *text;

    text = element->QueryText();
    texture = text->QueryTexte();
    size = text->querySize();
    SDL_RenderCopy(render, texture, NULL, size);
}

void    disp_border(std::shared_ptr<CS_Element> element, SDL_Renderer *render)
{
    CS_Border       *border;
    SDL_Texture     *texture;
    SDL_Rect        *size;

    border = element->QueryBorder();
    texture = border->QueryTexture();
    size = border->QueryRectUp();
    SDL_RenderCopy(render, texture, NULL, size);
    size = border->QueryRectDown();
    SDL_RenderCopy(render, texture, NULL, size);
    size = border->QueryRectRight();
    SDL_RenderCopy(render, texture, NULL, size);
    size = border->QueryRectLeft();
    SDL_RenderCopy(render, texture, NULL, size);
}

void    disp_brightness(std::shared_ptr<CS_Element> element, SDL_Renderer *render)
{
    CS_Brightness   *brightness;
    SDL_Texture     *texture;
    SDL_Rect        *size;

    brightness = element->QueryBrightness();
    texture = brightness->QueryTexture();
    size = brightness->QuerySize();
    SDL_RenderCopy(render, texture, NULL, size);
}

void    dispScene(CS_Scene *current, SDL_Renderer *render)
{
    int                                         i;
    int                                         len;
    std::shared_ptr<CS_Element>                 element;

    i = 0;
    len = current->QuerySceneLen();
    while (i < len)
    {
        element = current->QuerySingleElement(i);
        if (element->CS_isElementDisp())
        {
            disp_element(element, render);
            if (element->CS_haveBrightness())
                disp_brightness(element, render);
            if (element->CS_haveText())
                disp_text(element, render);
            if (element->CS_haveBorder()) 
                disp_border(element, render);
        }
        i++;
    }
}

void    renderParallax(CS_Parallax *parallax, SDL_Renderer *render)
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
//        std::cout << "i am here ->" << scopeMain->w << std::endl;
    }
}

void    renderAssets(CS_Assets *assets, SDL_Renderer *render, SDL_Rect *size, int cameraX, int cameraY)
{
    CS_Asset        *asset;
    SDL_Texture     *texture;
    int             i;

    i = 0;

    while (i < assets->QueryNbAssets())
    {
        asset = assets->QueryAsset(i);
        texture = asset->QueryTexture();
        asset->QuerySize(size->w, size->h, size->x, size->y);
        size->x -= cameraX;
        size->y -= cameraY;
        SDL_RenderCopy(render, texture, NULL, size);
        i++;
    }
}


void    renderMC(CS_Character *MC, SDL_Renderer *render, SDL_Rect *size, int cameraX, int cameraY)
{
    SDL_Texture     *texture;
    SDL_Rect        *frame;

    texture = MC->QueryTexture();
    frame = MC->QueryFrame();
    MC->QuerySizePos(size->w, size->h, size->x, size->y);
    size->x -= cameraX;
    size->y -= cameraY;

    SDL_RenderCopy(render, texture, frame, size);
}

void    renderEnemy(CS_Enemies *enemies, SDL_Renderer *render, SDL_Rect *size, int cameraX, int cameraY)
{
    CS_Enemy        *enemy;
    SDL_Texture     *texture;
    SDL_Rect        *frame;
    int             i;

    i = 0;

    while (i < enemies->QueryNbEnemies())
    {
        enemy = enemies->QueryEnemy(i);
        texture = enemy->QueryTexture();
        frame = enemy->QueryFrame();
        enemy->QuerySize(size->w, size->h, size->x, size->y);
        size->x -= cameraX;
        size->y -= cameraY;
        SDL_RenderCopy(render, texture, frame, size);
        i++;
    }
}

void    dispGameScene(CS_GameScene *gameScene, SDL_Renderer *render)
{
    SDL_Rect        size;

    CS_Camera       *camera;
    int             cameraX;
    int             cameraY;

    camera = gameScene->QueryCamera();
    camera->QueryCameraPosition(cameraX, cameraY);

    if (gameScene->haveParallax())
        renderParallax(gameScene->QueryParallax(), render);
    if (gameScene->haveAssets())
        renderAssets(gameScene->QueryAssets(), render, &size, cameraX, cameraY);

    dispScene(gameScene, render);

    if (gameScene->haveMC())
        renderMC(gameScene->QueryMC(), render, &size, cameraX, cameraY);
    if (gameScene->haveEnemies())
        renderEnemy(gameScene->QueryEnemies(), render, &size, cameraX, cameraY);
}

void    CS_Renderer::CS_dispScene(CS_Scene *current, CS_GameScene *gameScene, t_pos pos)
{
    if (gameScene != NULL)
    {
        if (pos & (menuMenu | game))
        {
//            std::cout << "disp game" << std::endl;
            dispGameScene(gameScene, CS_render);
        }
    }
    if (current != NULL)
    {
        if (pos & (homeHome | menuMenu))
        {
//            std::cout << "disp menu" << std::endl;
            dispScene(current, CS_render);
        }
    }
    SDL_RenderPresent(CS_render);
}