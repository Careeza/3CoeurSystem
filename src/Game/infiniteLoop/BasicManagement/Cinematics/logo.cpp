#include "game.h"

CS_Scene    *initLogoCinematics(SDL_Renderer *render)
{
    CS_Scene        *scene;

    scene = new(CS_Scene);
    scene->loadRenderer(render);
    
    scene->createElementToSceneFromPng("Background", "resources/source/Cinematics/logoJeu.png", 100, 100, 0, 0, 0);

    return (scene);
}

void    logoCinematics(CS_Renderer *render)
{
    CS_Scene                    *scene;
    CS_Timer                    timer;
    CS_Timer                    time;
    CS_KeyControl               event;

    scene = initLogoCinematics(render->QueryRender());

    time.start();
    while (time.get_ticks() < 2000)
    {
        timer.start();

        while (event.loadEvenement(scene));

        render->renderScene(scene);
        render->dispScreen();

        SDL_Delay(fmax(0, (1000 / (float)60 - timer.get_ticks())));
    }
}