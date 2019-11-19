#include "game.h"

using namespace std;

void    closeGame(void* settings, SDL_Renderer *render)
{
    CS_Settings *set;

    set = (CS_Settings*)settings;
    set->getCloseRequest(true);
}

void    menuToHotkeys(void* settings, SDL_Renderer *render)
{
    CS_Settings *set;

    set = (CS_Settings*)settings;
    set->getPosition(menuHotkeys);
    set->getScene(render);
}

void    goToMenu(void* settings, SDL_Renderer *render)
{
    CS_Settings *set;

    set = (CS_Settings*)settings;
    set->getPosition(menuMenu);
    set->getScene(render);
}

void    goToHome(void* settings, SDL_Renderer *render)
{
    CS_Settings *set;

    set = (CS_Settings*)settings;
    set->getPosition(homeHome);
    set->getScene(render);
}

void    homeToHotkeys(void* settings, SDL_Renderer *render)
{
    CS_Settings *set;

    set = (CS_Settings*)settings;
    set->getPosition(homeHotkeys);
    set->getScene(render);
}

void    homeToLevelSelect(void* settings, SDL_Renderer *render)
{
    CS_Settings *set;

    set = (CS_Settings*)settings;
    set->getPosition(homeLevelSelect);
    set->getScene(render);
}

void    homeToVideo(void* settings, SDL_Renderer *render)
{
    CS_Settings *set;

    set = (CS_Settings*)settings;
    set->getPosition(homeVideo);
    set->getScene(render);
}

void    menuTovideo(void* settings, SDL_Renderer *render)
{
    CS_Settings *set;

    set = (CS_Settings*)settings;
    set->getPosition(menuVideo);
    set->getScene(render);
}

void    homeToSound(void* settings, SDL_Renderer *render)
{
    CS_Settings *set;

    set = (CS_Settings*)settings;
    set->getPosition(homeSound);
    set->getScene(render);
}

void    menuToSound(void* settings, SDL_Renderer *render)
{
    CS_Settings *set;

    set = (CS_Settings*)settings;
    set->getPosition(menuSound);
    set->getScene(render);
}

void    levelSelectToGame(void* settings, SDL_Renderer *render)
{
    CS_Settings *set;

    set = (CS_Settings*)settings;
    set->getPosition(game);
    set->getScene(render);
}

void    dispDialogueBox(void* settings, SDL_Renderer *render)
{
    CS_Settings *set;
    CS_Scene    *scene;

    set = (CS_Settings*)settings;
    scene = set->QueryScene();
    scene->CS_setDisp(true, scene->CS_queryIndexByName("filtre"));
    scene->CS_setDisp(true, scene->CS_queryIndexByName("dialogue"));
    scene->CS_setDisp(true, scene->CS_queryIndexByName("Question"));
    scene->CS_setDisp(true, scene->CS_queryIndexByName("YES"));
    scene->CS_setDisp(true, scene->CS_queryIndexByName("NO"));

    scene->CS_setButton(false, scene->CS_queryIndexByName("Play"));
    scene->CS_setButton(false, scene->CS_queryIndexByName("Hotkeys"));
    scene->CS_setButton(false, scene->CS_queryIndexByName("Video"));
    scene->CS_setButton(false, scene->CS_queryIndexByName("Sound"));
    scene->CS_setButton(false, scene->CS_queryIndexByName("Exit game"));
    set->getPosition(homeBox);
}

void    hideDialogueBox(void* settings, SDL_Renderer *render)
{
    CS_Settings *set;
    CS_Scene    *scene;

    set = (CS_Settings*)settings;
    scene = set->QueryScene();
    scene->CS_setDisp(false, scene->CS_queryIndexByName("filtre"));
    scene->CS_setDisp(false, scene->CS_queryIndexByName("dialogue"));
    scene->CS_setDisp(false, scene->CS_queryIndexByName("Question"));
    scene->CS_setDisp(false, scene->CS_queryIndexByName("YES"));
    scene->CS_setDisp(false, scene->CS_queryIndexByName("NO"));

    scene->CS_setButton(true, scene->CS_queryIndexByName("Play"));
    scene->CS_setButton(true, scene->CS_queryIndexByName("Hotkeys"));
    scene->CS_setButton(true, scene->CS_queryIndexByName("Video"));
    scene->CS_setButton(true, scene->CS_queryIndexByName("Sound"));
    scene->CS_setButton(true, scene->CS_queryIndexByName("Exit game"));
    set->getPosition(homeHome);
}