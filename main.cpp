#include "main.h"
#include "student.h"

#include <vector>
#include <iostream>
#include <fstream>

#define CLS std::cout << str(100, '\n')

void printHeader()
{
    std::cout << "============================================================================================================" << std::endl;
    std::cout << "||                                        STUDENT RECORDS                                                 ||" << std::endl;
    std::cout << "============================================================================================================" << std::endl;
}

int main()
{
    std::vector<student> students;
    std::ifstream studentDataRead("students.csv", std::fstream::app);
    str line;
    uint studentID = 1;
    while (std::getline(studentDataRead, line))
    {
        str params[9];
        int k = 0;
        str temp;

        // for (char &c : line)
        for (int i = 0; i < line.size(); i++)
        {
            if (line[i] == ',')
            {
                params[k] = temp;
                k = k + 1;
                temp.clear();
            }
            else
            {
                temp = temp + line[i];
            }
        }
        if (std::stoul(params[0]) >= studentID)
            studentID = std::stoul(params[0]) + 1;
        params[8] = temp;
        students.push_back(student(std::stoul(params[0]), params[1], params[2], std::stoul(params[3]), std::stoul(params[4]), std::stoul(params[5]), std::stoul(params[6]), std::stoul(params[7]), std::stoul(params[8])));
    }
    std::ofstream studentDatabase("students.csv", std::fstream::app);
    bool repeat = true;
    while (repeat)
    {
        str command;

        std::cout << "SYSTEM MENU" << std::endl;
        std::cout << "1. Create new student record" << std::endl;
        std::cout << "2. Display all student records" << std::endl;
        std::cout << "3. Search student record by ID" << std::endl;
        std::cout << "4. Search student record by name" << std::endl;
        std::cout << "5. Modify student record" << std::endl;
        std::cout << "6. Delete student record" << std::endl;
        std::cout << "7. Exit" << std::endl;
        std::cout << "Please enter a command (1-7)" << std::endl;
        std::getline(std::cin, command);

        CLS;

        if (command == "7")
        {
            repeat = false;
            studentDatabase.close();
        }
        else if (command == "1")
        {
            // Create new student record
            str params[] = {std::to_string(studentID), "First Name:", "Last Name:", "Grade Level:", "Math Score:", "Science Score:", "English Score:", "History Score:", "Art Score:"};
            for (int i = 1; i < 9; i++)
            {
                std::cout << params[i] << std::endl;
                std::getline(std::cin, params[i]);
            }
            for (int i = 0; i < 9; i++)
            {
                studentDatabase << params[i];
                if (i < 8)
                    studentDatabase << ',';
            }
            studentDatabase << '\n';
            students.push_back(student(studentID, params[1], params[2], std::stoul(params[3]), std::stoul(params[4]), std::stoul(params[5]), std::stoul(params[6]), std::stoul(params[7]), std::stoul(params[8])));
            studentID = studentID + 1;
        }
        else if (command == "2")
        {
            // Display all student records
            printHeader();
            for (student student : students)
                student.printData();
        }
        else if (command == "3")
        {
            // Search for record by student ID
            std::cout << "Input Student ID" << std::endl;
            str inputID;
            std::getline(std::cin, inputID);
            printHeader();
            for (student student : students)
            {
                if (std::stoul(inputID) == student.getID())
                {
                    student.printData();
                    break;
                }
            }
        }
        else if (command == "4")
        {
            // Search for record by student name
            str lastName;
            std::cout << "Input last name of student" << std::endl;
            std::getline(std::cin, lastName);
            printHeader();
            for (student student : students)
            {
                if (lastName == student.getLastName())
                    student.printData();
            }
        }
        else if (command == "5")
        {
            // Modify student record
            str classes[5] = {"Math", "Science", "English", "History", "Art"};
            str inputID;
            std::cout << "Input Student ID" << std::endl;
            std::getline(std::cin, inputID);
            for (int i = 0; i < students.size(); i++)
            {
                if (std::stoi(inputID) == students[i].getID())
                {
                    str strInput;
                    std::cout << "Change first name or press enter to skip" << std::endl;
                    std::getline(std::cin, strInput);
                    if (!strInput.empty())
                    {
                        students[i].setFirstName(strInput);
                    }

                    std::cout << "Change last name or press enter to skip" << std::endl;
                    std::getline(std::cin, strInput);
                    if (!strInput.empty())
                    {
                        students[i].setLastName(strInput);
                    }

                    std::cout << "Change grade level or press enter to skip" << std::endl;
                    std::getline(std::cin, strInput);
                    if (!strInput.empty())
                    {
                        students[i].setGradeLevel(std::stoul(strInput));
                    }

                    for (int j = 0; j < 5; j++)
                    {
                        std::cout << "Change " << classes[j] << " score or press enter to skip" << std::endl;
                        std::getline(std::cin, strInput);
                        if (!strInput.empty())
                        {

                            students[i].setGrade(classes[j], std::stoul(strInput));
                        }
                    }
                }
            }
        }
        else if (command == "6")
        {
            // Delete student record
            std::cout << "Input Student ID to Delete" << std::endl;
            str inputID;
            std::getline(std::cin, inputID);
            for (int i = 0; i < students.size(); i++)
            {
                if (std::stoul(inputID) == students[i].getID())
                {
                    students.erase(students.begin() + i);
                    break;
                }
            }
            std::cout << "Student Record ID: " << inputID << " has been deleted." << std::endl;
        }

        std::cout << "Press Enter to continue/confirm" << std::endl;
        str temp;
        std::getline(std::cin, temp);
        CLS;
    }

    return 0;
}