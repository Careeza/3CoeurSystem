#ifndef KEYCONTROL_H

# define KEYCONTROL_H

# include "gameScene.h"
# include "tools.h"

# define    NO_ACTION -1
# define    NO_BOUTON 0
# define    MOUSE_MOTION 1
# define    BOUTTON_PRESS 2
# define    BOUTON_RELEASE 3

#define     CS_KEYUP 0
#define     CS_KEYDOWN 1
#define     CS_NOKEY 2

# define    CS_MOTION 1
# define    CS_MOUSE_DOWN 2
# define    CS_MOUSE_UP 3

typedef struct  s_actionValue
{
    int        up;
    int        down;
    int        right;
    int        left;
    int        jump;
    int        dodge;
    int        att;
    int        att_sp;
    int        use;
    int        spell_1;
    int        spell_2;
}               t_actionValue;

typedef struct  s_actionTable
{
    bool        up;
    bool        down;
    bool        right;
    bool        left;
    bool        jump;
    bool        dodge;
    bool        att;
    bool        att_sp;
    bool        use;
    bool        spell_1;
    bool        spell_2;
}               t_actionTable;

class   CS_KeyControl
{
    public:
        CS_KeyControl();
        int                                     loadEvenement(CS_Scene *scene);
        int                                     getKeyboardActions(int& key);
        std::shared_ptr<CS_Element>             getBoutton(int &boutonInfo);
        int                                     getMouseActions(int &x, int &y);
//      int                                     getMouseActions(int& x, int& y);

    private:
        SDL_Event       event;
        Uint32          type;

        int             len;
        CS_Scene        *scene;
};

#endif