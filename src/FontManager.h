#pragma once
#include <iostream>
#include <SDL.h>
#include <SDL_ttf.h>
#include <string>

using namespace std;

class FontManager
{
private:

	SDL_Texture* Tex;

	TTF_Font* font;

	SDL_Color color_text;

	SDL_Rect pos_text;

public:

	FontManager();

	// load

	void Load_Font(const char* address, int font_size);

	void Render(SDL_Renderer* ren, string& text, int x, int y);

	//

	void Set_color_text(Uint8 r, Uint8 g, Uint8 b);

	void Clean();
};