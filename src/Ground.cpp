#include "Ground.h"

Ground::Ground()
{
	ground_1 = { 0, gY, gW, gH };

	ground_2 = { gW, gY, gW, gH };
}

void Ground::Render(SDL_Renderer* ren)
{
	SDL_RenderCopy(ren, get_Tex(), nullptr, &ground_1);

	SDL_RenderCopy(ren, get_Tex(), nullptr, &ground_2);
}

void Ground::Update()
{
	ground_1.x -= speed_ground;

	ground_2.x -= speed_ground;

	if (ground_1.x <= -ground_1.w)
	{
		ground_1.x = ground_2.x + ground_1.w;
	}

	if (ground_2.x <= -ground_2.w)
	{
		ground_2.x = ground_1.x + ground_2.w;
	}
}

SDL_Rect& Ground::get_ground_1()
{
	return ground_1;
}

void Ground::LoadTexture1(const char* address, SDL_Renderer* ren)
{
	if (Tex != nullptr)
	{
		SDL_DestroyTexture(Tex);
	}

	Tex = TextureManager::Texture(address, ren);
}