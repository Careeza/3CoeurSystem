#include "scene.h"

void            CS_Element::setDisp(bool disp)
{
    elementIsDisp = disp;
}

void            CS_Element::setZIndex(int z)
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
    text->policeSetting(color, flags, marginX, marginY);
}

void            CS_Element::setBrightness(bool disp)
{
    dispBrightness = disp;
}

void            CS_Element::setZoom(int zoom)
{
    text->zoomText(zoom);
}

void            CS_Element::setButton(bool button)
{
    enabaleButton = button;
}
