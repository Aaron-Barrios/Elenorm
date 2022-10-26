#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "randMaker.h"
using namespace std;
#ifndef PLAYERCLASS_H
#define PLAYERCLASS_H
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

//player class implementations

playerClass::playerClass(){//default constructor
    name = "Joe Mama"; //funny and it helps debugging
    numShopVisits = 0;
    deathCount = 0;
    masteryPts = 0;
    hasCool = false;
    deja = false;

}
playerClass::playerClass(string n, int t){ //paramaterized constructor
    name = n;
    tribe = t;
    numShopVisits = 0;
    deathCount = 0;
    masteryPts = 0;
    hasCool = false;
    deja = false;
}
string playerClass::getName(){
    return name;
}
void playerClass::setName(string N){
    name = N;
}
int playerClass::getPower(){
    power = (health + attack + defense) / 3.0;
    return power;
}
void playerClass::setPower(int P){
    power = P;
}
int playerClass::getHealth(){
    return health;
}
void playerClass::setHealth(int H){
    health = H;
    playerInfo[0] = H;
}
int playerClass::getAttack(){
    return attack;
}
void playerClass::setAttack(int A){
    attack = A;
    playerInfo[1] = A;
}
int playerClass::getDefense(){
    return defense;
}
void playerClass::setDefense(int D){
    defense = D;
    playerInfo[2] = D;
}
string playerClass::getTribe(){ //gets the players tribe
    if(tribe == 1){
        return "Water Tribe";
    }
    else if(tribe == 2){
        return "Fire Nation";
    }
    else if(tribe == 3){
        return "Earth Kingdom";
    }
    else if(tribe == 4){
        return "Air Nomads";
    }
    return "error";
}
int playerClass::getTribeNum(){
    return tribe;
}

