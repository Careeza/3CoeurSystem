#include "gameScene.h"

bool            CS_Animation::verifyAnimationEnd()
{
    return (interrupt && animationEnd);
}
