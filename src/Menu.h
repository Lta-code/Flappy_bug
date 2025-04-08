#pragma once
#include "TextureManager.h"

class Menu
{
private:

	SDL_Texture* Tex;

	SDL_Rect src[15];

	SDL_Rect buttons[15];

	bool in_button[15];

	bool press_button[15];

	const int button_count = 14;

	SDL_Rect mouse;

	const int button_W = 210;

	const int button_H = 90;

	const int button2_W = 140;

	const int SAB_W = 400;

	int SAB_H = 217;

	int mouseX, mouseY;

public:

	Menu();

	// load and ren

	void LoadTexture1(const char* address, SDL_Renderer* ren);

	void Render1(SDL_Renderer* ren);

	void Render2(SDL_Renderer* ren);

	void Render3(SDL_Renderer* ren);

	// xử lí nút

	enum Button_type
	{
		Play1,
		Play2,
		Options1,
		Options2,
		Restart1,
		Restart2,
		Back1,
		Back2,
		Back3,
		Back4,
		Quit1,
		Quit2,
		Sound_Music1,
		Sound_Music2,
		ScoreAndBest
	};

	// vị trí

	SDL_Rect& get_Button(Button_type type);

	// 

	void Button_Collision();

	bool State_In_Button(Button_type type);

	bool State_Press_Button(Button_type type);

	void Pressed_Button(Button_type type);

	void UnPressed_Button(Button_type type);

	void Reset();
};