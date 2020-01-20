#include "editAnimation.h"

void    editAnimationUseAction(t_action *table, CS_Character *MC)
{
    if (table->att & KeyPress)
        MC->loadAnimation(ATTACK);
    if (table->dodge & KeyPress)
    {
        MC->swapMC();
        MC->loadAnimation(STATIC);
    }
    if (table->right & KeyPress || table->left & KeyPress)
        MC->loadAnimation(WALK);
    if (table->left & KeyPress)
        MC->setRight(false);
    if (table->right & KeyPress)
        MC->setRight(true);
}

t_buttonValue   editAnimationUseButton(t_keyManagement mouse, std::shared_ptr<CS_Element> button, CS_Renderer *render, t_actionValue *value, t_actionTable *actionTable)
{
    t_buttonValue buttonValue;

    buttonValue = CS_KeyControl::useButton(mouse, button);
    if (buttonValue == exitButton)
    {
        if (loopDialogue(render, value, actionTable))
            return (exitButton);
        else
            return (backButton);
    }
    if (buttonValue == noAction)
        return (noAction);
    return (buttonValue);
}

CS_HitBox    *getHitBox(CS_GameScene *scene)
{
    return (scene->QueryMC()->QueryPhysic()->QueryRawHitbox());
}

void    printHitBox(CS_Animation *animation, bool right)
{
    int index;
    int indexMax;
    CS_HitBox *hitBox;

    int w;
    int h;

    animation->restartAnimation();
    index = 0;
    indexMax = animation->QueryMaxIndex();
    while (index < indexMax)
    {
        hitBox = animation->QueryHitbox(right);

        animation->QuerySize(w, h);

        std::cout << "setHitBox(" << index;
        std::cout << ", " << hitBox->QueryW() / (float)w;
        std::cout << ", " << hitBox->QueryH() / (float)h;
        std::cout << ", " << hitBox->QueryX() / (float)w;
        std::cout << ", " << hitBox->QueryY() / (float)h;
        std::cout << ");" << std::endl;

        animation->nextFrame();
        index++;
    }
}

void    changeParams(CS_GameScene *scene, t_buttonValue buttonValue, CS_Renderer *render, bool& playAnimation)
{
    CS_Character    *MC;
    CS_Animation    *animation;
    int             animationTime;
    static int      pas = 1;

    MC = scene->QueryMC();
    animation = MC->QueryAnimation();
    animationTime = animation->QueryAnimationTime();

    if (buttonValue == button0)
        animation->nextFrame();
    else if (buttonValue == button1)
        animation->previousFrame();
    else if (buttonValue == button2)
        playAnimation = true;
    else if (buttonValue == button3)
        playAnimation = false;
    else if (buttonValue == button4)
    {
        animationTime += 1;
        animation->setAnimationTime(animationTime);
    }
    else if (buttonValue == button5)
    {
        animationTime -= 1;
        animation->setAnimationTime(animationTime);
    }
    else if (buttonValue == button6)
    {
        animationTime += 10;
        animation->setAnimationTime(animationTime);
    }
    else if (buttonValue == button7)
    {
        animationTime -= 10;
        animation->setAnimationTime(animationTime);
    }
    else if (buttonValue == button8)
        getHitBox(scene)->extandW(pas);
    else if (buttonValue == button9)
        getHitBox(scene)->extandW(-pas);
    else if (buttonValue == button10)
        getHitBox(scene)->extandH(pas);
    else if (buttonValue == button11)
        getHitBox(scene)->extandH(-pas);
    else if (buttonValue == button12)
        getHitBox(scene)->moveX(pas);
    else if (buttonValue == button13)
        getHitBox(scene)->moveX(-pas);
    else if (buttonValue == button14)
        getHitBox(scene)->moveY(pas);
    else if (buttonValue == button15)
        getHitBox(scene)->moveY(-pas);
    else if (buttonValue == button16)
        pas++;
    else if (buttonValue == button17)
        pas--;
    else if (buttonValue == button18)
        printHitBox(animation, MC->VerifyRight());

    int index;
    int frameIndex;
    int nbFrame;
    std::shared_ptr<CS_Element> element;
 
    index = scene->QueryIndexByName("fps");
    element = scene->QuerySingleElement(index);
    element->changeText(std::to_string(animationTime), render->QueryRender());

    index = scene->QueryIndexByName("pas");
    element = scene->QuerySingleElement(index);
    element->changeText(std::to_string(pas), render->QueryRender());

    index = scene->QueryIndexByName("index");
    element = scene->QuerySingleElement(index);
    frameIndex = animation->QueryIndex() + 1;
    nbFrame = animation->QueryMaxIndex();
    element->changeText(std::to_string(frameIndex) + "/" + std::to_string(nbFrame), render->QueryRender());

    CS_HitBox   *hitBox;

    hitBox = getHitBox(scene);
    index = scene->QueryIndexByName("w");
    element = scene->QuerySingleElement(index);
    element->changeText("w=" + std::to_string(hitBox->QueryW()), render->QueryRender());

    index = scene->QueryIndexByName("h");
    element = scene->QuerySingleElement(index);
    element->changeText("h=" + std::to_string(hitBox->QueryH()), render->QueryRender());

    index = scene->QueryIndexByName("x");
    element = scene->QuerySingleElement(index);
    element->changeText("x=" + std::to_string(hitBox->QueryX()), render->QueryRender());

    index = scene->QueryIndexByName("y");
    element = scene->QuerySingleElement(index);
    element->changeText("y=" + std::to_string(hitBox->QueryY()), render->QueryRender());
}

