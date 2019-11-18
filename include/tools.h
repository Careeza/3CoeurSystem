#ifndef TOOLS_H

# define TOOLS_H

# include <SDL2/SDL.h>
# include <SDL2/SDL_timer.h>
# include <SDL2/SDL_image.h>
# include <SDL2/SDL_ttf.h>

# include <fstream>
# include <iostream>
# include <string>
# include <vector>

void        setSize(SDL_Rect *size, float w, float h, float x, float y);

typedef enum	e_debug {
    LEVEL0,
    LEVEL1,
    LEVEL2,
    LEVEL3
}				t_debug;


class   CS_Tools
{
    public:
        CS_Tools();
        ~CS_Tools();

        void    setSize(SDL_Rect *size, float w, float h, float x, float y);
        void    setSize(SDL_Rect *size, SDL_Rect *container, float w, float h, float x, float y);
        void    setSize(SDL_Rect *size, int w, int h, int x, int y);

        int     transformWidth(float w);
        int     transformWidth(SDL_Rect *container, float w);
        
        int     transformHeight(float h);
        int     transformHeight(SDL_Rect *container, float h);

        int     QueryWindowWidth();
        int     QueryWindowHeight();
        int     QueryWindowResolution();

        void    verbose(t_debug debugSource, string element, ...);

        void    getWindowSize(int w, int h);
        void    debugMode(t_debug debugSource);

    private:
        int     windowWidth;
        int     windowHeight;
        int     resolution;
        t_debug debug;
}

#endif