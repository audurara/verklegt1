#ifndef DATAACCESS_H
#define DATAACCESS_H
//#include <ofstream>
#include <istream>
#include <iostream>
#include <vector>
#include "performer.h"

// basic file operations
#include <iostream>
//#include <fstream>
using namespace std;

class DataAccess
{

public:

    void writeData();

    DataAccess();
    DataAccess(char name);
    vector<Performer> readData();
};

#endif // DATAACCESS_H
