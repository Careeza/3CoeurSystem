#include "game.h"

int     gameOverUseButton(t_keyManagement mouse, std::shared_ptr<CS_Element> button)
{
    t_buttonValue buttonValue;

    buttonValue = CS_KeyControl::useButton(mouse, button);
    if (buttonValue == exitButton)
        return (-1);
    else if (buttonValue == button1)
        return (1);
    else
        return (0);
}

int gameOverUseEvent(t_action action, std::shared_ptr<CS_Element> button, int level)
{
    int buttonInfo;

    buttonInfo = gameOverUseButton(action.att, button);
    
    if (buttonInfo == 0)
        return (0);
    else if (buttonInfo == -1)
        return (-1);
    else
        return ((level * -1) - 1);
}

static CS_Scene    *initGameOver(SDL_Renderer *render)
{
    CS_Scene        *scene;

    scene = new(CS_Scene);
    scene->loadRenderer(render);
    
    scene->setSceneColor(0x00, 0x00, 0x00, 255);
    scene->setTextColor(0xFF, 0xFF, 0xFF, 0xFF);

    scene->createElementToScene("filtre", 100, 100, 0, 0, 0);

    scene->createElementToScene("GameOver", 20, 10, 60, 30, 0);
    scene->writeTexteScaleW(-1, "Game Over");

    scene->createButtonToScene("Retry", 30, 50, 40, 10, 0, &closeGame);
    scene->writeTexteScaleW(-1, "Retry !");

    scene->createButtonToScene("Exit", 30, 50, 40, 10, 0, &useButton1);
    scene->writeTexteScaleW(-1, "Exit");

    return (scene);
}

int     gameOver(CS_Renderer *render, t_actionValue *value, t_actionTable *actionTable, int level)
{
    CS_Scene                        *scene;
    std::shared_ptr<CS_Element>     button;

    CS_Timer        timer;
    CS_Timer        time;
    CS_KeyControl   event;
    t_action        action;
    int             closeRequested = 0;


    scene = initGameOver(render->QueryRender());

    time.start();
    while (closeRequested == 0)
    {
        timer.start();

        homeGetEvenement(scene, button, value, actionTable);
        homeEventProcessing(actionTable, &action);
        closeRequested = gameOverUseEvent(action, button, level);

        render->renderScene(scene);
        render->dispScreen();

        SDL_Delay(fmax(0, (1000 / (float)60 - timer.get_ticks())));
    }

    delete scene;
    return (closeRequested);
}