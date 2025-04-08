#include "Pipe.h"

Pipe::Pipe()
{
	
}

void Pipe::Init_Pipes()
{
	pipes.clear();

	int count = 0;

	for (int i = 0; i < pipe_count; i++)
	{
		pipe_X = edge_screen + (count++) * pipe_spacing;

		random_H = Random_Pipe();

		pipe_pair pi;

		pi.topPipe = { pipe_X, -pipe_H + random_H, pipe_W, pipe_H };

		pi.bottomPipe = { pipe_X, random_H + pipe_Distane, pipe_W, pipe_H };

		pi.passed = false;

		pipes.push_back(pi);
	}
}

int Pipe::Random_Pipe()
{
	int ran;

	static int kt = -1;

	do
	{
		ran = rand() % 240 + 100;

	} while (ran == kt);

	kt = ran;

	return ran;
}

void Pipe::Update()
{
	for (auto& pipe : pipes)
	{
		pipe_X -= speed_pipe;

		pipe.topPipe.x -= speed_pipe;

		pipe.bottomPipe.x -= speed_pipe;

		if (pipe.topPipe.x + pipe_W < 0)
		{
			Reset_Pipe(pipe);
		}
	}
}

void Pipe::Reset_Pipe(pipe_pair& pipe)
{
	pipe_X = 210 * 5 + 90 * 4; 

	random_H = Random_Pipe();

	pipe.topPipe.x = pipe_X;

	pipe.topPipe.y = -pipe_H + random_H;

	pipe.bottomPipe.x = pipe_X;

	pipe.bottomPipe.y = random_H + pipe_Distane; 

	pipe.passed = false;
}

vector<Pipe::pipe_pair>& Pipe::get_pipe_pair()
{
	return pipes;
}

void Pipe::Render(SDL_Renderer* ren)
{
	for (auto& pipe : pipes)
	{
		SDL_RenderCopyEx(ren, Tex, nullptr, &pipe.topPipe, 0, nullptr, SDL_FLIP_VERTICAL);

		SDL_RenderCopy(ren, Tex, nullptr, &pipe.bottomPipe);
	}
}

void Pipe::Load_Pipe(const char* address, SDL_Renderer* ren)
{
	Tex = TextureManager::Texture(address, ren);

	Init_Pipes();
}