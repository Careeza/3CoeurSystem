#include "game.h"

t_pos   closeRequested(CS_Renderer *render, t_actionValue *value, t_actionTable *actionTable)
{
    if (callDialogueBox(render, value, actionTable))
        return (close);
    else
        return (home);
}

t_pos    boucleHome(CS_Renderer *render, t_actionValue *value, t_actionTable *actionTable) // => need le render et les settings et la texture screen
{
    CS_Scene                    *scene;
    t_action                    action;
    std::shared_ptr<CS_Element> button;
    CS_Timer                    timer;
    CS_Timer                    time;
    t_pos                       pos;

    CS_KeyControl::resetAction(&action);
    scene = initHome(render->QueryRender()); //initHomeKey
    pos = home;

    time.start();

    while (pos == home)
    {
        timer.start();

        homeGetEvenement(scene, button, value, actionTable);
        homeEventProcessing(actionTable, &action);
        pos = homeUseEvent(action, button);

        render->renderScene(scene);
        render->dispScreen();

        if (pos == close)
            pos = closeRequested(render, value, actionTable);
            

        SDL_Delay(fmax(0, (1000 / (float)60 - timer.get_ticks())));
    }

    delete scene;
    return (pos);
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