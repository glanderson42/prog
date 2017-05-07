#ifndef FUNCTIONS
#define FUNCTIONS

#include <iostream>
#include <vector>
#include <fstream>
#include <conio.h>
#include <windows.h>
#include <iomanip>

enum Exception {
    WI,
    NC,
    WV
};

template<class T>
std::istream& operator>>(std::istream& in, std::vector<T> &data);
std::istream& operator>>(std::istream& in, std::vector<int> &data);
std::ostream& operator<<(std::ostream& out, const std::vector<std::vector<int> > &data);

void echoMenu(std::vector<std::vector<int> > &data);
void echoTask();
void readFromStandardInput(std::vector<std::vector<int> > &data);
void readFromFile(std::vector<std::vector<int> > &data);
std::vector<std::vector<int> > loadFromFile(std::vector<std::vector<int> > &data);
std::vector<std::vector<int> > standardInput(std::vector<std::vector<int> > &data);
bool existsVillageWithAllBirds(const std::vector<std::vector<int> > &v);
bool isColumnNonzero(const std::vector<std::vector<int> > &v,const int col);
#endif
