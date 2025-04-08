#pragma once
#include "TextureManager.h"
#include <vector>

class Player
{
private:

    SDL_Texture* Tex;

    vector<SDL_Texture*> birds;

    int current_bird;

    SDL_Rect src1;

    SDL_Rect dest1;

    const double pX = 210;

    const double pY = 0;

    const double pW = 60;

    const double pH = 42;

    bool bird_Jump;

    double speed_Y;

    double pos_Y = 100;

    const double jumpHeight = -1;

    const double gravity = 0.01;

    const double max_top = -100;

    const double max_bottom = 600;

    double time = 0;

    double tocdo_1;

    double angle_bird;

    double angle_speed = 2;

public:

    Player();

    // load ảnh

    void Load_Birds(const vector<const char*>& addresses, SDL_Renderer* ren);

    SDL_Texture* get_Tex() { return Tex; };

    void Render1(SDL_Renderer* ren);

    void Render2(SDL_Renderer* ren);

    // tọa độ

    void set_src1(int x, int y, int w, int h);

    void set_dest1(int x, int y, int w, int h);

    SDL_Rect& get_src1();

    SDL_Rect& get_dest1();

    //

    void Jump();

    bool JumpState();

    void Gravity();

    void anima_1();

    void Update();

    void Bird_Die();

    void Reset();

    void Change_Bird();

};