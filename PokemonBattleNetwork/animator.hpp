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
#include <string>
#include <fstream>
#include <sstream>

#include <vector>

using namespace std;
class animator : public gameobject
{
public:
    animator(char * bitmapName,char * spritesheetName)
    {
        b = al_load_bitmap(bitmapName);
        animationFrame = 0;
        nextAnimation = 0;
        currentAnimation = 0;
        resetCount = 0;
        parse(spritesheetName);
    
    
    };
    ~animator()
    {
        al_destroy_bitmap(b);
    };
    void parse(char * ssName);
    void switchAnimations(int animationNumber);
    void update();
    
    void draw();
    
    
private:
    ALLEGRO_BITMAP *b;
    int animationFrame;
    int nextAnimation;
    
    vector<int> speed;
    vector<int> numFrames;
    vector<int> x;
    vector<int> y;
    
    int currentAnimation;
    int numAnimations;
    int height;
    int width;
    int resetCount;
};