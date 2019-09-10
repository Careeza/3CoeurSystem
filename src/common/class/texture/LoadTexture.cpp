#include "texture.h"
using namespace std; 

void    Texture::LoadTexture(string str, SDL_Renderer *rend, Canvas canvas)
{
    string      Query;
    float       w;
    float       h;
    float       x;
    float       y;
    int         z;

    rect = new SDL_Rect;
    frame = new SDL_Rect;
    ifstream file_text(str.c_str());
    getline(file_text, Query);
    load_texture(Query, rend);
    file_text >> w;
    file_text >> h;
    file_text >> x;
    file_text >> y;
    resize_texture(canvas, w, h, x, y);
	frame->x = 0;
	frame->y = 0;
    Query_Texture_Size(&frame->w, &frame->h);
    file_text >> z;
    set_z_index(z);
}