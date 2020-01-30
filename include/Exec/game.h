#ifndef GAME_H

# define GAME_H

# include <SDL2/SDL.h>
# include <SDL2/SDL_timer.h>
# include <SDL2/SDL_image.h>
# include <SDL2/SDL_ttf.h>

# include <fstream>
# include <iostream>
# include <string>
# include <vector>
# include <stdarg.h>
# include <math.h>
# include <time.h>

# include "tools.h"
# include "common.h"

typedef enum	e_pos {
	home,
    levelSelect,
    game,
    close,
}				t_pos;


void            homeGetEvenement(CS_Scene *scene, std::shared_ptr<CS_Element>& button, t_actionValue *value, t_actionTable *actionTable);
void            basicGetEvenement(CS_Scene *scene, t_actionValue *value, t_actionTable *actionTable);
void            homeEventProcessing(t_actionTable *actionTable, t_action *action);
bool            basicUseEvent(t_action action);

bool            callDialogueBox(CS_Renderer *render, t_actionValue *value, t_actionTable *actionTable);

void            logoCinematics(CS_Renderer *render, t_actionValue *value, t_actionTable *actionTable);
void            homeCinematics(CS_Renderer *render,  t_actionValue *value, t_actionTable *actionTable);
int             gameOver(CS_Renderer *render, t_actionValue *value, t_actionTable *actionTable, int level);


t_pos           loopHome(CS_Renderer *render, t_actionValue *value, t_actionTable *actionTable); // => need le render et les settings et la texture screen
CS_Scene        *initHome(SDL_Renderer *render);
t_pos           homeUseEvent(t_action action, std::shared_ptr<CS_Element> button, CS_Renderer *render, t_actionValue *value, t_actionTable *actionTable);

t_pos           loopLevelSelect(CS_Renderer *render, t_actionValue *value, t_actionTable *actionTable);
CS_Scene        *initLevelSelect(SDL_Renderer *render);
t_pos           levelSelectEvent(t_action action, std::shared_ptr<CS_Element> button);


bool            loopMenu(CS_Renderer *render, t_actionValue *value, t_actionTable *actionTable);
CS_Scene        *initMenu(SDL_Renderer *render);
int             MenuUseEvent(t_action action, std::shared_ptr<CS_Element> button);

int             gameUseEventStage(t_action action, CS_Renderer *render, t_actionValue *value, t_actionTable *actionTable, CS_Timer *timer);
int             KillMonster(CS_Enemies *enemies, CS_Camera *camera);

int             startLevel01(CS_Renderer *render, t_actionValue *value, t_actionTable *actionTable, CS_GameScene *scene, bool restart);
int             startLevel02(CS_Renderer *render, t_actionValue *value, t_actionTable *actionTable, CS_GameScene *scene, bool restart);

t_pos           loopGame(CS_Renderer *render, t_actionValue *value, t_actionTable *actionTable);
CS_Camera       *initCamera();
CS_Enemies      *initEnemies(SDL_Renderer *render);
CS_GameScene    *initGameScene(SDL_Renderer *render);
CS_Character    *initMC(SDL_Renderer *render);
CS_Parallax     *initParallax(SDL_Renderer *render);
void            gameGetEvenement(CS_Scene *scene, t_actionValue *value, t_actionTable *actionTable);
void            gameEventProcessing(t_actionTable *actionTable, t_action *action);
t_pos           gameUseEvent(t_action action, CS_Renderer *render, t_actionValue *value, t_actionTable *actionTable, CS_Timer *timer);
void            useAction(t_action *table, CS_GameScene *scene);
void            parallaxManagement(CS_Parallax *parallax, CS_Camera *camera);
CS_Assets       *initAssets(SDL_Renderer *render);

CS_Projectiles  *initProjectiles(SDL_Renderer *render);

void            resolveAllAction(CS_GameScene *scene, int bornMin, int bornMax);
CS_Animation    *deadEnfant(SDL_Renderer *render);
CS_Enemy        *initEnfant1(SDL_Renderer *render);
CS_Enemy        *initEnfant2(SDL_Renderer *render);
CS_Enemy        *initEnfant3(SDL_Renderer *render);
CS_Enemy        *initEnfant4(SDL_Renderer *render);
CS_Enemy        *initEnfant5(SDL_Renderer *render);
CS_Enemy        *initEnfant6(SDL_Renderer *render);

CS_EnemyBank    *initBankEnemies(SDL_Renderer *render);



#endif