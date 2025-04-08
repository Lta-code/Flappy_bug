#include "Menu.h"

Menu::Menu()
{
	// nút trong nguồn

	src[Play1] = { 3, 79, 70, 30 };

	src[Play2] = { 149, 83, 70, 26 };

	src[Options1] = { 217, 181, 90, 30 };

	src[Options2] = { 310, 185, 90, 26 };

	src[Quit1] = { 4, 215, 55, 30 };

	src[Quit2] = { 120, 219, 55, 26 };

	src[ScoreAndBest] = { 251, 463, 103, 56 };

	src[Restart1] = { 154, 249, 92, 30 };

	src[Restart2] = { 249, 253, 92, 26 };

	src[Back1] = { 181, 215, 55, 30 };

	src[Back2] = { 239, 219, 55, 26 };

	src[Back3] = src[Back1];

	src[Back4] = src[Back2];

	src[Sound_Music1] = { 188, 295, 14, 17 };

	src[Sound_Music2] = { 205, 297, 14, 15 };

	// nút trong game

	buttons[Play1] = { 270 - button_W / 2, 205, button_W, button_H };

	buttons[Play2] = { 270 - button_W / 2, 215, button_W, button_H };

	buttons[Options1] = { 270 - button_W / 2, 315, button_W, button_H };

	buttons[Options2] = { 270 - button_W / 2, 322, button_W, button_H };

	buttons[Quit1] = { 270 - button_W / 2, 425, button_W, button_H };

	buttons[Quit2] = { 270 - button_W / 2, 433, button_W, button_H };

	buttons[ScoreAndBest] = { 270 - SAB_W / 2, 360 - SAB_H / 2, SAB_W, SAB_H };

	buttons[Restart1] = { 270 - SAB_W / 2 + 54, 500, button2_W, button2_W * 30 / 55 };

	buttons[Restart2] = { 270 - SAB_W / 2 + 54, 508, button2_W, button2_W * 26 / 55 };

	buttons[Back1] = { 270 - SAB_W / 2 + 54 + button2_W + 20, 500, button2_W, button2_W * 30 / 55 };

	buttons[Back2] = { 270 - SAB_W / 2 + 54 + button2_W + 20, 509, button2_W, button2_W * 26 / 55 };

	buttons[Back3] = { 270 - button2_W / 2, 500, button2_W, button2_W * 30 / 55 };

	buttons[Back4] = { 270 - button2_W / 2, 509, button2_W, button2_W * 26 / 55 };

	buttons[Sound_Music1] = { 480, 650, 40, 49 };

	buttons[Sound_Music2] = { 480, 654, 40, 40 };

	//

	for (auto& state : in_button)
	{
		state = false;
	}

	for (auto& state : press_button)
	{
		state = false;
	}
}

void Menu::Reset()
{
	for (int i = 0; i < 12; i++)
	{
		in_button[i] = false;

		press_button[i] = false;
	}
}

void Menu::Button_Collision()
{
	SDL_GetMouseState(&mouseX, &mouseY);

	mouse = { mouseX, mouseY, 1, 1 };

	for (int i = 0; i < button_count; i += 2)
	{
		if (SDL_HasIntersection(&mouse, &buttons[i]))
		{
			in_button[i] = true;
		}
		else
		{
			in_button[i] = false;
		}
	}
}

void Menu::Render1(SDL_Renderer* ren)
{
	if (!in_button[Play1]) SDL_RenderCopy(ren, Tex, &src[Play1], &buttons[Play1]);
	else SDL_RenderCopy(ren, Tex, &src[Play2], &buttons[Play2]);

	if (!in_button[Options1]) SDL_RenderCopy(ren, Tex, &src[Options1], &buttons[Options1]);
	else SDL_RenderCopy(ren, Tex, &src[Options2], &buttons[Options2]);

	if (!in_button[Quit1]) SDL_RenderCopy(ren, Tex, &src[Quit1], &buttons[Quit1]);
	else SDL_RenderCopy(ren, Tex, &src[Quit2], &buttons[Quit2]);

	if (!in_button[Sound_Music1])
	{
		if(!press_button[Sound_Music1])
		{
			SDL_RenderCopy(ren, Tex, &src[Sound_Music1], &buttons[Sound_Music1]);
		}
		else
		{
			SDL_RenderCopy(ren, Tex, &src[Sound_Music2], &buttons[Sound_Music2]);
		}
	}
	else
	{
		if (!press_button[Sound_Music1])
		{
			SDL_RenderCopy(ren, Tex, &src[Sound_Music1], &buttons[Sound_Music1]);
		}
		else
		{
			SDL_RenderCopy(ren, Tex, &src[Sound_Music2], &buttons[Sound_Music2]);
		}
	}
}

void Menu::Render2(SDL_Renderer* ren)
{
	SDL_RenderCopy(ren, Tex, &src[ScoreAndBest], &buttons[ScoreAndBest]);

	if (!in_button[Restart1]) SDL_RenderCopy(ren, Tex, &src[Restart1], &buttons[Restart1]);
	else SDL_RenderCopy(ren, Tex, &src[Restart2], &buttons[Restart2]);

	if (!in_button[Back1]) SDL_RenderCopy(ren, Tex, &src[Back1], &buttons[Back1]);
	else SDL_RenderCopy(ren, Tex, &src[Back2], &buttons[Back2]);
}

void Menu::Render3(SDL_Renderer* ren)
{
	if (!in_button[Back3]) SDL_RenderCopy(ren, Tex, &src[Back3], &buttons[Back3]);
	else SDL_RenderCopy(ren, Tex, &src[Back4], &buttons[Back4]);
}

SDL_Rect& Menu::get_Button(Button_type type)
{
	return buttons[type];
}

bool Menu::State_In_Button(Button_type type)
{
	return in_button[type];
}

bool Menu::State_Press_Button(Button_type type)
{
	return press_button[type];
}

void Menu::Pressed_Button(Button_type type)
{
	press_button[type] = true;
}

void Menu::UnPressed_Button(Button_type type)
{
	press_button[type] = false;
}

void Menu::LoadTexture1(const char* address, SDL_Renderer* ren)
{
	if (Tex != nullptr)
	{
		SDL_DestroyTexture(Tex);
	}

	Tex = TextureManager::Texture(address, ren);
}