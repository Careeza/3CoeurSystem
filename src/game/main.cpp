#include "canvas.h"
#include "render.h"
#include "texture.h"
#include "event.h"
#include "timer.h"
#include <time.h>
#include <math.h>

using namespace std;

int main()
{
	Canvas		canvas;
	Event		event;
	Texture		background;
	Animation	cursor;
	Animation	atk;
	Render		render;

	Timer 	fps; 
	Timer 	update;
	Timer	wait;
	int		frame; 

	canvas.init(SDL_INIT_VIDEO | SDL_INIT_TIMER);
//	canvas.create_window(0, "Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 500, 500);
	canvas.create_window(SDL_WINDOW_FULLSCREEN_DESKTOP);
	render.init_renderer(canvas);
	
	background.LoadTexture("resources/Texture/Texture/BackGround.tex", render.Query_Renderer(), canvas);
	cursor.load_animation("resources/Animation/animation/Curseur.animation", render.Query_Renderer(), canvas);
	atk.load_animation("resources/Animation/animation/MCAnimation.animation", render.Query_Renderer(), canvas);

	render.add_texture_in_render(cursor);
	render.add_texture_in_render(background);
	render.add_texture_in_render(atk);

	frame = 0;
	update.start();
	fps.start();

	while (!canvas.window_closed())
	{
		wait.start();
		event.QueryEvent();
		if (event.GestEvent() == CLOSE)
			canvas.close_window();
		cursor.launch_animation();
		atk.launch_animation();
		render.aff_all();
		SDL_RenderPresent(render.Query_Renderer());
		frame++;
		SDL_Delay(fmax(0, 1000/FRAMES_PER_SECOND - wait.get_ticks()));
		if( update.get_ticks() > 1000)
		{
			cout << "fps = " << (float)frame / (fps.get_ticks() / 1000.0) << endl;			update.start();
		}
	}
	return 0;
} 
