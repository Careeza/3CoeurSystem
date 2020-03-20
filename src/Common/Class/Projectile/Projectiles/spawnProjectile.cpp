#include "projectile.h"


CS_PersonalPhysic   *initPhysicProjectile(CS_Animation *animation, bool right, int x, int y)
{
    CS_PersonalPhysic *physic;

    physic = new (CS_PersonalPhysic);

    physic->setPosXPixel(x);
    physic->setPosYPixel(y);
    physic->setSpeedX(animation->QueryMovementX(right));
    physic->setHitBox(animation->QueryHitbox(right));
    physic->setAttack(animation->QueryAttack(right));

    return (physic);
}

CS_Projectile        *copyProjectile(CS_Projectile *projectileSource)
{
    CS_Projectile *newProjectile;

    newProjectile = new (CS_Projectile);

    newProjectile->initAnimation(projectileSource->QueryAnimation());
    newProjectile->setRange(projectileSource->QueryRange());
    newProjectile->setAlly(projectileSource->QueryAlly());

    return (newProjectile);
}

void        CS_Projectiles::spawnProjectile(t_projectile name, int x, int y, bool right)
{
    CS_Projectile *newProjectile;

    newProjectile = copyProjectile(projectileBank->QueryProjectile(name));
    newProjectile->setRight(right);
    newProjectile->initPhysicProjectile(initPhysicProjectile(newProjectile->QueryAnimation(), right, x, y));
    newProjectile->getFrame();

    projectile.push_back(newProjectile);
    updateID();
}
