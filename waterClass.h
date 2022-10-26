#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "playerClass.cpp"
using namespace std;
class waterClass: public playerClass{

private:
    string name;
    double power;
    double health;
    double attack;
    double defense;

    int upgrade;

    //what I use to make the range of damage in my attacks (seen later on)
    vector <int> damageStats = {-1,-1,-1};
    vector <int> damageStats2 = {-1,-1,-1};
    vector <int> damageStats3 =  {-1,-1,-1};

public:

    waterClass();
    waterClass(string n, int h, int a, int d);

    /*all these are my player's (and npcs) options for attack. The first two are "special" abiliites and can only be used once 
    per two turns, but they deal lots of damage depending on the opponets defense level, which will be implemented in a battle 
    class I'll be making shortly. They all return an int that's damage inflicted, and its from a range that I set later on. */

    int tsunami(); //this one will do more damage when defense > 0
    int iceSpikes();// this one will do more damage when defense == 0
    int hose(); //this is your basic attack
};