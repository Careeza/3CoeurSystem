#ifndef EDITANIMATION_H

# define EDITANIMATION_H

# include <SDL2/SDL.h>
# include <SDL2/SDL_timer.h>
# include <SDL2/SDL_image.h>
# include <SDL2/SDL_ttf.h>
# include <SDL2/SDL_mixer.h>

# include <fstream>
# include <iostream>
# include <string>
# include <vector>
# include <stdarg.h>
# include <math.h>

# include "tools.h"
# include "common.h"


bool            loopDialogue(CS_Renderer *render, t_actionValue *value, t_actionTable *actionTable);
CS_Scene        *initDialogue(SDL_Renderer *render);
int             dialogueUseEvent(t_action action, std::shared_ptr<CS_Element> button);

void            loopEditAnimation(CS_Renderer *render, t_actionValue *value, t_actionTable *actionTable);
CS_Camera       *initCamera();
CS_Enemies      *initEnemies(SDL_Renderer *render);
CS_GameScene    *initGameScene(SDL_Renderer *render);
CS_Character    *initMC(SDL_Renderer *render);
CS_Parallax     *initParallax(SDL_Renderer *render);
CS_Assets       *initAssets(SDL_Renderer *render);
void            parallaxManagement(CS_Parallax *parallax, CS_Camera *camera);

#endif