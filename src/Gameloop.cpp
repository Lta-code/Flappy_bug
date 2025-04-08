#include "Gameloop.h"
using namespace std;

Gameloop::Gameloop()
{
    window = nullptr;

    renderer = nullptr;

    GameState = false;

    srand(time(0));

    score = 0;

    Load_best_score();
}

bool Gameloop::get_GameState()
{
    return GameState;
}

void Gameloop::Init()
{
    SDL_Init(SDL_INIT_EVERYTHING);

    window = SDL_CreateWindow(TITLE, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);

    if (window)
    {
        renderer = SDL_CreateRenderer(window, -1, 0);

        if (renderer)
        {
            cout << "Done~@_@" << "\n";

            GameState = true;

            pipe.Load_Pipe("images/ong_cong.png", renderer);

            back.Load_Backgrounds
            (
                {
                    "images/back_0.png",
                    "images/back_1.png",
                    "images/back_2.png",
                    "images/back_3.png",
                    "images/back_4.png",
                    "images/back_5.png",
                    "images/back_6.png",
                    "images/back_7.png",
                    "images/back_8.png",
                }
                , renderer
            );

            ph.Load_Birds
            (
                {
                    "images/bird_1.png",
                    "images/bird_2.png",
                    "images/bird_3.png",
                    "images/bird_4.png",
                    "images/bird_5.png",
                }
                , renderer
            );

            gr.LoadTexture1("images/ground.png", renderer);

            menu.LoadTexture1("images/Buttons.png", renderer);

            if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
            {
                cout << "SDL_mixer could not initialize! Error: " << Mix_GetError() << "\n";
            }

            sound.Load_Sound(renderer);

            sound.Play_Music();
        }
        else
        {
            cout << "Failed create renderer. Error: " << SDL_GetError() << "\n";
        }
    }
    else
    {
        cout << "Failed create window. Error: " << SDL_GetError() << "\n";
    }

    TTF_Init();

    font.Load_Font("font/lta.ttf", 48);

    font.Set_color_text(255, 255, 255);
}

void Gameloop::Update()
{
    if (menu.State_Press_Button(Menu::Play1) || menu.State_Press_Button(Menu::Restart1))
    {
        if (col.Bird_State())
        {
            ph.Update();

            ph.Gravity();

            f.frame();

            gr.Update();

            back.Update();

            col.get_PosBird(ph.get_dest1());

            col.get_PosGround(gr.get_ground_1());

            for (auto& pipe : pipe.get_pipe_pair())
            {
                if (!pipe.passed && pipe.topPipe.x < ph.get_dest1().x)
                {
                    pipe.passed = true;

                    sound.Play_Pass();

                    score++;
                }

                col.get_PosPipe(pipe.topPipe, pipe.bottomPipe);

                col.Handling();
            }

            pipe.Update();
        }
        else
        {
            ph.Bird_Die();

            menu.Button_Collision();
        }

        // test va chạm

        //    //cout << col.Bird_State() << "\n";

        //    //cout << menu.get_playState() << "\n";

        //    cout << score << "\n";

        //    if (!col.Bird_State())
        //    {
        //        //col.true_bird(); 
        //    }
    }
    else
    {
        menu.Button_Collision();

        back.Update();

        gr.Update();

        f.frame();
    }
}

