#ifndef ENEMY_H

# define ENEMY_H

# include <SDL2/SDL.h>
# include <SDL2/SDL_timer.h>
# include <SDL2/SDL_image.h>
# include <SDL2/SDL_ttf.h>

# include <fstream>
# include <iostream>
# include <string>
# include <vector>
# include <memory>

# include "character.h"

typedef enum	e_enemy {
	CubeRouge,
    CuveVert
}				t_enemy;

class   CS_Enemy
{
    public:
        CS_Enemy();
        ~CS_Enemy();

        void    addEnemy(SDL_Renderer *render, CS_Character *(*create)(SDL_Renderer *render), void (*algoSource)(CS_Character *enemy, CS_Character *MC));
        void    spawnEnemy(float xSource, float ySource);
        void    reloadParam(CS_Character *MC);
        void    getFrame();
        void    moveCharacter();
        
        SDL_Texture *QueryTexture();
        void        QuerySize(int& w, int& h, int& x, int& y);
        SDL_Rect    *QueryFrame();
    private:
        CS_Character    *enemy;
        void            (*algo)(CS_Character *enemy, CS_Character *MC);
};

class   CS_Enemies
{
    public:
        CS_Enemies();
        ~CS_Enemies();

        void        addEnemy(SDL_Renderer *render, CS_Character *(*create)(SDL_Renderer *render), void (*algo)(CS_Character *enemy, CS_Character *MC), float w, float h);
        void        reloadParam(int index, CS_Character *MC);

        CS_Enemy    *QueryEnemy(int index);
        int         QueryNbEnemies();

    private:
        std::vector<CS_Enemy *> enemies;   
};

#endif