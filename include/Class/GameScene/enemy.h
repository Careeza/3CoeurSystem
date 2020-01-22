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
	Enfant1,
    Enfant2,
    Enfant3,
	Enfant4,
    Enfant5,
    Enfant6,
	Enfant7,
    Enfant8,
    Enfant9,
	Enfant10,
    Enfant11,
    Enfant12,
    Boss,
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


        void                setName(t_enemy nameSource);
        void                initEnemyAnimationBank(CS_BankAnimation *animationBankSource);
        void                initEnemyPhysic(CS_PersonalPhysic *physicSource);
        void                initAlgo(t_enemyAction (*algoSource)(CS_Character *MC, CS_PersonalPhysic *physic));

        void                setActionToUse(CS_Character *MC);
        void                loadAnimation(t_animation name);
        void                updateFrame(int deltaT);
        void                moveCharacter(int deltaT);
        void                getFrame();
        
        void                setID(int idSource);


        void                QuerySizePos(int& wDest, int& hDest, int& xDest, int& yDest);
        void                QuerySize(int& wDest, int& hDest);
        void                QueryPos(int& xDest, int& yDest);

        t_enemy             QueryName();
        int                 QueryID();
        CS_BankAnimation    *QueryAnimationBank();
        CS_Animation        *QueryAnimation();
        CS_PersonalPhysic   *QueryPhysic();
        SDL_Texture         *QueryTexture();
        SDL_Rect            *QueryFrame();
        t_enemyAction (*QueryAlgo())(CS_Character *MC, CS_PersonalPhysic *physic);


    private:
        t_enemy             name;
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
        void        updateEnemies(CS_Character *MC, int deltaT);

        void        deleteEnemy(int index);
        void        updateID();

        CS_Enemy    *QueryEnemy(int index);
        int         QueryNbEnemies();

    private:
        std::vector<CS_Enemy *>     enemies;
        CS_EnemyBank               *enemyBank;

};

#endif