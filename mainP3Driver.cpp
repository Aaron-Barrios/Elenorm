#include <iostream>
#include <fstream>
#include <string>
#include <vector>   
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "waterClass.cpp"
#include "fireClass.cpp"
#include "earthClass.cpp"
#include "airClass.cpp"
#include "NormieClass.cpp"
#include "Map.cpp"
using namespace std;


/*Each segment of this game will follow the same format:
There will be/is a begin function, then I will add another function that will be the main function 
used for the game (it will be the menu options and make use of the Map class), as well as an end class- 
and anything in between. Between submitting this code skeleton and the due date, there will be most likely
more functions/helper functions, as well as a combat class (still unsure if I have to do a whole class or 
just a function but the former's the current plan).*/

//I need to declare four seperate players, because you cannot declare a 
//person of class playerClass in an if statment and then use it later on

//declerations:
playerClass P1 = playerClass();

//water
waterClass PlayerA = waterClass("Joe mama", 45, 30, 35); 

waterClass NPC1 = waterClass("Archibald", 35, 35, 40);//these should all be fixed

//fire
fireClass PlayerB = fireClass("Joe mama", 45, 40, 25);

fireClass NPC2 = fireClass("Quentin", 35, 40, 40);

//earth
earthClass PlayerC = earthClass("Joe mama", 45, 25, 40);

earthClass NPC3 = earthClass("Genevieve", 35, 40, 40);

//air
airClass PlayerD = airClass("Joe mama", 45, 35, 30);

airClass NPC4 = airClass("Joe", 40, 40, 35);

NormieClass Dagon = NormieClass("King Dagon", 35, 65, 100);

vector<playerClass> defeatedPeeps;


void begin(string& name, string& tribeName);
string setTribe(int& choice, string Pname);
void introduction(string name);
void test();
void mainP3(int region);
string attack(bool isPlayer, int pInfo, int region, int moveNum);
bool battleTime(bool isRival, int region);
void shop(int region);
int finalBoss();
void writeDefeatedToFile();

int main(){
    string name = "";
    string tribeName = "";
    begin(name, tribeName);
    introduction(name);
    for(int i = 1; i < 5; i++){ //handles every single region
        mainP3(i);
        if(P1.getDeaths() == 3){
            cout << "Better luck next time...." << endl;
            return -1;
        }
        else{
            switch (i){
            case 1:
                P1.readFile("endOfRegion.txt", 0, 4);
                break;
            case 2:
                P1.readFile("endOfRegion.txt", 5, 10);
                break;
            case 3:
                P1.readFile("endOfRegion.txt", 11, 17);
                break;
            case 4:
                P1.readFile("endOfRegion.txt", 18, 26);
                break;
            default:
                break;
            }
        }
    }
    //here on out is the boss battle and the end of the game
    int result = 0;
    while(result == 0){
        result = finalBoss();
        if(result == -1){
            cout << endl << endl << "And you were so close....." << endl;
            cout << "Game. Over." << endl;
            return -1;
        }   
        else if(result == 2){
            cout << "You've got one more chance... use it wisely" << endl;
            cout << endl << "Here's access to the shop" << endl;
            cout << endl;
            shop(4);
            result = 0;
        }
        else if(result == 1){
            writeDefeatedToFile(); //writing to a file function
            string ans;
            cout << endl << "You defeated King Dagon, and have brought peace to the Island!" << endl;
            cout << "Well, until the sequel. But for now, the people thank you." << endl;
            cout << "And I, well I congratulate you for making it all the way through." << endl;
            cout << "I would display a whole credits page, but it's just all me, and I don't wanna type all that" << endl;
            cout << "Anyways, thanks for playing!" << endl;
            cout << endl << "Would you like to display all the people you've defeated? y/n" << endl;
            bool got = false;
            while(got != true){
                cin >> ans;
                if(ans == "y" || ans == "n"){
                    got = true;
                }
                else{
                    cout << "You must be tired from the fight. I'll give ya another chance." << endl;
                }
            }
            if(ans == "y"){
                for(int i = 0; i < defeatedPeeps.size(); i++){
                    cout << defeatedPeeps[i].getName() << "'s stats: " << endl;
                    for(int j = 0; j < 3; j++){
                        cout << defeatedPeeps[i].getInitialStatsAt(j) << ", ";
                    }
                    cout << defeatedPeeps[i].getInitialStatsAt(3) << endl;
                    cout << endl;
                }
                if(defeatedPeeps.size() == 5){
                    cout << "pshh. Speedrunner" << endl;
                }
            }
            cout << endl << endl << "That's all folks!" << endl;
            return 1;
        }
    }
}

