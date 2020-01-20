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

# define YBigTree01 0.0
# define YBigTree02 0.0
# define YBigTree03 0.0
# define YBushTree01 87.1
# define YBushTree02 86
# define YBushTree03 84.7
# define YBushTree04 91.8
# define YGrass01 90.7
# define YGrass02 91.9
# define YGrass03 87.8
# define YGrass04 89.8
# define YGrass05 88
# define YGround01 96
# define YMediumTree01 28.2
# define YMediumTree02 35.6
# define YMediumTree03 43.1
# define YSmallTree01 59.3
# define YSmallTree02 53.8
# define YSmallTree03 48
# define YSmallTree04 53.4

bool            loopDialogue(CS_Renderer *render, t_actionValue *value, t_actionTable *actionTable);
CS_Scene        *initDialogue(SDL_Renderer *render);
int             dialogueUseEvent(t_action action, std::shared_ptr<CS_Element> button);

void            loopEditAnimation(CS_Renderer *render, t_actionValue *value, t_actionTable *actionTable);
CS_Camera       *initCamera();
CS_GameScene    *initGameScene(SDL_Renderer *render);
CS_Parallax     *initParallax(SDL_Renderer *render);
CS_Assets       *initAssets(SDL_Renderer *render);
void            parallaxManagement(CS_Parallax *parallax, CS_Camera *camera);

void            changeButton(CS_Asset* &assetSelected, CS_Assets *assets, bool& haveAnAsset);

void    loadBigTree01(CS_Asset* &assetSelected, CS_Assets *assets, bool& haveAnAsset);
void    loadBigTree02(CS_Asset* &assetSelected, CS_Assets *assets, bool& haveAnAsset);
void    loadBigTree03(CS_Asset* &assetSelected, CS_Assets *assets, bool& haveAnAsset);
void    loadBushTree01(CS_Asset* &assetSelected, CS_Assets *assets, bool& haveAnAsset);
void    loadBushTree02(CS_Asset* &assetSelected, CS_Assets *assets, bool& haveAnAsset);
void    loadBushTree03(CS_Asset* &assetSelected, CS_Assets *assets, bool& haveAnAsset);
void    loadBushTree04(CS_Asset* &assetSelected, CS_Assets *assets, bool& haveAnAsset);
void    loadGrass01(CS_Asset* &assetSelected, CS_Assets *assets, bool& haveAnAsset);
void    loadGrass02(CS_Asset* &assetSelected, CS_Assets *assets, bool& haveAnAsset);
void    loadGrass03(CS_Asset* &assetSelected, CS_Assets *assets, bool& haveAnAsset);
void    loadGrass04(CS_Asset* &assetSelected, CS_Assets *assets, bool& haveAnAsset);
void    loadGrass05(CS_Asset* &assetSelected, CS_Assets *assets, bool& haveAnAsset);
void    loadGround01(CS_Asset* &assetSelected, CS_Assets *assets, bool& haveAnAsset);
void    loadMediumTree01(CS_Asset* &assetSelected, CS_Assets *assets, bool& haveAnAsset);
void    loadMediumTree02(CS_Asset* &assetSelected, CS_Assets *assets, bool& haveAnAsset);
void    loadMediumTree03(CS_Asset* &assetSelected, CS_Assets *assets, bool& haveAnAsset);
void    loadSmallTree01(CS_Asset* &assetSelected, CS_Assets *assets, bool& haveAnAsset);
void    loadSmallTree02(CS_Asset* &assetSelected, CS_Assets *assets, bool& haveAnAsset);
void    loadSmallTree03(CS_Asset* &assetSelected, CS_Assets *assets, bool& haveAnAsset);
void    loadSmallTree04(CS_Asset* &assetSelected, CS_Assets *assets, bool& haveAnAsset);

#endif


