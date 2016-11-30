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
    void search();
};

#endif // PERFORMERSERVICE_H