int finalBoss(){ //final boss big battle function, the other one couldn't handle the specifcs I needed for this fight
    bool isRival = false;
    int region = 5;
    P1.readFileFrom(5, false, "fightTalk.txt");
    bool contin = true;
    string move1 = "";
    string move2 = "";
    string move3 = "";
    string result = "";
    int playerTribe = P1.getTribeNum();
    int choice = -1;
    int counter = 0;
    cout << "It's Boss battle time!" << endl;

    if(playerTribe == 1){
        move1 = "Tsunami";
        move2 = "Ice Spikes";
        move3 = "Hose";
    }
    else if(playerTribe == 2){
        move1 = "Firewall";
        move2 = "Lightning Bolt";
        move3 = "Fireball";
    }
    else if(playerTribe == 3){
        move1 = "The Boulder";
        move2 = "Magma Blast";
        move3 = "Earth Gauntlet";
    }
    else if(playerTribe == 4){
        move1 = "Tornado";
        move2 = "Wind Whip";
        move3 = "Air Blast";
    }
    while(contin == true){
        cout << "=== Fight menu ===" << endl;
        cout << "1. " << move1 << endl << "2. " << move2 << endl << "3. " << move3 << endl;
        bool get = false;
        string choice1 = "";
        int counter = 0;
        while(get != true){
            cin >> choice1;
            if(choice1 == "1" || choice1 == "2" || choice1 == "3"){
                get = true;
            }
            else{
                if(counter > 2){
                    cout << "You were too indecisive, and now Dagon strikes!" << endl;
                    get = true;
                }
                else{
                    cout << "Please press 1, 2, or 3." << endl;
                }
            }
            counter++;
        }
        cout << endl;
        if(counter > 2){
            result = "success";
        }  
        else{
            choice = stoi(choice1);
            result = attack(true, playerTribe, region, choice);
        }
        // cout << "result1: " << result << endl;
        if(result != "success"){
            contin = false;
            continue;
        }
        cout << endl;
        cout << "Opponents turn: " << endl;
        result = attack(false, playerTribe, region, P1.makeRandNums(2));
        // cout << "result2: " << result << endl;
        cout << endl;
        if(result != "success"){
            contin = false;
            continue;
        }
    }
    if(result == "Loss"){
        P1.addDie();
        if(P1.getDeaths() == 3){
            return -1;
        }
        return 2;
    }
    return 1;
}

void begin(string& name, string& tribeName){ //my begin function, sets the stage for the whole game
    string option1;
    cout << endl << endl;
    cout << "Hello there! Welcome to Elenorm!" << endl;
    cout << "Now, what shall we call you?" << endl;
    getline(cin, name);
    cout << "Hello, " << name << "! What tribe would you like to play as?" << endl;
    cout << "1. Water" << endl << "2. Fire" << endl << "3. Earth" << endl << "4. Air" << endl << "5. Random!" << endl;
    bool stay = true;
    char option_i;
    int option = 0;
    while(stay == true){
        cin >> option1;
        option_i = option1[0];
        // cout << "option_i: " << option_i << endl;
        if(option1.length() != 1){
            cout << "You entered more than one character." << endl;
        }
        else{
            option_i = option1[0];
            if(isdigit(option_i)){
                option = option_i;
                // cout << "Recieved succesfully: " << option << endl;
                if(option > 48 && option < 54){
                    stay = false;
                }
                else{
                    cout << "Your input was not between 1 and 5." << endl;
                }
            }
            else{
                cout << "Sorry, you did not enter a number. Please try again." << endl;
            }

        }
    }
    switch (option){
    case 49:
        option = 1;
        break;
    case 50:
        option = 2;
        break;
    case 51:
        option = 3;
        break;
    case 52:
        option = 4;
        break;
    case 53:
        option = 5;
        break;
    default:
        break;
    }
    tribeName = setTribe(option, name);
    cout << "Welcome, " << name << " of the " << tribeName << ", to Ele Island!" << endl;
}

string setTribe(int& choice, string Pname){ //helper function, sets the names and the class I'll use for the player
    P1.setName(Pname);
    if (choice == 5){
        srand(time(NULL));
        choice = rand() % 4 + 1;
    }

    if(choice <= 4 && choice >= 1){
        P1.setName(Pname);
        if(choice == 1){
            PlayerA.setName(Pname);
            P1.setTribe(1);
            return "Water Tribe";
        }
        else if(choice == 2){  
            PlayerB.setName(Pname);
            P1.setTribe(2);
            return "Fire Nation";
        }
        else if(choice == 3){
            PlayerC.setName(Pname);
            P1.setTribe(3);
            return "Earth Kingdom";
        }
        else if(choice == 4){
            PlayerD.setName(Pname);
            P1.setTribe(4);
            return "Air Nomads";
        }
    }
    return "error";

}


void introduction(string name){
    P1.readFile("firstMeet.txt", 1, 17);
}

