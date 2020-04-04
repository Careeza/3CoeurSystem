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


t_buttonValue   closeGame();
t_buttonValue   returnTrue();
t_buttonValue   returnFalse();
t_buttonValue   goToHome();
t_buttonValue   goToLevelSelect();
t_buttonValue   goToMenu();
t_buttonValue   goToGame();

t_buttonValue   useButton0();
t_buttonValue   useButton1();
t_buttonValue   useButton2();
t_buttonValue   useButton3();
t_buttonValue   useButton4();
t_buttonValue   useButton5();
t_buttonValue   useButton6();
t_buttonValue   useButton7();
t_buttonValue   useButton8();
t_buttonValue   useButton9();

t_buttonValue   useButton10();
t_buttonValue   useButton11();
t_buttonValue   useButton12();
t_buttonValue   useButton13();
t_buttonValue   useButton14();
t_buttonValue   useButton15();
t_buttonValue   useButton16();
t_buttonValue   useButton17();
t_buttonValue   useButton18();
t_buttonValue   useButton19();

bool            loopDialogue(CS_Renderer *render, t_actionValue *value, t_actionTable *actionTable);
CS_Scene        *initDialogue(SDL_Renderer *render);
int             dialogueUseEvent(t_action action, std::shared_ptr<CS_Element> button);

#endif