#include "projectile.h"

void        CS_Projectiles::deleteProjectile(int index)
{
    projectile.erase(projectile.begin() + index);
    updateID();
}
