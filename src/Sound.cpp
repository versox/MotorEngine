/*
 * File:   Sound.cpp
 * Author: browr3317
 *
 * Created on June 9, 2017, 10:18 AM
 */

#include <cstdlib>
#include "Sound.h"

using namespace std;


Sound::Sound(std::string path){


    //loading
       sound = Mix_LoadWAV(path.c_str());
        if((sound = NULL)){
        return false;
        }       
 // if everything loaded fine   
       return true;
}

   Sound::~Sound()
   {
   //Free
       Mix_FreeChunk(sound);
   }

    void Sound::playSound()
    {
    //play it
        Mix_PlayChannel(-1,sound,0);
    }
