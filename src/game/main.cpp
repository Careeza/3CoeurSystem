#include "common.h"

using namespace std;

int main()
{
	Canvas	canvas;
	Event	event;
	Texture	background;

	canvas.init(SDL_INIT_VIDEO | SDL_INIT_TIMER);
//	canvas.create_window(0, "Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 500, 500);
	canvas.create_window(SDL_WINDOW_FULLSCREEN_DESKTOP);
	canvas.init_renderer();
	background.load_texture("resources/BackGround.png", canvas);
	background.resize_texture(500, 500);
	while (!canvas.window_closed())
	{
		event.QueryEvent();
		if (event.GestEvent() == CLOSE)
			canvas.close_window();
		background.aff(canvas);
		SDL_RenderPresent(canvas.Query_Renderer());
	}
	cout << "Hello World" << endl;
	return 0;
}

//		SDL_RenderPresent(rend);
//   vector<int> tableau(5);
