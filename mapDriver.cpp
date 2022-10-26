#include "Map.cpp"

using namespace std; 

int main() {
    Map map;  // create object called map of type Map
    map.spawnShop(1, 9);
    map.spawnNPC(3, 2);
    map.spawnNPC(4, 8);
    map.spawnrival(1, 1);
    map.spawnBoss();

    char move;  // for storing user input

    // quit after 10 moves
    for(int i = 0; i < 50; i++) {
        map.displayMap();  // pretty print map_data in terminal

        cout << "Valid moves are: " << endl; 
        map.displayMoves();  // give user a menu of valid moves to pick from
        
        cout << "Input a move: "; 
        cin >> move;
        cout << endl;
        map.executeMove(move);  // move the player on map based on user input

        if (map.isShopLocation()) {
            cout << "You're in the Shop!" << endl;
        }

        if (map.isrivalLocation()) {
            cout << "You've encountered a rival!" << endl;
        }

        if (map.isNPCLocation()) {
            cout << "You've encountered an NPC!" << endl;
        }
        if (map.isBossLocation()) {
            cout << "You're at the boss battle!" << endl;
        }
    }
}
