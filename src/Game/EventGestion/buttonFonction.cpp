#include "game.h"

using namespace std;

void    closeGame(void* settings)
{
    CS_Settings *set;

    set = (CS_Settings*)settings;
    set->getCloseRequest(true);
}

void    menuToHotkeys(void* settings)
{
    CS_Settings *set;

    set = (CS_Settings*)settings;
    set->getPosition(menuHotkeys);
}

void    goToMenu(void* settings)
{
    CS_Settings *set;

    set = (CS_Settings*)settings;
    set->getPosition(menuMenu);
}

void    goToHome(void* settings)
{
    CS_Settings *set;

    set = (CS_Settings*)settings;
    set->getPosition(homeHome);
}

void    homeToHotkeys(void* settings)
{
    CS_Settings *set;

    set = (CS_Settings*)settings;
    set->getPosition(homeHotkeys);
}

void    homeToLevelSelect(void* settings)
{
    CS_Settings *set;

    set = (CS_Settings*)settings;
    set->getPosition(homeLevelSelect);
}

void    homeToVideo(void* settings)
{
    CS_Settings *set;

    set = (CS_Settings*)settings;
    set->getPosition(homeVideo);
}

void    menuTovideo(void* settings)
{
    CS_Settings *set;

    set = (CS_Settings*)settings;
    set->getPosition(menuVideo);
}

void    homeToSound(void* settings)
{
    CS_Settings *set;

    set = (CS_Settings*)settings;
    set->getPosition(homeSound);
}

void    menuToSound(void* settings)
{
    CS_Settings *set;

    set = (CS_Settings*)settings;
    set->getPosition(menuSound);
}

void    levelSelectToGame(void* settings)
{
    CS_Settings *set;

    set = (CS_Settings*)settings;
    set->getPosition(game);
}

void    dispDialogueBox(void* settings)
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

void    hideDialogueBox(void* settings)
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