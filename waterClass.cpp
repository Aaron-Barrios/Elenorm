#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "waterClass.h"
using namespace std;
//waterClass implementation

waterClass::waterClass(){ //like all my other classes, this will set the default stats of the player/npc
    tribe = 1;
    health = 35;
    attack = 30;
    defense = 30;
    power = (health + attack + defense) / 3.0;
    setInitialStats(health, attack, defense);
    upgrade = 0;
    randomvalue = 0;
}
waterClass::waterClass(string n, int h, int a, int d){
    tribe = 1;
    name = n;
    health = h;
    attack = a;
    defense = d;
    power = (health + attack + defense) / 3.0;
    setTribe(tribe);
    setName(n);
    setHealth(h);
    setAttack(a);
    setDefense(d);
    setPower(power);
    setInitialStats(h, a, d);

}
//the following three are waterClass's attacks, identical to the other three classes' attacks but in name
int waterClass::tsunami(){ //have to wait two turns to use this
    cout << getName() << " used Tsunami!" << endl;
    int max = attack + 10;
    int min = attack + 5;

    damageStats[0] = max;
    damageStats[1] = min;

    //a range your attack can do, and a percentage of getting any value along that range
    srand(time(NULL));

    damageStats[2]  = rand() % (damageStats[0] - damageStats[1] + 1) + damageStats[1];

    return damageStats[2];
}
int waterClass::iceSpikes(){ //have to wait two turns to use this
    cout << getName() << " used Ice Spikes!" << endl;
    int max = attack + 5;
    int min = attack;

    damageStats2[0] = max;
    damageStats2[1] = min;

    //a range your attack can do, and a percentage of getting any value along that range
    srand(time(NULL));

    damageStats2[2] = rand() % (damageStats2[0] - damageStats2[1] + 1) + damageStats2[1];
    return damageStats2[2];
}
int waterClass::hose(){ // you can use this every turn
    cout << getName() << " used Hose!" << endl;
    int max = attack + 5;
    int min = attack - 5;

    damageStats3[0] = max;
    damageStats3[1] = min;

    //a range your attack can do, and a percentage of getting any value along that range
    srand(time(NULL));

    damageStats3[2]  = rand() % (damageStats3[0] - damageStats3[1] + 1) + damageStats3[1];

    return damageStats3[2];

}