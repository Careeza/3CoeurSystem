#include "editAnimation.h"

CS_EditAnimationSetting::CS_EditAnimationSetting()
{
    paused = true;
}

CS_EditAnimationSetting::~CS_EditAnimationSetting()
{

}

void    CS_EditAnimationSetting::play()
{
    paused = false;
}

void    CS_EditAnimationSetting::pause()
{
    paused = true;
}

bool    CS_EditAnimationSetting::isPaused()
{
    return (paused);
}

void    CS_EditAnimationSetting::setFpsAnimation(int fpsSource)
{
    fpsAnimation = fpsSource;
}


int     CS_EditAnimationSetting::QueryFpsAnimation()
{
    return (fpsAnimation);
}

void    CS_EditAnimationSetting::increaseFps(int fps)
{
    fpsAnimation += fps;
}

void    CS_EditAnimationSetting::decreaseFps(int fps)
{
    fpsAnimation -= fps;
}