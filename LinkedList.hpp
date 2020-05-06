#include "Resident.hpp"

using namespace std;

class LinkedList
{
    private:
        int count;
        Resident* head;
    public:
        LinkedList();
        void addFront(string residentType);
        int getCount();
        Resident* getAtIndex(int index);
        Resident* removeAtIndex(int index);
        void displayResidents();
};