void mainP3(int region){ //where every region gameplay is housed 
    bool goOn = false;
    Map map;  // create object called map of type Map
    int holder = 0;
    int holder1 = 0;
    int holder2 = 0;
    int thing = 0;
    holder = P1.makeRandNums(0);
    holder1 = P1.makeRandNums(0);
    holder2 = P1.makeRandNums(0);
    if(holder1 == holder2){
        holder2++;
    }
    map.spawnShop(1, 3);
    map.spawnNPC(holder1, 13);
    map.spawnNPC(holder2, 2);
    map.spawnrival(holder, P1.makeRandNums(1));

    string move;  // for storing user input
    int i = 0;
    bool contin = false;
    while(goOn != true) {
        P1.addmasteryPts(3);
        cout << endl << "You are in " << P1.getRegion(region) << endl;
        map.displayMap();  // print map_data in terminal
        cout << "Valid moves are: " << endl; 
        map.displayMoves();  // give user a menu of valid moves to pick from
        cout << "5) Display stats" << endl;
        cout << "6) Recieve a hooligan hint" << endl;
        cout << "7) View your mastery points" << endl;
        cout << "8) View/change settings" << endl;
        cout << "9) Fast travel to the end of the map/certain amount" << endl;
        cout << "Input a move: "; 
        cout << endl;
        cin >> move;
        if(move == "5"){
            cout << "Would you like to display all stats, or just your health?" << endl;
            cout << "Press 1 for the former, 2 for the latter" << endl;
            bool yet = false;
            string yuu = "";
            while(yet != true){
                cin >> yuu;
                if(yuu == "1" || yuu == "2"){
                    yet = true;
                }
                else{
                    cout << "Please press 1 or 2." << endl;
                }
            }
            thing = stoi(yuu);
            if(thing == 1){
                switch (P1.getTribeNum()){
                case 1:
                    PlayerA.displayStats();
                    break;
                case 2:
                    PlayerB.displayStats();
                    break;
                case 3:
                    PlayerC.displayStats();
                    break;
                case 4:
                    PlayerD.displayStats();
                    break;
                default:
                    break;
                }
            }
            else{
                int H = 0;
                switch (P1.getTribeNum()){
                case 1:
                    H = PlayerA.getHealth();
                    break;
                case 2:
                    H = PlayerB.getHealth();
                    break;
                case 3:
                    H = PlayerC.getHealth();
                    break;
                case 4:
                    H = PlayerD.getHealth();
                    break;
                default:
                    break;
                }

                cout << "Health: " << H << endl;
            }
        }
        else if(move == "6"){
            randMaker rand = randMaker(1,21);
            int rV = rand.getRandNum();
            if(rV % 5 == 0){
                cout << "The row of the hooligan is " << holder << endl;
            }
            else{
                cout << "Sorry, the chances were not in your favor" << endl;
            }
        }
        else if(move == "7"){
            randMaker rand = randMaker(1,1000);
            cout << "You have " << rand.getRandNum() << " points" << endl;
            cout << "You: Wow! Is that really how much I have?" << endl;
            cout << "Weird Old guy: HAHAHAHA- no. I can't believe you fell for that. " << endl;
            cout << "No, here's the real number" << endl;
            cout << "Mastery Points: " << P1.getmasteryPts() << endl;
        }
        else if(move == "8"){
            string otherThing = "";
            cout << "Settings: " << endl;
            cout << "Weird Old guy meanness: MAX" << endl;
            cout << "Would you like to change it? y/n" << endl;
            cin >> otherThing;
            if(otherThing == "y"){
                cout << "Weird Old guy: Aww, you wish I was nicer? WELL TOO BAD" << endl;
            }
            else{
                if(otherThing == "n"){
                    cout << "Weird Old guy: Well thank you liking me just the way I am :)" << endl;
                }
                else{
                    cout << "Weird Old guy: That's not even a proper answer." << endl;
                }
            }
            cout << "NOW GET BACK TO WORK" << endl;
        }
        else if(move == "9"){
            cout << "Press 1 for the end of your row/collumn, and 2 to travel in your desired direction" << endl;
            int num;
            bool yet = false;
            string userInput = "";
            while(yet != true){
                cin >> userInput;
                if(userInput == "1" || userInput == "2"){
                    yet = true;
                }
                else{
                    cout << "Please press 1 or 2." << endl;
                }
            }
            num = stoi(userInput);
            if(num == 1){
                yet = false;
                userInput = "";
                int choice = 0;
                // choice = stoi(userInput);
                bool noDoThis = false;
                cout << "Would you like to go to the end of your row (1) or collumn (2)?" << endl;
                yet = false;
                userInput = "";
                while(yet != true){
                    cin >> userInput;
                    if(userInput == "1" || userInput == "2"){
                        yet = true;
                    }
                    else{
                        cout << "Please press 1 or 2." << endl;
                    }
                }
                choice = stoi(userInput);
                if(choice == 2){
                    noDoThis = map.atMaxRow();
                    if(noDoThis == true){
                        cout << "You cannot do that action at this time" << endl;
                    }
                    else{
                        while(map.atMaxRow() == false){
                            map.executeMove('s');
                        }
                    }

                }
                else if(choice == 1){
                    noDoThis = map.atMaxCol();
                    if(noDoThis == true){
                        cout << "You cannot do that action at this time" << endl;
                    }
                    else{
                        while(map.atMaxCol() == false){
                            map.executeMove('d');
                        }
                    }
                }
            }
            else if(num == 2){
                char dir;
                string uInput = "";
                int numMove;
                cout << "Please pick a direction: w,a,s,d" << endl;
                bool something = false;
                while(something != true){
                    cin >> uInput;
                    if(uInput == "w" || uInput == "a" || uInput == "s" || uInput == "d"){
                        something = true;
                    }
                    else{
                        cout << "Please press w, a, s, or d." << endl;
                    }
                }
                dir = uInput[0];
                cout << "How many times do you want to travel in this direction?" << endl;
                uInput = "";
                something = false;
                while(something != true){
                    cin >> uInput;
                    if(isdigit(uInput[0])){
                        something = true;
                    }
                    else{
                        cout << "Please input a positive integer" << endl;
                    }
                }
                numMove = stoi(uInput);
                if(map.move(dir, numMove) == false){
                    cout << "Cannot fast travel to desired direction that amount." << endl;
                }
            }
        }
        else if(move == "*"){ //easter egg ;)
            if(P1.isCool() == true){
                int H = 0;
                switch (P1.getTribeNum()){
                case 1:
                    H = PlayerA.getHealth();
                    PlayerA.setHealth(2*H);
                    break;
                case 2:
                    H = PlayerB.getHealth();
                    PlayerB.setHealth(2*H);
                    break;
                case 3:
                    H = PlayerC.getHealth();
                    PlayerC.setHealth(2*H);
                    break;
                case 4:
                    H = PlayerD.getHealth();
                    PlayerD.setHealth(2*H);
                    break;
                default:
                    break;
                }
                cout << "Your health is now doubled!" << endl;
                P1.makeCool(false);
            }
            else{
                cout << "Ooo, sorry there buddy. No can do." << endl;
            }
        }
        else{
            char mv = move[0];
            map.executeMove(mv);  // move the player on map based on user input
        }
        if(i == 0 && region == 1){
            P1.readFile("firstMeet.txt", 20, 48);
            P1.readFile("firstMeet.txt" , 50, 84);
        }
        if (map.isShopLocation()) {
            cout << "You're in a Shop!" << endl;
            shop(region);
            map.executeMove('s');
        }
        if (map.isrivalLocation()) {
            cout << "You've encountered a hooligan!" << endl;
            P1.readFileFrom(region, false, "fightTalk.txt");
            battleTime(false, region); 
            map.executeMove('a');//you need to make sure that it doesn't redo if you don't move anywhere else. Also in other places where this may happen
        }
        if (map.isNPCLocation()) {
            cout << "You've encountered an NPC!" << endl;
            if(holder1 > holder2){
                if(map.getPlayerRowPosition() == holder1){
                    P1.readNPC(region, false);
                }
                else if(map.getPlayerRowPosition() == holder2){
                    P1.readNPC(region, true);
                }
            }
            else{
                if(map.getPlayerRowPosition() == holder1){
                    P1.readNPC(region, true);
                }
                else if(map.getPlayerRowPosition() == holder2){
                    P1.readNPC(region, false);
                }  
            }
            map.executeMove('w');
            
        }
        if (map.isBossLocation()) {
            string userChoice = "";
            cout << "Are you sure you want to do the boss battle?" << endl;
            cin >> userChoice;
            cout << endl;
            if(userChoice == "n"){
                cout << "Alright, not ready yet. Gotcha, gotcha." << endl;
                map.executeMove('w');
            }
            else{
                if(userChoice == "y"){
                    cout << "Alrighty then- time to fight this Region's rival!" << endl;
                }
                else{
                    cout << "Wasn't a yes or no so if you're not ready yet too bad cause here we go!" << endl;
                }
                P1.readFileFrom(region, true, "fightTalk.txt");
                bool didWin;
                didWin = battleTime(true, region); 
                if(didWin == true){
                    goOn = true;
                    // continue;
                }
                else{
                    if(P1.getDeaths() == 3){
                        goOn = true;
                        continue;
                    }
                    else{
                        cout << "They'll be fully rested when you come back, so make sure to rejuvenate yourself!" << endl;
                        goOn = false;
                        map.executeMove('w');
                    }
                    
                }
            }
            
        }
        i++;
    }
}

