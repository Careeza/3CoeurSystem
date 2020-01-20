#include "game.h"

static CS_Scene    *initLogoCinematics(SDL_Renderer *render)
{
    CS_Scene        *scene;

    scene = new(CS_Scene);
    scene->loadRenderer(render);
    
    scene->createElementToSceneFromPng("Background", "resources/source/Cinematics/logoJeu.png", 100, 100, 0, 0, 0);

    return (scene);
}

static CS_Scene    *initFondu(SDL_Renderer *render, int alpha)
{
    CS_Scene        *scene;

    scene = new(CS_Scene);
    scene->loadRenderer(render);
    
    scene->setSceneColor(0x00, 0x00, 0x00, alpha);
    scene->createElementToScene("filtre", 100, 100, 0, 0, 40);

    return (scene);
}

static CS_Scene    *blackScreen(SDL_Renderer *render)
{
    CS_Scene        *scene;

    scene = new(CS_Scene);
    scene->loadRenderer(render);
    
    scene->setSceneColor(0x00, 0x00, 0x00, 255);
    scene->createElementToScene("filtre", 100, 100, 0, 0, 40);

    return (scene);
}

void    logoCinematics(CS_Renderer *render, t_actionValue *value, t_actionTable *actionTable)
{
    CS_Scene                    *scene;
    CS_Timer                    timer;
    CS_Timer                    time;
    CS_KeyControl               event;
    t_action                    action;
    bool                        closeRequested = false;

    CS_KeyControl::resetAction(&action);
    scene = initLogoCinematics(render->QueryRender());

    time.start();
    while (time.get_ticks() < 2000 && !closeRequested)
    {
        timer.start();

        basicGetEvenement(scene, value, actionTable);
        homeEventProcessing(actionTable, &action);
        closeRequested = basicUseEvent(action);

        render->renderScene(scene);
        render->dispScreen();

        SDL_Delay(fmax(0, (1000 / (float)60 - timer.get_ticks())));
    }


    CS_Scene        *fondu;

    time.start();

    int alpha = 0;
    while (alpha <= 255 && !closeRequested)
    {
        timer.start();

        fondu = initFondu(render->QueryRender(), alpha);
        alpha += 5;

        basicGetEvenement(scene, value, actionTable);
        homeEventProcessing(actionTable, &action);
        closeRequested = basicUseEvent(action);

        render->renderScene(scene);
        render->renderScene(fondu);
        render->dispScreen();

        delete fondu;

        SDL_Delay(fmax(0, (1000 / (float)60 - timer.get_ticks())));
    }

    delete scene;

    scene = blackScreen(render->QueryRender());
    time.start();
    while (time.get_ticks() < 500 && !closeRequested)
    {
        timer.start();

        basicGetEvenement(scene, value, actionTable);
        homeEventProcessing(actionTable, &action);
        closeRequested = basicUseEvent(action);

        render->renderScene(scene);
        render->dispScreen();

        SDL_Delay(fmax(0, (1000 / (float)60 - timer.get_ticks())));
    }
}