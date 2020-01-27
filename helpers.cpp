#include "helpers.h"

#define uint unsigned int
#define str std::string

void printMenu()
{
    std::cout << "SYSTEM MENU" << std::endl;
    std::cout << "1. Create new student record" << std::endl;
    std::cout << "2. Display all student records" << std::endl;
    std::cout << "3. Search student record by ID" << std::endl;
    std::cout << "4. Search student record by name" << std::endl;
    std::cout << "5. Modify student record" << std::endl;
    std::cout << "6. Delete student record" << std::endl;
    std::cout << "7. Exit & SAVE" << std::endl;
    std::cout << "Please enter a command (1-7)" << std::endl;
}

void printHeader()
{
    std::cout << "============================================================================================================" << std::endl;
    std::cout << "||                                        STUDENT RECORDS                                                 ||" << std::endl;
    std::cout << "============================================================================================================" << std::endl;
}

void readFile(std::ifstream &file, std::vector<student> &students, uint &studentID)
{
    str line;
    while (std::getline(file, line))
    {
        str params[9];
        int k = 0;
        str temp;

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
        students.push_back(student(std::stoul(params[0]), params[2], params[1], std::stoul(params[3]), std::stoul(params[4]), std::stoul(params[5]), std::stoul(params[6]), std::stoul(params[7]), std::stoul(params[8])));
    }
}