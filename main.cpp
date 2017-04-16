#include <iostream>
#include <vector>
#include <fstream>
#include "function.h"

using namespace std;

int main()
{
    vector<vector<int> > data;
    bool run = true;

    while(run) {
        echoMenu(data);
    }
    return 0;
}

