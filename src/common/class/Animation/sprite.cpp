#include "texture.h"

Animation::Animation(int nb_column, int nb_line)
{
    column = nb_column;
    line = nb_line;
    nb_frames = column * line;
    current_frame = 0;
    end = true;
}

void	Animation::load_animation(std::string route, SDL_Renderer *render, Canvas canvas)
{
    int w;
    int h;
    int i;

    load_texture(route, render, canvas);
	Query_Texture_Size(&w, &h);
    frame->w = w / column;
    frame->h = h / line;
    for (i = 0 ; i < nb_frames ; i++)
    {
        frame_x.push_back(frame->w * (i % column));
        frame_y.push_back(frame->h * (i / column));
    }
    std::cout << nb_frames << std::endl;
}

void	Animation::launch_animation()
{
    if (current_frame == nb_frames)
    {
        current_frame = 0;
        end = true;
    }
    else
    {
        frame->x = frame_x[current_frame];
        frame->y = frame_y[current_frame];
//        std::cout << "frame ->" << frame->x << " -- " << frame->y << " -- " << frame->w << " -- " << frame->h << std::endl;
//        std::cout << frame_x[current_frame] << " -- " << frame_y[current_frame] << " -- " << current_frame << std::endl;
        current_frame++;
    }
}

void    Animation::debug()
{
    std::cout << "frame ->" << frame->x << " -- " << frame->y << " -- " << frame->w << " -- " << frame->h << std::endl;
}
