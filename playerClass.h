#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#ifndef PLAYERCLASS_H
#define PLAYERCLASS_H
#include "randMaker.h"
using namespace std;

class playerClass{

protected:
    randMaker rows = randMaker(2,6);
    randMaker colls = randMaker(5, 8);
    randMaker moves = randMaker(1,3);
    bool hasCool;
    string name;
    int power;
    int health;
    int attack;
    int defense;
    bool deja;

    int upgrade;
    int randomvalue;
    int tribe;
    vector<int> playerInfo = {-1,-1,-1};
    vector<randMaker> randomPositions = {rows, colls, moves};  
    int numShopVisits;
    int deathCount;
    int masteryPts;

    vector<int> befStats;

public:
    playerClass();
    playerClass(string n, int t);

    string getTribe();
    int getTribeNum();
    void setTribe(int t);
    string getName();
    void setName(string N);
    int getPower();
    void setPower(int P);
    int getHealth();
    void setHealth(int H);
    int getAttack();
    void setAttack(int A);
    int getDefense();
    void setDefense(int D);
    void damage(int dam);
    void displayStats();
    void defenseDown();
    void readFile(string filename, int begin, int end);
    void readFileFrom(int region, bool isBoss, string filename);
    void readNPC(int region, bool isFarther);
    void addShopVisit();
    int getNumShopVisits();
    void setInfo(string na, int he, int at, int de);
    void addDie();
    int getDeaths();
    vector<int> displayShopItems(int region);
    void addmasteryPts(int num);
    int getmasteryPts();
    int makeRandNums(int position);
    void makeCool(bool choice);
    bool isCool();
    string getRegion(int i);

    void setInitialStats(int h, int a, int d);
    vector<int> getInitialStats();
    int getInitialStatsAt(int place);

};
#endif