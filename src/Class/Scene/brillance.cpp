#include "scene.h"

CS_Element  *CS_Scene::CS_queryBrillance()
{
    return (brillance);
}
        
void        CS_Scene::CS_initBrillance()
{
    CS_setSceneColor(0xFF, 0xFF, 0xFF, 80);
 //   CS_setSceneColor(0xA9, 0xA9, 0xA9, 127);
    brillance->CS_CreateNoButtonFromHand(colorSource, render, 0, 0, 0, 0);
    brillance->CS_setDisp(false);
}
        
void        CS_Scene::resizeBrillance(int w, int h, int x, int y)
{
    brillance->CS_resizeElementPixel(w, h, x, y);
}

void        CS_Scene::CS_setDispBrillance(bool disp)
{
    brillance->CS_setDisp(disp);
}

bool        CS_Scene::CS_DispBrillance()
{
    return(brillance->CS_isElementDisp());
}