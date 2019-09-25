#include "scene.h"

bool            CS_Element::CS_isElementButton()
{
    return (elementIsButton);
}

bool            CS_Element::CS_isElementDisp()
{
    return(elementIsDisp);
}

bool            CS_Element::CS_haveBorder()
{
    return (dispBorder);
}

bool            CS_Element::CS_haveText()
{
    return (haveText);
}

bool            CS_Element::CS_haveBrightness()
{
    return (dispBrightness);
}
