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
       sound = Mix_loadWAV(path);
        
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
   



