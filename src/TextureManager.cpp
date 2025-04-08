#include "TextureManager.h"

SDL_Texture* TextureManager::Texture(const char* address, SDL_Renderer* ren)
{
	SDL_Surface* surface = IMG_Load(address);

	if (!surface)
	{
		cout << "Failed to load image. Error: " << IMG_GetError();
		return nullptr;
	}

	SDL_Texture* Texture =  SDL_CreateTextureFromSurface(ren, surface);

	if (!Texture)
	{
		cout << "Failed to create texture from surface. Error: " << SDL_GetError();
	}

	SDL_FreeSurface(surface);

	return Texture;
}