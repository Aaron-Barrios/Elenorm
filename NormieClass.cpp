#include <iostream>
#include <fstream>
#include <string>
#include <vector>   
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "NormieClass.h"
using namespace std;

NormieClass::NormieClass(){ //like all my other classes, this will set the default stats of the player/npc
    tribe = 5;
    health = 50;
    attack = 40;
    defense = 40;
    power = (health + attack + defense) / 3.0;
    setInitialStats(health, attack, defense);
}
NormieClass::NormieClass(string n, int h, int a, int d){
    tribe = 5;
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

int NormieClass::tsunami(){ //have to wait two turns to use this
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
int NormieClass::iceSpikes(){ //have to wait two turns to use this
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
int NormieClass::hose(){ // you can use this every turn
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

int NormieClass::firewall(){ //have to wait two turns to use this
    cout << getName() << " used Firewall!" << endl;
    int max = attack + 10;
    int min = attack + 5;

    damageStats[0] = max;
    damageStats[1] = min;

    //a range your attack can do, and a percentage of getting any value along that range
    srand(time(NULL));

    damageStats[2]  = rand() % (damageStats[0] - damageStats[1] + 1) + damageStats[1];

    return damageStats[2];

}

int NormieClass::lightningBolt(){ //have to wait two turns to use this
    cout << getName() << " used Lightning Bolt!" << endl;
    int max = attack + 5;
    int min = attack;

    damageStats2[0] = max;
    damageStats2[1] = min;

    //a range your attack can do, and a percentage of getting any value along that range
    srand(time(NULL));

    damageStats2[2] = rand() % (damageStats2[0] - damageStats2[1] + 1) + damageStats2[1];
    return damageStats2[2];
}

int NormieClass::fireball(){ //you can use this every turn
    cout << getName() << " used Fireball!" << endl;
    int max = attack + 5;
    int min = attack - 5;
    damageStats3[0] = max;
    damageStats3[1] = min;


    //a range your attack can do, and a percentage of getting any value along that range
    srand(time(NULL));

    damageStats3[2]  = rand() % (damageStats3[0] - damageStats3[1] + 1) + damageStats3[1];

    return damageStats3[2];
}

int NormieClass::theBoulder(){ //have to wait two turns to use this
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
int NormieClass::magmaBlast(){ //have to wait two turns to use this
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
int NormieClass::gauntlet(){ // you can use this every turn
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

int NormieClass::tornado(){ //have to wait two turns to use this
    cout << name << " used Tornado!" << endl;
    int max = attack + 10;
    int min = attack + 5;

    damageStats[0] = max;
    damageStats[1] = min;

    //a range your attack can do, and a percentage of getting any value along that range
    srand(time(NULL));

    damageStats[2]  = rand() % (damageStats[0] - damageStats[1] + 1) + damageStats[1];

    return damageStats[2];
}
int NormieClass::windWhip(){//have to wait two turns to use this
    cout << name << " used Windwhip!" << endl;
    int max = attack + 5;
    int min = attack;

    damageStats2[0] = max;
    damageStats2[1] = min;

    //a range your attack can do, and a percentage of getting any value along that range
    srand(time(NULL));

    damageStats2[2] = rand() % (damageStats2[0] - damageStats2[1] + 1) + damageStats2[1];
    return damageStats2[2];
}
int NormieClass::airBlast(){// you can use this every turn
    cout << name << " used Air Blast!" << endl;
    int max = attack + 5;
    int min = attack - 5;

    damageStats3[0] = max;
    damageStats3[1] = min;

    //a range your attack can do, and a percentage of getting any value along that range
    srand(time(NULL));

    damageStats3[2]  = rand() % (damageStats3[0] - damageStats3[1] + 1) + damageStats3[1];

    return damageStats3[2];
}
