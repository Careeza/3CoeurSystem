#include "game.h"

std::string     authorizedKey::keyName(int key)
{
    if (keyA.value == key)
        return (keyA.name);
    else if (keyB.value == key)
        return (keyB.name);
    else if (keyC.value == key)
        return (keyC.name);
    else if (keyD.value == key)
        return (keyD.name);
    else if (keyE.value == key)
        return (keyE.name);
    else if (keyF.value == key)
        return (keyF.name);
    else if (keyG.value == key)
        return (keyG.name);
    else if (keyH.value == key)
        return (keyH.name);
    else if (keyI.value == key)
        return (keyI.name);
    else if (keyJ.value == key)
        return (keyJ.name);
    else if (keyK.value == key)
        return (keyK.name);
    else if (keyL.value == key)
        return (keyL.name);
    else if (keyM.value == key)
        return (keyM.name);
    else if (keyN.value == key)
        return (keyN.name);
    else if (keyO.value == key)
        return (keyO.name);
    else if (keyP.value == key)
        return (keyP.name);
    else if (keyQ.value == key)
        return (keyQ.name);
    else if (keyR.value == key)
        return (keyR.name);
    else if (keyS.value == key)
        return (keyS.name);
    else if (keyT.value == key)
        return (keyT.name);
    else if (keyU.value == key)
        return (keyU.name);
    else if (keyV.value == key)
        return (keyV.name);
    else if (keyW.value == key)
        return (keyW.name);
    else if (keyX.value == key)
        return (keyX.name);
    else if (keyY.value == key)
        return (keyY.name);
    else if (keyZ.value == key)
        return (keyZ.name);
    else if (key0.value == key)
        return (key0.name);
    else if (key1.value == key)
        return (key1.name);
    else if (key2.value == key)
        return (key2.name);
    else if (key3.value == key)
        return (key3.name);
    else if (key4.value == key)
        return (key4.name);
    else if (key5.value == key)
        return (key5.name);
    else if (key6.value == key)
        return (key6.name);
    else if (key7.value == key)
        return (key7.name);
    else if (key8.value == key)
        return (key8.name);
    else if (key9.value == key)
        return (key9.name);
    else if (keyTab.value == key)
        return (keyTab.name);
    else if (keyMaj.value == key)
        return (keyMaj.name);
    else if (keyCtrl.value == key)
        return (keyCtrl.name);
    else if (keySpace.value == key)
        return (keySpace.name);
    else if (keyEnter.value == key)
        return (keyEnter.name);
    else if (keyUp.value == key)
        return (keyUp.name);
    else if (keyDown.value == key)
        return (keyDown.name);
    else if (keyRight.value == key)
        return (keyRight.name);
    else if (keyLeft.value == key)
        return (keyLeft.name);
    else
        return (NULL);
}


void    loadKey(t_key& key, std::string name, int value)
{
    key.name = name;
    key.value = value;
}

void            authorizedKey::loadAuthorizedKey()
{
    loadKey(keyA, "A", SDL_SCANCODE_A);
    loadKey(keyB, "B", SDL_SCANCODE_B);
    loadKey(keyC, "C", SDL_SCANCODE_C);
    loadKey(keyD, "D", SDL_SCANCODE_D);
    loadKey(keyE, "E", SDL_SCANCODE_E);
    loadKey(keyF, "F", SDL_SCANCODE_F);
    loadKey(keyG, "G", SDL_SCANCODE_G);
    loadKey(keyH, "H", SDL_SCANCODE_H);
    loadKey(keyI, "I", SDL_SCANCODE_I);
    loadKey(keyJ, "J", SDL_SCANCODE_J);
    loadKey(keyK, "K", SDL_SCANCODE_K);
    loadKey(keyL, "L", SDL_SCANCODE_L);
    loadKey(keyM, "M", SDL_SCANCODE_M);
    loadKey(keyN, "N", SDL_SCANCODE_N);
    loadKey(keyO, "O", SDL_SCANCODE_O);
    loadKey(keyP, "P", SDL_SCANCODE_P);
    loadKey(keyQ, "Q", SDL_SCANCODE_Q);
    loadKey(keyR, "R", SDL_SCANCODE_R);
    loadKey(keyS, "S", SDL_SCANCODE_S);
    loadKey(keyT, "T", SDL_SCANCODE_T);
    loadKey(keyU, "U", SDL_SCANCODE_U);
    loadKey(keyV, "V", SDL_SCANCODE_V);
    loadKey(keyW, "W", SDL_SCANCODE_W);
    loadKey(keyX, "X", SDL_SCANCODE_X);
    loadKey(keyY, "Y", SDL_SCANCODE_Y);
    loadKey(keyZ, "Z", SDL_SCANCODE_Z);
    
    loadKey(key0, "0", SDL_SCANCODE_0);
    loadKey(key1, "1", SDL_SCANCODE_1);
    loadKey(key2, "2", SDL_SCANCODE_2);
    loadKey(key3, "3", SDL_SCANCODE_3);
    loadKey(key4, "4", SDL_SCANCODE_4);
    loadKey(key5, "5", SDL_SCANCODE_5);
    loadKey(key6, "6", SDL_SCANCODE_6);
    loadKey(key7, "7", SDL_SCANCODE_7);
    loadKey(key8, "8", SDL_SCANCODE_8);
    loadKey(key9, "9", SDL_SCANCODE_9);

    loadKey(keyTab, "TAB", SDL_SCANCODE_TAB);
    loadKey(keyMaj, "MAJ", SDL_SCANCODE_LSHIFT);
    loadKey(keyCtrl, "CTRL", SDL_SCANCODE_LCTRL);
    loadKey(keySpace, "SPACE", SDL_SCANCODE_SPACE);
    loadKey(keyEnter, "ENTER", SDL_SCANCODE_RETURN);
    loadKey(keyUp, "UP", SDL_SCANCODE_UP);
    loadKey(keyDown, "DOWN", SDL_SCANCODE_DOWN);
    loadKey(keyRight, "RIGHT", SDL_SCANCODE_RIGHT);
    loadKey(keyLeft, "LEFT", SDL_SCANCODE_LEFT);
}
