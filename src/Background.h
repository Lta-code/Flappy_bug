#pragma once
#include "TextureManager.h"
#include <vector>

class Background
{
private:

	vector<SDL_Texture*> backgrounds;

	int current_background;

	SDL_Rect background_1;

	SDL_Rect background_2;

	const double speed_background = 0.15;

	double count = 0;

public:

	Background();

	// load ảnh

	void Load_Backgrounds(const vector<const char*>& addresses, SDL_Renderer* ren);

	void Render(SDL_Renderer* ren);

	// tọa độ

	void set_background_1(int x, int y, int w, int h);

	void set_background_2(int x, int y, int w, int h);

	SDL_Rect& get_background_1();

	SDL_Rect& get_background_2();

	//

	void Update();

	void Change_background();

	void Reset();
};
