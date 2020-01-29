# include "gameScene.h"

void    CS_Animation::setHitBox(bool right, float wSource, float hSource, float xSource, float ySource)
{
    if (right)
    {
        hitboxesR->setWPixel(wSource * w);
        hitboxesR->setHPixel(hSource * h);
        hitboxesR->setXPixel(xSource * w);
        hitboxesR->setYPixel(ySource * h);
    }
    else
    {
        hitboxesL->setWPixel(wSource * w);
        hitboxesL->setHPixel(hSource * h);
        hitboxesL->setXPixel(xSource * w);
        hitboxesL->setYPixel(ySource * h);
    }
}

void    CS_Animation::setAttack(bool right, float wSource, float hSource, float xSource, float ySource)
{
    if (right)
    {
        attackR->setWPixel(wSource * w);
        attackR->setHPixel(hSource * h);
        attackR->setXPixel(xSource * w);
        attackR->setYPixel(ySource * h);
    }
    else
    {
        attackL->setWPixel(wSource * w);
        attackL->setHPixel(hSource * h);
        attackL->setXPixel(xSource * w);
        attackL->setYPixel(ySource * h);
    }
}