void shop(int region){ //shop function, allows you to add on to your health, attack, and/or defense with the currency: mastery points
    if(P1.getNumShopVisits() == 0){
        cout << "Shop keeper: Hello there! You must be one of the new arrivals! " << P1.getName() << ", if I'm not mistaken." << endl;
        cout << "Pleasure to meet you. This is my shop, where you can get anything you need. Health potions, boosters, " << "power-ups- you name it!" << endl;
    }
    cout << "Feel free to look around!" << endl;
    vector<int> additives;
    additives = P1.displayShopItems(region); //actually does the pricing and checking, this is just the end result
    cout << "Hope to see you again soon!" << endl;
    if(additives.at(0) != -1){
        switch (P1.getTribeNum()){
        case 1:
            PlayerA.setHealth(PlayerA.getHealth() + additives.at(0)); //same thing as adding the health that you should get from the shop
            PlayerA.setAttack(PlayerA.getAttack() + additives.at(1));
            PlayerA.setDefense(PlayerA.getDefense() + additives.at(2));
            break;
        case 2:
            PlayerB.setHealth(PlayerB.getHealth() + additives.at(0));
            PlayerB.setAttack(PlayerB.getAttack() + additives.at(1));
            PlayerB.setDefense(PlayerB.getDefense() + additives.at(2));
            break;
        case 3:
            PlayerC.setHealth(PlayerC.getHealth() + additives.at(0));
            PlayerC.setAttack(PlayerC.getAttack() + additives.at(1));
            PlayerC.setDefense(PlayerC.getDefense() + additives.at(2));
            break;
        case 4:
            PlayerD.setHealth(PlayerD.getHealth() + additives.at(0));
            PlayerD.setAttack(PlayerD.getAttack() + additives.at(1));
            PlayerD.setDefense(PlayerD.getDefense() + additives.at(2));
            break;
        
        default:
            break;
        }
    }


}

