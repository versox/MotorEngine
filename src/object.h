/* 
 * File:   object.h
 * Author: mathp0455
 *
 * Created on June 1, 2017, 10:30 AM
 */

#ifndef OBJECT_H
#define	OBJECT_H
#include "Sprite.h"
#include "Game.h"
class object {
public:
    static object* getObject(int objectID);
    static void updateObjects();
private:
    
public:
    object(Game* window, Sprite* sprite, int xPos, int yPos, int size=1);
    object(const object& orig);
    virtual ~object();
    int getID();
    int xPos, yPos;
private:
    Sprite* sprite;
    int objID;
    int size;
    int width, height;
    bool visible;
protected:
    Game* window;
};

#endif	/* OBJECT_H */

