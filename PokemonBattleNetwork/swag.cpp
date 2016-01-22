//
//  swag.cpp
//  AllegroGame
//
//  Created by Sasha Han on 1/20/16.
//
//

#include "swag.hpp"

using namespace std;
void swag::collide(gameobject go)
{
}

void swag::update()
{
    anim.update();
}
void swag::draw()
{
    anim.draw(x,y);
}

void swag::parse(char * filename)
{
    int doesEvolve,numswags;
    cout << "hi";
    ifstream myfile;
    
    myfile.open(filename);
    string file_line;
    getline(myfile,file_line);
    stringstream fl(file_line);
    fl >> name;
    fl >> id;
    fl >> numswags;
    fl >> doesEvolve;
    cout << "\n";
    cout << name << numswags << doesEvolve;
    for (int i = 0; i < numswags; i++)
    {
        
        getline(myfile, file_line);
        istringstream is( file_line );
        
        string j;
        is >> j;
        swags.push_back(j);
        int k;
        is >> k;
        swaglevel.push_back(k);
        cout << "\n" << j;
    }
    if (doesEvolve)
    {
        getline(myfile, file_line);
        istringstream is( file_line );
        is >> evolveto;
        is >> evolveat;
    }
    else
    {
        evolveto = "";
        evolveat = 101;
    }
    //current line of text is in file_line, not including the \n
    myfile.close();
}
