#include "scene.h"

std::vector<std::shared_ptr<CS_Element>>     CS_Scene::CS_querySceneElements()
{
    return (CS_sceneContain);
}

std::shared_ptr<CS_Element>                CS_Scene::CS_querySingleElement(int index)
{
    return(CS_sceneContain[index]);
}

int                                         CS_Scene::CS_querySceneLen()
{
    return (CS_sceneLen);
}

std::string                                 CS_Scene::CS_queryName(int index)
{
    return (CS_sceneContain[index]->CS_queryName());
}

int                                         CS_Scene::CS_queryIndexByName(std::string name)
{
    int i;

    i = 0;
    while (i < CS_sceneLen)
    {
        if (CS_sceneContain[i]->CS_queryName().compare(name) == 0)
            return (i);
        i++;
    }
    std::cout << "No element found" << std::endl;
    return (-1);
}