void Gameloop::Event()
{
    SDL_PollEvent(&event1);
    if (event1.type == SDL_QUIT)
    {
        GameState = false;
    }

    if (menu.State_Press_Button(Menu::Play1) || menu.State_Press_Button(Menu::Restart1))
    {
        if (col.Bird_State())
        {
            const Uint8* KeyState = SDL_GetKeyboardState(nullptr);

            if (KeyState[SDL_SCANCODE_UP] || KeyState[SDL_SCANCODE_SPACE] || (event1.type == SDL_MOUSEBUTTONDOWN && event1.button.button == SDL_BUTTON_LEFT))
            {
                if (!ph.JumpState())
                {
                    ph.Jump();

                    sound.Play_Jump();
                }
                else
                {
                    ph.Gravity();
                }
            }
            else
            {
                ph.Gravity();
            }
        }
        else
        {
            if (!sound_die)
            {
                sound_die = true;

                sound.Play_Die();
            }

            if (event1.type == SDL_MOUSEBUTTONDOWN && event1.button.button == SDL_BUTTON_LEFT)
            {
                if (menu.State_In_Button(Menu::Restart1))
                {
                    Restart();
                }

                if (menu.State_In_Button(Menu::Back1))
                {
                    Back();
                }
            }
        }
    }
    else
    {
        if (event1.type == SDL_MOUSEBUTTONDOWN && event1.button.button == SDL_BUTTON_LEFT && !menu.State_Press_Button(Menu::Options1))
        {
            if (menu.State_In_Button(Menu::Quit1)) GameState = false;

            if (menu.State_In_Button(Menu::Play1) && !menu.State_Press_Button(Menu::Play1))
            {
                menu.Pressed_Button(Menu::Play1);

                back.Change_background();
            }

            if (menu.State_In_Button(Menu::Options1))
            {
                menu.Pressed_Button(Menu::Options1);

                back.Change_background();
            }

            if (menu.State_In_Button(Menu::Sound_Music1))
            {
                if (!menu.State_Press_Button(Menu::Sound_Music1))
                {
                    menu.Pressed_Button(Menu::Sound_Music1);

                    sound.Mute_Music();
                }
                else
                {
                    menu.UnPressed_Button(Menu::Sound_Music1);

                    sound.UnMute_Music();
                }
            }
        }
        else
        {
            if (event1.type == SDL_MOUSEBUTTONDOWN && event1.button.button == SDL_BUTTON_LEFT)
            {
                if (!menu.State_In_Button(Menu::Back3))
                {
                    ph.Change_Bird();
                }
                else
                {
                    Back();

                    menu.UnPressed_Button(Menu::Options1);
                }
            }
        }
    }
}

void Gameloop::Render()
{
    SDL_RenderClear(renderer);

    if ((menu.State_Press_Button(Menu::Play1) || menu.State_Press_Button(Menu::Restart1)) && !menu.State_Press_Button(Menu::Options1))
    {
        back.Render(renderer);

        pipe.Render(renderer);

        ph.Render1(renderer);

        gr.Render(renderer);

        score_text = to_string(score);

        best_score_text = to_string(best_score);

        if (!col.Bird_State())
        {
            Save_best_score();

            menu.Render2(renderer);

            font.Render(renderer, score_text, 350, 300);

            font.Render(renderer, best_score_text, 340, 370);
        }
        else
        {
            font.Render(renderer, score_text, 250, 20);
        }
    }
    else
    {
        back.Render(renderer);

        gr.Render(renderer);

        menu.Render1(renderer);
    }

    if (menu.State_Press_Button(Menu::Options1))
    {
        back.Render(renderer);

        gr.Render(renderer);

        menu.Render3(renderer);

        ph.Render2(renderer);
    }

    SDL_RenderPresent(renderer);
}

void Gameloop::Restart()
{
    back.Change_background();

    col.true_bird();

    pipe.Init_Pipes();

    ph.Reset();

    score = 0;

    sound_die = false;
}

void Gameloop::Back()
{
    back.Reset();

    col.true_bird();

    pipe.Init_Pipes();

    ph.Reset();

    menu.Reset();

    score = 0;

    sound_die = false;
}

void Gameloop::Load_best_score()
{
    ifstream file_in("Best_score.txt");

    if (file_in.is_open())
    {
        file_in >> best_score;

        file_in.close();
    }
}

void Gameloop::Save_best_score()
{
    if (score > best_score)
    {
        best_score = score;

        ofstream file_out("Best_score.txt");

        if (file_out.is_open())
        {
            file_out << best_score;

            file_out.close();
        }
    }
}

void Gameloop::Clear()
{
    SDL_DestroyRenderer(renderer);

    SDL_DestroyWindow(window);

    font.Clean();

    TTF_Quit();

    sound.Clean();
}