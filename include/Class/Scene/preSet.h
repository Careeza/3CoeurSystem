#ifndef PRESET_H

# define PRESET_H

# include <SDL2/SDL.h>
# include <SDL2/SDL_timer.h>
# include <SDL2/SDL_image.h>
# include <SDL2/SDL_ttf.h>

# include <fstream>
# include <iostream>
# include <string>
# include <vector>
# include <memory>


# if SDL_BYTEORDER == SDL_BIG_ENDIAN
    #define rmask 0xff000000
    #define gmask 0x00ff0000
    #define bmask 0x0000ff00
    #define amask 0x000000ff
# else
    #define rmask 0x000000ff
    #define gmask 0x0000ff00
    #define bmask 0x00ff0000
    #define amask 0xff000000
# endif

# define ALIGN_LEFT 1
# define ALIGN_RIGHT 2
# define ALIGN_CENTER 3
# define ZOOM 8

# define    NOZOOM 0
# define    ZOOMIN 1
# define    ZOOMOUT 2

class   CS_Color
{
    public:
        CS_Color();
        CS_Color(int red, int green, int blue, int alpha);

        void    setRed(int redSource);
        void    setGreen(int greenSource);
        void    setBlue(int blueSource);
        void    setAlpha(int alphaSource);
        void    setColor(int red = 0, int green = 0, int blue = 0, int alpha = 0);

        int QueryRed();
        int QueryGreen();
        int QueryBlue();
        int QueryAlpha();

    private:
        int red;
        int green;
        int blue;
        int alpha;
};

#endif