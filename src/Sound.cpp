#include "Sound.h"
#include "TextureManager.h"

Sound::Sound()
{
	
}

void Sound::Load_Sound(SDL_Renderer* ren)
{
    // load

    sound_jump = Mix_LoadWAV("sounds/Jump.wav");

    die_sound = Mix_LoadWAV("sounds/Die.mp3");

    pass_sound = Mix_LoadWAV("sounds/Pass.mp3");

    Music = Mix_LoadMUS("sounds/Music.mp3");

    // chỉnh âm lượng

    Mix_VolumeMusic(64);

    // if

    if (!sound_jump) cout << "Failed to load jump sound.Error: " << Mix_GetError() << "\n";

    if (!die_sound) cout << "Failed to load hit sound.Error: " << Mix_GetError() << "\n";

    if (!pass_sound) cout << "Failed to load hit sound.Error: " << Mix_GetError() << "\n";

    if (!Music) cout << "Failed to load music.Error: " << Mix_GetError() << "\n";
}

void Sound::Play_Jump()
{
    if (!isMuted && sound_jump) Mix_PlayChannel(-1, sound_jump, 0);
}

void Sound::Play_Die()
{
    if (!isMuted && die_sound) Mix_PlayChannel(-1, die_sound, 0);
}

void Sound::Play_Pass()
{
    if (!isMuted && pass_sound) Mix_PlayChannel(-1, pass_sound, 0);
}

void Sound::Play_Music()
{
    if (!isMuted && Music) Mix_PlayMusic(Music, -1);
}

void Sound::Mute_Music()
{
    Mix_VolumeMusic(0);
}

void Sound::UnMute_Music()
{
    Mix_VolumeMusic(64);
}

void Sound::Clean()
{
    Mix_FreeChunk(sound_jump);
    Mix_FreeChunk(die_sound);
    Mix_FreeMusic(Music);
}