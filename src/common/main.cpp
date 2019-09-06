#include "canvas.h"
#include "common.h"
#include "event.h"

using namespace std;

int main()
{
	Canvas	canvas;
	Event	event;

	canvas.init(SDL_INIT_VIDEO | SDL_INIT_TIMER);
	canvas.create_window(SDL_WINDOW_FULLSCREEN_DESKTOP);
	while (!canvas.window_closed())
	{
		event.QueryEvent();
		if (event.GestEvent() == CLOSE)
			canvas.close_window();
	}
	cout << "Hello World" << endl;
	return 0;
}