string attack(bool isPlayer, int pInfo, int region, int moveNum){ //This is my extremely long battle function. It splits up from is the player attacking, then to the bender, then to the moves
    //also inflicts damage here, as well as shows stats, and other messages to the player. Only works for one turn
    int damageDealt = 0;
    randMaker doIt = randMaker(1, 4);
    if(isPlayer == true){
        switch (pInfo){
        case 1:
            if(moveNum == 1){
                damageDealt = PlayerA.tsunami();
            }
            else if(moveNum == 2){
                damageDealt = PlayerA.iceSpikes();
            }
            else if(moveNum == 3){
                damageDealt = PlayerA.hose();
            }
            else{
                cout << "error" << endl;
            }
            break;

        case 2:
            if(moveNum == 1){
                damageDealt = PlayerB.firewall();
            }
            else if(moveNum == 2){
                damageDealt = PlayerB.lightningBolt();
            }
            else if(moveNum == 3){
                damageDealt = PlayerB.fireball();
            }
            else{
                cout << "error" << endl;
            }
            
            break;

        case 3:
            if(moveNum == 1){
                damageDealt = PlayerC.theBoulder();
            }
            else if(moveNum == 2){
                damageDealt = PlayerC.magmaBlast();
            }
            else if(moveNum == 3){
                damageDealt = PlayerC.gauntlet();
            }
            else{
                cout << "error" << endl;
            }
            break;
        case 4:
            if(moveNum == 1){
                damageDealt = PlayerD.tornado();
            }
            else if(moveNum == 2){
                damageDealt = PlayerD.windWhip();
            }
            else if(moveNum == 3){
                damageDealt = PlayerD.airBlast(); 
            }
            else{
                cout << "error" << endl;
            }
            break;
        default:
            cout << "Wrong info" << endl;
            break;
        }
        cout << "You did " << damageDealt << " damage!" << endl;
        switch (region){
        case 1:
            if(NPC1.getDefense() > 0){
                if(moveNum == 1){
                    damageDealt += 5;
                }
                else if(moveNum == 2){
                    damageDealt -= 5;
                }
            }
            else if(NPC1.getDefense() == 0){
                if(moveNum == 1){
                    damageDealt -= 5;
                }
                else if(moveNum == 2){
                    damageDealt += 5;
                }
            }
            NPC1.damage(damageDealt);
            // cout << "New damage: " << damageDealt << endl;
            if(NPC1.getHealth() == 0){
                cout << "You defeated " << NPC1.getName() << "!" << endl;
                defeatedPeeps.push_back(NPC1);
                return "Win";
            }
            else{
                cout << NPC1.getName() << "'s stats: " << endl;
                NPC1.displayStats();
                NPC1.defenseDown();
            }
            break;
        case 2:
            if(NPC2.getDefense() > 0){
                if(moveNum == 1){
                    damageDealt += 5;
                }
                else if(moveNum == 2){
                    damageDealt -= 5;
                }
            }
            else if(NPC2.getDefense() == 0){
                if(moveNum == 1){
                    damageDealt -= 5;
                }
                else if(moveNum == 2){
                    damageDealt += 5;
                }
            }
            NPC2.damage(damageDealt);
            if(NPC2.getHealth() == 0){
                cout << "You defeated " << NPC2.getName() << "!" << endl;
                defeatedPeeps.push_back(NPC2);
                return "Win";
            }
            else{
                cout << NPC2.getName() << "'s stats: " << endl;
                NPC2.displayStats();
                NPC2.defenseDown();
            }
            break;
        case 3:
            if(NPC3.getDefense() > 0){
                if(moveNum == 1){
                    damageDealt += 5;
                }
                else if(moveNum == 2){
                    damageDealt -= 5;
                }
            }
            else if(NPC3.getDefense() == 0){
                if(moveNum == 1){
                    damageDealt -= 5;
                }
                else if(moveNum == 2){
                    damageDealt += 5;
                }
            }
            NPC3.damage(damageDealt);
            if(NPC3.getHealth() == 0){
                cout << "You defeated " << NPC3.getName() << "!" << endl;
                defeatedPeeps.push_back(NPC3);
                return "Win";
            }
            else{
                cout << NPC3.getName() << "'s stats: " << endl;
                NPC3.displayStats();
                NPC3.defenseDown();
            }
            break;
        case 4:
            if(NPC4.getDefense() > 0){
                if(moveNum == 1){
                    damageDealt += 5;
                }
                else if(moveNum == 2){
                    damageDealt -= 5;
                }
            }
            else if(NPC4.getDefense() == 0){
                if(moveNum == 1){
                    damageDealt -= 5;
                }
                else if(moveNum == 2){
                    damageDealt += 5;
                }
            }
            NPC4.damage(damageDealt);
            if(NPC4.getHealth() == 0){
                cout << "You defeated " << NPC4.getName() << "!" << endl;
                defeatedPeeps.push_back(NPC4);
                return "Win";
            }
            else{
                cout << NPC4.getName() << "'s stats: " << endl;
                NPC4.displayStats();
                NPC4.defenseDown();
            }
            break;
        case 5:
            if(Dagon.getDefense() > 0){
                if(moveNum == 1){
                    damageDealt += 5;
                }
                else if(moveNum == 2){
                    damageDealt -= 5;
                }
            }
            else if(Dagon.getDefense() == 0){
                if(moveNum == 1){
                    damageDealt -= 5;
                }
                else if(moveNum == 2){
                    damageDealt += 5;
                }
            }
            Dagon.damage(damageDealt);
            if(Dagon.getHealth() == 0){
                cout << "You defeated " << Dagon.getName() << "!" << endl;
                defeatedPeeps.push_back(Dagon);
                return "Win";
            }
            else{
                cout << Dagon.getName() << "'s stats: " << endl;
                Dagon.displayStats();
                Dagon.defenseDown();
            }
            break;
        default:
            cout << "error, line 914" << endl;
            break;
        }
        cout << "Your stats: " << endl;
        if(pInfo == 1){
            PlayerA.displayStats();
        }
        else if(pInfo == 2){
            PlayerB.displayStats();
        }
        else if(pInfo == 3){
            PlayerC.displayStats();
        }
        else if(pInfo == 4){
            PlayerD.displayStats();
        }
    }
    else{
        switch (region){
           case 1:

            if(NPC1.getDefense() == 0){
                cout << NPC1.getName() << "'s defense has been broken!" << endl;
                if(NPC1.getHealth() == 0){
                    cout << "error, NPC health is at 0" << endl;
                    return "NPC dead";
                }
            }

            if(moveNum == 1){
                damageDealt = NPC1.tsunami();
            }
            else if(moveNum == 2){
                damageDealt = NPC1.iceSpikes();
            }
            else if(moveNum == 3){
                damageDealt = NPC1.hose();
            }
            else{
                cout << "error" << endl;
            }
            cout << NPC1.getName() << " did " << damageDealt << " damage!" << endl;  
            break;
        case 2:
            if(NPC2.getDefense() == 0){
                cout << NPC2.getName() << "'s defense has been broken!" << endl;
                if(NPC2.getHealth() == 0){
                    cout << "error, NPC health is at 0" << endl;
                    return "NPC2 dead";
                }
            }
            if(moveNum == 1){
                damageDealt = NPC2.firewall();
            }
            else if(moveNum == 2){
                damageDealt = NPC2.lightningBolt();
            }
            else if(moveNum == 3){
                damageDealt = NPC2.fireball();
            }
            else{
                cout << "error" << endl;
            }
            cout << NPC2.getName() << " did " << damageDealt << " damage!" << endl;  
            break;
        case 3:
            if(NPC3.getDefense() == 0){
                cout << NPC3.getName() << "'s defense has been broken!" << endl;
                if(NPC3.getHealth() == 0){
                    cout << "error, NPC health is at 0" << endl;
                    return "NPC dead";
                }
            }
            if(moveNum == 1){
                damageDealt = NPC3.theBoulder();
            }
            else if(moveNum == 2){
                damageDealt = NPC3.magmaBlast();
            }
            else if(moveNum == 3){
                damageDealt = NPC3.gauntlet();
            }
            else{
                cout << "error" << endl;
            }      
            cout << NPC3.getName() << " did " << damageDealt << " damage!" << endl;        
            break;
        case 4:
            if(NPC4.getDefense() == 0){
                cout << NPC4.getName() << "'s defense has been broken!" << endl;
                if(NPC4.getHealth() == 0){
                    cout << "error, NPC health is at 0" << endl;
                    return "NPC dead";
                }
            }
            if(moveNum == 1){
                damageDealt = NPC4.tornado();
            }
            else if(moveNum == 2){
                damageDealt = NPC4.windWhip();
            }
            else if(moveNum == 3){
                damageDealt = NPC4.airBlast();
            }
            else{
                cout << "error" << endl;
            }
            cout << NPC4.getName() << " did " << damageDealt << " damage!" << endl;  
            break; 
        case 5: 
            if(Dagon.getDefense() == 0){
                cout << Dagon.getName() << "'s defense has been broken!" << endl;
                if(Dagon.getHealth() == 0){
                    cout << "error, Dagon health is at 0" << endl;
                    return "Dagon dead";
                }
            }
            switch (doIt.getRandNum()){
            case 1:
                if(moveNum == 1){
                    damageDealt = Dagon.tsunami();
                }
                else if(moveNum == 2){
                    damageDealt = Dagon.iceSpikes();
                }
                else if(moveNum == 3){
                    damageDealt = Dagon.hose();
                }
                else{
                    cout << "error" << endl;
                }
                break;
            case 2: 
                if(moveNum == 1){
                    damageDealt = Dagon.firewall();
                }
                else if(moveNum == 2){
                    damageDealt = Dagon.lightningBolt();
                }
                else if(moveNum == 3){
                    damageDealt = Dagon.fireball();
                }
                break;
            case 3:
                if(moveNum == 1){
                    damageDealt = Dagon.theBoulder();
                }
                else if(moveNum == 2){
                    damageDealt = Dagon.magmaBlast();
                }
                else if(moveNum == 3){
                    damageDealt = Dagon.gauntlet();
                }
                else{
                    cout << "error" << endl;
                }  
                break;
            
            case 4:
                if(moveNum == 1){
                    damageDealt = Dagon.tornado();
                }
                else if(moveNum == 2){
                    damageDealt = Dagon.windWhip();
                }
                else if(moveNum == 3){
                    damageDealt = Dagon.airBlast();
                }
                else{
                    cout << "error" << endl;
                }
                break;
            default:
                break;
            }
            cout << Dagon.getName() << " did " << damageDealt << " damage!" << endl;  
            break; 

        default:
            cout << "Wrong info" << endl;
            break;
        } 
        int health = -1;
        // cout << "Previous damage: " << damageDealt << endl;
        cout << "Your stats: " << endl;
        if(P1.getDefense() > 0){
            if(moveNum == 1){
                damageDealt += 5;
            }
            else if(moveNum == 2){
                damageDealt -= 5;
            }
        }
        else if(P1.getDefense() == 0){
            if(moveNum == 1){
                damageDealt += 5;
            }
            else if(moveNum == 2){
                damageDealt -= 5;
            }
        }
        if(pInfo == 1){
            PlayerA.damage(damageDealt);
            health = PlayerA.getHealth();
        }
        else if(pInfo == 2){
            PlayerB.damage(damageDealt);
            health = PlayerB.getHealth();
        }
        else if(pInfo == 3){
            PlayerC.damage(damageDealt);
            health = PlayerC.getHealth();
        }
        else if(pInfo == 4){
            PlayerD.damage(damageDealt);
            health = PlayerD.getHealth();
        }

        if(health == 0){
            cout << "You were defeated!" << endl;
            return "Loss";
        }
        else if(health == -1){
            cout << "error2" << endl;
            return "neee";
        }
        else{
            if(pInfo == 1){
                PlayerA.displayStats();
            }
            else if(pInfo == 2){
                PlayerB.displayStats();
            }
            else if(pInfo == 3){
                PlayerC.displayStats();
            }
            else if(pInfo == 4){
                PlayerD.displayStats();
            }
            if(health == 0){
                cout << "You were defeated!" << endl;
                return "Loss";
            }
            else{
                if(region == 1){
                    cout << NPC1.getName() << "'s stats: " << endl;
                    NPC1.displayStats();
                    NPC1.defenseDown();
                }
                else if(region == 2){
                    cout << NPC2.getName() << "'s stats: " << endl;
                    NPC2.displayStats();
                    NPC2.defenseDown();
                }
                else if(region == 3){
                    cout << NPC3.getName() << "'s stats: " << endl;
                    NPC3.displayStats();
                    NPC3.defenseDown();
                }
                else if(region == 4){
                    cout << NPC4.getName() << "'s stats: " << endl;
                    NPC4.displayStats();
                    NPC4.defenseDown();
                }
                else if(region == 5){
                    cout << Dagon.getName() << "'s stats: " << endl;
                    Dagon.displayStats();
                    Dagon.defenseDown();
                }
            }
        }
    }
    return "success";
}

