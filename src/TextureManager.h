#pragma once
#include <iostream>
#include <SDL.h>
#include <SDL_image.h>

using namespace std;

struct TextureManager
{
	static SDL_Texture* Texture(const char* address, SDL_Renderer* ren);
};