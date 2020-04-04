# include "scene.h"

SDL_Texture     *CS_Police::QueryTexte()
{
    return (texture);
}

SDL_Rect        *CS_Police::QuerySize()
{
//    std::cout << "the zoom is set as - " << zoom << std::endl;
    if (zoom == NOZOOM)
    {
//        std::cout << "ZOOM NO" << std::endl;
        return (size);
    }
    else if (zoom == ZOOMIN)
        return (zoomIn);
    else if (zoom == ZOOMOUT)
        return (zoomOut);
    else
    {
        std::cout << "weird things happend with the police !" << std::endl;
        return (NULL);
    }
}
