#include "game.h"

using namespace std;

void    menuToHotkeys(void* settings, SDL_Renderer *render)
{
    CS_Settings *set;

    set = (CS_Settings*)settings;
    set->getPosition(menuHotkeys);
    set->getScene(init_menuHotkeys(render));
}

void    goToMenu(void* settings, SDL_Renderer *render)
{
    CS_Settings *set;

    set = (CS_Settings*)settings;
    set->getPosition(menuMenu);
    set->getScene(init_menu(render));
}

void    goToHome(void* settings, SDL_Renderer *render)
{
    CS_Settings *set;

    set = (CS_Settings*)settings;
    set->getPosition(homeHome);
    set->getScene(init_home(render));
}

void    homeToHotkeys(void* settings, SDL_Renderer *render)
{
    CS_Settings *set;

    set = (CS_Settings*)settings;
    set->getPosition(homeHotkeys);
    set->getScene(init_homeHotkeys(render));
}

void    homeToLevelSelect(void* settings, SDL_Renderer *render)
{
    CS_Settings *set;

    set = (CS_Settings*)settings;
    set->getPosition(homeLevelSelect);
    set->getScene(init_play(render));
}

void    homeToVideo(void* settings, SDL_Renderer *render)
{
    CS_Settings *set;

    set = (CS_Settings*)settings;
    set->getPosition(homeVideo);
    set->getScene(init_homeVideo(render));
}

void    menuTovideo(void* settings, SDL_Renderer *render)
{
    CS_Settings *set;

    set = (CS_Settings*)settings;
    set->getPosition(menuVideo);
    set->getScene(init_menuVideo(render));
}

void    homeToSound(void* settings, SDL_Renderer *render)
{
    CS_Settings *set;

    set = (CS_Settings*)settings;
    set->getPosition(homeSound);
    set->getScene(init_homeSound(render));
}

void    menuToSound(void* settings, SDL_Renderer *render)
{
    CS_Settings *set;

    set = (CS_Settings*)settings;
    set->getPosition(menuSound);
    set->getScene(init_menuSound(render));
}

void    levelSelectToGame(void* settings, SDL_Renderer *render)
{
    CS_Settings *set;

    set = (CS_Settings*)settings;
    set->getPosition(game);
//    set->getScene(render);
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