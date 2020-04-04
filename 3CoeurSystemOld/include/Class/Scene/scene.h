#ifndef SCENE_H

# define SCENE_H

# include "Element/element.h"
# include "../../Tools/tools.h"

class   CS_Scene
{
    public:
        CS_Scene();
        ~CS_Scene();

        void                                        loadRenderer(SDL_Renderer *renderSource);

        void                                        addElementToScene(std::shared_ptr<CS_Element> element);
        void                                        createElementToScene(std::string name, float w, float h, float x, float y, int z);
        void                                        createButtonToScene(std::string name, float w, float h, float x, float y, int z, t_buttonValue (*f)());
        void                                        createElementToSceneFromPng(std::string name, std::string route, float w, float h, float x, float y, int z);
        void                                        createButtonToSceneFromPng(std::string name, std::string route, float w, float h, float x, float y, int z, t_buttonValue (*f)());
        void                                        deleteElementFromeScene(int index);
        
        void                                        setSceneColor(int r, int g, int b, int a);
        void                                        setTextColor(int r, int g, int b, int a);
        void                                        setBorderColor(int r, int g, int b, int a);
        void                                        setBrightnessColor(int r, int g, int b, int a);
        void                                        setDisp(bool disp, int index);
        void                                        setButton(bool button, int index);

        std::vector<std::shared_ptr<CS_Element>>    QuerySceneElements();
        std::shared_ptr<CS_Element>                 QuerySingleElement(int index);
        int                                         QuerySceneLen();
        std::string                                 QueryName(int index);
        int                                         QueryIndexByName(std::string name);

        void                                        writeTexte(int index, std::string comment);
        void                                        writeTexteScaleW(int index, std::string comment);
        void                                        addBorder(int index);

        void                                        setDispScene(bool dispSource);
        bool                                        QueryDispScene();

    private:
        std::vector<std::shared_ptr<CS_Element>>    sceneContain;
        int                                         lastElement;
        int                                         sceneLen;

        CS_Color                                    colorSource;
        CS_Color                                    colorText;
        CS_Color                                    colorBordure;
        CS_Color                                    colorBrightness;

        bool                                        dispScene;

    protected:
        SDL_Renderer                                *render;
};

#endif