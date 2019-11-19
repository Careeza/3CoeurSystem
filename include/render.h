#ifndef RENDER_H

# define RENDER_H

# include <SDL2/SDL.h>
# include <SDL2/SDL_timer.h>
# include <SDL2/SDL_image.h>
# include <SDL2/SDL_ttf.h>
# include "gameScene.h"

# include <fstream>
# include <iostream>
# include <string>
# include <vector>

# include "tools.h"

class   CS_Renderer
{
    private:
        CS_Scene        *CS_renderScene;
        SDL_Renderer    *CS_render;
    
    public:
        void    CS_loadRenderer(SDL_Renderer *render);
        void    CS_dispScene(CS_Scene *current, CS_GameScene *gameScene, t_pos pos);
};

#endif