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

typedef enum	e_pos {
	homeHome,
	homeHotkeys,
	homeVideo,
	homeSound,
	menuMenu,
	menuHotkeys,
    menuVideo,
    menuSound,
    game,
    levelSelect
}				t_pos;

class   CS_Scene;

void	        init(int flags);
SDL_Window      *create_window(int flags, const std::string name = "canvas", int x = 0, int y = 0, int w = 0, int h = 0);
SDL_Renderer    *init_renderer(SDL_Window    *window);
CS_Scene        *init_home(SDL_Renderer *render);
CS_Scene        *init_menu(SDL_Renderer *render);
CS_Scene        *init_menuHotkeys(SDL_Renderer *render);
CS_Scene        *init_homeHotkeys(SDL_Renderer *render);
CS_Scene        *init_game(SDL_Renderer *render);
CS_Scene        *init_play(SDL_Renderer *render);
CS_Scene        *init_homeVideo(SDL_Renderer *render);
CS_Scene        *init_menuVideo(SDL_Renderer *render);
CS_Scene        *init_homeSound(SDL_Renderer *render);
CS_Scene        *init_menuSound(SDL_Renderer *render);

void    closeGame(void);
void    menuToHotkeys(void);
void    goToMenu(void);
void    goToHome(void);
void    homeToHotkeys(void);
void    homeToLevelSelect(void);
void    homeToVideo(void);
void    menuTovideo(void);
void    homeToSound(void);
void    menuToSound(void);


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

    t_pos       pos;

    CS_Scene    *scene1Game;
    CS_Scene    *home;
    CS_Scene    *saveMenu;
    CS_Scene    *menu;
    CS_Scene    *controlGame;
    CS_Scene    *controlHome;
    CS_Scene    *current;
    CS_Scene    *currentGame;
    CS_Scene    *homeVideo;
    CS_Scene    *menuVideo;
    CS_Scene    *homeSound;
    CS_Scene    *menuSound;
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