#include "Dungeon.hpp"


Dungeon::Dungeon(string dungeonName)
{
    this->Entrance = 0;
    this->BossRoom = 0;
    this->dungeonName = dungeonName;
}

void Dungeon::setName(string dungeonName)
{
    this->dungeonName = dungeonName;
}

void Dungeon::addEntrance()
{
    if(!this->Entrance)
    {
        Room* room = new Room("The Entrance");
        // LinkedList* temp = room->getListOfResidents();
        // temp->addFront("nothing");
        this->Entrance = room;
    }
    else
    {
        cout << "Error::Prior entrance already in existence.\n";
    }
}

void Dungeon::setBossRoom(Room* BossRoom)
{
    this->BossRoom = BossRoom;
}

Room* Dungeon::getBossRoom()
{
    return this->BossRoom;
}

string Dungeon::getName()
{
    return this->dungeonName;
}

Room* Dungeon::getEntrance()
{
    return this->Entrance;
}