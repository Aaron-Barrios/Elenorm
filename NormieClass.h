#include <iostream>
#include <fstream>
#include <string>
#include <vector>   
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "playerClass.cpp"
using namespace std;

class NormieClass: public playerClass{
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

    NormieClass();
    NormieClass(string n, int h, int a, int d);


    int tsunami(); //this one will do more damage when defense > 0
    int iceSpikes();// this one will do more damage when defense == 0
    int hose(); //this is your basic attack

    int firewall(); //this one will do more damage when defense > 0
    int lightningBolt(); // this one will do more damage when defense == 0
    int fireball(); //this is your basic attack

    int theBoulder(); //this one will do more damage when defense > 0
    int magmaBlast(); // this one will do more damage when defense == 0
    int gauntlet(); //this is your basic attack

    int tornado();  //this one will do more damage when defense > 0
    int windWhip(); // this one will do more damage when defense == 0
    int airBlast(); //this is your basic attack
};


