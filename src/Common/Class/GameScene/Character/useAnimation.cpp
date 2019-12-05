# include "gameScene.h"


bool        CS_Character::nextFrame()
{
    animation->nextFrame();
}

bool        CS_Character::previousFrame()
{
    animation->previousFrame();
}

void        CS_Character::getFrame()
{
    animation->getFrame(right, frame, texture);
}

void        CS_Character::moveCharacter()
{
    animation->moveCharacter(right, x, y);
}


void        CS_Character::setRight(bool rightSource)
{
    right = rightSource;
}