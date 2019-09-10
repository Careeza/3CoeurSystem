#include "common.h"
#include <time.h>

using namespace std;
 
int main()
{
	Canvas		canvas;
	Event		event;
	Texture		background;
	Animation	cursor;
	Render		render;

	Timer 	fps; 
	Timer 	update;
	int		frame; 

	canvas.init(SDL_INIT_VIDEO | SDL_INIT_TIMER);
//	canvas.create_window(0, "Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 500, 500);
	canvas.create_window(SDL_WINDOW_FULLSCREEN_DESKTOP);
	render.init_renderer(canvas);
	
	background.LoadTexture("resources/Texture/Texture/BackGround.tex", render.Query_Renderer(), canvas);
	cursor.load_animation("resources/Animation/animation/Curseur.animation", render.Query_Renderer(), canvas);
	
	render.add_texture_in_render(cursor);
	render.add_texture_in_render(background);

	frame = 0;
	update.start();
	fps.start();

	while (!canvas.window_closed())
	{
		if( update.get_ticks() > 1000)
		{
			cout << "fps = " << (float)frame / (fps.get_ticks / 1000.0) << endl;
			update.start();
		}
		event.QueryEvent();
		if (event.GestEvent() == CLOSE)
			canvas.close_window();
		cursor.launch_animation();
		render.aff_all();
		SDL_RenderPresent(render.Query_Renderer());
		frame++;
		SDL_Delay(1000/FRAME_PER_SECOND);
	}
	return 0;
} 
