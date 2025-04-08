#pragma once
#include "TextureManager.h"

class Collision
{
private:

	SDL_Rect posBird;

	SDL_Rect posGround;

	SDL_Rect pos_topPipe, pos_bottomPipe;

	bool BirdState;

public:

	Collision();	

	// lấy tọa độ các yếu tố va chạm

	void get_PosBird(SDL_Rect bird);

	void get_PosGround(SDL_Rect ground);

	void get_PosPipe(SDL_Rect top_pipe, SDL_Rect bottom_pipe);

	// kiểm tra va chạm

	bool Bird_State();

	// test va chạm và làm chim sống lại

	void true_bird() { BirdState = true; };

	// xử lý va chạm

	void Handling();
};