void playerClass::setTribe(int t){
    tribe = t;
}
void playerClass::damage(int dam){
    // cout << endl << "previous health: " << health << endl;
    // cout << "previous defense: " << defense << endl << endl;
    int leftOver = 0;
    if(defense > dam){
        defense = defense - dam;
    }
    else if(defense == dam){
        defense = 0;
    }
    else{
        leftOver = dam - defense;
        defense = 0;
        health = health - leftOver;
        if(health <= 0){
            health = 0;
        }
    }
    // cout << endl << "health from class: " << health << endl;
    // cout << "defense from class: " << defense << endl << endl;
}
void playerClass::displayStats(){
    cout << "Health: " << health << endl;
    cout << "Attack: " << attack << endl;
    cout << "Defense: " << defense << endl;
    cout << "Power: " << getPower() << endl;
}
void playerClass::defenseDown(){
    if(defense == 0){
        cout << name << "'s defense has been broken!" << endl;
    }
    else{
        cout << "Their shield is still up!" << endl;
    }
}
void playerClass::readFile(string filename, int begin, int end){
    ifstream file;
    string buffer = "";
    string skip1;
    char skip;
    file.open(filename);
    bool contin = false;
    int choice = 0;
    cout << "Would you like to skip dialogue? y/n" << endl;
    cin >> skip1;
    if(skip1[0] == 'n'){
        if(file.fail()){
            cout << "Unable to read file" << endl;
        }
        else{
            for(int i = 0; i < begin; i++){
                getline(file, buffer);
            }
            cout << endl;
            cout << "*********************************" << endl;
            for(int i = begin; i <= end; i++){
                getline(file, buffer);
                cout << buffer << endl;
            }
            cout << "*********************************" << endl;
            cout << endl;
        }

    }
    else{
        if(skip1[0] == 'y'){
            cout << "Dude. Uncool" << endl;
        }
        else{
            cout << "You entered the wrong thing so now you won't get the story." << endl;
        }
    }
    
}
void playerClass::readFileFrom(int region, bool isBoss, string filename){
    switch (region){
    case 1:
        if(isBoss == true){
            readFile(filename, 10, 16);
        }
        else{
            readFile(filename, 3, 7);
        }
        break;
    
    case 2: 
        if(isBoss == true){
            readFile(filename, 29, 39);
        }
        else{
            readFile(filename, 19, 26);
        }
        break;

    case 3: 

        if(isBoss == true){
            readFile(filename, 50, 64);
        }
        else{
            readFile(filename, 44, 47);
        }
        break;

    case 4: 
        if(isBoss == true){
            readFile(filename, 81, 92);
        }
        else{
            readFile(filename, 69, 78);
        }
        break;
    
    case 5: 
        readFile(filename, 96, 127);
    default:
        // cout << "error" << endl;
        break;
    }
}
void playerClass::readNPC(int region, bool isFarther){
    string filename = "NPC_Talks.txt";
    switch (region){
    case 1:
        if(isFarther == true){
            readFile(filename, 6, 22);
        }
        else{
            readFile(filename, 25, 29);
        }
        break;
    
    case 2: 
        if(isFarther == true){
            readFile(filename, 34, 45);
        }
        else{
            readFile(filename, 48, 52);
        }
        break;

    case 3: 

        if(isFarther == true){
            readFile(filename, 57, 67);
        }
        else{
            readFile(filename, 70, 74);
        }
        break;

    case 4: 
        if(isFarther == true){
            readFile(filename, 78, 87);
        }
        else{
            readFile(filename, 90, 93);
        }
        break;
    
    default:
        break;
    }
}
void playerClass::addShopVisit(){
    numShopVisits++;
}
int playerClass::getNumShopVisits(){
    return numShopVisits;
}
void playerClass::setInfo(string na, int he, int at, int de){
    name = na;
    health = he;
    attack = at;
    defense = de;
    power = (health + attack + defense) / 3.0;
}
void playerClass::addDie(){
    deathCount++;
}
int playerClass::getDeaths(){
    return deathCount;
}
vector<int> playerClass::displayShopItems(int region){ //add something that tells you the price and effects of it 
    //also add something in this class that allows you to have a secret ability later on with enough points
    string item1 = "";
    string item2 = "";
    string item3 = "";
    char option = 0;
    int price = 0;
    int addAttack = 0;
    int addDefense = 0;
    vector<int> result;
    switch (region){
    case 1:
        item1 = "Blubbered Sea Jerkey";
        item2 = "Two-Headed Fish Soup";
        item3 = "Artic Hen";
        break;
    case 2:
        item1 = "Komodo Chicken";
        item2 = "Stick on a stick";
        item3 = "Hotcakes";

    case 3:
        item1 = "Egg custard tart";
        item2 = "Cabbage soup";
        item3 = "Cactus Juice";
    case 4:
        item1 = "Dumplings";
        item2 = "Macaroons";
        item3 = "Tofu and Bean Sprouts";
    default: 
        break;
    }
    cout << "For a taste of our nutritious- and delicious!- cuisine, we have these to offer: " << endl;
    cout << "1. $ " << item1 << endl << "2. $ " << item2 << endl << "3. $$ " << item3 << endl;
    if(numShopVisits > 0){
        cout << "We also have some scrolls to upgrade/replenish your abilities!" << endl;
        cout << "4. $$$ Scroll of Ferocity" << endl << "5. $$ Scroll of impermeability rejuvination" << endl;
    }
    if(numShopVisits == 0){
        cout << endl;
        cout << "Seeing as how it's your first time, your purchase is on the house!" << endl;
        cout << "Just remember that from now on, you'll need your mastery points to buy anything here." << endl;
        cout << "You: So how do I get that?" << endl;
        cout << "Shopkeeper: Your mastery points increase whenever you win a battle. The higher power your opponent is, " << endl;
        cout << "the more points you get. You also get them passively every turn" << endl;
        cout << "*Leans in a little closer* But if you help clean up the riffraff here, I'll " << endl;
        cout << "give ya some more. " << endl;
        cout << "You: What riffraff? " << endl; 
        cout << "Oh just some punks trying to take advantage of the less-than-stellar Tribal law enforcement." << endl;
        cout << "They'll be somewhere around, you just gotta do some 'xplorin. Take care of them, and " <<endl;
        cout << "you'll earn yourself some extra 'points' with me! " << endl;
        cout << "The promise of extra points is just barely enough for you to nodd through the pain of that joke." << endl;
        cout << endl;
    }
    cout << "If you don't want to buy anything, simply press 'n'" << endl;
    int addHealth = 0;
    bool lesGoOn = false;
    string option1 = "";
    cout << endl;
    if(option == 'n'){
        cout << "That's all right, maybe next time." << endl;
        vector<int> out = {-1};
        return out;
    }
    while(lesGoOn != true){
        cout << "Now, what'll you have?" << endl;
        option1 = "";
        cin >> option1;
        if(option1.size() > 1){
            cout << "Sorry, only heard the first part of that, hopefully the rest wasn't too important!" << endl;
        }
        option = option1[0];
        if(option == '1'){
            addHealth += 35;
            price += 10;
        }
        else if(option == '2'){
            addHealth += 25;
            price += 5;
        }
        else if(option == '3'){
            addHealth += 45;
            price += 30;
        }
        else if(option == '4'){
            addAttack += 30;
            price += 35;
        }
        else if(option == '5'){
            addDefense = 45;
            price = 15; 
        }
        else if(option == '*'){
            if(deja == false){
                cout << "Achiviement aquired: Wait that actually worked?" << endl << endl;
                cout << "Congrats- you now have a melon!" << endl;
                cout << "If you press * when in the menu, your health will be doubled!" << endl;
                cout << "But be careful. You can only use it once, and if you health is low, it won't be the boost you wanted." << endl;
                cout << endl;
                deja = true;
                hasCool = true;
            }
            else{
                cout << "Sorry bub, some things only come once a lifetime..." << endl;
            }
        }
        else if(option == 'n'){
            lesGoOn = true;
            continue;
        }
        else{
            cout << "My apolgies, but the store's busy, don't have time for a chit-chat. " << endl;
            price = -1;
            lesGoOn = true;
            continue;
        }
        if(numShopVisits == 0){
            price = 0;
            lesGoOn = true;
            continue;
        }
        if(price > masteryPts){
            cout << "Ooof, sorry player. Don't have enough for that." << endl;
            cout << "My memory's not all that good, but if you bought anything before, it'll register in your stats!" << endl;
            
            result = {addHealth, addAttack, addDefense};;
            return result;
        }
        else{
            masteryPts -= price;
        }
        
        cout << "Got it- will that be all?" << endl;
        option1 = "";
        cin >> option1;
        option = option1[0];
        if(option == 'y'){
            lesGoOn = true;
        }
        else if(option == 'n'){
            lesGoOn = false;
        }
        else{
            cout << "What was that? Yes? Great!" << endl;
            lesGoOn = false;
        }
    }
    if(price >= 0){
        cout << "Pleasure doing business with you!" << endl;
    }
    else{
        cout << "Maybe next time we can talk" << endl;
    }
    result = {addHealth, addAttack, addDefense};
    numShopVisits++;
    return result;
}
void playerClass::addmasteryPts(int num){
    masteryPts += num;
}
int playerClass::getmasteryPts(){
    return masteryPts;
}  
int playerClass::makeRandNums(int position){
    int result = -1;
    if(position < 0 || position > 3){
        return -1;
    }
    result = randomPositions.at(position).getRandNum();
    return result;
}
void playerClass::makeCool(bool choice){
    if(choice == true){
        hasCool = true;
    }
    else{
        hasCool = false;
    }
}
bool playerClass::isCool(){
    return hasCool;
}
void playerClass::setInitialStats(int h, int a, int d){
    befStats.push_back(h);
    befStats.push_back(a);
    befStats.push_back(d);
    befStats.push_back( (h + a + d) / 3.0 );
}
vector<int> playerClass::getInitialStats(){
    return befStats;
}
int playerClass::getInitialStatsAt(int place){
    return befStats[place];
}
string playerClass::getRegion(int i){
    if(i == 1){
        return "Wateree";
    }
    else if(i == 2){
        return "the Fire Nation";
    }
    else if(i == 3){
        return "the Earth Kingdom";
    }
    else if(i == 4){
        return "the Air Temples";
    }
    return "error";
}
#endif