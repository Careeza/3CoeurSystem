#ifndef PROJECTILE_H

# define PROJECTILE_H

# include <SDL2/SDL.h>
# include <SDL2/SDL_timer.h>
# include <SDL2/SDL_image.h>
# include <SDL2/SDL_ttf.h>
# include <SDL2/SDL_mixer.h>

# include <fstream>
# include <iostream>
# include <string>
# include <vector>
# include <memory>

# include "character.h"

typedef enum	e_projectile {
	projectile1,
	projectile2,
	projectile3,
}				t_projectile;

class   CS_Projectile
{
    public:
        CS_Projectile();
        ~CS_Projectile();


        void                initPhysicProjectile(CS_PersonalPhysic *physicSource);
        void                initAnimation(CS_Animation *animationSource);

        void                updateFrame(int deltaT);
        void                moveProjectile(CS_GameScene *scene, int deltaT);
        void                getFrame();
        bool                projectileEnd();
        
        void                setName(t_projectile nameSource);
        void                setID(int idSource);
        void                setRight(int rightSource);
        void                setRange(int rangeSource);
        void                setAlly(bool allySource);

        void                QuerySizePos(int& wDest, int& hDest, int& xDest, int& yDest);
        void                QuerySize(int& wDest, int& hDest);
        void                QueryPos(int& xDest, int& yDest);

        int                 QueryID();
        int                 QueryRange();
        bool                QueryAlly();
        t_projectile        QueryName();
        CS_Animation        *QueryAnimation();
        CS_PersonalPhysic   *QueryPhysic();
        SDL_Texture         *QueryTexture();
        SDL_Rect            *QueryFrame();

    private:
        t_projectile        name;
        SDL_Texture         *texture;
        SDL_Rect            *frame;
        CS_PersonalPhysic   *physic;
        CS_Animation        *animation;
        int                 range;
        int                 id;
        bool                right;
        bool                ally;
};

class   CS_ProjectileBank
{
    public:
        CS_ProjectileBank();
        ~CS_ProjectileBank();
        void            addProjectile(CS_Projectile *projectileSource);
        CS_Projectile   *QueryProjectile(t_projectile name);

    private:
        std::vector<CS_Projectile *> projectile;
};

class   CS_Projectiles
{
    public:
        CS_Projectiles();
        ~CS_Projectiles();

        void        spawnProjectile(t_projectile name, int x, int y, bool right);
        void        loadProjectileBank(CS_ProjectileBank *projectileBankSource);
        void        deleteProjectile(int index);
        void        updateProjectiles(CS_GameScene *scene, int deltaT);
        void        updateID();

        CS_Projectile   *QueryProjectile(int index);
        int             QueryNbProjectile();

    private:
        std::vector<CS_Projectile *>    projectile;
        CS_ProjectileBank               *projectileBank;

};

#endif