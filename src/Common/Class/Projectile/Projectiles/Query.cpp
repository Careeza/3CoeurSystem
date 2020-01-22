#include "projectile.h"

CS_Projectile   *CS_Projectiles::QueryProjectile(int index)
{
    return (projectile[index]);
}

int             CS_Projectiles::QueryNbProjectile()
{
    return (projectile.size());
}