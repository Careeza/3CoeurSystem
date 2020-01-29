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

typedef struct  e_prop {
    float w;
    float h;
    float x;
    float y;
}               t_prop;


class   CS_Force
{
    public:
        CS_Force();
        ~CS_Force();

        void    setAccelerationX(float aXsource);
        void    setAccelerationY(float aYsource);
        void    setAccelerationXPixel(float aXsource);
        void    setAccelerationYPixel(float aYsource);

        void    usePhysic(float& vXDest, float& vYDest, int deltaT);

        float   QueryAX();
        float   QueryAY();

    private:
        float aX;
        float aY;
        
};

class   CS_WorldPhysics
{
    public:
        CS_WorldPhysics();
        ~CS_WorldPhysics();

        void        setGravityPixel(float aX, float aY);
        void        setWindPixel(float aX, float aY);
        void        setGravity(float aX, float aY);
        void        setWind(float aX, float aY);

        CS_Force    QueryGravity();
        CS_Force    QueryWind();

    private:
        CS_Force    gravity;
        CS_Force    wind;

};

extern CS_WorldPhysics  *WorldPhysics;

class   CS_Speed
{
    public:
        CS_Speed();
        ~CS_Speed();

        void    setSpeedX(float vXSource);
        void    setSpeedY(float vYSource);
        void    setSpeed(float vXSource, float vYSource);

        
        void    setSpeedXPixel(float vXSource);
        void    setSpeedYPixel(float vYSource);
        void    setSpeedPixel(float vXSource, float vYSource);

        void    updateSpeed(CS_Force force, int deltaT);
        void    updateSpeed(float aXSource, float aYSource, int deltaT);

        void    moveObject(float &x, float &y, int deltaT);

        float   QuerySpeedX();
        float   QuerySpeedY();
        
    private:
        float     vX;
        float     vY;
};

class   CS_Position
{
    public:
        CS_Position();
        ~CS_Position();

        void    setPositionX(float xSource);
        void    setPositionY(float ySource);
        void    setPositionXPixel(float xSource);
        void    setPositionYPixel(float ySource);

        bool    updatePosition(CS_GameScene *scene, CS_HitBox *hitbox, CS_Speed speed, int deltaT);
        bool    updatePosition(CS_GameScene *scene, CS_HitBox *hitbox, float vXSource, float vYSource, int deltaT);

        void    QueryPostion(int& xDest, int& yDest);
        int     QueryPostionX();
        int     QueryPostionY();

    private:
        float x;
        float y;
};

class   CS_PersonalPhysic
{
    public:
        CS_PersonalPhysic();
        ~CS_PersonalPhysic();

        void        setOnGround(bool onGroundSource);
        void        setBounciness(bool bouncinessSource);
        void        setGravity(float gravitySource);
        void        setHitBox(CS_HitBox *hitboxSource);
        void        setAttack(CS_HitBox *attackSource);

        void        setHP(int hpSource);
        void        increaseHP(int hpSource);

        bool        verifyOnGround();
        bool        verifyBounciness();
        float       QueryGravity();

        void        setSpeedX(float speedX);
        void        setSpeedY(float speedY);

        void        setPosX(float posX);
        void        setPosY(float posY);
        void        setPosXPixel(int speedX);
        void        setPosYPixel(int speedY);

        void        updateSpeed(int deltaT);
        void        updatePosition(CS_GameScene *scene, int deltaT);

        int         QueryPostionX();
        int         QueryPostionY();

        float       QuerySpeedX();
        float       QuerySpeedY();

        int         QueryHP();
        void        QueryPostion(int& xDest, int& yDest);
        void        QueryHitBox(int& wDest, int& hDest, int& xDest, int& yDest);
        CS_HitBox   *QueryRawHitbox();
        void        QueryAttack(int& wDest, int& hDest, int& xDest, int& yDest);
        CS_HitBox   *QueryRawAttack();


    private:
        CS_Speed        speed;
        CS_Position     position;
        CS_HitBox       *hitbox;
        CS_HitBox       *attack;
        int             hp;
        bool            onGround;
        bool            bounciness;
        float           gravity;
};

#endif
