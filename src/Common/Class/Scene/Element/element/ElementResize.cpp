#include "scene.h"

void            CS_Element::CS_resizeElement(float w, float h, float x, float y)
{
    if (elementIsButton)
        elementButton->CS_resize(w, h, x, y);
    else
        elementNoButton->CS_resize(w, h, x, y);

}

void            CS_Element::CS_resizeElementPixel(int w, int h, int x, int y)
{
    if (elementIsButton)
        elementButton->CS_resizePixel(w, h, x, y);
    else
        elementNoButton->CS_resizePixel(w, h, x, y);
}