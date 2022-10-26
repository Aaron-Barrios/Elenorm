#include "Map.h"

using namespace std; 

Map::Map()
{
    resetMap();
}

// resets player position, count values, and initializes values in position arrays to -1
void Map::resetMap() {
    playerPosition[0] = 0; 
    playerPosition[1] = 0;

    ShopPosition[0] = -1;
    ShopPosition[1] = -1;

    bossPosition[0] = -1;
    bossPosition[1] = -1;

    npc_count = 0;
    rival_count = 0;
    shop_on_map = false;
    boss_on_map = false;

    for (int i = 0; i < num_npcs; i++) {
        npcPositions[i][0] = -1;
        npcPositions[i][1] = -1;
    }

    for (int i = 0; i < num_rivals; i++) {
        rivalPositions[i][0] = -1;
        rivalPositions[i][1] = -1;
    }

    for (int i = 0; i < num_rows; i++) {
        for (int j = 0; j < num_cols; j++) {
            mapData[i][j] = '-';
        }
    }
    mapData[num_rows-1][num_cols-1] = 'B';
}

// return player's row position
int Map::getPlayerRowPosition() {
    return playerPosition[0];
}

// return player's column position
int Map::getPlayerColPosition() {
    return playerPosition[1];
}

int Map::getNPCCount() {
    return npc_count;
}

int Map::getrivalCount() {
    return rival_count;
}

// set player's row position to parameter row
void Map::setPlayerRowPosition(int row) {
    playerPosition[0] = row;
}

// set player's column position to parameter row
void Map::setPlayerColPosition(int col) {
    playerPosition[1] = col;
}

void Map::setNPCCount(int count) {
    npc_count = count;
}

void Map::setrivalCount(int count) {
    rival_count = count;
}

/* add rival to map
 * Parameters: where to spawn rival -- row (int), col (int)
 * Return: (bool) false if no more space in rivalPositions array
 *                      or if (row, col) is an invalid position
 *                      or if (row, col) is already populated; else true
 */
bool Map::spawnrival(int row, int col) {
    // out of map bounds
    if (!(row >= 0 && row < num_rows && col >= 0 && col < num_cols)) {
        return false;
    }

    if (rival_count >= num_rivals) {
        return false;
    }

    // location must be blank to spawn
    if (mapData[row][col] != '-') {
        return false;
    }

    if (rivalPositions[rival_count][0] == -1 && rivalPositions[rival_count][1] == -1) {
        rivalPositions[rival_count][0] = row;
        rivalPositions[rival_count][1] = col;
        mapData[row][col] = 'H';
        rival_count++;
        return true;
    }

    return false;
}

/* add NPC to map
 * Parameters: where to spawn NPC -- row (int), col (int)
 * Return: (bool) false if no more space in npcPositions array
 *                      or if (row, col) is an invalid position
 *                      or if (row, col) is already populated; else true
 */
bool Map::spawnNPC(int row, int col) {
    // out of map bounds
    if (!(row >= 0 && row < num_rows && col >= 0 && col < num_cols)) {
        return false;
    }

    if (npc_count >= num_npcs) {
        return false;
    }

    // location must be blank to spawn
    if (mapData[row][col] != '-') {
        return false;
    }

    if (npcPositions[npc_count][0] == -1 && npcPositions[npc_count][1] == -1) {
        npcPositions[npc_count][0] = row;
        npcPositions[npc_count][1] = col;
        mapData[row][col] = 'N';
        npc_count++;
        return true;
    }

    return false;
}

/* add Best Buy to map
 * Parameters: where to spawn Best Buy -- row (int), col (int)
 * Return: (bool) false if (row, col) is an invalid location
 *                      or if (row, col) is already populated
 *                      or if there is a best buy already on the map; else true
 */
bool Map::spawnShop(int row, int col) {
    // out of map bounds
    if (!(row >= 0 && row < num_rows && col >= 0 && col < num_cols)) {
        return false;
    }

    // location must be blank to spawn
    if (mapData[row][col] != '-') {
        return false;
    }

    if (shop_on_map) {
        return false;
    }

    if (ShopPosition[0] == -1 && ShopPosition[1] == -1) {
        ShopPosition[0] = row;
        ShopPosition[1] = col;
        mapData[row][col] = 'S';
        shop_on_map = true;
        return true;
    }
    if (bossPosition[0] == -1 && bossPosition[1] == -1) {
        bossPosition[0] = row;
        bossPosition[1] = col;
        mapData[row][col] = 'B';
        shop_on_map = true;
        return true;
    }

    return false;
}

bool Map::spawnBoss() {
    // location must be blank to spawn
    if (mapData[num_rows-1][num_cols-1] != '-') {
        return false;
    }

    if (boss_on_map) {
        return false;
    }

    if (bossPosition[0] == -1 && bossPosition[1] == -1) {
        bossPosition[0] = num_rows-1;
        bossPosition[1] = num_cols-1;
        // cout << "bossPosition: " << bossPosition[0] << " " << bossPosition[1] << endl;
        mapData[num_rows-1][num_cols-1] = 'B';
        shop_on_map = true;
        return true;
    }

    return false;
}

// return true if x, y position has a best buy there
bool Map::isShopLocation(){
    return ShopPosition[0] == playerPosition[0] && ShopPosition[1] == playerPosition[1];
}

