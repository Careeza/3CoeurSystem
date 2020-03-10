# include "initMC.h"

CS_PersonalPhysic   *initPhysic()
{
    CS_PersonalPhysic *physic;

    physic = new (CS_PersonalPhysic);
    physic->setPosXPixel(0);
    physic->setPosY(0);
    
    return (physic);
}

CS_Character        *initMC(SDL_Renderer *render)
{
    CS_Character    *MC;
    int             i = 0;

    MC = new(CS_Character);

    MC->setMC(KITSUNE);
    MC->addAnimation(render, staticKitsune);
    MC->addAnimation(render, walkKitsune);
    MC->addAnimation(render, jumpKitsune);
    MC->addAnimation(render, fallKitsune);
    MC->addAnimation(render, attackKitsune);


    MC->setMC(MOINE);
    MC->addAnimation(render, staticMoine);
    MC->addAnimation(render, walkMoine);
    MC->addAnimation(render, attackMoine);
    MC->addAnimation(render, jumpMoine);
    MC->addAnimation(render, fallMoine);
    MC->addAnimation(render, dashMoine);


    MC->loadAnimation(STATIC);

    MC->loadPhysic(initPhysic());

    
    return (MC);
}