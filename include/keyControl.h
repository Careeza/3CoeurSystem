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

void    escapeKeyManagement(CS_KeyControl event);
int     bouttonManagement(CS_KeyControl& control);
void    actionKeyManagement(CS_KeyControl event, t_actionValue *value);
void    filtreActionTable(t_actionTable *table, t_actionTable *filtre);
void    fillActionTable(t_actionTable *table, t_actionValue *value, int key, int info);
void    resetActionTable(t_actionTable *table);
void    fillActionValue(t_actionValue *value);

#endif