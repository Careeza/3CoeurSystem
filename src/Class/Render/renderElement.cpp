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

void    dispGameScene(CS_GameScene *gameScene, SDL_Renderer *render)
{
    CS_Character    *MC;
    SDL_Texture     *texture;
    SDL_Rect        *size;
    SDL_Rect        *frame;

    dispScene(gameScene, render);
    MC = gameScene->CS_queryMC();
    texture = MC->queryTexture();
    frame = MC->queryFrame();
    size = MC->querySize();
    if (render == NULL)
    {
        std::cout << "la texture c'est une pute" << std::endl;
        exit (0);
    }
    if (size == NULL)
    {
        std::cout << "la texture c'est une pute" << std::endl;
        exit (0);
    }
    if (frame == NULL)
    {
        std::cout << "la texture c'est une pute" << std::endl;
        exit (0);
    }
    SDL_RenderCopy(render, texture, frame, size);
}

void    CS_Renderer::CS_dispScene()
{
    if (gameSettings.current != NULL)
    {
        if (gameSettings.pos & (menuMenu | game))
            dispGameScene(gameSettings.gameScene, CS_render);
        if (gameSettings.pos & (homeHome | menuMenu))
            dispScene(gameSettings.current, CS_render);
    }
    SDL_RenderPresent(CS_render);
}