#include "./student.h"

#define uint unsigned int
#define str std::string

student::student(uint ID, str firstname, str lastname, uint gradelevel, uint math, uint science, uint english, uint history, uint art)
{
    firstName = firstname;
    lastName = lastname;
    studentID = ID;
    gradeLevel = gradelevel;
    Math = math;
    Science = science;
    English = english;
    History = history;
    Art = art;
};

void student::setGradeLevel(int grade)
{
    gradeLevel = grade;
};

uint student::getID()
{
    return studentID;
}

int student::getGradeLevel()
{
    return gradeLevel;
};

void student::setGrade(str subject, uint grade)
{
    if (subject == "Math")
    {
        Math = grade;
    }
    else if (subject == "Science")
    {
        Science = grade;
    }
    else if (subject == "English")
    {
        English = grade;
    }
    else if (subject == "History")
    {
        History = grade;
    }
    else if (subject == "Art")
    {
        Art = grade;
    }
    else
    {
        std::cout << "That subject is not recognized." << std::endl;
    }
};

int student::getGrade(str subject)
{
    if (subject == "Math")
    {
        return Math;
    }
    else if (subject == "Science")
    {
        return Science;
    }
    else if (subject == "English")
    {
        return English;
    }
    else if (subject == "History")
    {
        return History;
    }
    else if (subject == "Art")
    {
        return Art;
    }
};

void student::setFirstName(str first)
{
    firstName = first;
};

void student::setLastName(str last)
{
    lastName = last;
};

str student::getFirstName()
{
    return firstName;
};

str student::getLastName()
{
    return lastName;
};

void student::printData()
{
    std::cout << "Name: "
              << firstName
              << ","
              << lastName
              << " | ID:"
              << studentID
              << " | Grade:"
              << gradeLevel
              << " | Math:"
              << Math
              << " | Science:"
              << Science
              << " | English:"
              << English
              << " | History:"
              << History
              << " | Art:"
              << Art
              << std::endl;
    std::cout << "-----------------------------------------------------------------------------------------------------" << std::endl;
}