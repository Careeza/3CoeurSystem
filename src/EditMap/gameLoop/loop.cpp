#include "editMap.h"


void    editAnimationGetEvenement(CS_KeyControl& event, CS_Scene *scene, std::shared_ptr<CS_Element>& button, t_actionValue *value, t_actionTable *actionTable)
{
    while (event.loadEvenement(scene))
    {
        button = event.getButtonScene();
        event.fillActionTable(actionTable, value);
        event.updateMousePos();
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


void    getAsset(CS_KeyControl event, CS_Camera *camera, CS_Asset* &assetSelected, CS_Assets *assets, bool& haveAnAsset)
{
    int         xMouse;
    int         yMouse;

    event.getMousePos(xMouse, yMouse);
    xMouse *= 2; //MAC ONLY
    yMouse *= 2;

    int         xCamera;
    int         yCamera;

    camera->QueryCameraPosition(xCamera, yCamera);

    xMouse += xCamera;
    yMouse += yCamera;

    int         x;
    int         y;
    int         w;
    int         h;

    int         i;
    CS_Asset    *asset;

    i = assets->QueryNbAssets() - 1;
    while (i >= 0)
    {
        asset = assets->QueryAsset(i);
        asset->QuerySize(w, h, x, y);
        if (xMouse >= x && xMouse <= x + w && yMouse >= y && yMouse <= y + h)
            break ;
        i--;
    }
    if (i >= 0)
    {
        assetSelected = assets->QueryAsset(i);
        haveAnAsset = true;
    }
    else
    {
        std::cout << "noob" << std::endl;
    }
}

void    placeAsset(CS_KeyControl event, CS_Camera *camera, CS_Asset* &assetSelected, CS_Assets *assets, bool& haveAnAsset)
{
    if (haveAnAsset)
        assetSelected = assets->loadAssetPixel(assetSelected->QueryName(), 1, 0, 0);
    else
    {
        getAsset(event, camera, assetSelected, assets, haveAnAsset);
    }
}

void    editAnimationUseAction(CS_KeyControl event, t_action *table, CS_Camera *camera, CS_Asset* &assetSelected, CS_Assets *assets, bool& haveAnAsset)
{
    if (table->left & KeyHoldPress)
        camera->moveCamera2(-10, 0, NULL);
    if (table->right & KeyHoldPress)
        camera->moveCamera2(10, 0, NULL);
    if (table->dodge & KeyPress)
        changeButton(assetSelected, assets, haveAnAsset);
    if (table->att & KeyRelease)
        placeAsset(event, camera, assetSelected, assets, haveAnAsset);
    if (table->jump & KeyPress)
        assets->printAsset();
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
    return (buttonValue);
}

void    changeParams(t_buttonValue buttonValue, CS_Asset* &assetSelected, CS_Assets *assets, bool& haveAnAsset)
{
    if (buttonValue == button0)
        loadBigTree01(assetSelected, assets, haveAnAsset);
    else if (buttonValue == button1)
        loadBigTree02(assetSelected, assets, haveAnAsset);
    else if (buttonValue == button2)
        loadBigTree03(assetSelected, assets, haveAnAsset);
    else if (buttonValue == button3)
        loadBushTree01(assetSelected, assets, haveAnAsset);
    else if (buttonValue == button4)
        loadBushTree02(assetSelected, assets, haveAnAsset);
    else if (buttonValue == button5)
        loadBushTree03(assetSelected, assets, haveAnAsset);
    else if (buttonValue == button6)
        loadBushTree04(assetSelected, assets, haveAnAsset);
    else if (buttonValue == button7)
        loadGrass01(assetSelected, assets, haveAnAsset);
    else if (buttonValue == button8)
        loadGrass02(assetSelected, assets, haveAnAsset);
    else if (buttonValue == button9)
        loadGrass03(assetSelected, assets, haveAnAsset);
    else if (buttonValue == button10)
        loadGrass04(assetSelected, assets, haveAnAsset);
    else if (buttonValue == button11)
        loadGrass05(assetSelected, assets, haveAnAsset);
    else if (buttonValue == button12)
        loadGround01(assetSelected, assets, haveAnAsset);
    else if (buttonValue == button13)
        loadMediumTree01(assetSelected, assets, haveAnAsset);
    else if (buttonValue == button14)
        loadMediumTree02(assetSelected, assets, haveAnAsset);
    else if (buttonValue == button15)
        loadMediumTree03(assetSelected, assets, haveAnAsset);
    else if (buttonValue == button16)
        loadSmallTree01(assetSelected, assets, haveAnAsset);
    else if (buttonValue == button17)
        loadSmallTree02(assetSelected, assets, haveAnAsset);
    else if (buttonValue == button18)
        loadSmallTree03(assetSelected, assets, haveAnAsset);
    else if (buttonValue == button19)
        loadSmallTree04(assetSelected, assets, haveAnAsset);
}

bool    escapeManagement(CS_Renderer *render, t_action action, t_actionValue *value, t_actionTable *actionTable)
{
    if (action.escape == KeyPress)
    {
        render->saveScreen();
        if (loopDialogue(render, value, actionTable))
            return (true);
        else
            return (false);
    }
    return (false);
}

void    moveAssetSelected(bool haveAnAsset, CS_Asset *assetSelected, CS_Camera *camera, CS_KeyControl& event)
{
    int     xMouse;
    int     yMouse;
    int     xCamera;
    int     yCamera;
    int     w;
    int     h;
    int     x;
    int     y;

    if (haveAnAsset)
    {
        event.getMousePos(xMouse, yMouse);
        xMouse *= 2; //MAC ONLY
        yMouse *= 2;
        camera->QueryCameraPosition(xCamera, yCamera);
        assetSelected->QuerySize(w, h, x, y);
        assetSelected->moveAsset((xMouse + xCamera) - w / 2, (yMouse + yCamera) - h / 2, true);
    }
}

void    loopEditAnimation(CS_Renderer *render, t_actionValue *value, t_actionTable *actionTable)
{
    CS_KeyControl               event;
    CS_GameScene                *scene;
    CS_Camera                   *camera;
    CS_Parallax                 *parallax;
    t_buttonValue               buttonValue;
    t_action                    action;
    CS_Timer                    timer;
    std::shared_ptr<CS_Element> button;

    CS_KeyControl::resetAction(&action);
    scene = initGameScene(render->QueryRender());
    camera = scene->QueryCamera();
    parallax = scene->QueryParallax();


    CS_Asset    *assetSelected;
    CS_Assets   *assets;
    bool        haveAnAsset;

    assets = scene->QueryAssets();
    assetSelected = NULL;
    haveAnAsset = false;

    int             deltaTMS;
    bool            closeRequested = false;

    while (!closeRequested)
    {
        deltaTMS = timer.get_ticks();
 
        timer.start();

        editAnimationGetEvenement(event, scene, button, value, actionTable);
        editAnimationEventProcessing(actionTable, &action);

        closeRequested = escapeManagement(render, action, value, actionTable);
        buttonValue = editAnimationUseButton(action.att, button, render, value, actionTable);
        if (buttonValue == exitButton)
            closeRequested = true;
        if (buttonValue == noButton)
            editAnimationUseAction(event, &action, scene->QueryCamera(), assetSelected, assets, haveAnAsset);
        changeParams(buttonValue, assetSelected, assets, haveAnAsset);
        moveAssetSelected(haveAnAsset, assetSelected, camera, event);
        
        parallaxManagement(parallax, camera);
        render->renderGameScene(scene);
        render->renderScene(scene);
        render->dispScreen();

        SDL_Delay(fmax(0, (1000 / (float)60 - timer.get_ticks())));
    }

    delete scene;
}