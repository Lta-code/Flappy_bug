#pragma once
#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>
#include <fstream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include "Player.h"
#include "Background.h"
#include "Fps.h"
#include "Ground.h"
#include "Pipe.h" 
#include "Menu.h"
#include "Collision.h"
#include "FontManager.h"
#include "Sound.h"

using namespace std;
   
class Gameloop
{
private:

    Sound sound;

    bool sound_die = false;

    FontManager font;

    Pipe pipe;

    Collision col;

    Player ph;

    Background back;

    fps f;

    Ground gr;

    Menu menu;

    int score;

    int best_score;

    string score_text;

    string best_score_text;

    bool GameState; // biến kiểm tra tình trạng chương trình

    const int WIDTH = 540; // chiều rộng cửa sổ 

    const int HEIGHT = 720; // chiều cao cửa sổ

    const char* TITLE = "Flappy bug"; // tiêu đề trên thanh cửa sổ

    SDL_Window* window;

    SDL_Renderer* renderer;

    SDL_Event event1;

public:

    Gameloop();

    bool get_GameState(); // kiểm tra tình trạng chương

    void Init(); // khởi tạo cửa sổ

    void Render(); // kết xuất hình ảnh

    void Update();

    void Event(); // xử lí các sự kiện (VD: chuột, bàn phím, ...)

    void Clear(); // dọn dẹp bộ nhớ

    //

    void Load_best_score();

    void Save_best_score();

    void Restart();

    void Back();
};
