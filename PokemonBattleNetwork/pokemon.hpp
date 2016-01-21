//
//  pokemon.hpp
//  AllegroGame
//
//  Created by Sasha Han on 1/20/16.
//
//

#ifndef pokemon_hpp
#define pokemon_hpp

#include <stdio.h>

#endif /* pokemon_hpp */
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
using namespace std;
class pokemon : public gameobject
{
public:
    pokemon(float iX, float iY, int iSize, float iDX, float iDY)
    {
     
        cout << "ERROR1";
    };
    pokemon()
    {
        cout << "ERROR2";
    };
    ~pokemon()
    {
        al_destroy_bitmap(b);
    };
    
    void collide(gameobject go);
    void update();
    void init();
    void draw();
    
    
private:
    int dx;
    int dy;
    ALLEGRO_BITMAP *b;
    int resetCount;
};