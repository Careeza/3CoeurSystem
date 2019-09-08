#include "common.h"
#include <time.h>

using namespace std;
 
int main()
{
	Canvas		canvas;
	Event		event;
	Texture		background;
	Animation	cursor(10, 1);
	Render		render;

	canvas.init(SDL_INIT_VIDEO | SDL_INIT_TIMER);
//	canvas.create_window(0, "Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 500, 500);
	canvas.create_window(SDL_WINDOW_FULLSCREEN_DESKTOP);
	render.init_renderer(canvas);
	
	background.load_texture("resources/BackGround.png", render.Query_Renderer(), canvas);
	cursor.load_animation("resources/Curseur.png", render.Query_Renderer(), canvas);
	cursor.resize_texture(canvas, 10, 10, 45, 45);
	background.set_z_index(4);
	cursor.set_z_index(3);
	
	render.add_texture_in_render(cursor);
	render.add_texture_in_render(background);
	render.debug();
	
	while (!canvas.window_closed())
	{
		event.QueryEvent();
		if (event.GestEvent() == CLOSE)
			canvas.close_window();
		cursor.launch_animation();
		render.aff_all();
		//cursor.debug();
//		background.aff(canvas);
//		cursor.aff(canvas);
		SDL_RenderPresent(render.Query_Renderer());
	}
	cout << "Hello World" << endl;
	return 0;
}

//		SDL_RenderPresent(rend);
//   vector<int> tableau(5);
