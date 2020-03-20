#include "projectile.h"

CS_Projectile   *CS_ProjectileBank::QueryProjectile(t_projectile name)
{
    unsigned long i;

    i = 0;
    while (i < projectile.size())
    {
        if (name == projectile[i]->QueryName())
            return (projectile[i]);
        i++;
    }
    std::cout << "something went wrong in queryProjectile" << std::endl;
    return (NULL);
}
