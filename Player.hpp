#include <iostream>
#include <string>
#include "Dungeon.hpp"
//#include "Resident.hpp"

using namespace std;

class Player
{
    private:
        string playerName;
        int health;
        Room* currPos;
        LinkedList* playerInventory;  //will hold items from rooms

    public:
        Player(string playerName, Room* Entrance);
        //getters
        string getPlayerName();
        Room* getCurrPos();
        int getHealth();
        void displayHealthBar();    //display current health of player
        void checkRoom();   //check for doors in room
        void moveRooms(string direction);   //move between rooms
        string decideMovement(); 
        void seeResidentList(); //looks through room to see what residents are there
                                //also controls player interactions with those residents
        
        Resident* pickUpItem(string item, int i); //adds to inventory
        void dropItem();   //removes from inventory

};