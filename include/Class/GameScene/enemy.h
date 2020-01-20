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

typedef enum    e_enemyAction {
    WalkR,
    WalkL,
    AttR,
    AttL,
    StaticR,
    StaticL,
}               t_enemyAction;

class   CS_Enemy
{
    public:
        CS_Enemy();
        ~CS_Enemy();


        void                initEnemyAnimationBank(CS_BankAnimation *animationBankSource);
        void                initEnemyPhysic(CS_PersonalPhysic *physicSource);

        void                setActionToUse(CS_Character *MC);
        void                useEnemyAction();
        void                updateFrame(int deltaT);
        void                moveCharacter(int deltaT);
        void                getFrame();
        
        void                setID(int idSource);


        void                QuerySizePos(int& wDest, int& hDest, int& xDest, int& yDest);
        void                QuerySize(int& wDest, int& hDest);
        void                QueryPos(int& xDest, int& yDest);

        t_enemy             QueryName();
        int                 QueryID();
        CS_Animation        *QueryAnimation();
        CS_PersonalPhysic   *QueryPhysic();
        SDL_Texture         *QueryTexture();
        SDL_Rect            *QueryFrame();


    private:
        t_enemy             name;
        t_enemyAction       action;
        t_enemyAction       (*algo)(CS_Character *MC, CS_PersonalPhysic *physic);
        SDL_Texture         *texture;
        SDL_Rect            *frame;
        CS_BankAnimation    *animationBank;
        CS_PersonalPhysic   *physic;
        CS_Animation        *animation;
        int                 id;
        bool                right;

};

class   CS_EnemyBank
{
    public:
        CS_EnemyBank();
        ~CS_EnemyBank();
        void        addEnemy(CS_Enemy *enemySource);
        CS_Enemy    *QueryEnemy(t_enemy name);

    private:
        std::vector<CS_Enemy *> enemy;
};

class   CS_Enemies
{
    public:
        CS_Enemies();
        ~CS_Enemies();

        void        loadEnemyBank(CS_EnemyBank *enemyBankSource);
        void        addAnEnemy(float x, float y, t_enemy name);
        void        addAnEnemyPixel(int x, int y, t_enemy name);

        void        deleteEnemy(int index);
        void        updateID();

    private:
        std::vector<CS_Enemy *>     enemy;
        CS_EnemyBank               *enemyBank;

};

#endif