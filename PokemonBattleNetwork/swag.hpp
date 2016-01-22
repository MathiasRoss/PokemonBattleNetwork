//
//  swag.hpp
//  AllegroGame
//
//  Created by Sasha Han on 1/20/16.
//
//

#ifndef swag_hpp
#define swag_hpp

#include <stdio.h>

#endif /* swag_hpp */
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
class swag : public gameobject
{
public:
    swag(string n, pokemon * own, pokemon *op, int orient)
    {
        init(n,own,op,orient);
    };
    swag()
    {
        isDead = false;
    };
    ~swag()
    {
        al_destroy_bitmap(b);
    };
    
    void collide(gameobject go);
    void update();
    void draw();
    
    void parse(char * filename);
protected:
    bool isDead;
    int orientation;
    pokemon *owner;
    pokemon *opponent;
    animator anim;
    string name;
    int id;
    vector<string> swags;
    vector<int> swaglevel;
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