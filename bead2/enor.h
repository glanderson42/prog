#ifndef ENOR_H_INCLUDED
#define ENOR_H_INCLUDED

#include <iostream>
#include <fstream>
#include <windows.h>
#include <conio.h>
#include <fstream>
class Results {
private:
    std::string identy;
    std::string typeOfFish;
    double sizeOfFish;
public:
    Results() {}
    Results(std::string i, std::string t, double s);
    std::string getIdenty();
    std::string getTypeOfFish();
    double getSizeOfFish();
    friend std::istream& operator>>(std::istream &in, Results &r);
    friend std::ostream& operator<<(std::ostream &out,const Results& r);
};

std::istream& operator>>(std::istream &in, Results &r);
std::ostream& operator<<(std::ostream &out,const Results& r);

class outResults {
private:
    std::string ident;
    std::string type;
    double maxFish;
public:
    void setIdent(std::string n);
    void setType(std::string t);
    void setMaxFish(double s);
    std::string getIdent();
    std::string getType();
    double getMaxFish();
    friend std::ostream& operator<<(std::ostream &out, const outResults& os);
};

class Enor {
private:
    std::ifstream f;
    std::string filename;
    Results Data;
    outResults cur;
    bool endIs = false;
public:
    Enor(std::string fn);
    void init();
    void first();
    void next();
    bool isEnd();
    outResults current();
};

std::ostream& operator<<(std::ostream &out, const outResults& os);

void doIt(std::string fn);
void echoTask();
void echoMenu(std::string &fn);
void readFromFile(std::string &fn);

#endif // ENOR_H_INCLUDED
