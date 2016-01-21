//
//  animator.cpp
//  AllegroGame
//
//  Created by Sasha Han on 1/12/16.
//
//

#include "animator.hpp"
using namespace std;

void animator::update()
{
  
    if (resetCount == 0)
    {
        resetCount = speed[currentAnimation];
        if (animationFrame == numFrames[currentAnimation])
        {
            if (nextAnimation != 0)
            {
                currentAnimation = nextAnimation;
                animationFrame = 0;
                nextAnimation = 0;
            }
            animationFrame = 0;
            currentAnimation = 0;
        }
        else
        {
            
            animationFrame++;
        }
    }
    else
    {
        resetCount--;
    }
}
void animator::switchAnimations(int animationNumber)
{//rework with moves
    if (nextAnimation != 0)
        return;
    if (currentAnimation == 0)
    {
        currentAnimation = animationNumber;
        animationFrame = 0;
    }
    else
    {
        nextAnimation = animationNumber;
    }
}
void animator::draw()
{
    al_draw_bitmap_region(b, x[currentAnimation]+(width+10)*animationFrame, y[currentAnimation], width, height, 100, 100, 0);
//    al_draw_bitmap(b, x, y, 0);
}
void animator::parse(char * ssName)
{
    cout << "hi";
    ifstream myfile;
    
    myfile.open(ssName);
    string file_line;
    getline(myfile,file_line);
    stringstream fl(file_line);
    fl >> numAnimations;
    fl >> width;
    fl >> height;
    cout << width << height << numAnimations;
    while(std::getline(myfile, file_line))
    {
       
        
        std::istringstream is( file_line );
        int n;
        is >> n;
        speed.push_back(n);
        is >> n;
        numFrames.push_back(n);
        is >> n;
        x.push_back(n);
        is >> n;
        y.push_back(n);
        
        //current line of text is in file_line, not including the \n
    }
    resetCount = speed[0];
}
