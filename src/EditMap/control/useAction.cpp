#include "editMap.h"

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


void    useAction2(t_actionTable *table, CS_EditMapSetting& settings)
{
    CS_Camera    *camera;

    camera = settings.QueryGameScene()->QueryCamera();
    if (table->right)
    {
        camera->moveCamera2(25, 0, settings.QueryGameScene());
    }
    else if (table->left)
    {
        camera->moveCamera2(-25, 0, settings.QueryGameScene());
    }
    else if (table->dodge)
    {
        if (settings.QuerySelected())
            deleteActualAsset(&settings);
    }
    else if (table->jump)
    {
        settings.QueryGameScene()->QueryAssets()->printAsset();
    }
    else
    {

    }
}