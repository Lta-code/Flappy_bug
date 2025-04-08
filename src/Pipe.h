#pragma once
#include "TextureManager.h"
#include <vector>

class Pipe
{
private:

	SDL_Texture* Tex;

	struct pipe_pair
	{
		SDL_Rect topPipe;

		SDL_Rect bottomPipe;

		bool passed = false;
	};

	vector<pipe_pair> pipes;

	const int pipe_count = 5;

	const double speed_pipe = 2;

	int pipe_X;

	const int pipe_W = 90;

	const int pipe_H = 517;

	const int pipe_Distane = 155;

	const int edge_screen = 1200;

	int pipe_spacing = 300;

	int random_H;

public:

	Pipe();

	// load

	void Load_Pipe(const char* address, SDL_Renderer* ren);

	void Render(SDL_Renderer* ren);

	// vị trí

	vector<pipe_pair>& get_pipe_pair();

	//

	void Init_Pipes();

	void Update();

	bool out_screen();

	void Reset_Pipe(pipe_pair& pipe);

	int Random_Pipe();
};