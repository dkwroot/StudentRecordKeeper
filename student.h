#pragma once
#include <string>

#define uint unsigned int
#define str std::string

class student
{
public:
    student(uint ID, str firstName, str lastName, uint gradelevel, uint Math, uint Science, uint English, uint History, uint Art);
    uint getID();
    void setGradeLevel(int grade);
    int getGradeLevel();
    void setGrade(str subject, uint grade);
    int getGrade(str subject);
    void setFirstName(str first);
    void setLastName(str last);
    str getFirstName();
    str getLastName();
    void printData();

private:
    str firstName = "John";
    str lastName = "Doe";
    uint studentID = 0;
    uint gradeLevel = 0;
    uint Math = 0;
    uint Science = 0;
    uint English = 0;
    uint History = 0;
    uint Art = 0;
};