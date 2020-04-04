# include "gameScene.h"

CS_Animation        *initAnimationProjectile3(SDL_Renderer *render)
{
    CS_Animation    *animation;
    
    animation = new (CS_Animation);

    animation->newAnimation(STATIC, true);
    animation->loadTexture(render, "resources/source/Projectiles/MC2attackProjectileL.png", "resources/source/Projectiles/MC2attackProjectileR.png");
    animation->setSize(3, 2);
    animation->cutFrame(1, 1, 1);
    animation->setSpeed(0.06, 0);
    animation->setAnimationTime(300);

    return (animation);
}

CS_Projectile       *initProjectile3(SDL_Renderer *render)
{
    CS_Projectile   *projectile;

    projectile = new (CS_Projectile);

    projectile->setName(projectile3);
    projectile->setRange(3000);
    projectile->initAnimation(initAnimationProjectile3(render));
    projectile->setAlly(true);

    return (projectile);
}

CS_Animation        *initAnimationProjectile2(SDL_Renderer *render)
{
    CS_Animation    *animation;
    
    animation = new (CS_Animation);

    animation->newAnimation(STATIC, true);
    animation->loadTexture(render, "resources/source/Projectiles/Projectile2Boss.png", "resources/source/Projectiles/Projectile2Boss.png");
    animation->setSize(6, 10);
    animation->cutFrame(1, 1, 1);
    animation->setSpeed(0.03, 0);
    animation->setAnimationTime(200);

    return (animation);
}

CS_Projectile       *initProjectile2(SDL_Renderer *render)
{
    CS_Projectile   *projectile;

    projectile = new (CS_Projectile);

    projectile->setName(projectile2);
    projectile->setRange(3000);
    projectile->initAnimation(initAnimationProjectile2(render));
    projectile->setAlly(false);

    return (projectile);
}

CS_Animation        *initAnimationProjectile1(SDL_Renderer *render)
{
    CS_Animation    *animation;
    
    animation = new (CS_Animation);

    animation->newAnimation(STATIC, true);
    animation->loadTexture(render, "resources/source/Projectiles/Projectile1Boss.png", "resources/source/Projectiles/Projectile1Boss.png");
    animation->setSize(3, 5);
    animation->cutFrame(2, 2, 1);
    animation->setSpeed(0.06, 0);
    animation->setAnimationTime(200);

    return (animation);
}

CS_Projectile       *initProjectile1(SDL_Renderer *render)
{
    CS_Projectile   *projectile;

    projectile = new (CS_Projectile);

    projectile->setName(projectile1);
    projectile->setRange(3000);
    projectile->initAnimation(initAnimationProjectile1(render));
    projectile->setAlly(false);

    return (projectile);
}

CS_ProjectileBank   *initProjectileBank(SDL_Renderer *render)
{
    CS_ProjectileBank *projectileBank;

    projectileBank = new (CS_ProjectileBank);

    projectileBank->addProjectile(initProjectile1(render));
    projectileBank->addProjectile(initProjectile2(render));
    projectileBank->addProjectile(initProjectile3(render));

    return (projectileBank);
}

CS_Projectiles      *initProjectiles(SDL_Renderer *render)
{
    CS_Projectiles *projectiles;

    projectiles = new (CS_Projectiles);

    projectiles->loadProjectileBank(initProjectileBank(render));

    return (projectiles);
}
