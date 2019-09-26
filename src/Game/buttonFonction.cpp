#include "game.h"

using namespace std;

void    Function1(void)
{
    gameSettings.closeRequested = true;
    cout << "1" << endl;
}

void    Function2(void)
{
    gameSettings.current = gameSettings.controlGame;
    cout << "2" << endl;
}

void    Function3(void)
{
    gameSettings.current = gameSettings.menu;
    cout << "3" << endl;
}

void    Function4(void)
{
    gameSettings.current = gameSettings.home;
    cout << "4" << endl;
}

void    Function5(void)
{
    gameSettings.current = gameSettings.controlHome;
    cout << "5" << endl;
}

void    Function6(void)
{
    gameSettings.current = gameSettings.saveMenu;
}