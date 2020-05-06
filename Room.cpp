#include "Room.hpp"
#include <iostream>

using namespace std;

Room::Room(string name)
{
    this->RoomName = name;
    this->ListOfResidents = new LinkedList();

    Door* NorthDoor = 0;
    Door* EastDoor = 0;
    Door* WestDoor = 0;
    Door* SouthDoor = 0;
    Room* NorthRoom = 0;
    Room* EastRoom = 0;
    Room* WestRoom = 0;
    Room* SouthRoom = 0;
}

Room* Room::addRoom(int direction, string RoomName)   //where are we adding a room and door to
{
    if(direction == 12)  //north door
    {
        Door* door = new Door(1); //for now, all doors are open
        this->NorthDoor = door;

        Room* room = new Room(RoomName);  
        this->NorthRoom = room;

        room->SouthDoor = door;
        room->SouthRoom = this;
        //cout << "Northern door and room were added to " << this->RoomName << "\n";
        return room;
    }
    else if(direction == 3)  //east door
    {
        Door* door = new Door(1);
        this->EastDoor = door;

        Room* room = new Room(RoomName);   //set room name in dungeon
        this->EastRoom = room;

        room->WestDoor = door;
        room->WestRoom = this;
        //cout << "Eastern door and room were added to " << this->RoomName << "\n";
        return room;
    }
    else if(direction == 6)  //south door
    {
        Door* door = new Door(1);
        this->SouthDoor = door;

        Room* room = new Room(RoomName);   //set room name in dungeon
        this->SouthRoom = room;

        room->NorthDoor = door;
        room->NorthRoom = this;
        //cout << "Southern door and room were added to " << this->RoomName << "\n";
        return room;
    }
    else if(direction == 9)  //west door
    {
        Door* door = new Door(1);
        this->WestDoor = door;
        
        Room* room = new Room(RoomName);   //set room name in dungeon
        this->WestRoom = room;

        room->EastDoor = door;
        room->EastRoom = this;
        //cout << "Western door and room were added to " << this->RoomName << "\n";
        return room;
    }
    else
    {
        cout << "Error::Incorrect direction input.\n";
        return 0;
    }
    
}

void Room::addDoorEW(Room* eastRoom,Room* westRoom)
{
    Door* door = new Door(1);
    eastRoom->WestDoor = door;
    eastRoom->WestRoom = westRoom;
    westRoom->EastDoor = door;
    westRoom->EastRoom = eastRoom;
    //cout << "Door was formed between " << eastRoom->getRoomName() << " and " << westRoom->getRoomName() << "\n";
}

void Room::addDoorNS(Room* northRoom,Room* southRoom)
{
    Door* door = new Door(1);
    northRoom->SouthDoor = door;
    northRoom->SouthRoom = southRoom;
    southRoom->NorthDoor = door;
    southRoom->NorthRoom = northRoom;
    //cout << "Door was formed between " << southRoom->getRoomName() << " and " << northRoom->getRoomName() << "\n";
}


/************************************get room info************************************/
string Room::getRoomName()
{
    return this->RoomName;
}


LinkedList* Room::getListOfResidents()
{
    return this->ListOfResidents;
}


/************************************Check directions for a door************************************/
bool Room::checkNorth()
{
    if(this->NorthDoor)
    {
        return true;
    }
    else
    {
        return false;
    }   
}

bool Room::checkSouth()
{
    if(this->SouthDoor)
    {
        return true;
    }
    else
    {
        return false;
    }  
}

bool Room::checkEast()
{
    if(this->EastDoor)
    {
        return true;
    }
    else
    {
        return false;
    }  
}

bool Room::checkWest()
{
    if(this->WestDoor)
    {
        return true;
    }
    else
    {
        return false;
    }  
}


/************************************Get info on adjacent rooms************************************/
Room* Room::getNorthRoom()
{
    return this->NorthRoom;
}
Room* Room::getSouthRoom()
{
    return this->SouthRoom;
}
Room* Room::getWestRoom()
{
    return this->WestRoom;
}
Room* Room::getEastRoom()
{
    return this->EastRoom;
}