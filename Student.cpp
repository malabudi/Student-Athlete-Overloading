#include "Student.h"

Student::Student(std::string firstName, std::string lastName, int grade)
{
    this->firstName = firstName;
    this->lastName = lastName;
    this->grade = grade;
    this->totalFees = 0.00f;
}

Student Student::operator+=(float fees)
{
    this->totalFees = this->totalFees + fees;
    return *this;
}

std::ostream& operator<<(std::ostream& output, Student aStudent)
{
    output << "\n\nName: " << aStudent.firstName << " " << aStudent.lastName << "\nGrade: " << aStudent.grade << "th Grade" << "\nTotal Fees: $" << aStudent.totalFees;
    return output;
}

bool operator==(const std::string& lastName, const Student& oneStudent)
{
    return lastName.compare(oneStudent.lastName) == 0;
}

bool operator==(const int& grade, const Student& oneStudent)
{
    return grade == oneStudent.grade;
}
