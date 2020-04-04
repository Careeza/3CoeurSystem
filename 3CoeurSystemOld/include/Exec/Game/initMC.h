#ifndef INITMC_H

# define INITMC_H

# include <SDL2/SDL.h>
# include <SDL2/SDL_timer.h>
# include <SDL2/SDL_image.h>
# include <SDL2/SDL_ttf.h>
# include <SDL2/SDL_mixer.h>

# include <fstream>
# include <iostream>
# include <string>
# include <vector>
# include <stdarg.h>
# include <math.h>
# include <time.h>

# include "tools.h"
# include "common.h"

# define AC_STATIC 0
# define AC_WALK 1
# define AC_JUMP 2
# define AC_ATTACK 3

# define NOPRIO 0
# define LOWPRIO 1
# define MEDIUMPRIO 2
# define HIGHPRIO 3

CS_Animation        *staticMoine(SDL_Renderer *render);
CS_Animation        *walkMoine(SDL_Renderer *render);
CS_Animation        *jumpMoine(SDL_Renderer *render);
CS_Animation        *fallMoine(SDL_Renderer *render);
CS_Animation        *attackMoine(SDL_Renderer *render);
CS_Animation        *dashMoine(SDL_Renderer *render);

CS_Animation        *staticKitsune(SDL_Renderer *render);
CS_Animation        *walkKitsune(SDL_Renderer *render);
CS_Animation        *jumpKitsune(SDL_Renderer *render);
CS_Animation        *fallKitsune(SDL_Renderer *render);
CS_Animation        *attackKitsune(SDL_Renderer *render);

CS_PersonalPhysic   *initPhysic();
CS_Character        *initMC(SDL_Renderer *render);


#endif