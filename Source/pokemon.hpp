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
#include "animator.hpp"

class pokemon : public gameobject
{
public:
    pokemon(std::string n, float iY, int iSize, float iDX, float iDY)
    {
		std::cout << "Started pokemon creation\n";
        name = n;
    //  std::cout << n;
        n+=".txt";
        char * tem = (char *)n.c_str();
        parse(tem);
		std::cout << "parsed\n";
        std::string temSS = name+"ss";

		std::string temSStxt = temSS + ".txt";
		std::string temSSpng = temSS + ".png";

        char * ssImg = (char *)temSSpng.c_str();
        char * ssDesc = (char *)temSStxt.c_str();
		std::cout << ssDesc << "\n";




        anim = *new animator(ssImg,ssDesc);
		//anim = *new animator(ssImg,"treekoss.txt");
		std::cout << "animator loaded";
        hp = 100;
    };
    pokemon()
    {
    //  std::cout << "ERROR2";
    };
    ~pokemon()
    {
        al_destroy_bitmap(b);
    };
    
    void collide(gameobject *go);
    void update();
    void init();
    void draw();
    
    void parse(char * filename);
    
    
    int hp,speed;
    int debuffs;
    animator anim;
protected:
    
    std::string name;
    int id;
    std::vector<std::string> moves;
    std::vector<int> movelevel;
    int evolveat;
    std::string evolveto;

private:

    int dx;
    int dy;
    ALLEGRO_BITMAP *b;
    int resetCount;
};