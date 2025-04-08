#pragma once
#include <iostream>
#include <SDL.h>
#include <SDL_mixer.h>

using namespace std;

class Sound
{
private:

    Mix_Chunk* sound_jump;

    Mix_Chunk* die_sound;

    Mix_Chunk* pass_sound;

    Mix_Music* Music;

    bool isMuted;

public:

    Sound();

    void Load_Sound(SDL_Renderer* ren);

    void Play_Jump();

    void Play_Die();

    void Play_Pass();

    void Play_Music();

    void Mute_Music();

    void UnMute_Music();

    void Clean();

};