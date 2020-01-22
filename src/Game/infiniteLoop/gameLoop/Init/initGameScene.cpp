# include "game.h"

CS_GameScene    *initGameScene(SDL_Renderer *render)
{
    CS_GameScene        *scene;

    scene = new(CS_GameScene);

    scene->loadRenderer(render);

    std::cout << "1" << std::endl;
    scene->setBorneMap(-100000, 100000);
    std::cout << "2" << std::endl;
    scene->loadMC(initMC(render));
    std::cout << "3" << std::endl;
    scene->loadEnemies(initEnemies(render));
    std::cout << "4" << std::endl;
    scene->loadParallax(initParallax(render));
    std::cout << "5" << std::endl;
    scene->loadCamera(initCamera());
    std::cout << "6" << std::endl;
    scene->loadAssets(initAssets(render));
    std::cout << "7" << std::endl;
    scene->loadProjectiles(initProjectiles(render));
    std::cout << "8" << std::endl;
    scene->loadOnScreen(new(CS_OnScreen));
    std::cout << "9" << std::endl;


    return (scene);
}