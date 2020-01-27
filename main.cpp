#include "main.h"
#include "student.h"
#include "helpers.h"

#define uint unsigned int
#define str std::string
#define CLS std::cout << str(100, '\n')

int main()
{
    std::vector<student> students;
    std::ifstream studentDataRead("students.csv");
    uint studentID = 1;
    readFile(studentDataRead, students, studentID);

    bool repeat = true;
    while (repeat)
    {
        printMenu();
        str command;
        std::getline(std::cin, command);
        CLS;

        if (command == "0")
        {
        }

        if (command == "1")
        {
            // Create new student record
            str params[] = {std::to_string(studentID), "", "", "1", "1", "1", "1", "1", "1"};
            str paramItems[] = {std::to_string(studentID), "First Name:", "Last Name:", "Grade Level: (1-12)", "Math Score: (0-100)", "Science Score: (0-100)", "English Score: (0-100)", "History Score: (0-100)", "Art Score: (0-100)"};
            int iter = 1;
            while (iter < 9)
            {
                std::cout << paramItems[iter] << std::endl;
                if (iter < 3)
                {
                    str userInput;
                    std::cin >> userInput;
                    if (std::cin.good())
                    {
                        params[iter] = userInput;
                        iter = iter + 1;
                    }
                    else
                    {
                        std::cout << "Please enter a valid name" << std::endl;
                    }
                }
                else if (iter == 3)
                {
                    int userInput;
                    std::cin >> userInput;
                    if (std::cin.good() && userInput >= 1 && userInput <= 12)
                    {
                        params[iter] = std::to_string(userInput);
                        iter = iter + 1;
                    }
                    else
                    {
                        std::cout << "Please enter a valid integer between 1 and 12" << std::endl;
                    }
                }
                else
                {
                    int userInput;
                    std::cin >> userInput;
                    if (std::cin.good() && userInput >= 0 && userInput <= 100)
                    {
                        params[iter] = std::to_string(userInput);
                        iter = iter + 1;
                    }
                    else
                    {
                        std::cout << "Please enter a valid integer between 0 and 100" << std::endl;
                    }
                }
            }
            // for (const str &text : params)
            //     std::cout << "value of text: " << text << std::endl;

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
            if (!inputID.empty())
            {
                for (student student : students)
                {
                    if (std::stoul(inputID) == student.getID())
                    {
                        student.printData();
                        break;
                    }
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
            if (!lastName.empty())
            {
                for (student student : students)
                {
                    if (lastName == student.getLastName())
                        student.printData();
                }
            }
        }
        else if (command == "5")
        {
            // Modify student record
            str classes[5] = {"Math", "Science", "English", "History", "Art"};
            str inputID;
            std::cout << "Input Student ID" << std::endl;
            std::getline(std::cin, inputID);
            if (!inputID.empty())
            {
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
        }
        else if (command == "6")
        {
            // Delete student record
            std::cout << "Input Student ID to Delete" << std::endl;
            str inputID;
            std::getline(std::cin, inputID);
            if (!inputID.empty())
            {
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
        }
        else if (command == "7")
        {
            // Save and Quit
            std::ofstream studentDatabase("students.csv");
            studentDatabase.clear();
            for (int i = 0; i < students.size(); i++)
            {
                studentDatabase << std::to_string(students[i].getID()) + ','
                                << students[i].getLastName() + ','
                                << students[i].getFirstName() + ','
                                << std::to_string(students[i].getGradeLevel()) + ','
                                << std::to_string(students[i].getGrade("Math")) + ','
                                << std::to_string(students[i].getGrade("Science")) + ','
                                << std::to_string(students[i].getGrade("English")) + ','
                                << std::to_string(students[i].getGrade("History")) + ','
                                << std::to_string(students[i].getGrade("Art"));
                if (i < students.size() - 1)
                    studentDatabase << '\n';
            }
            repeat = false;
            studentDatabase.close();
        }

        std::cout << "Press Enter to continue/confirm" << std::endl;
        str temp;
        std::getline(std::cin, temp);
        CLS;
    }

    return 0;
}