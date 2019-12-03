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

int     bouttonManagement2(CS_KeyControl& control, CS_EditMapSetting& settings, SDL_Renderer *render);


#endif