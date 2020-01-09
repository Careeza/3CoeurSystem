# include "game.h"

bool    callDialogueBox(CS_Renderer *render, t_actionValue *value, t_actionTable *actionTable)
{
    render->saveScreen();
    return (loopDialogue(render, value, actionTable));
}