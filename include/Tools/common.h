#ifndef COMMON_H

# define COMMON_H

# include "scene.h"
# include "keyControl.h"
# include "timer.h"
# include "render.h"

class   CS_Settings
{
    public:
        CS_Settings();
        ~CS_Settings();

        void            getWindowSize(int w, int h);

        void            getCloseRequest(bool close);
        void            getPauseRequest(bool pause);
        void            getFps(int fpsSource);

        void            initScene(CS_Scene *sceneSource);
        void            initGameScene(CS_GameScene *gameSceneSource);

        void            getScene(CS_Scene *sceneSource);
        void            getGameScene(SDL_Renderer *render);
        void            getPosition(t_pos position);

        int             QueryWindowsWidth();
        int             QueryWindowsHeight();
        float           QueryWindowsResolution();

        bool            QueryCloseRequest();
        bool            QueryPauseRequest();
        int             QueryFps();

        t_pos           QueryPosition();
        CS_Scene        *QueryScene();
        CS_GameScene    *QueryGameScene();

    private:
        int             windowWidth;
        int             windowHeight;
        float           resolution;

        bool            closeRequested;
        bool            pauseRequested;
        int             fps;

        t_pos           pos;

        CS_GameScene    *gameScene;
        CS_Scene        *Scene;
};

void    closeGame(void *settings, SDL_Renderer *render);
int     bouttonManagement(CS_KeyControl& control, CS_Settings& settings, SDL_Renderer *render);

#endif