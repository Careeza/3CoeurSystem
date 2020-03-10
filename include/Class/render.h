#ifndef RENDER_H

# define RENDER_H

# include <SDL2/SDL.h>
# include <SDL2/SDL_timer.h>
# include <SDL2/SDL_image.h>
# include <SDL2/SDL_ttf.h>
# include <SDL2/SDL_mixer.h>
# include "gameScene.h"

# include <fstream>
# include <iostream>
# include <string>
# include <vector>

# include "tools.h"

class   CS_Renderer
{
    
    public:
        CS_Renderer();
        ~CS_Renderer();

        void    loadRenderer(SDL_Renderer *renderSource);

        void    renderScene(CS_Scene *scene);
        void    renderElement(std::shared_ptr<CS_Element> element);
        void    renderText(CS_Police *text);
        void    renderBorder(CS_Border *border);
        void    renderBrightness(CS_Brightness *brightness);

        void    renderGameScene(CS_GameScene *gameScene);
        void    renderParallax(CS_Parallax *parallax);
        void    renderAssets(CS_Assets *assets, int cameraX, int cameraY);
        void    renderMC(CS_Character *MC, int cameraX, int cameraY);
        void    renderEnemy(CS_Enemies *enemies, int cameraX, int cameraY);
        void    renderProjectiles(CS_Projectiles *projectiles, int cameraX, int cameraY);

        void    renderTexture(SDL_Texture *texture, SDL_Rect *frame, SDL_Rect *size);
        void    renderScreenSave();

        void    dispScreen();
        void    saveScreen();

        SDL_Texture     *QueryScreen();
        SDL_Texture     *QueryScreenSave();
        SDL_Renderer    *QueryRender();

    private:
        SDL_Renderer    *render;
        SDL_Texture     *screen;
        SDL_Texture     *screenSave;
};

#endif