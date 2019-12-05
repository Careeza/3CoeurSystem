#include "scene.h"

void                        CS_Scene::CS_writeTexte(int index, std::string comment)
{
    int i;

    if (index == -1)
        i = lastElement;
    else
        i = index;
    CS_sceneContain[i]->setPoliceSettings(colorText);
    CS_sceneContain[i]->CS_addTextToElement(comment, render);
}

void                        CS_Scene::CS_writeTexteScaleW(int index, std::string comment)
{
    int i;

    if (index == -1)
        i = lastElement;
    else
        i = index;
    CS_sceneContain[i]->setPoliceSettings(colorText);
    CS_sceneContain[i]->CS_addTextToElementScaleW(comment, render);
}

void                        CS_Scene::CS_addBorder(int index)
{
    int i;

    if (index == -1)
        i = lastElement;
    else
        i = index;
    CS_sceneContain[i]->loadBorder(colorBordure, render);
}


void                        CS_Scene::CS_addElementToScene(std::shared_ptr<CS_Element> element)
{
    int i;

    i = 0;
    while (i < CS_sceneLen && element->QueryElementZIndex() >= CS_sceneContain[i]->QueryElementZIndex())
        i++;
    CS_sceneContain.emplace(CS_sceneContain.begin() + i, element);
    lastElement = i;
    CS_sceneLen++;
}

void                        CS_Scene::createElementToScene(std::string name, float w, float h, float x, float y, int z)
{
    std::shared_ptr<CS_Element> element (new CS_Element);
    element->CreateNoButtonFromHand(colorSource, colorBrightness, render, w, h, x, y);
    element->setZIndex(z);
    element->loadName(name);
    addElementToScene(element);
}

void                        CS_Scene::createButtonToScene(std::string name, float w, float h, float x, float y, int z, void (*f)(void *, SDL_Renderer*))
{
    std::shared_ptr<CS_Element> element (new CS_Element);
    element->CreateButtonFromHand(colorSource, colorBrightness, render, w, h, x, y, f);
    element->setZIndex(z);
    element->loadName(name);
    addElementToScene(element);
}

void                        CS_Scene::createElementToSceneFromPng(std::string name, std::string route, float w, float h, float x, float y, int z)
{
    std::shared_ptr<CS_Element> element (new CS_Element);
    element->CreateNoButtonFromPng(route, colorBrightness, render, w, h, x, y);
    element->setZIndex(z);
    element->loadName(name);
    addElementToScene(element);
}

void                        CS_Scene::createButtonToSceneFromPng(std::string name, std::string route, float w, float h, float x, float y, int z, void (*f)(void *, SDL_Renderer*))
{
    std::shared_ptr<CS_Element> element (new CS_Element);
    element->CreateButtonFromPng(route, colorBrightness, render, w, h, x, y, f);
    element->setZIndex(z);
    element->loadName(name);
    addElementToScene(element);
}

void                        CS_Scene::deleteElementFromeScene(int index)
{
    if (index >= CS_sceneLen)
        std::cout << "trying to delete a non existant element" << std::endl;
    else
    {
        CS_sceneContain.erase(CS_sceneContain.begin() + index);
        CS_sceneLen--;
    }
}