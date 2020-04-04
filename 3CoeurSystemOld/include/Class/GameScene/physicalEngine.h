#ifndef PHYSICALENGINE

# define PHYSICALENGINE

# include <SDL2/SDL.h>
# include <SDL2/SDL_timer.h>
# include <SDL2/SDL_image.h>
# include <SDL2/SDL_ttf.h>
# include <SDL2/SDL_mixer.h>

# include <fstream>
# include <iostream>
# include <string>
# include <vector>
# include <memory>

class   CS_GameScene;

class   CS_HitBox
{
    public:
        CS_HitBox();
        ~CS_HitBox();
        bool                Collision(int wTest, int hTest, int xTest, int yTest);

        void                setW(float wSource);
        void                setH(float hSource);
        void                setX(float xSource);
        void                setY(float ySource);

        void                setWPixel(int wSource);
        void                setHPixel(int hSource);
        void                setXPixel(int xSource);
        void                setYPixel(int ySource);

        void                moveX(int xSource);
        void                moveY(int ySource);
        void                extandW(int wSource);
        void                extandH(int hSource);
        void                extandSize(int wSource, int hSource);

        void                setHitBoxSize(float wSource, float hSource);
        void                setHitBoxPos(float xSource, float ySource);
        void                setHitBox(float wSource, float hSource, float xSource, float ySource);

        void                setHitBoxSizePixel(int wSource, int hSource);
        void                setHitBoxPosPixel(int xSource, int ySource);
        void                setHitBoxPixel(int wSource, int hSource, int xSource, int ySource);

        int                 QueryW();
        int                 QueryH();
        int                 QueryX();
        int                 QueryY();

        void                QuerySize(int& wDest, int& hDest);
        void                QueryPos(int& xDest, int &yDest);
        void                QuerySizePos(int& wDest, int& hDest, int& xDest, int& yDest);

    private:
        int                 w;
        int                 h;
        int                 x;
        int                 y;
};


#endif
