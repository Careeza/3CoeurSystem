#include "game.h"

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
    gameSettings.pos = game;
}