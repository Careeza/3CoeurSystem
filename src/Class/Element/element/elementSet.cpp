#include "scene.h"

void            CS_Element::CS_setDisp(bool disp)
{
    elementIsDisp = disp;
}

void            CS_Element::CS_setZIndex(int z)
{
    elementZIndex = z;
}

void            CS_Element::loadName(std::string nameSrc)
{
    name = nameSrc;
}

void            CS_Element::setPoliceSettings(CS_Color color, int flags, int marginX, int marginY)
{
    text = new (CS_Police);
    haveText = true;
    text->CS_policeSetting(color, flags, marginX, marginY);
}

void            CS_Element::CS_setBrightness(bool disp)
{
    dispBrightness = disp;
}

void            CS_Element::CS_setZoom(int zoom)
{
    text->CS_zoomText(zoom);
}