bool   editAnimationUseEvent(CS_GameScene *scene, t_action action, std::shared_ptr<CS_Element> button, CS_Renderer *render, t_actionValue *value, t_actionTable *actionTable, bool& playAnimation)
{
    if (action.escape == KeyPress)
    {
        render->saveScreen();
        if (loopDialogue(render, value, actionTable))
            return (true);
        else
            return (false);
    }
    t_buttonValue buttonValue;
    
    buttonValue = editAnimationUseButton(action.att, button, render, value, actionTable);
    if (buttonValue == exitButton)
        return (true);
    if (buttonValue == noButton)
        editAnimationUseAction(&action, scene->QueryMC());
    changeParams(scene, buttonValue, render, playAnimation);
    return (false);
}

void    editAnimationGetEvenement(CS_Scene *scene, std::shared_ptr<CS_Element>& button, t_actionValue *value, t_actionTable *actionTable)
{
    CS_KeyControl   event;


    while (event.loadEvenement(scene))
    {
        button = event.getButtonScene();
        event.fillActionTable(actionTable, value);
    }
}

void    editAnimationEventProcessing(t_actionTable *actionTable, t_action *action)
{
    CS_KeyControl::transformActionTable(actionTable);
    CS_KeyControl::resetAction(action);
    

    if ((actionTable->right & KeyHoldPress) && (actionTable->left & KeyReleaseNoPress))
        action->right = actionTable->right;
    if ((actionTable->left & KeyHoldPress) && (actionTable->right & KeyReleaseNoPress))
        action->left = actionTable->left;

    if ((actionTable->up & KeyHoldPress) && (actionTable->down & KeyReleaseNoPress))
        action->up = actionTable->up;
    if ((actionTable->down & KeyHoldPress) && (actionTable->up & KeyReleaseNoPress))
        action->down = actionTable->down;

    action->escape = actionTable->escape;
    action->att = actionTable->att;
    action->dodge = actionTable->dodge;
    action->jump = actionTable->jump;
}

void   loopEditAnimation(CS_Renderer *render, t_actionValue *value, t_actionTable *actionTable)
{
    CS_GameScene                *scene;
    t_action                    action;
    CS_Timer                    timer;
    std::shared_ptr<CS_Element> button;

    CS_KeyControl::resetAction(&action);
    scene = initGameScene(render->QueryRender());

    int             deltaTMS;
    CS_Character    *MC;
    CS_Animation    *animation;
    bool            playAnimation = true;

    MC = scene->QueryMC();
    animation = MC->QueryAnimation();

    bool            closeRequested = false;

    int index = scene->QueryIndexByName("fps");
    std::shared_ptr<CS_Element> element = scene->QuerySingleElement(index);
    element->changeText(std::to_string(animation->QueryAnimationTime()), render->QueryRender());

    MC->getFrame();
    while (!closeRequested)
    {
        deltaTMS = timer.get_ticks();
 
        timer.start();

        editAnimationGetEvenement(scene, button, value, actionTable);
        editAnimationEventProcessing(actionTable, &action);

        if (playAnimation)
            MC->updateFrame(deltaTMS);
        closeRequested = editAnimationUseEvent(scene, action, button, render, value, actionTable, playAnimation);
        MC->getFrame();

        render->renderScene(scene);
        render->renderGameScene(scene);
        render->dispScreen();

        SDL_Delay(fmax(0, (1000 / (float)60 - timer.get_ticks())));
    }

    delete scene;
}