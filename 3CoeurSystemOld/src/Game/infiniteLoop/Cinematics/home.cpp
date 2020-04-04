#include "game.h"

static CS_Scene    *initHomeCinematics(SDL_Renderer *render)
{
    CS_Scene        *scene;

    scene = new(CS_Scene);
    scene->loadRenderer(render);
    
    scene->setSceneColor(0x00, 0x00, 0x00, 255);
    scene->createElementToScene("filtre", 100, 100, 0, 0, 0);

    scene->createElementToSceneFromPng("Background", "resources/source/HomeJeu.png", 100, 100, 0, 0, 0);
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

void    homeCinematics(CS_Renderer *render, t_actionValue *value, t_actionTable *actionTable)
{
    CS_Scene        *scene;
    CS_Scene        *fondu;

    CS_Timer        timer;
    CS_Timer        time;
    CS_KeyControl   event;
    int             alpha = 255;
    t_action        action;
    bool            closeRequested = false;


    scene = initHomeCinematics(render->QueryRender());

    time.start();
    while (alpha > 0 && !closeRequested)
    {
        timer.start();

        fondu = initFondu(render->QueryRender(), alpha);
        alpha -= 5;

        basicGetEvenement(scene, value, actionTable);
        homeEventProcessing(actionTable, &action);
        closeRequested = basicUseEvent(action);

        render->renderScene(scene);
        render->renderScene(fondu);
        render->dispScreen();

        SDL_Delay(fmax(0, (1000 / (float)60 - timer.get_ticks())));
    }


    delete fondu;
    delete scene;
}
