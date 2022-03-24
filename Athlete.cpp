#include "Athlete.h"

float Athlete::athleticFee = 125.50;

std::string Athlete::getLastName() { return this->lastName; }

Athlete::Athlete(std::string firstName, std::string lastName, std::string sportPlayed)
{
    this->firstName = firstName;
    this->lastName = lastName;
    this->sportPlayed = sportPlayed;
}

std::ostream& operator<<(std::ostream& output, const Athlete& oneAthlete)
{
    output << "\n\nSport: " << oneAthlete.sportPlayed << "\nAthlete Name: " << oneAthlete.firstName << " " << oneAthlete.lastName;
    return output;
}

bool operator==(const std::string& sport, const Athlete& oneAthlete)
{
    return sport.compare(oneAthlete.sportPlayed) == 0;
}
