#include "texture.h"
#include "pixel.h"
using namespace std; 

Animation::Animation()
{
    current_frame = 0;
    end = true;
}

void	Animation::load_animation(std::string route, SDL_Renderer *render, Canvas canvas)
{
    int w;
    int h;
    string str;

    ifstream file_text(route.c_str());
    getline(file_text, str);
    LoadTexture(str, render, canvas);
    file_text >> column;
    file_text >> line;
    file_text >> nb_frames;
    file_text >> time;
    pas = (FRAMES_PER_SECOND / (float)nb_frames) * time;
    cout << "test" << pas << endl;
    if (pas == 0)
        pas = 1;
	Query_Texture_Size(&w, &h);
    frame->w = w / column;
    frame->h = h / line;
    for (int i = 0 ; i < nb_frames ; i++)
    {
        frame_x.push_back(frame->w * (i % column));
        frame_y.push_back(frame->h * (i / column));
    }
}

void	Animation::launch_animation()
{
    int i;

   // cout << pas << endl;
    i = current_frame / pas;
    if (i == nb_frames)
    {
        current_frame = 0;
        end = true;
    }
    else
    {
        frame->x = frame_x[i];
        frame->y = frame_y[i];
        current_frame++;
        end = false;
    }
}

void    Animation::debug()
{
    std::cout << "frame ->" << frame->x << " -- " << frame->y << " -- " << frame->w << " -- " << frame->h << std::endl;
}
