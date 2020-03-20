#include "render.h"

void    CS_Renderer::renderScene(CS_Scene *scene)
{
    int                                         i;
    int                                         len;
    std::shared_ptr<CS_Element>                 element;

    if (scene->QueryDispScene())
    {
        i = 0;
        len = scene->QuerySceneLen();
        while (i < len)
        {
            element = scene->QuerySingleElement(i);
            if (element->isElementDisp())
            {
                renderElement(element);
                if (element->haveBrightness())
                    renderBrightness(element->QueryBrightness());
                if (element->containsText())
                    renderText(element->QueryText());
                if (element->haveBorder()) 
                    renderBorder(element->QueryBorder());
            }
            i++;
        }
    }
}
