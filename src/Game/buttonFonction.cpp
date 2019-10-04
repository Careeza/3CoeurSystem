#include "game.h"

using namespace std;

void    closeGame(void)
{
    gameSettings.closeRequested = true;
}

void    menuToHotkeys(void)
{
    gameSettings.current = gameSettings.controlGame;
}

void    goToMenu(void)
{
    gameSettings.current = gameSettings.menu;
}

void    goToHome(void)
{
    gameSettings.current = gameSettings.home;
}

void    homeToHotkeys(void)
{
    gameSettings.current = gameSettings.controlHome;
}

void    homeToLevelSelect(void)
{
    gameSettings.current = gameSettings.saveMenu;
}

void    homeToVideo(void)
{
    gameSettings.current = gameSettings.homeVideo;
}

void    menuTovideo(void)
{
    gameSettings.current = gameSettings.menuVideo;
}

void    homeToSound(void)
{
    gameSettings.current = gameSettings.homeSound;
}

void    menuToSound(void)
{
    gameSettings.current = gameSettings.menuSound;
}