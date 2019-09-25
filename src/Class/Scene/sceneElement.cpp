#include "scene.h"

void                        CS_Scene::CS_writeTexte(int index, std::string comment)
{
    int i;

    if (index == -1)
        i = lastElement;
    else
        i = index;
    CS_sceneContain[i]->setPoliceSettings(colorSource);
    CS_sceneContain[i]->CS_addTextToElement(comment, render);
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
    while (i < CS_sceneLen && element->CS_queryElementZIndex() >= CS_sceneContain[i]->CS_queryElementZIndex())
        i++;
    CS_sceneContain.emplace(CS_sceneContain.begin() + i, element);
    lastElement = i;
    CS_sceneLen++;
}

void                        CS_Scene::CS_createElementToScene(float w, float h, float x, float y, int z)
{
    std::shared_ptr<CS_Element> element (new CS_Element);
    element->CS_CreateNoButtonFromHand(colorSource, render, w, h, x, y);
    element->CS_setZIndex(z);
    CS_addElementToScene(element);
}

void                        CS_Scene::CS_createButtonToScene(float w, float h, float x, float y, int z, void (*f)(void))
{
    std::shared_ptr<CS_Element> element (new CS_Element);
    element->CS_CreateButtonFromHand(colorSource, render, w, h, x, y, f);
    element->CS_setZIndex(z);
    CS_addElementToScene(element);
}

void                        CS_Scene::CS_deleteElementFromeScene(int index)
{
    if (index >= CS_sceneLen)
        std::cout << "trying to delete a non existant element" << std::endl;
    else
    {
        CS_sceneContain.erase(CS_sceneContain.begin() + index);
        CS_sceneLen--;
    }
}