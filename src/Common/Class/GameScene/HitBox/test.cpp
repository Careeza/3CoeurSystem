# include "gameScene.h"

bool    CS_HitBox::Collision(int wTest, int hTest, int xTest, int yTest)
{
    return ((x < xTest + wTest) 
        && (x + w > xTest) 
        && (y < yTest + hTest) 
        && (y + h > yTest));
}
