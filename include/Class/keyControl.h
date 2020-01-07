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

typedef enum    e_keyManagement
{
    keyNone             = 0b0000,
    KeyPress            = 0b0001,
    KeyHold             = 0b0010,
    KeyHoldPress        = 0b0011,
    KeyRelease          = 0b0100,
    KeyNoPress          = 0b1000,
    KeyReleaseNoPress   = 0b1100,
    KeyPressRelease     = 0b0101
}               t_keyManagement;

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

typedef struct          s_actionTable
{
    t_keyManagement     up;
    t_keyManagement     down;
    t_keyManagement     right;
    t_keyManagement     left;
    t_keyManagement     jump;
    t_keyManagement     dodge;
    t_keyManagement     att;
    t_keyManagement     att_sp;
    t_keyManagement     use;
    t_keyManagement     spell_1;
    t_keyManagement     spell_2;

    t_keyManagement     upSave;
    t_keyManagement     downSave;
    t_keyManagement     rightSave;
    t_keyManagement     leftSave;
    t_keyManagement     jumpSave;
    t_keyManagement     dodgeSave;
    t_keyManagement     attSave;
    t_keyManagement     att_spSave;
    t_keyManagement     useSave;
    t_keyManagement     spell_1Save;
    t_keyManagement     spell_2Save;
}                       t_actionTable;

typedef struct  s_action
{
    t_keyManagement     up;
    t_keyManagement     down;
    t_keyManagement     right;
    t_keyManagement     left;
    t_keyManagement     jump;
    t_keyManagement     dodge;
    t_keyManagement     att;
    t_keyManagement     att_sp;
    t_keyManagement     use;
    t_keyManagement     spell_1;
    t_keyManagement     spell_2;
    t_keyManagement     noAction;

}               t_action;

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


void    fillActionValue(t_actionValue *value);
void    initActionTable(t_actionTable *table);
void    fillActionTable(t_actionTable *table, t_actionValue *value, int key, int info);
void    transformActionTable(t_actionTable *table);

#endif