#include <string>
#include <iostream>

class Student
{
    private:
        std::string firstName;
        std::string lastName;
        int grade;
        float totalFees;

    public:
        Student(std::string firstName, std::string lastName, int grade);

        Student operator+=(float fees);
        friend std::ostream& operator<<(std::ostream& output, Student aStudent);
        friend bool operator==(const std::string& lastName, const Student& oneStudent);
        friend bool operator==(const int& lastName, const Student& oneStudent);
};

