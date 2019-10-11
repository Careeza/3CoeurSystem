# include "scene.h"

SDL_Texture     *CS_Police::CS_queryTexte()
{
    return (texture);
}

SDL_Rect        *CS_Police::querySize()
{
//    std::cout << "the zoom is set as - " << zoom << std::endl;
    if (zoom == NOZOOM)
    {
//        std::cout << "ZOOM NO" << std::endl;
        return (CS_size);
    }
    else if (zoom == ZOOMIN)
        return (CS_zoomIn);
    else if (zoom == ZOOMOUT)
        return (CS_zoomOut);
    else
    {
        std::cout << "weird things happend with the police !" << std::endl;
        return (NULL);
    }
}