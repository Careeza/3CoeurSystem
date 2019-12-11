#ifndef PHYSICALENGINE

# define PHYSICALENGINE

# include <SDL2/SDL.h>
# include <SDL2/SDL_timer.h>
# include <SDL2/SDL_image.h>
# include <SDL2/SDL_ttf.h>

# include <fstream>
# include <iostream>
# include <string>
# include <vector>
# include <memory>


class   CS_Force
{
    public:
        CS_Force();
        ~CS_Force();

        void    setAccelerationX(float aXsource);
        void    setAccelerationY(float aYsource);
        void    setAccelerationXPixel(int aXsource);
        void    setAccelerationYPixel(int aYsource);

        void    usePhysic(int& vXDest, int& vYDest, float deltaT);

    private:
        int aX;
        int aY;
        
};

class   CS_WorldPhysics
{
    public:
        CS_WorldPhysics();
        ~CS_WorldPhysics();

        void        setGravityPixel(int aX, int aY);
        void        setWindPixel(int aX, int aY);
        void        setGravity(float aX, float aY);
        void        setWind(float aX, float aY);

        CS_Force    QueryGravity();
        CS_Force    QueryWind();

    private:
        CS_Force    gravity;
        CS_Force    wind;

};

class   CS_Speed
{
    public:
        CS_Speed();
        ~CS_Speed();

        void    setSpeedX(float vXSource);
        void    setSpeedY(float vYSource);
        void    setSpeed(float vXSource, float vYSource);

        
        void    setSpeedXPixel(int vXSource);
        void    setSpeedYPixel(int vYSource);
        void    setSpeedPixel(int vXSource, int vYSource);

        void    updateSpeed(CS_Force force, float deltaT);
        void    updateSpeed(int aXSource, int aYSource, float deltaT);

        void    moveObject(int &x, int &y, float deltaT);
        
    private:
        int     vX;
        int     vY;
};

class   CS_Position
{
    public:
        CS_Position();
        ~CS_Position();

        void    setPositionX(float xSource);
        void    setPositionY(float ySource);
        void    setPositionXPixel(int xSource);
        void    setPositionYPixel(int ySource);

        void    updatePosition(CS_Speed speed, float deltaT);
        void    updatePosition(int vXSource, int vYSource, float deltaT);

        void    QueryPostion(int& xDest, int& yDest);
        int     QueryPostionX();
        int     QueryPostionY();

    private:
        int x;
        int y;
};

class   CS_PersonalPhysic
{
    public:
        CS_PersonalPhysic();
        ~CS_PersonalPhysic();

        void    loadWorldPhysics(CS_WorldPhysics *WorldPhysicsSource);

        void    setOnGround(bool onGroundSource);
        void    setBounciness(bool bouncinessSource);
        void    setGravity(bool gravitySource);

        void    setSpeedX(int speedX);
        void    setSpeedY(int speedY);

        void    setPosX(float posX);
        void    setPosY(float posY);
        void    setPosXPixel(int speedX);
        void    setPosYPixel(int speedY);

        void    updateSpeed(float deltaT);
        void    updatePosition(float deltaT);

    private:
        CS_WorldPhysics  *WorldPhysics;
        CS_Speed        speed;
        CS_Position     position;
        bool            onGround;
        bool            bounciness;
        bool            gravity;
};

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

typedef struct  e_prop {
    float w;
    float h;
    float x;
    float y;
}               t_prop;

#endif