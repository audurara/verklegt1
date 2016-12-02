#ifndef DATAACCESS_H
#define DATAACCESS_H
#include <vector>
#include "performer.h"

using namespace std;

class DataAccess
{

public:

    void writeData(string all);//Með þessu falli má skrifa streng inn í skrána
    void removeData(string name);//Þetta fall tekur út strenginn sem inniheldur ákveðið nafn

    DataAccess();
    vector<Performer> readData();//Les upplýsingar úr skrá og setur í vektor
    friend bool operator ==(const Performer& p1, const Performer& p2);
};

#endif // DATAACCESS_H
