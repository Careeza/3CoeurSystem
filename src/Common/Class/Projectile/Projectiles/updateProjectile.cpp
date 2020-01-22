#include "projectile.h"

void        CS_Projectiles::updateProjectiles(int deltaT)
{
    unsigned long i;

    i = 0;
    while (i < projectile.size())
    {
        projectile[i]->updateFrame(deltaT);
        projectile[i]->moveProjectile(deltaT);
        projectile[i]->getFrame();
        if (projectile[i]->projectileEnd())
                deleteProjectile(i);
        i++;
    }
}

void        CS_Projectiles::updateID()
{
    unsigned long i;

    i = 0;
    while (i < projectile.size())
    {
        projectile[i]->setID(i);
        i++;
    }
}