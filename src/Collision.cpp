#include "Collision.h"

Collision::Collision()
{
	BirdState = true; // còn sống
}

void Collision::Handling()
{
	// va nền

	if (posBird.y + posBird.h >= posGround.y)
	{
		BirdState = false;
	}

	// va cột

	if (posBird.x + posBird.w > pos_topPipe.x && posBird.x < pos_topPipe.x + pos_topPipe.w)
	{
		if (posBird.y < pos_topPipe.y + pos_topPipe.h || posBird.y + posBird.h > pos_bottomPipe.y)
		{
			BirdState = false;	
		}
	}
}

void Collision::get_PosBird(SDL_Rect bird)
{
	posBird = bird;
}

void Collision::get_PosGround(SDL_Rect ground)
{
	posGround = ground;
}

void Collision::get_PosPipe(SDL_Rect top_pipe, SDL_Rect bottom_pipe)
{
	pos_topPipe = top_pipe;

	pos_bottomPipe = bottom_pipe;
}

bool Collision::Bird_State()
{
	return BirdState;
}