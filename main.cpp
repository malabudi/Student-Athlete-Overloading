#include <iostream>
#include "Student.h"
#include "Athlete.h"
#include <vector>

// Function prototypes
void displayMenu();
void addStudent(std::vector<Student>& students, std::vector<Athlete>& athletes);
void askPlayedSport(char& playedSport);
void displayStudents(const std::vector<Student>& students);
void displayOneStudent(const std::vector<Student>& students);
void displayAthletes(const std::vector<Athlete>& athletes);
void displayStudentsByGrade(const std::vector<Student>& students);
void displayStudentsBySport(const std::vector<Athlete>& athletes);
void displayStudentsByGradeAndSport(const std::vector<Student>& students, const std::vector<Athlete>& athletes);


int main()
{
    std::vector<Student> students;
    std::vector<Athlete> athletes;
    int userChoice;

    do
    {
        displayMenu();
        std::cin >> userChoice;

        while (userChoice < 1 || userChoice > 8)
        {
            std::cout << "\nInvalid input, please enter a valid choice from the menu";
            displayMenu();
            std::cin >> userChoice;
        }

        std::cin.ignore(100, '\n');

        switch(userChoice)
        {
            case 1:
                addStudent(students, athletes);
                break;
            case 2:
                displayStudents(students);
                break;
            case 3:
                displayOneStudent(students);
                break;
            case 4:
                displayAthletes(athletes);
                break;
            case 5:
                displayStudentsByGrade(students);
                break;
            case 6:
                displayStudentsBySport(athletes);
                break;
            case 7:
                displayStudentsByGradeAndSport(students, athletes);
                break;
        }
    }
    while (userChoice != 8);

    return 0;
}


void displayMenu()
{
    std::cout << "\n\nPlease choose from the following menu:";
    std::cout << "\n1: Add student";
    std::cout << "\n2: Print a list of enrolled students";
    std::cout << "\n3: Print a list of students by last name";
    std::cout << "\n4: Print a list of students who play sports";
    std::cout << "\n5: Print a list of students by grade";
    std::cout << "\n6: Print a list of students by sport";
    std::cout << "\n7: Print a list of student by grade and sport";
    std::cout << "\n8: Exit program\n";
}

void addStudent(std::vector<Student>& students, std::vector<Athlete>& athletes)
{
    std::string firstName, lastName, sportPlayed;
    int grade;
    char sportChoice;

    std::cout << "\nPlease enter your first name: ";
    std::getline(std::cin, firstName);
    std::cout << "\nPlease enter your last name: ";
    std::getline(std::cin, lastName);
    std::cout << "\nPlease enter your current grade level: ";
    std::cin >> grade;

    while (grade > 12 || grade < 9)
    {
        std::cout << "\nInvalid input, please make your you are entering grade 9-12";
        std::cout << "\nPlease enter your current grade level: ";
        std::cin >> grade;
    }

    Student oneStudent(firstName, lastName, grade);

    do
    {
        askPlayedSport(sportChoice);

        if (sportChoice == 'Y')
        {
            std::cout << "\nPlease enter the name of the sport you are playing: ";
            std::getline(std::cin, sportPlayed);

            Athlete oneAthlete(firstName, lastName, sportPlayed);
            athletes.push_back(oneAthlete);

            oneStudent += oneAthlete.athleticFee;
        }

    } while (sportChoice == 'Y');

    students.push_back(oneStudent);
}

void askPlayedSport(char& sportChoice)
{
    std::cout << "\nDo you currently play a sport? (Y/N) ";
    std::cin >> sportChoice;

    if (sportChoice >= 'a' && sportChoice <= 'z')
        sportChoice -= 32;

    while (sportChoice != 'Y' && sportChoice != 'N')
    {
        std::cout << "\nInvalid input, please enter either Y or N";
        std::cout << "\nDo you currently play a sport? (Y/N) ";
        std::cin >> sportChoice;
        if (sportChoice >= 'a' && sportChoice <= 'z')
            sportChoice -= 32;
    }

    std::cin.ignore(100, '\n');
}

void displayStudents(const std::vector<Student>& students)
{
    for (Student oneStudent : students)
        std::cout << oneStudent;
}

void displayOneStudent(const std::vector<Student>& students)
{
    std::string lastName;
    bool studentFound = false;

    std::cout << "\nPlease enter the last name: ";
    std::getline(std::cin, lastName);

    for (Student oneStudent : students)
    {
        if (lastName == oneStudent)
        {
            std::cout << oneStudent;
            studentFound = true;
        }
    }

    if (studentFound == false)
        std::cout << "\nSorry, the student could not be found.";
}

void displayAthletes(const std::vector<Athlete>& athletes)
{
    for (Athlete oneAthlete : athletes)
        std::cout << oneAthlete;
}

void displayStudentsByGrade(const std::vector<Student>& students)
{
    int grade;

    std::cout << "\nPlease enter the grade level you want to display (9-12): ";
    std::cin >> grade;

    while (grade > 12 || grade < 9)
    {
        std::cout << "\nInvalid input, please make your you are entering grade 9-12";
        std::cout << "\nPlease enter the grade level you want to display (9-12): ";
        std::cin >> grade;
    }

    for (Student oneStudent : students)
    {
        if (grade == oneStudent)
        {
            std::cout << oneStudent;
        }
    }
}

void displayStudentsBySport(const std::vector<Athlete>& athletes)
{
    std::string sportName;

    std::cout << "\nPlease enter the name of the sport you would like to display the students by: ";
    std::getline(std::cin, sportName);

    for (Athlete oneAthlete : athletes)
    {
        if (sportName == oneAthlete)
        {
            std::cout << oneAthlete;
        }
    }
}

void displayStudentsByGradeAndSport(const std::vector<Student>& students, const std::vector<Athlete>& athletes)
{
    int grade;
    std::string sportName;

    std::cout << "\nPlease enter the grade level you want to display (9-12): ";
    std::cin >> grade;

    while (grade > 12 || grade < 9)
    {
        std::cout << "\nInvalid input, please make your you are entering grade 9-12";
        std::cout << "\nPlease enter the grade level you want to display (9-12): ";
        std::cin >> grade;
    }

    std::cin.ignore(100, '\n');

    std::cout << "\nPlease enter the name of the sport you would like to display the students by: ";
    std::getline(std::cin, sportName);


    for (Student oneStudent : students)
    {
        if (grade == oneStudent)
        {
            for (Athlete oneAthlete : athletes)
            {
                if (sportName == oneAthlete && oneAthlete.getLastName() == oneStudent)
                {
                    std::cout << oneStudent;
                }
            }
        }
    }
}
