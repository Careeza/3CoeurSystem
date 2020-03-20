# include "gameScene.h"

CS_Parallax     *initParallax(SDL_Renderer *render)
{
    CS_Parallax *parallax;


    parallax = new (CS_Parallax);
    parallax->createLayer(render, "resources/source/FondNeige/FOND1/backgroundlayer0.png", 0.03125, 0);
    parallax->createLayer(render, "resources/source/FondNeige/FOND1/backgroundlayer1.png", 0.0625, 1);
    parallax->createLayer(render, "resources/source/FondNeige/FOND1/backgroundlayer2.png", 0.125, 2);
    parallax->createLayer(render, "resources/source/FondNeige/FOND1/backgroundlayer3.png", 0.25, 3);

    return (parallax);
}
