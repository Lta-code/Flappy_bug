#pragma once
#include "TextureManager.h"

class Ground
{
private:

	SDL_Texture* Tex;

	SDL_Rect ground_1, ground_2;

	const double speed_ground = 2;

	const int gY = 600;

	const int gW = 1260;

	const int gH = 120;

public:

	Ground();

	// load

	void LoadTexture1(const char* address, SDL_Renderer* ren);

	SDL_Texture* get_Tex() { return Tex; };

	void Render(SDL_Renderer* ren);

	// vị trí

	SDL_Rect& get_ground_1();

	//

	void Update();
};