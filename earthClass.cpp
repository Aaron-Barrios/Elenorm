#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "earthClass.h"
using namespace std;

//earthClass implementation

earthClass::earthClass(){
    health = 80;
    attack = 60;
    defense = 80;
    power = (health + attack + power) / 3.0;
    upgrade = 0;
    randomvalue = 0;
    setInitialStats(health, attack, defense);
}

earthClass::earthClass(string n, int h, int a, int d){
    tribe = 3;
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

    upgrade = 0;
    randomvalue = 0;
}

int earthClass::theBoulder(){ //have to wait two turns to use this
    cout << getName() << " used The Boulder!" << endl;
    int max = attack + 10;
    int min = attack + 5;

    damageStats[0] = max;
    damageStats[1] = min;

    //a range your attack can do, and a percentage of getting any value along that range
    srand(time(NULL));

    damageStats[2]  = rand() % (damageStats[0] - damageStats[1] + 1) + damageStats[1];

    return damageStats[2];
}
int earthClass::magmaBlast(){ //have to wait two turns to use this
    cout << getName() << " used Magma Blast!" << endl;
    int max = attack + 5;
    int min = attack;

    damageStats2[0] = max;
    damageStats2[1] = min;

    //a range your attack can do, and a percentage of getting any value along that range
    srand(time(NULL));

    damageStats2[2] = rand() % (damageStats2[0] - damageStats2[1] + 1) + damageStats2[1];
    return damageStats2[2];
}
int earthClass::gauntlet(){ // you can use this every turn
    cout << getName() << " used Earth Gauntlet!" << endl;
    int max = attack + 5;
    int min = attack - 5;

    damageStats3[0] = max;
    damageStats3[1] = min;

    //a range your attack can do, and a percentage of getting any value along that range
    srand(time(NULL));

    damageStats3[2]  = rand() % (damageStats3[0] - damageStats3[1] + 1) + damageStats3[1];

    return damageStats3[2]; 
}