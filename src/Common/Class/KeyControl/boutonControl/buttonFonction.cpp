#include "gameScene.h"

using namespace std;

void    closeGame(void)
{
    gameSettings.closeRequested = true;
}

void    menuToHotkeys(void)
{
    gameSettings.current = gameSettings.controlGame;
    gameSettings.pos = menuHotkeys;
}

void    goToMenu(void)
{
    gameSettings.current = gameSettings.menu;
    gameSettings.pos = menuMenu;
}

void    goToHome(void)
{
    gameSettings.current = gameSettings.home;
    gameSettings.pos = homeHome;
}

void    homeToHotkeys(void)
{
    gameSettings.current = gameSettings.controlHome;
    gameSettings.pos = homeHotkeys;
}

void    homeToLevelSelect(void)
{
    gameSettings.current = gameSettings.saveMenu;
    gameSettings.pos = homeLevelSelect;
}

void    homeToVideo(void)
{
    gameSettings.current = gameSettings.homeVideo;
    gameSettings.pos = homeVideo;
}

void    menuTovideo(void)
{
    gameSettings.current = gameSettings.menuVideo;
    gameSettings.pos = menuVideo;
}

void    homeToSound(void)
{
    gameSettings.current = gameSettings.homeSound;
    gameSettings.pos = homeSound;
}

void    menuToSound(void)
{
    gameSettings.current = gameSettings.menuSound;
    gameSettings.pos = menuSound;
}

void    levelSelectToGame(void)
{
    gameSettings.current = gameSettings.menu;
    gameSettings.pos = game;
}

void    dispDialogueBox(void)
{
    CS_Scene    *scene;

    scene = gameSettings.current;
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
    gameSettings.pos = homeBox;
}

void    hideDialogueBox(void)
{
    CS_Scene    *scene;

    scene = gameSettings.current;

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
    gameSettings.pos = homeHome;
}