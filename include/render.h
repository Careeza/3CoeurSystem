#ifndef RENDER_H

# define RENDER_H

# include <SDL2/SDL.h>
# include <SDL2/SDL_timer.h>
# include <SDL2/SDL_image.h>
# include <SDL2/SDL_ttf.h>
# include "scene.h"

# include <fstream>
# include <iostream>
# include <string>
# include <vector>

class   CS_Renderer
{
    private:
        CS_Scene        *CS_renderScene;
        SDL_Renderer    *CS_render;
    
    public:
        void    CS_loadRenderer(SDL_Renderer *render);
        void    CS_dispScene();
};

#endif