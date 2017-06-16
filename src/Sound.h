/*
 * File:   Sound.h
 * Author: browr3317
 *
 * Created on June 9, 2017, 10:18 AM
 */

#ifndef SOUND_H
#define	SOUND_H
#include "SDL_mixer.h"
#include <string>
#include <iostream>

class Sound{

public:

    Sound(std::string path);
    void playSound();
    virtual ~Sound();
private:
    Mix_Chunk* sound; //insert sound type here instead of "sound" (e.g. hit, shot, impact, etc)
};


#endif	/* SOUND_H */
