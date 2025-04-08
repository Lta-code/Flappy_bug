#include "Player.h"

Player::Player()
{
	bird_Jump = false;

	speed_Y = 0;

	pos_Y = 200;

	angle_bird = 0;

	set_dest1(pX, pos_Y, pW, pH);

	current_bird = 0;
}

void Player::Reset()
{
	bird_Jump = false;

	speed_Y = 0;

	pos_Y = 200;

	angle_bird = 0;

	set_dest1(pX, pos_Y, pW, pH);
}

void Player::Change_Bird()
{
	if (!birds.empty())
	{
		current_bird = (++current_bird) % birds.size();
	}
}

void Player::Render1(SDL_Renderer* ren)
{
	Tex = birds[current_bird];

	SDL_RenderCopyEx(ren, get_Tex(), &get_src1(), &get_dest1(), angle_bird, nullptr, SDL_FLIP_NONE);
}

void Player::Render2(SDL_Renderer* ren)
{
	Tex = birds[current_bird];

	anima_1();

	set_dest1(240, 200, pW, pH);

	SDL_RenderCopy(ren, get_Tex(), &get_src1(), &get_dest1());
}

bool Player::JumpState()
{
	return bird_Jump;
}

void Player::Gravity()
{
	// chim rơi

	speed_Y += gravity;

	pos_Y += speed_Y;

	if (speed_Y > 0 && JumpState())
	{
		bird_Jump = false;
	}

	if (pos_Y < max_top)
	{
		pos_Y = max_top + 40;

		bird_Jump = false;
	}

	set_dest1(pX, pos_Y, pW, pH);

	// chim quay

	angle_speed = (angle_speed + speed_Y * 0.2) * 0.8;

	angle_bird += angle_speed;

	if (angle_bird > 90) angle_bird = 90;

	if (angle_bird < -30) angle_bird = -30;
}

void Player::Jump()
{
	speed_Y = jumpHeight;

	angle_speed = -30;

	bird_Jump = true;
}

void Player::anima_1()
{
	int count_frame = 3;

	time++;

	int frame = time / 10;

	tocdo_1 = frame % count_frame;

	if (tocdo_1 >= count_frame)
	{
		time = 0;
	}

	set_src1(tocdo_1 * 92, 0, 91, 63);
}

void Player::Update()
{
	Gravity();

	anima_1();
}

void Player::Bird_Die()
{
	if (pos_Y < 558)
	{
		Gravity();
	}
}

void Player::set_src1(int x, int y, int w, int h)
{
	src1.x = x;
	src1.y = y;
	src1.w = w;
	src1.h = h;
}

void Player::set_dest1(int x, int y, int w, int h)
{
	dest1.x = x;
	dest1.y = y;
	dest1.w = w;
	dest1.h = h;
}

SDL_Rect& Player::get_src1()
{
	return src1;
}

SDL_Rect& Player::get_dest1()
{
	return dest1;
}

void Player::Load_Birds(const vector<const char*>& addresses, SDL_Renderer* ren)
{
	if (!birds.empty())
	{
		for (auto& Tex : birds)
		{
			SDL_DestroyTexture(Tex);
		}
		birds.clear();
	}

	for (auto& address : addresses)
	{
		birds.push_back(TextureManager::Texture(address, ren));
	}
}