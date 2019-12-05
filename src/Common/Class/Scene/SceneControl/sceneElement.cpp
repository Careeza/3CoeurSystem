#include "scene.h"

void                        CS_Scene::writeTexte(int index, std::string comment)
{
    int i;

    if (index == -1)
        i = lastElement;
    else
        i = index;
    std::cout << "element = " << sceneContain[i]->QueryName() << std::endl;
    sceneContain[i]->setPoliceSettings(colorText);
    sceneContain[i]->addTextToElement(comment, render);
}

void                        CS_Scene::writeTexteScaleW(int index, std::string comment)
{
    int i;

    if (index == -1)
        i = lastElement;
    else
        i = index;
    sceneContain[i]->setPoliceSettings(colorText);
    sceneContain[i]->addTextToElementScaleW(comment, render);
}

void                        CS_Scene::addBorder(int index)
{
    int i;

    if (index == -1)
        i = lastElement;
    else
        i = index;
    sceneContain[i]->loadBorder(colorBordure, render);
}


void                        CS_Scene::addElementToScene(std::shared_ptr<CS_Element> element)
{
    int i;

    i = 0;
    while (i < sceneLen && element->QueryElementZIndex() >= sceneContain[i]->QueryElementZIndex())
        i++;
    sceneContain.emplace(sceneContain.begin() + i, element);
    lastElement = i;
    sceneLen++;
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
    if (index >= sceneLen)
        std::cout << "trying to delete a non existant element" << std::endl;
    else
    {
        sceneContain.erase(sceneContain.begin() + index);
        sceneLen--;
    }
}