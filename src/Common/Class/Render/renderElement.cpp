#include "render.h"

void    disp_element(std::shared_ptr<CS_Element> element, SDL_Renderer *render)
{
    SDL_Texture     *texture;
    SDL_Rect        *size;

    texture = element->CS_queryElementTexture();
    size = element->CS_queryElementSize();
    SDL_RenderCopy(render, texture, NULL, size);
}

void    disp_text(std::shared_ptr<CS_Element> element, SDL_Renderer *render)
{
    SDL_Texture     *texture;
    SDL_Rect        *size;
    CS_Police       *text;

    text = element->CS_queryText();
    texture = text->CS_queryTexte();
    size = text->querySize();
    SDL_RenderCopy(render, texture, NULL, size);
}

void    disp_border(std::shared_ptr<CS_Element> element, SDL_Renderer *render)
{
    CS_Border       *border;
    SDL_Texture     *texture;
    SDL_Rect        *size;

    border = element->CS_queryBorder();
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

void    disp_brightness(std::shared_ptr<CS_Element> element, SDL_Renderer *render)
{
    CS_Brightness   *brightness;
    SDL_Texture     *texture;
    SDL_Rect        *size;

    brightness = element->CS_queryBrightness();
    texture = brightness->CS_queryTexture();
    size = brightness->CS_querySize();
    SDL_RenderCopy(render, texture, NULL, size);
}

void    dispScene(CS_Scene *current, SDL_Renderer *render)
{
    int                                         i;
    int                                         len;
    std::shared_ptr<CS_Element>                 element;

    i = 0;
    len = current->CS_querySceneLen();
    while (i < len)
    {
        element = current->CS_querySingleElement(i);
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
        layerTexture = layer->queryTexture();
        if (layer->secondScopeNeeded())
        {
            scopeMain = layer->queryScopeMain();
            scopeSecond = layer->queryScopeSecond();
            sizeMain = layer->querySizeMain();
            sizeSecond = layer->querySizeSecond();
            SDL_RenderCopy(render, layerTexture, scopeMain, sizeMain);
            SDL_RenderCopy(render, layerTexture, scopeSecond, sizeSecond);
        }
        else
        {
            scopeMain = layer->queryScopeMain();
            sizeMain = layer->querySizeMain();
            SDL_RenderCopy(render, layerTexture, scopeMain, sizeMain);
        }
        i++;
//        std::cout << "i am here ->" << scopeMain->w << std::endl;
    }
}

void    renderMC(CS_Character *MC, SDL_Renderer *render, SDL_Rect *size, int cameraX, int cameraY)
{
    SDL_Texture     *texture;
    SDL_Rect        *frame;

    texture = MC->queryTexture();
    frame = MC->queryFrame();
    MC->querySizePos(size->w, size->h, size->x, size->y);
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
        texture = enemy->queryTexture();
        frame = enemy->queryFrame();
        enemy->querySize(size->w, size->h, size->x, size->y);
        size->x -= cameraX;
        size->y -= cameraY;
        SDL_RenderCopy(render, texture, frame, size);
        i++;
    }
}

void    dispGameScene(CS_GameScene *gameScene, SDL_Renderer *render)
{
    CS_Enemy        *enemy;
    SDL_Texture     *texture;
    SDL_Rect        *frame;
    SDL_Rect        *size;

    CS_Camera       *camera;
    int             cameraX;
    int             cameraY;

    size = new (SDL_Rect);

    camera = gameScene->QueryCamera();
    camera->queryCameraPosition(cameraX, cameraY);

    if (gameScene->haveParallax())
        renderParallax(gameScene->QueryParallax(), render);
    if (gameScene->haveMC())
        renderMC(gameScene->CS_queryMC(), render, size, cameraX, cameraY);
    if (gameScene->haveEnemies())
        renderEnemy(gameScene->CS_queryEnemies(), render, size, cameraX, cameraY);

    delete size;
}

void    CS_Renderer::CS_dispScene(CS_Scene *current, CS_GameScene *gameScene, t_pos pos)
{
    if (current != NULL)
    {
        if (pos & (menuMenu | game))
            dispGameScene(gameScene, CS_render);
        if (pos & (homeHome | menuMenu))
            dispScene(current, CS_render);
    }
    SDL_RenderPresent(CS_render);
}