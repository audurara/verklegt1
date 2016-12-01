#ifndef PERFORMERSERVICE_H
#define PERFORMERSERVICE_H
#include <vector>
#include "performer.h"
#include "dataaccess.h"
//#include "consoleui.h"

using namespace std;

class PerformerService
{
public:
    PerformerService();
    //
    vector<Performer> getPerformers();
    vector<Performer> search(string name);
    vector<Performer> sortByName();
    vector<Performer> sortBybYear();
    vector<Performer> sortByGender();
    string addPerformer(string name, string gender, string birth, string death);
private:
    DataAccess _data;
};

#endif // PERFORMERSERVICE_H
