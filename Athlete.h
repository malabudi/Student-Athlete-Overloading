#include <string>
#include <iostream>

class Athlete
{
    private:
        std::string firstName;
        std::string lastName;
        std::string sportPlayed;


    public:
        Athlete(std::string firstName, std::string lastName, std::string sportPlayed);

        // This getter used for Extra Credit question
        std::string getLastName();

        static float athleticFee;
        friend std::ostream& operator<<(std::ostream& output, const Athlete& oneAthlete);
        friend bool operator==(const std::string& sport, const Athlete& oneAthlete);
};

