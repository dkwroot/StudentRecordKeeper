#ifndef HELPERS_H__
#define HELPERS_H__

#include "student.h"

#include <vector>
#include <fstream>

void printMenu();
void printHeader();
void readFile(std::ifstream &, std::vector<student> &, uint &);

#endif