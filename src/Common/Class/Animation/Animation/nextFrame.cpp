# include "gameScene.h"

void        CS_Animation::nextFrame2(int deltaT)
{
    time += deltaT;
    if (time >= animationTime)
        time -= animationTime;
    index = time / frameTime;
    if (index == nbFrame)
    {
        std::cout << "time - " << time << " <-> " << animationTime << std::endl;
        std::cout << "frame - " << nbFrame << " <-> " << index << std::endl;
        std::cout << "frame time = " << frameTime << std::endl;
        exit (0);
    }
    if (index == nbFrame - 1)
        animationEnd = true;
    else
        animationEnd = false;
}


void        CS_Animation::nextFrame()
{
    index++;
    if (index >= nbFrame)
        index = 0;
}

void        CS_Animation::previousFrame()
{
    index--;
    if (index < 0)
        index = nbFrame - 1;
}