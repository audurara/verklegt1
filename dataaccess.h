#ifndef DATAACCESS_H
#define DATAACCESS_H
//#include <ofstream>
#include <istream>
#include <iostream>
#include <vector>

// basic file operations
#include <iostream>
//#include <fstream>
using namespace std;

class DataAccess
{

public:

    /*
    void writeData (parameters)


    vector <string> computerguys
    */
    DataAccess();
    DataAccess(char name);
    vector<string> readData();
};

#endif // DATAACCESS_H
