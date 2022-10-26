#include <fstream>
#include <iostream>
#include <ctype.h>

//Changed some aspects to fit my El Island game better

using namespace std; 

class Map
{
     private:
          static const int num_rows = 7;
          static const int num_cols = 15;
          static const int num_npcs = 3;
          static const int num_rivals = 3;

          int playerPosition[2];
          int ShopPosition[2];
          int bossPosition[2];
          int npcPositions[num_npcs][2];
          int rivalPositions[num_rivals][2];
          char mapData[num_rows][num_cols];

          int npc_count;
          int rival_count;
          bool shop_on_map;
          bool boss_on_map;

     public :
          Map();

          void resetMap();

          // getters
          int getPlayerRowPosition();
          int getPlayerColPosition();
          // int getRivalPosition();
          int getNPCCount();
          int getrivalCount();

          // setters
          void setPlayerRowPosition(int);
          void setPlayerColPosition(int);
          void setNPCCount(int);
          void setrivalCount(int);

          bool spawnNPC(int, int);
          bool spawnShop(int, int);
          bool spawnrival(int, int);
          bool spawnBoss();

          void displayMap();
          void displayMoves();  
          bool executeMove(char);

          bool isShopLocation();
          bool isNPCLocation();
          bool isrivalLocation();
          bool isBossLocation();

          bool isShopOnMap();
          bool isBossOnMap();
          bool atMaxCol();
          bool atMaxRow();

          bool move(char direction, int moveNum);

};