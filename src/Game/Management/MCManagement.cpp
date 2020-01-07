#include "game.h"

void    MCManagement(CS_Settings& settings, t_action *action, int& xCamera, int& yCamera, float deltaTS, int deltaTMS)
{
    CS_GameScene    *map;
    CS_Character    *MC;
    CS_Camera       *camera;
    int             BorderMinX;
    int             BorderMaxX;

    map = settings.QueryGameScene();
    useAction(action, settings, deltaTMS);
    map->QueryBorne(BorderMinX, BorderMaxX);

    MC = map->QueryMC();
    MC->getFrame();
    MC->moveCharacter(deltaTS, BorderMinX, BorderMaxX);

    camera = map->QueryCamera();
    camera->moveCamera3(MC, deltaTS);
    camera->QueryCameraPosition(xCamera, yCamera);
}