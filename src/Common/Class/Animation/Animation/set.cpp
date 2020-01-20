# include "gameScene.h"

void    CS_Animation::setHitBox(int indexSource, bool right, float wSource, float hSource, float xSource, float ySource)
{
    if (right)
    {
        hitboxesR[indexSource]->setWPixel(wSource * w);
        hitboxesR[indexSource]->setHPixel(hSource * h);
        hitboxesR[indexSource]->setXPixel(xSource * w);
        hitboxesR[indexSource]->setYPixel(ySource * h);
    }
    else
    {
        hitboxesL[indexSource]->setWPixel(wSource * w);
        hitboxesL[indexSource]->setHPixel(hSource * h);
        hitboxesL[indexSource]->setXPixel(xSource * w);
        hitboxesL[indexSource]->setYPixel(ySource * h);
    }
}

void    CS_Animation::setAttack(int indexSource, bool right, float wSource, float hSource, float xSource, float ySource)
{
    if (right)
    {
        attackR[indexSource]->setWPixel(wSource * w);
        attackR[indexSource]->setHPixel(hSource * h);
        attackR[indexSource]->setXPixel(xSource * w);
        attackR[indexSource]->setYPixel(ySource * h);
    }
    else
    {
        attackL[indexSource]->setWPixel(wSource * w);
        attackL[indexSource]->setHPixel(hSource * h);
        attackL[indexSource]->setXPixel(xSource * w);
        attackL[indexSource]->setYPixel(ySource * h);
    }
}
