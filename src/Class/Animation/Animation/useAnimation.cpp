bool        animationOver(int index, int nbFrame)
{
    if (index >= nbFrame)
    {
        index = 0;
        return (true);
    }
    else
    {
        if (interrupt == INTERRUPT)
            return (true);
        else
            return (false);
    }
}

void        hitBoxGestion(SDL_Rect *size)
{
    if (size->x < 0)
        size->x = 0;
    if (size->x > gameSettings.window_width - size->w)
        size->x = gameSettings.window_width - size->w;
}

bool        CS_Animation::CS_UseAnimation(bool right, SDL_Rect *size, SDL_Rect* &frameDest, SDL_Texture* &textureDest)
{
    if (right == true)
    {
        textureDest = textureR;
        size->x += movement[index];
    }
    else
    {
        textureDest = textureL;
        size->x -= movement[index];
    }
    frameDest = frame[index];
    index++;
    return (animationOver(index, nbFrame));
}