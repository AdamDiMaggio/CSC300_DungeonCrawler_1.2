#include <string>

using namespace std;

class Resident
{
    private:
        string residentType;
        Resident* nextResident;

    public:
        Resident(string residentType);
        string getResidentType();
        Resident* getNextResident();
        void setNextResident(Resident* r);
};