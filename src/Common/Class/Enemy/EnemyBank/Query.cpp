# include "enemy.h"

CS_Enemy    *CS_EnemyBank::QueryEnemy(t_enemy name)
{
    unsigned long i;

    i = 0;
    while (i < enemy.size())
    {
        if (name == enemy[i]->QueryName())
            return (enemy[i]);
        i++;
    }
    std::cout << "something went wrong in QueryEnemy" << std::endl;
    return (NULL);
}
