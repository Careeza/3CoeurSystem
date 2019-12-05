#include "scene.h"

bool            CS_Element::isElementButton()
{
    return (elementIsButton);
}

bool            CS_Element::isElementDisp()
{
    return(elementIsDisp);
}

bool            CS_Element::haveBorder()
{
    return (dispBorder);
}

bool            CS_Element::containsText()
{
    return (haveText);
}

bool            CS_Element::haveBrightness()
{
    return (dispBrightness);
}

bool            CS_Element::isButtonEnable()
{
    return (enabaleButton);
}