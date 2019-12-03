#ifndef EDITMAP_H

# define EDITMAP_H

# include <SDL2/SDL.h>
# include <SDL2/SDL_timer.h>
# include <SDL2/SDL_image.h>
# include <SDL2/SDL_ttf.h>

# include <fstream>
# include <iostream>
# include <string>
# include <vector>
# include <stdarg.h>
# include <math.h>

# include "tools.h"
# include "common.h"


class   CS_EditMapSetting : public CS_Settings
{
    public:
        CS_EditMapSetting();
        ~CS_EditMapSetting();

        void        setAssetSelected(CS_Asset *assetSource);
        void        setSelected(bool selectedSource);

        bool        QuerySelected();
        CS_Asset    *QueryAsset();

    private:
        bool        selected;
        CS_Asset    *assetSelected;        
};

# define YBigTree01 0.0
# define XBigTree01 34.4

# define YBigTree02 0.0
# define XBigTree02 40.625

# define YBigTree03 0.0
# define XBigTree03 37.1

# define YBushTree01 87.1
# define XBushTree01 40.34

# define YBushTree02 86
# define XBushTree02 39.79

# define YBushTree03 84.5
# define XBushTree03 40

# define YBushTree04 91.7
# define XBushTree04 39.5

# define YGrass01 90.5
# define XGrass01 30.5

# define YGrass02 91.8
# define XGrass02 38.8

# define YGrass03 87.7
# define XGrass03 40.3

# define YGrass04 89.8
# define XGrass04 42.5

# define YGrass05 88.2
# define XGrass05 44.5

# define YGround01 96
# define XGround01 0

# define YMediumTree01 28.2
# define XMediumTree01 44.8

# define YMediumTree02 35.5
# define XMediumTree02 44.8

# define YMediumTree03 43.1
# define XMediumTree03 54

# define YSmallTree01 59.3
# define XSmallTree01 62.7

# define YSmallTree02 53.8
# define XSmallTree02 63

# define YSmallTree03 48
# define XSmallTree03 61.3

# define YSmallTree04 53.3
# define XSmallTree04 63.2

int     bouttonManagement2(CS_KeyControl& control, CS_EditMapSetting& settings, SDL_Renderer *render);

void    loadBigTree01(void* settings, SDL_Renderer *render);
void    loadBigTree02(void* settings, SDL_Renderer *render);
void    loadBigTree03(void* settings, SDL_Renderer *render);
void    loadBushTree01(void* settings, SDL_Renderer *render);
void    loadBushTree02(void* settings, SDL_Renderer *render);
void    loadBushTree03(void* settings, SDL_Renderer *render);
void    loadBushTree04(void* settings, SDL_Renderer *render);
void    loadGrass01(void* settings, SDL_Renderer *render);
void    loadGrass02(void* settings, SDL_Renderer *render);
void    loadGrass03(void* settings, SDL_Renderer *render);
void    loadGrass04(void* settings, SDL_Renderer *render);
void    loadGrass05(void* settings, SDL_Renderer *render);
void    loadGround01(void* settings, SDL_Renderer *render);
void    loadMediumTree01(void* settings, SDL_Renderer *render);
void    loadMediumTree02(void* settings, SDL_Renderer *render);
void    loadMediumTree03(void* settings, SDL_Renderer *render);
void    loadSmallTree01(void* settings, SDL_Renderer *render);
void    loadSmallTree02(void* settings, SDL_Renderer *render);
void    loadSmallTree03(void* settings, SDL_Renderer *render);
void    loadSmallTree04(void* settings, SDL_Renderer *render);


#endif