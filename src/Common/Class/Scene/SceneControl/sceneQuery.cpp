#include "scene.h"

std::vector<std::shared_ptr<CS_Element>>     CS_Scene::QuerySceneElements()
{
    return (sceneContain);
}

std::shared_ptr<CS_Element>                CS_Scene::QuerySingleElement(int index)
{
    return(sceneContain[index]);
}

int                                         CS_Scene::QuerySceneLen()
{
    return (sceneLen);
}

std::string                                 CS_Scene::QueryName(int index)
{
    return (sceneContain[index]->QueryName());
}

int                                         CS_Scene::QueryIndexByName(std::string name)
{
    int i;

    i = 0;
    while (i < sceneLen)
    {
        if (sceneContain[i]->QueryName().compare(name) == 0)
            return (i);
        i++;
    }
    std::cout << "No element found" << std::endl;
    return (-1);
}

