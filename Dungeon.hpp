#include "Room.hpp"
#include <iostream>

using namespace std;

class Dungeon
{
    private:
        Room* Entrance;
        Room* BossRoom;
        string dungeonName;

    public:
        Dungeon(string dungeonName);
        void addEntrance();
        string getName();
        void setName(string dungeonName);
        Room* getEntrance();
        void setBossRoom(Room* BossRoom);
        Room* getBossRoom();
};