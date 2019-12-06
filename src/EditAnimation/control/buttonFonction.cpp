#include "editAnimation.h"

void    nextFrame(void* settings, SDL_Renderer *render)
{
    CS_EditAnimationSetting *set;
    CS_Character            *MC;

    (void)render;
    set = (CS_EditAnimationSetting*)settings;
    MC = set->QueryGameScene()->QueryMC();
    if (set->isPaused())
    {
        MC->nextFrame();
        MC->getFrame();
    }
}

void    previousFrame(void* settings, SDL_Renderer *render)
{
    CS_EditAnimationSetting *set;
    CS_Character            *MC;

    (void)render;
    set = (CS_EditAnimationSetting*)settings;
    MC = set->QueryGameScene()->QueryMC();
    if (set->isPaused())
    {
        MC->previousFrame();
        MC->getFrame();
    }
}

void    pause(void* settings, SDL_Renderer *render)
{
    CS_EditAnimationSetting *set;

    (void)render;
    set = (CS_EditAnimationSetting*)settings;
    set->pause();
}

void    play(void* settings, SDL_Renderer *render)
{
    CS_EditAnimationSetting *set;

    (void)render;
    set = (CS_EditAnimationSetting*)settings;
    set->play();
}

void    left(void* settings, SDL_Renderer *render)
{
    CS_EditAnimationSetting *set;
    CS_Character            *MC;

    (void)render;
    set = (CS_EditAnimationSetting*)settings;
    MC = set->QueryGameScene()->QueryMC();
    MC->setRight(false);
    MC->getFrame();
}

void    right(void* settings, SDL_Renderer *render)
{
    CS_EditAnimationSetting *set;
    CS_Character            *MC;

    (void)render;
    set = (CS_EditAnimationSetting*)settings;
    MC = set->QueryGameScene()->QueryMC();
    MC->setRight(true);
    MC->getFrame();
}

void    incraseFps(void* settings, SDL_Renderer *render)
{
    CS_EditAnimationSetting *set;
    CS_Character            *MC;

    std::shared_ptr<CS_Element> element;
    int                         index;

    (void)render;
    set = (CS_EditAnimationSetting*)settings;
    set->increaseFps();
    MC = set->QueryGameScene()->QueryMC();
    MC->setPas((set->QueryFpsAnimation() / (float)set->QueryFps()));

    index = set->QueryGameScene()->QueryIndexByName("fps");
    element = set->QueryGameScene()->QuerySingleElement(index);
    element->changeText(std::to_string(set->QueryFpsAnimation()), render);
}

void    decreaseFps(void* settings, SDL_Renderer *render)
{
    CS_EditAnimationSetting *set;
    CS_Character            *MC;

    std::shared_ptr<CS_Element> element;
    int                         index;

    (void)render;
    set = (CS_EditAnimationSetting*)settings;
    set->decreaseFps();
    MC = set->QueryGameScene()->QueryMC();
    MC->setPas((set->QueryFpsAnimation() / (float)set->QueryFps()));

    index = set->QueryGameScene()->QueryIndexByName("fps");
    element = set->QueryGameScene()->QuerySingleElement(index);
    element->changeText(std::to_string(set->QueryFpsAnimation()), render);
}