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

        int             QueryWindowsWidth();
        int             QueryWindowsHeight();
        float           QueryWindowsResolution();

        bool            QueryCloseRequest();
        bool            QueryPauseRequest();
        int             QueryFps();

        CS_Scene        *QueryScene();
        CS_GameScene    *QueryGameScene();

    private:
        int             windowWidth;
        int             windowHeight;
        float           resolution;

        bool            closeRequested;
        bool            pauseRequested;
        int             fps;

        CS_GameScene    *gameScene;
        CS_Scene        *Scene;
};

#endif