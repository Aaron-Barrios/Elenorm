#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "playerClass.cpp"
using namespace std;

class fireClass: public playerClass{

private:
    string name;
    double power;
    int health;
    int attack;
    int defense;

    int upgrade;

    vector <int> damageStats = {-1,-1,-1};
    vector <int> damageStats2 = {-1,-1,-1};
    vector <int> damageStats3 =  {-1,-1,-1};

public:

    fireClass();
    fireClass(string n, int h, int a, int d);

    /*all these are my player's (and npcs) options for attack. The first two are "special" abiliites and can only be used once 
    per two turns, but they deal lots of damage depending on the opponets defense level, which will be implemented in a battle 
    class I'll be making shortly. They all return an int that's damage inflicted, and its from a range that I set later on. */

    int firewall(); //this one will do more damage when defense > 0
    int lightningBolt(); // this one will do more damage when defense == 0
    int fireball(); //this is your basic attack

};