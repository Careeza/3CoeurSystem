#include "game.h"

bool    loopMenu(CS_Renderer *render, t_actionValue *value, t_actionTable *actionTable) // => need le render et les settings et la texture screen
{
    CS_Scene                    *scene;
    t_action                    action;
    std::shared_ptr<CS_Element> button;
    CS_Timer                    timer;
    int                         answer = -1;


    CS_KeyControl::resetAction(&action);
    scene = initMenu(render->QueryRender()); //initHomeKey

    while (answer == -1)
    {
        timer.start();

        homeGetEvenement(scene, button, value, actionTable);
        homeEventProcessing(actionTable, &action);
        answer = MenuUseEvent(action, button);

        render->renderScreenSave();
        render->renderScene(scene);
        render->dispScreen();

        SDL_Delay(fmax(0, (1000 / (float)60 - timer.get_ticks())));

        if (answer == 0)
        {
            if (loopDialogue(render, value, actionTable))
                answer = 0;
            else
                answer = -1;
        }
    }

    delete scene;

    if (answer == 0)
        return (true);
    else
        return (false);
}


    // boucle infi
    /*
        gestion des evenements () => Une gestion basique uniqument des boutons !
            => refactor des fonctions des boutons ?
            => Renvoie une valeur dans un tableau ?
                => Ex bouton 1 leads to input 'z'

        utulisation si nécessaire de l'action
            => Z is pressed so do this
                => Z need a verification (dialogue box)
                    => set dialogue box aff a true + disable all the other evenemnt

        affichage en fonction => Refactor du render plus précis
        => Afficher une scènes (idée afficher groupe de scène)
            => affAllScene(int nbr scene, ...);

            => is home aff ? 
                => aff home
            => is homeKey aff ?
                => aff key
    */