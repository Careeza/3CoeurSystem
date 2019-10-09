#include "scene.h"

CS_Scene::CS_Scene()
{
    std::cout << " --- create scene --- "<< std::endl;
    CS_sceneLen = 0;

    colorBrightness.CS_setColor(0xFF, 0xFF, 0xFF, 80);
}

CS_Scene::~CS_Scene()
{
    int i;

    i = 0;
    while (i < CS_sceneLen)
    {
        CS_sceneContain.pop_back();
        i++;
    }
    CS_sceneLen = 0;
}

void                        CS_Scene::CS_loadRenderer(SDL_Renderer *renderSource)
{
    render = renderSource;
}

void                        CS_Scene::CS_setSceneColor(int r, int g, int b, int a)
{
    colorSource.CS_setColor(r, g, b, a);
}

void                        CS_Scene::CS_setBorderColor(int r, int g, int b, int a)
{
    colorBordure.CS_setColor(r, g, b, a);
}

void                        CS_Scene::CS_setTextColor(int r, int g, int b, int a)
{
    colorText.CS_setColor(r, g, b, a);
}

void                        CS_Scene::CS_setBrightnessColor(int r, int g, int b, int a)
{
    colorBrightness.CS_setColor(r, g, b, a);
}

void                        CS_Scene::CS_setDisp(bool disp, int index)
{
    if (index == -1)
        index = lastElement;
    CS_sceneContain[index]->CS_setDisp(disp);
}
