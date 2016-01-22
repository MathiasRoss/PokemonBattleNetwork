//
//  move.cpp
//  AllegroGame
//
//  Created by Sasha Han on 1/20/16.
//
//

#include "move.hpp"

using namespace std;
void move::collide(gameobject go)
{
}
/*
void move::update()
{
 //   anim.update();
}
void move::draw()
{
    anim.draw(x,y);
}*/
void move::init(string n,pokemon * own, pokemon *op, int orient)
{
    name = n;
    owner = own;
    opponent = op;
    orientation = orient;
    string temSS = n+"ss";
    char * ssImg = (char *)(temSS + ".png").c_str();
    char * ssDesc = (char *)(temSS + ".txt").c_str();
    anim = *new animator(ssImg,ssDesc);
}
void move::parse(char * filename)
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
