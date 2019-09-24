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