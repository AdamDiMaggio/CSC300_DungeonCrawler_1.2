#include "Resident.hpp"

Resident::Resident(string residentType)
{
    this->residentType = residentType;
    this->nextResident = 0;
}

string Resident::getResidentType()
{
    return this->residentType;
}

Resident* Resident::getNextResident()
{
    return this->nextResident;
}

void Resident::setNextResident(Resident* r)
{
    this->nextResident = r;
}