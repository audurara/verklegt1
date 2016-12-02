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
    void removeData(string name);
    friend bool operator ==(const Performer& p1, const Performer& p2);
};

#endif // DATAACCESS_H
