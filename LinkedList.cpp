#include "LinkedList.hpp"
#include <iostream>

using namespace std;
LinkedList::LinkedList()
{
    this->count = 0;
    this->head = 0;
}

int LinkedList::getCount()
{
    return this->count;
}


void LinkedList::addFront(string residentType)
{
    Resident* r = new Resident(residentType);
    if(!this->head)
    {
        this->head = r;
    }
    else
    {
        r->setNextResident(this->head);
        this->head = r;
    }
    this->count++;
}

//get locator for resident of room
Resident* LinkedList::getAtIndex(int index)
{
    if(index > this->count-1 || index < 0)
    {
        return 0;
    }
    else
    {
        Resident* currNode = this->head;
        for(int i = 0; i < index; i++)
        {
            currNode = currNode->getNextResident();
        }
        return currNode;
    }
}

//remove resident from room
Resident* LinkedList::removeAtIndex(int index)
{
    //index is out of range or list is empty
    if(!this->head || index < 0 || index > this->count-1)
    {
        return 0; 
    }
    else
    {
        Resident* residentToReturn;
        if(index == 0)
        {
            //removeFront
            residentToReturn = this->head;
            this->head = this->head->getNextResident();
        }  
        else if(index == this->count-1)
        {
            //removeEnd
            Resident* currResident = this->head;
            for(int i = 0; i < this->count - 1; i++)  //puts currNode on end Node
            {
                currResident = currResident->getNextResident();
            }
            //residentToReturn = currResident->getNextResident();
            residentToReturn = currResident;
            //Resident* nodeToDelete = currResident->getNextResident();
            Resident* nodeToDelete = currResident;
            currResident->setNextResident(0);
            delete nodeToDelete;
        }
        else
        {
            //remove from any index
            Resident* currResident = this->head;
            for(int i = 0; i < index - 1; i++)  
            {
                currResident = currResident->getNextResident();
            }
            residentToReturn = currResident->getNextResident();
            Resident* nodeToDelete = currResident->getNextResident();
            currResident->setNextResident(residentToReturn->getNextResident());
            delete nodeToDelete;
        }
        count--;
        return residentToReturn;
    }
}

void LinkedList::displayResidents()
{
    //display all items in the list
    for(int i = 0; i < this->getCount(); i++)
    {
        cout << i << ": " << this->getAtIndex(i)->getResidentType() << "\n";
    }
}