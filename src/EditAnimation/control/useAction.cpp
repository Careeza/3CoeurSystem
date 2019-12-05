#include "editAnimation.h"

void    filtreActionTable(t_actionTable *table, t_actionTable *filtre)
{
    resetActionTable(filtre);
//    std::cout << "reset" << std::endl;
    if (table->right & !table->left)
        filtre->right = true;
    if (table->left & !table->right)
        filtre->left = true;
    filtre->dodge = table->dodge;
    filtre->jump = table->jump;
}


void    useAction2(t_actionTable *table, CS_EditAnimationSetting& settings)
{
    (void)table;
    (void)settings;
}