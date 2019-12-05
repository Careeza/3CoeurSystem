#include "scene.h"

CS_Scene::CS_Scene()
{
    Tools->verbose(LEVEL2, "s", "create scene");
    sceneLen = 0;

    colorBrightness.setColor(0xFF, 0xFF, 0xFF, 80);
}

CS_Scene::~CS_Scene()
{
    int i;

    Tools->verbose(LEVEL2, "s", "delete scene");
    i = 0;
    while (i < sceneLen)
    {
        sceneContain.pop_back();
        i++;
    }
    sceneLen = 0;
}

void                        CS_Scene::loadRenderer(SDL_Renderer *renderSource)
{
    render = renderSource;
}

void                        CS_Scene::setSceneColor(int r, int g, int b, int a)
{
    colorSource.setColor(r, g, b, a);
}

void                        CS_Scene::setBorderColor(int r, int g, int b, int a)
{
    colorBordure.setColor(r, g, b, a);
}

void                        CS_Scene::setTextColor(int r, int g, int b, int a)
{
    colorText.setColor(r, g, b, a);
}

void                        CS_Scene::setBrightnessColor(int r, int g, int b, int a)
{
    colorBrightness.setColor(r, g, b, a);
}

void                        CS_Scene::setDisp(bool disp, int index)
{
    if (index == -1)
        index = lastElement;
    sceneContain[index]->setDisp(disp);
}

void                        CS_Scene::setButton(bool button, int index)
{
    if (index == -1)
        index = lastElement;
    sceneContain[index]->setButton(button);   
}
