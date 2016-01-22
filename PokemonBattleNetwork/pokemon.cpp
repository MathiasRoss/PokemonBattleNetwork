//
//  pokemon.cpp
//  AllegroGame
//
//  Created by Sasha Han on 1/20/16.
//
//

#include "pokemon.hpp"

using namespace std;
void pokemon::collide(gameobject go)
{
}

void pokemon::update()
{
    anim.update();
}
void pokemon::draw()
{
    anim.draw(x,y);
}
void pokemon::init()
{
    
}
void pokemon::parse(char * filename)
{
    int doesEvolve,numMoves;
    cout << "hi";
    ifstream myfile;
    
    myfile.open(filename);
    string file_line;
    getline(myfile,file_line);
    stringstream fl(file_line);
    fl >> name;
    fl >> id;
    fl >> numMoves;
    fl >> doesEvolve;
    cout << "\n";
    cout << name << numMoves << doesEvolve;
    for (int i = 0; i < numMoves; i++)
    {
    
        getline(myfile, file_line);
        istringstream is( file_line );
        
        string j;
        is >> j;
        moves.push_back(j);
        int k;
        is >> k;
        movelevel.push_back(k);
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
