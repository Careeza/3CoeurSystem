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

    (void)render;
    set = (CS_Settings*)settings;
    set->getPosition(game);
//    set->getScene(render);
}

void    dispDialogueBox(void* settings, SDL_Renderer *render)
{
    CS_Settings *set;
    CS_Scene    *scene;

    (void)render;
    set = (CS_Settings*)settings;
    scene = set->QueryScene();
    scene->setDisp(true, scene->QueryIndexByName("filtre"));
    scene->setDisp(true, scene->QueryIndexByName("dialogue"));
    scene->setDisp(true, scene->QueryIndexByName("Question"));
    scene->setDisp(true, scene->QueryIndexByName("YES"));
    scene->setDisp(true, scene->QueryIndexByName("NO"));

    scene->setButton(false, scene->QueryIndexByName("Play"));
    scene->setButton(false, scene->QueryIndexByName("Hotkeys"));
    scene->setButton(false, scene->QueryIndexByName("Video"));
    scene->setButton(false, scene->QueryIndexByName("Sound"));
    scene->setButton(false, scene->QueryIndexByName("Exit game"));
    set->getPosition(homeBox);
}

void    hideDialogueBox(void* settings, SDL_Renderer *render)
{
    CS_Settings *set;
    CS_Scene    *scene;

    (void)render;
    set = (CS_Settings*)settings;
    scene = set->QueryScene();
    scene->setDisp(false, scene->QueryIndexByName("filtre"));
    scene->setDisp(false, scene->QueryIndexByName("dialogue"));
    scene->setDisp(false, scene->QueryIndexByName("Question"));
    scene->setDisp(false, scene->QueryIndexByName("YES"));
    scene->setDisp(false, scene->QueryIndexByName("NO"));

    scene->setButton(true, scene->QueryIndexByName("Play"));
    scene->setButton(true, scene->QueryIndexByName("Hotkeys"));
    scene->setButton(true, scene->QueryIndexByName("Video"));
    scene->setButton(true, scene->QueryIndexByName("Sound"));
    scene->setButton(true, scene->QueryIndexByName("Exit game"));
    set->getPosition(homeHome);
}