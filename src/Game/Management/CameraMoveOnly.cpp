#include "game.h"

void    CameraMove(CS_Settings& settings, t_action *action, int& xCamera, int& yCamera)
{
    CS_Camera       *camera;

    useAction2(action, settings);
    camera = settings.QueryGameScene()->QueryCamera();
    camera->QueryCameraPosition(xCamera, yCamera);
}
