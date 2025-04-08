#include "FontManager.h"

FontManager::FontManager()
{
	//font = nullptr;

	//Tex = nullptr;
}

void FontManager::Load_Font(const char* address, int font_size)
{
	font = TTF_OpenFont(address, font_size);

	if (!font)
	{
		cout << "Failed to load font. Error: " << TTF_GetError() << "\n";
	}
}

void FontManager::Set_color_text(Uint8 r, Uint8 g, Uint8 b)
{
	color_text = { r, g, b };
}

void FontManager::Render(SDL_Renderer* ren, string& text, int x, int y)
{
	if (Tex)
	{
		SDL_DestroyTexture(Tex);
		Tex = nullptr;
	}

	SDL_Surface* surface = TTF_RenderText_Solid(font, text.c_str(), color_text);


	if (!surface)
	{
		cout << "Failed to create surface.Error: " << TTF_GetError() << "\n";
		return;
	}

	Tex = SDL_CreateTextureFromSurface(ren, surface);


	if (!Tex)
	{
		cout << "Failed to create texture: " << SDL_GetError() << "\n";

		SDL_FreeSurface(surface);
		return;
	}

	pos_text.x = x;
	pos_text.y = y;
	pos_text.w = surface->w;
	pos_text.h = surface->h;

	SDL_RenderCopy(ren, Tex, nullptr, &pos_text);

	SDL_FreeSurface(surface);
}

void FontManager::Clean()
{
	if (Tex)
	{
		SDL_DestroyTexture(Tex);

		Tex = nullptr;
	}

	if (font)
	{
		TTF_CloseFont(font);

		font = nullptr;
	}
}
