#include "Door.hpp"
#include "LinkedList.hpp"
#include <string>

using namespace std;

class Room
{
    private:
        Door* NorthDoor;
        Door* EastDoor;
        Door* WestDoor;
        Door* SouthDoor;

        Room* NorthRoom;
        Room* EastRoom;
        Room* WestRoom;
        Room* SouthRoom;
        
        string RoomName;

        LinkedList* ListOfResidents;

    public:
        Room(string name);
        Room* addRoom(int direction, string RoomName);    
        //direction tells you which cardinal direction you 
        //add the door to(N or S, E or W)
        void addDoorEW(Room* eastRoom,Room* westRoom);
        void addDoorNS(Room* northRoom,Room* southRoom);

        string getRoomName();
        LinkedList* getListOfResidents();

        //checks to see if door exists in certain direction
        bool checkNorth();
        bool checkSouth();
        bool checkEast();
        bool checkWest();

        //gets the door from the certain direction
        Room* getNorthRoom();
        Room* getSouthRoom();
        Room* getWestRoom();
        Room* getEastRoom();

};