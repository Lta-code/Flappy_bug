#include "Background.h"

Background::Background()
{
	background_1 = { 0, 0, 1324, 699 };

	background_2 = { 1324, 0, 1324, 699 };

	count = 0;

	current_background = 0;
}

void Background::Reset()
{
	background_1 = { 0, 0, 1324, 699 };

	background_2 = { 1324, 0, 1324, 699 };

	count = 0;

	current_background = 0;
}

void Background::Render(SDL_Renderer* ren)
{
	SDL_Texture* Tex = backgrounds[current_background];

	SDL_RenderCopy(ren, Tex, nullptr, &background_1);

	SDL_RenderCopyEx(ren, Tex, nullptr, &background_2, 0, nullptr, SDL_FLIP_HORIZONTAL);
}

void Background::Change_background()
{
	if (!backgrounds.empty())
	{
		static int kt = -1;
		do
		{
			current_background = (rand() % (backgrounds.size() - 1) ) + 1 ;

		} while(current_background == kt);

		kt = current_background;
	}
}

void Background::Update()
{
	count += speed_background;

	int move = count;

	if (move >= 1)
	{
		background_1.x -= move;

		background_2.x -= move;

		count -= move;
	}

	if (background_1.x <= -background_1.w)
	{
		background_1.x = background_2.w;
	}

	if (background_2.x <= -background_2.w)
	{
		background_2.x = background_1.w;
	}
}
void Background::set_background_1(int x, int y, int w, int h)
{
	background_1.x = x;
	background_1.y = y;
	background_1.w = w;
	background_1.h = h;
}

void Background::set_background_2(int x, int y, int w, int h)
{
	background_2.x = x;
	background_2.y = y;
	background_2.w = w;
	background_2.h = h;
}

SDL_Rect& Background::get_background_1()
{
	return background_1;
}

SDL_Rect& Background::get_background_2()
{
	return background_2;
}

void Background::Load_Backgrounds(const vector<const char*>& addresses, SDL_Renderer* ren)
{
	if (!backgrounds.empty())
	{
		for (auto& Tex : backgrounds)
		{
			SDL_DestroyTexture(Tex);
		}
		backgrounds.clear();
	}

	for (auto& address : addresses)
	{
		backgrounds.push_back(TextureManager::Texture(address, ren));
	}
}