bool battleTime(bool isBoss, int region){ //my big battle function, this actually handles the whole fight, calling attack() until something happens
    bool contin = true;
    string move1 = "";
    string move2 = "";
    string move3 = "";
    string result = "";
    int playerTribe = P1.getTribeNum();
    int choice = -1;
    int counter = 0;
    cout << "It's battle time!" << endl;
    int pointsGained = 0;
    switch (region){
        case 1:
            pointsGained = NPC1.getPower();
            break;
        case 2:
            pointsGained = NPC2.getPower();
            break;
        case 3:
            pointsGained = NPC3.getPower();
            break;
        case 4:
            pointsGained = NPC4.getPower();
            break;
        default:
            break;
    }
    if(isBoss == true){
        switch (region){
        case 1: //wanted to have only four "NPC's", so I just change their name and stats to not have 8 case switch statements
            //In this, every time you go to the person they will be reset in their stats
            NPC1.setInfo("Old Nana", 45, 30, 30);
            pointsGained = NPC1.getPower();
            // cout << NPC1.getName() << endl;
            break;

        case 2:
            NPC2.setInfo("Zoku", 45, 55, 30);
            pointsGained = NPC2.getPower();
            break;

        case 3:
            NPC3.setInfo("Long Fang",55, 45, 45);
            pointsGained = NPC3.getPower();
            break;

        case 4:
            NPC4.setInfo("Zahir", 60, 60, 55);
            pointsGained = NPC4.getPower();
            break;

        default:
            cout << "error on default for battletime" << endl;
            break;
        }
    }
    else{
        switch (region){
        case 1: //wanted to have only four "NPC's", so I just change their name and stats to not have 8 case switch statements
            // cout << "here too" << endl;
            NPC1.setInfo("Archibald", 35, 35, 40);
            pointsGained = NPC1.getPower();
            // cout << NPC1.getName() << endl;
            break;

        case 2:
            NPC2.setInfo("Quentin", 35, 40, 40);
            pointsGained = NPC2.getPower();
            break;

        case 3:
            NPC3.setInfo("Genevieve", 35, 40, 40);
            pointsGained = NPC3.getPower();
            break;

        case 4:
            NPC4.setInfo("Joe", 40, 40, 35);
            pointsGained = NPC4.getPower();
            break;

        default:
            cout << "error on default for battletime" << endl;
            break;
        }

    }
    if(playerTribe == 1){
        move1 = "Tsunami";
        move2 = "Ice Spikes";
        move3 = "Hose";
    }
    else if(playerTribe == 2){
        move1 = "Firewall";
        move2 = "Lightning Bolt";
        move3 = "Fireball";
    }
    else if(playerTribe == 3){
        move1 = "The Boulder";
        move2 = "Magma Blast";
        move3 = "Earth Gauntlet";
    }
    else if(playerTribe == 4){
        move1 = "Tornado";
        move2 = "Wind Whip";
        move3 = "Air Blast";
    }
    while(contin == true){ //displays my fight menu
        bool yee = false;
        string input = "";
        int counter = 0;
        cout << "=== Fight menu ===" << endl;
        cout << "1. " << move1 << endl << "2. " << move2 << endl << "3. " << move3 << endl;
        while(yee != true){
            cin >> input;
            if(input == "1" || input == "2" || input == "3"){
                choice = stoi(input);
                yee = true;
            }
            else{
                if(counter > 2){
                    cout << "You were too indecisive, and now your opponent strikes!" << endl;
                    yee = true;
                }
                else{
                    cout << "Please press 1, 2, or 3." << endl;
                }
                
            }
            counter++;
        }
        cout << endl;
        if(counter > 2){
            result = "success";
        }  
        else{
            choice = stoi(input);
            result = attack(true, playerTribe, region, choice);
        }
        // cout << "result1: " << result << endl;
        if(result != "success"){
            contin = false;
            continue;
        }
        cout << endl;
        cout << "Opponents turn: " << endl;
        if(choice == 1 || choice == 2){
            result = attack(false, playerTribe, region, 3);
            if(result != "success"){
                contin = false;
                continue;
            }
            result = attack(false, playerTribe, region, 3);
            if(result != "success"){
                contin = false;
                continue;
            }
        }
        else{
            result = attack(false, playerTribe, region, P1.makeRandNums(2));
            if(result != "success"){
                contin = false;
                continue;
            }
        }
        // cout << "result2: " << result << endl;
        cout << endl;
        if(result != "success"){
            contin = false;
            continue;
        }

    }
    if(result == "Win"){
        cout << "You earned " << pointsGained << " master points!" << endl;
        P1.addmasteryPts(pointsGained);
        return true;

    }
    else if(result == "Loss"){
        P1.addDie();
        if(P1.getDeaths() == 3){
            cout << "Game Over!" << endl;
        }
        else{
            cout << endl << "Ah, don't worry player, you'll get them next time." << endl;
        }
        return false;
    }
    return false;
}

void writeDefeatedToFile(){
    ofstream outFile;
    outFile.open("Defeated Enemies");
    if(!outFile.fail()){
        outFile << "Name" << endl << "health, attack, defense, power" << endl << endl;
        for(int i = 0; i < defeatedPeeps.size(); i++){
            outFile << defeatedPeeps[i].getName();
            outFile << "'s stats: " << endl;
            for(int j = 0; j < 3; j++){
                outFile << defeatedPeeps[i].getInitialStatsAt(j) << ", ";
            }
            outFile << defeatedPeeps[i].getInitialStatsAt(3) << endl;
            outFile << endl;
        }
        outFile.close();
    }
    else{
        cout << "Error with writing defeated enemies" << endl;
    }
}