// return true if x, y position has an npc there
bool Map::isNPCLocation(){
    for(int i = 0; i < num_npcs; i++){
        if(npcPositions[i][0] == playerPosition[0] && npcPositions[i][1] == playerPosition[1]){
            return true; 
        }
    }
    return false; 
}

// return true if x, y position has a rival there
bool Map::isrivalLocation() {
    for(int i = 0; i < num_npcs; i++){
        if(rivalPositions[i][0] == playerPosition[0] && rivalPositions[i][1] == playerPosition[1]){
            return true; 
        }
    }
    return false; 
    
}
bool Map::isBossLocation(){
    // cout << "num_rows: " << num_rows -1 << endl;
    // cout << "num_cols: " << num_cols -1 << endl;
    // cout << "Player position: " << playerPosition[0] << " " << playerPosition[1] << endl;
    // cout << "Boss position: " << bossPosition[0] << " " << bossPosition[1] << endl;
    return num_rows-1 == playerPosition[0] && num_cols-1 == playerPosition[1];
}

/*
 * This function prints a menu of valid moves based on playerPosition
 * Parameters: none
 * Return: nothing (void)
 */
void Map::displayMoves(){
    if(!(playerPosition[0] == 0)){
        cout << "w (Up)" << endl;
    }
    if(!(playerPosition[1] == 0)){
        cout << "a (Left)" << endl; 
    }
    if(!(playerPosition[0] == (num_rows - 1))){
        cout << "s (Down)" << endl; 
    }
    if(!(playerPosition[1] == (num_cols - 1))){
        cout << "d (Right)" << endl; 
    }
}

/*
 * This function takes in user input
 * and updates playerPosition on the map.
 * Parameters: move (char) -- 'w' (up), 'a' (left), 's' (down), 'd' (right)
 * Return: (bool) if move is valid, then true, else false
 */
bool Map::executeMove(char move){
    // if user inputs w, move up if it is an allowed move
    if(!(playerPosition[0] == 0) && (tolower(move) == 'w')){
        playerPosition[0] -= 1;
        return true; 
    }
    // if user inputs s, move down if it is an allowed move
    else if(!(playerPosition[0] == (num_rows - 1))&& (tolower(move) == 's')){
        playerPosition[0] += 1;
        return true; 
    }
    // if user inputs a, move left if it is an allowed move
    else if(!(playerPosition[1] == 0)&& (tolower(move) == 'a')){
        playerPosition[1] -= 1;
        return true; 
    }
    // if user inputs d, move right if it is an allowed move
    else if(!(playerPosition[1] == (num_cols - 1))&& (tolower(move) == 'd')){
        playerPosition[1] += 1;
        return true; 
    }
    else{
        cout << "Invalid Move" << endl; 
        return false; 
    }
}

/*
 * This function prints a 2D map in the terminal.
 * Parameters: none
 * Return: nothing (void)
 */
void Map::displayMap() {
    for (int i = 0; i < num_rows; i++) {
        for (int j = 0; j < num_cols; j++) {
            if (playerPosition[0] == i && playerPosition[1] == j) {
                cout << "x";
            } else if (mapData[i][j] == 'H') {  // don't show hacker on the map
                cout << "-";
            }
            else {
                cout << mapData[i][j];
            }
        }
        cout << endl;
    }
}

// returns true if there is already a Best Buy on the map
bool Map::isShopOnMap() {
    return shop_on_map;
}
bool Map::isBossOnMap(){
    return boss_on_map;
}
bool Map::atMaxCol(){
    if(playerPosition[1] == num_cols-1){
        return true;
    }
    return false;
}
bool Map::atMaxRow(){
    if(playerPosition[0] == num_rows-1){
        return true;
    }
    return false;
}
bool Map::move(char direction, int moveNum){
    bool goN = true;
    int counter = 0;
    if(atMaxCol() == true){
        if(direction == 'd'){
            return false;
        }

    }
    if(playerPosition[0] == 0){
        if(direction == 'w'){
            return false;
        }
    }
    if(playerPosition[1] == 0){
        if(direction == 'a'){
            return false;
        }
    }
    if(atMaxRow() == true){
        if(direction == 's'){
            return false;
        }
    }
    goN = true;
    if(direction == 'w'){
        while(goN == true){
            executeMove('w');
            counter++;
            if(playerPosition[0] == 0){
                goN = false;
                return true;
            }
            if(counter >= moveNum){
                goN = false;
                return true;
            }

        }
    }
    else if(direction == 'a'){
        while(goN == true){
            executeMove('a');
            counter++;
            if(playerPosition[1] == 0){
                goN = false;
                return true;
            }
            if(counter >= moveNum){
                goN = false;
                return true;
            }

        }
    }
    else if(direction == 's'){
        while(goN == true){
            executeMove('s');
            counter++;
            if(atMaxRow() == true){
                goN = false;
                return true;
            }
            if(counter >= moveNum){
                goN = false;
                return true;
            }

        }
    }
    else if(direction == 'd'){
         while(goN == true){
            executeMove('d');
            counter++;
            if(atMaxCol() == true){
                goN = false;
                return true;
            }
            if(counter >= moveNum){
                goN = false;
                return true;
            }

        }
    }
    return true;
}
