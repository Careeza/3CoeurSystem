#ifndef GAME_H

# define GAME_H

# include <SDL2/SDL.h>
# include <SDL2/SDL_timer.h>
# include <SDL2/SDL_image.h>
# include <SDL2/SDL_ttf.h>

# include <fstream>
# include <iostream>
# include <string>
# include <vector>

# define    CS_MOTION 1
# define    CS_MOUSE_DOWN 2
# define    CS_MOUSE_UP 3

class   CS_Scene;

void	        init(int flags);
SDL_Window      *create_window(int flags, const std::string name = "canvas", int x = 0, int y = 0, int w = 0, int h = 0);
SDL_Renderer    *init_renderer(SDL_Window    *window);
CS_Scene        *init_scene(SDL_Renderer *render);
CS_Scene        *init_scene1(SDL_Renderer *render);
CS_Scene        *init_scene2(SDL_Renderer *render);
CS_Scene        *init_scene3(SDL_Renderer *render);
CS_Scene        *init_scene4(SDL_Renderer *render);
CS_Scene        *init_scene5(SDL_Renderer *render);

void    Function1(void);
void    Function2(void);
void    Function3(void);
void    Function4(void);
void    Function5(void);

class   CS_Scene;

typedef struct      s_settings
{
    int         window_width;
    int         window_height;
    float       resolution;
    bool        closeRequested;
    bool        pauseRequested;
    int         fps;
    bool        debug;

    CS_Scene    *scene1Game;
    CS_Scene    *home;
    CS_Scene    *menu;
    CS_Scene    *controlGame;
    CS_Scene    *controlHome;
    CS_Scene    *current;
    CS_Scene    *currentGame;
}                   CS_settings;

extern CS_settings  gameSettings;

class   CS_KeyControl
{
    public:
        CS_KeyControl();
        int     loadEvenement();
        int     queryEventType();
        int     getMouseActions(int& x, int& y);

    private:
        SDL_Event       event;
        Uint32          type;

        bool            keyPress;

        int             buttons;
        int             mouse_x;
        int             mouse_y;

        int             static_x;
        int             static_y;
};

#endif