#ifndef TOOLS_H

# define TOOLS_H

# include <SDL2/SDL.h>
# include <SDL2/SDL_timer.h>
# include <SDL2/SDL_image.h>
# include <SDL2/SDL_ttf.h>
# include <SDL2/SDL_mixer.h>

# include <fstream>
# include <iostream>
# include <string>
# include <vector>
# include <memory>

typedef enum	e_debug {
    LEVEL0,
    LEVEL1,
    LEVEL2,
    LEVEL3
}				t_debug;

void	        init(int flags);
SDL_Window      *create_window(int flags, const std::string name = "canvas", int x = 0, int y = 0, int w = 0, int h = 0);
SDL_Renderer    *init_renderer(SDL_Window *window);

class   CS_Tools
{
    public:
        CS_Tools();
        ~CS_Tools();

        void    setSize(SDL_Rect *size, float w, float h, float x, float y);
        void    setSize(SDL_Rect *size, SDL_Rect *container, float w, float h, float x, float y);
        void    setSize(SDL_Rect *size, int w, int h, int x, int y);

        float   transformWidth(float w);
        float   transformWidth(SDL_Rect *container, float w);
        
        float   transformHeight(float h);
        float   transformHeight(SDL_Rect *container, float h);

        float   transformX(float x);
        float   transformX(SDL_Rect *container, float x);

        float   transformY(float y);
        float   transformY(SDL_Rect *container, float y);

        int     QueryWindowWidth();
        int     QueryWindowHeight();
        float   QueryWindowResolution();

        void    verbose(t_debug debugSource, std::string element, ...);

        void    getWindowSize(int w, int h);
        void    debugMode(t_debug debugSource);

        int     modulo(int a, int b);

        void    copyRect(SDL_Rect *rectSource, SDL_Rect *rectDest);

    private:
        int     windowWidth;
        int     windowHeight;
        float   resolution;
        t_debug debug;
};

extern CS_Tools *Tools;


#endif