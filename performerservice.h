#ifndef PERFORMERSERVICE_H
#define PERFORMERSERVICE_H
#include <vector>
#include "performer.h"
#include "dataaccess.h"

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
    vector<Performer> sortByNationality();
    string addPerformer(string name, string gender, string birth, string death, string nation);
private:
    DataAccess _data;
};

#endif // PERFORMERSERVICE_H
