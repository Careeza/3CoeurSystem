#include "scene.h"

void            CS_Element::resizeElement(float w, float h, float x, float y)
{
    if (elementIsButton)
        elementButton->resize(w, h, x, y);
    else
        elementNoButton->resize(w, h, x, y);

}

void            CS_Element::resizeElementPixel(int w, int h, int x, int y)
{
    if (elementIsButton)
        elementButton->resizePixel(w, h, x, y);
    else
        elementNoButton->resizePixel(w, h, x, y);
}