#include "Fps.h"

void fps::frame()
{
	t1 = SDL_GetTicks();

	if (t1 - t2 <= 16.7)
	{
		SDL_Delay(16.7 - (t1 - t2));
	}

	//t1 = SDL_GetTicks();

	//cout << 1000 / (t1 - t2) << "\n";

	t2 = t1;
}