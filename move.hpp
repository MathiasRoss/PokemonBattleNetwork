//
//  move.hpp
//  AllegroGame
//
//  Created by Sasha Han on 1/20/16.
//
//

#ifndef move_hpp
#define move_hpp

#include <stdio.h>

#endif /* move_hpp */
#pragma once
#include <iostream>
#include "allegro5/allegro.h"
#include "allegro5/allegro_image.h"
//#include "allegro5/allegro_primitives.h"
#include "allegro5/allegro_font.h"
#include "allegro5/allegro_ttf.h"
#include "allegro5/allegro_audio.h"
#include "allegro5/allegro_acodec.h"
#include "globals.h"
#include "gameobject.hpp"
#include <typeinfo>
#include "animator.hpp"
#include "pokemon.hpp"
using namespace std;
class move : public gameobject
{
public:
    move(string n, float iY, int iSize, float iDX, float iDY)
    {
    };
    move()
    {
        isDead = false;
    };
    ~move()
    {
        al_destroy_bitmap(b);
    };
    
    void collide(gameobject go);
    virtual void update();
    void init(string n,pokemon * own, pokemon *op, int orient);
    virtual void draw();
    
    void parse(char * filename);
protected:
    bool isDead;
    int orientation;
    pokemon *owner;
    pokemon *opponent;
    animator anim;
    string name;
    int id;
    int evolveat;
    string evolveto;
    int hp,speed;
    int debuffs;
private:
    
    int dx;
    int dy;
    ALLEGRO_BITMAP *b;
    int resetCount;
};