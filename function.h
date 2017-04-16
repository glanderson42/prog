#ifndef THEM_WRONG
#define THEM_WRONG

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


bool task(const std::vector<std::vector<int> >& v);
void echoMenu(std::vector<std::vector<int> > &data);
void fileLoad(std::vector<std::vector<int> > &data);
void standardInput(std::vector<std::vector<int> > &data);
bool existsVillageWithAllBirds(const std::vector<std::vector<int> > &v);
bool isColumnNonzero(const std::vector<std::vector<int> > &v,const int col);
#endif
