# include "scene.h"

void    CS_Police::initPolice(std::string police)
{
    font = TTF_OpenFont(police.c_str(), 40);
    std::cout << "init Police" << std::endl;
    if (font == NULL)
    {
        std::cout << "error init police" << std::endl;
        exit (0);
    }
}

void    CS_Police::policeSetting(CS_Color colorSource, int flagsSource, int marginXSource, int marginYSource)
{
    flags = flagsSource;
    marginX = marginXSource;
    marginY = marginYSource;
    color.r = colorSource.QueryRed();
    color.g = colorSource.QueryGreen();
    color.b = colorSource.QueryBlue();
    color.a = colorSource.QueryAlpha();
}

void    CS_Police::initZoomIn()
{
    zoomIn->w = size->w + ZOOM;
    zoomIn->h = size->h + ZOOM;
    zoomIn->y = size->y - ZOOM / 2;
    if (flags == ALIGN_CENTER)
        zoomIn->x = size->x - ZOOM / 2;
    else if (flags == ALIGN_RIGHT)
        zoomIn->x = size->x - ZOOM;
}

void    CS_Police::initZoomOut()
{
    zoomOut->w = size->w - ZOOM;
    zoomOut->h = size->h - ZOOM;
    zoomOut->y = size->y + ZOOM / 2;
    if (flags == ALIGN_CENTER)
        zoomOut->x = size->x + ZOOM / 2;
    else if (flags == ALIGN_RIGHT)
        zoomOut->x = size->x + ZOOM;
}