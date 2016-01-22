//
//  Factory.hpp
//  AllegroGame
//
//  Created by Sasha Han on 1/20/16.
//
//

#ifndef Factory_hpp
#define Factory_hpp

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
#endif /* Factory_hpp */
//
//  Factory.cpp
//  AllegroGame
//
//  Created by Sasha Han on 1/20/16.
//
//



#include "pokemon.hpp"
#include "treeko.hpp"
#include "megaman.hpp"
#include "Factory.hpp"
enum pokeIDS { NONE,TREEKO,MEGAMAN };




class PokemonFactory
{
public:
    pokemon *Create(pokeIDS pokeID, string a, float b, int c, float d, float e)
    {
        if (pokeID == TREEKO)
            return new treeko(a,b,c,d,e);
        else if (pokeID == MEGAMAN)
            return new megaman(a,b,c,d,e);
        else
            return NULL;
        // else if (shape == TRIANGLE)
        //     return new Triangle;
    }
};