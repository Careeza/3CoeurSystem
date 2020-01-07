#ifndef EDITANIMATION_H

# define EDITANIMATION_H

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


class   CS_EditAnimationSetting : public CS_Settings
{
    public:
        CS_EditAnimationSetting();
        ~CS_EditAnimationSetting();

        void    play();
        void    pause();
        bool    isPaused();

        void    increaseFps(int fps);
        void    decreaseFps(int fps);

        void    setFpsAnimation(int fpsSource);
        int     QueryFpsAnimation();

    private:
        bool    paused;
        int     fpsAnimation;
};

void            initSettings(CS_EditAnimationSetting &settings, SDL_Window *window, SDL_Renderer *render);
CS_GameScene    *init_home(SDL_Renderer *render);
CS_Camera       *initCamera();

void    nextFrame(void* settings, SDL_Renderer *render);
void    previousFrame(void* settings, SDL_Renderer *render);
void    pause(void* settings, SDL_Renderer *render);
void    play(void* settings, SDL_Renderer *render);
void    left(void* settings, SDL_Renderer *render);
void    right(void* settings, SDL_Renderer *render);
void    incraseFps(void* settings, SDL_Renderer *render);
void    decreaseFps(void* settings, SDL_Renderer *render);
void    incraseFps10(void* settings, SDL_Renderer *render);
void    decreaseFps10(void* settings, SDL_Renderer *render);
void    incraseFps100(void* settings, SDL_Renderer *render);
void    decreaseFps100(void* settings, SDL_Renderer *render);
void    changeText(void* settings, SDL_Renderer *render);


void    escapeAction(CS_Settings& settings, SDL_Renderer *render);
void    escapeKeyManagement(CS_KeyControl event, CS_Settings& settings, SDL_Renderer *render);
void    fillActionTable(t_actionTable *table, t_actionValue *value, int key, int info);
void    fillActionValue(t_actionValue *value);
void    resetActionTable(t_actionTable *table);
void    fillAction(t_actionTable *table, t_action *action);
void    useAction2(t_action *table, CS_EditAnimationSetting& settings);
void    actionKeyManagement(CS_KeyControl event, t_actionValue *value, t_actionTable *actionTable, t_action *action);
void    mouseAction(CS_KeyControl event, CS_EditAnimationSetting &settings, int& xMouse, int &yMouse);
int     bouttonManagement2(CS_KeyControl& control, CS_EditAnimationSetting& settings, SDL_Renderer *render);

#endif