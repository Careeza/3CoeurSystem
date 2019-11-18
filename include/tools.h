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

class   Tools
{
    public:
        void    setSize(SDL_Rect *size, float w, float h, float x, float y);
        void    setSize(SDL_Rect *size, SDL_Rect *container, float w, float h, float x, float y);
        void    setSize(SDL_Rect *size, int w, int h, int x, int y);
        void    setSize(SDL_Rect *size, SDL_Rect *container, int w, int h, int x, int y);

        int     transformWidth(float w);
        int     transformWidth(SDL_Rect *container, float w);
        
        int     transformHeight(float h);
        int     transformHeight(SDL_Rect *container, float h);

        int     QueryWindowWidth();
        int     QueryWindowHeight();

        void    verbose();

        void    getWindowSize(int w, int h);

    private:
        int w;
        int h;
        int resolution;
        bool debug;
}

#endif