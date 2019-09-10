#include "texture.h"
using namespace std; 

void    Texture::LoadTexture(string str, SDL_Renderer *rend, Canvas canvas)
{
    string  Query;
    int     w;
    int     h;
    int     z;

    rect = new SDL_Rect;
    frame = new SDL_Rect;
    ifstream file_text(str.c_str());
    getline(file_text, Query);
    load_texture("resources/BackGround.png", rend);
	canvas.Query_Window_Size(&w, &h);
    file_text >> rect->w;
    file_text >> rect->h;
    rect->w *= (w / 100.0);
    rect->h *= (h / 100.0);
    file_text >> rect->x;
	file_text >> rect->y;
	frame->x = 0;
	frame->y = 0;
    file_text >> z;
    set_z_index(z);
	Query_Texture_Size(&frame->w, &frame->h);
}