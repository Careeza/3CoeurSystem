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


t_pos           loopHome(CS_Renderer *render, t_actionValue *value, t_actionTable *actionTable); // => need le render et les settings et la texture screen
CS_Scene        *initHome(SDL_Renderer *render);
t_pos           homeUseEvent(t_action action, std::shared_ptr<CS_Element> button, CS_Renderer *render, t_actionValue *value, t_actionTable *actionTable);

t_pos           loopLevelSelect(CS_Renderer *render, t_actionValue *value, t_actionTable *actionTable);
CS_Scene        *initLevelSelect(SDL_Renderer *render);
t_pos           levelSelectEvent(t_action action, std::shared_ptr<CS_Element> button);


bool            loopMenu(CS_Renderer *render, t_actionValue *value, t_actionTable *actionTable);
CS_Scene        *initMenu(SDL_Renderer *render);
int             MenuUseEvent(t_action action, std::shared_ptr<CS_Element> button);

t_pos           loopGame(CS_Renderer *render, t_actionValue *value, t_actionTable *actionTable);
CS_Camera       *initCamera();
CS_Enemies      *initEnemies(SDL_Renderer *render);
CS_GameScene    *initGameScene(SDL_Renderer *render);
CS_Character    *initMC(SDL_Renderer *render);
CS_Parallax     *initParallax(SDL_Renderer *render);
t_pos           gameUseEvent(t_action action, CS_Renderer *render, t_actionValue *value, t_actionTable *actionTable, CS_Timer *timer);
void            useAction(t_action *table, CS_Character *MC);
void            parallaxManagement(CS_Parallax *parallax, CS_Camera *camera);
CS_Assets       *initAssets(SDL_Renderer *render);

CS_Projectiles  *initProjectiles(SDL_Renderer *render);

void            resolveAllAction(CS_GameScene *scene);
CS_Enemy        *initEnfant1(SDL_Renderer *render);
CS_EnemyBank    *initBankEnemies(SDL_Renderer *render);



#endif