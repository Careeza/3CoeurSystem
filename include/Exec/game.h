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
void            homeEventProcessing(t_actionTable *actionTable, t_action *action);
bool            callDialogueBox(CS_Renderer *render, t_actionValue *value, t_actionTable *actionTable);

t_buttonValue   closeGame();
t_buttonValue   returnTrue();
t_buttonValue   returnFalse();

t_pos           boucleHome(CS_Renderer *render, t_actionValue *value, t_actionTable *actionTable);
CS_Scene        *initHome(SDL_Renderer *render);
t_pos           homeUseEvent(t_action action, std::shared_ptr<CS_Element> button);

bool            boucleDialogue(CS_Renderer *render, t_actionValue *value, t_actionTable *actionTable);
CS_Scene        *initDialogue(SDL_Renderer *render);
int             boucleUseEvent(t_action action, std::shared_ptr<CS_Element> button);

#endif