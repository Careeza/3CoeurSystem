#ifndef KEYCONTROL_H

# define KEYCONTROL_H

# include "gameScene.h"

# define    NO_ACTION -1
# define    NO_BOUTON 0
# define    MOUSE_MOTION 1
# define    BOUTTON_PRESS 2
# define    BOUTON_RELEASE 3

#define CS_KEYUP 0
#define CS_KEYDOWN 1
#define CS_NOKEY 2


class   CS_KeyControl
{
    public:
        CS_KeyControl();
        int                                     loadEvenement();
//        int     getMouseActions(int& x, int& y);
        int                                     CS_getKeyboardActions(int& key);
        std::shared_ptr<CS_Element>             CS_getBoutton(int &boutonInfo);

    private:
        SDL_Event       event;
        Uint32          type;

        int             len;
        CS_Scene        *scene;

};

void            escapeKeyManagement(CS_KeyControl event);
int             bouttonManagement(CS_KeyControl& control);

#endif