#include "Player.hpp"

Player::Player(string playerName, Room* Entrance)
{
    this->playerName = playerName;
    this->currPos = Entrance;
    this->health = 100;
    this->playerInventory = new LinkedList();
}

string Player::getPlayerName()
{
    return this->playerName;
}

Room* Player::getCurrPos()
{
    return this->currPos;
}

int Player::getHealth()
{
    return this->health;
}

void Player::displayHealthBar()
{
    cout << "Health = " << this->health << "\n";
}
//check for doors in room
void Player::checkRoom()
{
    cout << "You look around for some sort of door.\n";
    cout << "There is hope to the ";
    if(this->currPos->checkNorth())
    {
        cout << "north, ";
    }
    if(this->currPos->checkEast())
    {
        cout << "east, ";
    }
    if(this->currPos->checkWest())
    {
        cout << "west, ";
    }
    if(this->currPos->checkSouth())
    {
        cout << "south";
    }
    if(!this->currPos->checkNorth() && !this->currPos->checkSouth() && !this->currPos->checkWest() && !this->currPos->checkEast())
    {
        cout << "You see no way out. You were trapped and died of starvation. It was miserable.\n";
    }
    cout << ".\n";
}

//use user input to move between rooms
void Player::moveRooms(string direction)
{
    if(direction != "north" && direction != "North" && direction != "south" && direction != "South" 
    && direction != "east" && direction != "East" && direction != "west" && direction != "West")
    {
        cout << "Your stupidity overwhelms you and fail to make a decision.\n\n";
    }
    else if(direction == "north" || direction == "North")
    {
        cout << "You decide to take the door to your North.\n\n";
        if(this->currPos->checkNorth())
        {
        this->currPos = this->currPos->getNorthRoom();
        }
        else
        {
            cout << "There is no door in that direction. You smack your head on the cold stone of denial.\n\n";
        }
        
    }
    else if(direction == "east" || direction == "East")
    {
        cout << "You decide to take the door to your East.\n\n";
        if(this->currPos->checkEast())
        {
        this->currPos = this->currPos->getEastRoom();
        }
        else
        {
            cout << "There is no door in that direction. You smack your head on the cold stone of denial.\n\n";
        }
    }
    else if(direction == "west" || direction == "West")
    {
        cout << "You decide to take the door to your West.\n\n";
        if(this->currPos->checkWest())
        {
        this->currPos = this->currPos->getWestRoom();
        }
        else
        {
            cout << "There is no door in that direction. You smack your head on the cold stone of denial.\n\n";
        }
    }
    else if(direction == "south" || direction == "South")
    {
        cout << "Your cowardice overtakes you, so you go backwards.\n\n";
        if(this->currPos->checkSouth())
        {
        this->currPos = this->currPos->getSouthRoom();
        }
        else
        {
            cout << "There is no door in that direction. You smack your head on the cold stone of denial.\n\n";
        }
    }
    cout << "********************\n";
    cout << "You find yourself in " << this->getCurrPos()->getRoomName() << ".\n";
}

string Player::decideMovement()
{
    cout << "Where do you want to go? [";
        if(this->getCurrPos()->checkNorth())
        {
            cout << "north, ";
        }
        if(this->getCurrPos()->checkWest())
        {
            cout << "west, ";
        }
        if(this->getCurrPos()->checkEast())
        {
            cout << "east, ";
        }
        if(this->getCurrPos()->checkSouth())
        {
            cout << "south, ";
        }
        cout << "]\n";
        string direction;
        cin >> direction;
        return direction;
}

//looks through room to see what residents are there
void Player::seeResidentList()
{
    int listCount = this->getCurrPos()->getListOfResidents()->getCount();
    // cout << listCount <<"\n";
    for(int i = 0; i < listCount; i++)
    {
        Resident* currResident = this->currPos->getListOfResidents()->getAtIndex(i); 
        if(currResident->getResidentType() == "skeleton")
        {
            cout << "You notice there is a pile of bones in the corner of the room. Strange, they look human...\n";
        }
        else if(currResident->getResidentType() == "rotting flesh")
        {
            cout << "You gag as you enter the room. There is a pile of rotting flesh in the center of the room.\n";
        }
        else if(currResident->getResidentType() == "key")
        {
            cout << "You notice a key is hanging on the wall next to you.\n";
            this->pickUpItem("key", i);
            break;
        }
        else if(currResident->getResidentType() == "sword")
        {
            cout << "Hm, there is a sword laying on the floor in front of you.\n";
            this->pickUpItem("sword", i);
            break;
        }
        else if(currResident->getResidentType() == "shield")
        {
            cout << "You see a shield hanging from the wall next to you.\n";
            this->pickUpItem("shield", i);
            break;
        }
        else if(currResident->getResidentType() == "danger")
        {
            cout << "You feel an evil presence watching you...\n";
        }
        else
        {
            cout << "Doesn't look like there is anything interesting in here. Better get moving.\n";
        } 
    }
    //cout << "Checked Resident list.\n";
}

Resident* Player::pickUpItem(string item, int i)
{
    string input;
    cout << "Do you want to pick up the " << item << "?[yes/no]\n";
    cin >> input;
    if(input == "yes" || input == "y")
    {
        if(this->playerInventory->getCount() > 4)
        {
            cout << "Your inventory is full(max of 5 items). You must drop an item before you can pick anything else up.\n";
            this->playerInventory->displayResidents();
            cout << "Do you want to drop something?[yes/no]";
            string answer;
            cin >> answer;
            if(answer == "yes" || answer == "y")
            {
                cout << "********************\n";
                this->dropItem();
                this->playerInventory->addFront(item);

            }
            else
            {
                cout << "You decide to leave the " << item << " on the ground.\n";
            }
        }
        else
        {
            //remove from resident list
            this->currPos->getListOfResidents()->removeAtIndex(i);
            //add to inventory
            this->playerInventory->addFront(item);
            cout << "You acquired the " << item << "!\n";
            this->seeResidentList();
        }
    }
    else if(input == "no" || input == "n")
    {
        cout << "You chose to not pick up the " << item << ".\n";
    }
    else
    {
        cout << "Your own mortality temporarily overcomes you. Try again.\n";
        this->pickUpItem(item, i);
    }
}

void Player::dropItem()
{
    
    this->playerInventory->displayResidents();
    cout << "Which item would you like to drop?[index#] ";
    int i;
    cin >> i;

    
    string atIndex;// = this->playerInventory->getAtIndex(i)->getResidentType();
    switch (i)
    {
    case 0 ... 4:
        atIndex = this->playerInventory->getAtIndex(i)->getResidentType();
        //cout << atIndex << "\n";
        this->playerInventory->removeAtIndex(i);
        //cout << "Removed from index.\n";

        //add the dropped item to the current room
        this->currPos->getListOfResidents()->addFront(atIndex);
        cout << "Dropped the " << atIndex << " on the floor.\n";
        break;
    
    default:
        cout << "********************\n";
        cout << "That wasn't a choice you idiot.\n";
        this->dropItem();
    }
}