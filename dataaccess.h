#ifndef DATAACCESS_H
#define DATAACCESS_H
#include <vector>
#include "performer.h"

using namespace std;

class DataAccess
{

public:

    void writeData(string all);

    DataAccess();
    DataAccess(char name);
    vector<Performer> readData();
};

#endif // DATAACCESS_H
