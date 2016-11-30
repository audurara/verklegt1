#include "performerservice.h"
#include "dataaccess.h"
#include <algorithm>
#include <iostream>
//#include <ifstream>

using namespace std;

struct PerformerComparison {
  bool operator() (Performer i,Performer j) {
      return (i.getName()<j.getName());
  }
};

PerformerService::PerformerService()
{

}

vector<Performer> PerformerService::getPerformers()

{
    vector<Performer> performers;



    // Sort by name:
    PerformerComparison cmp;
    std::sort(performers.begin(), performers.end(), cmp);



    return performers;
}

/*
vector<Performer> addPerformer(newPerformer) {

    newVector = getPerformers();
    push_back(newPerformer);
    return newVector;
}
*/
vector <Performer> PerformerService:: search(string name)
{
    vector<Performer> pf = getPerformers();
    vector<Performer> newVector;
    for(size_t i = 0; i < pf.size(); i++)
    {

        if(pf[i].getName() == name)
        {
           newVector.push_back(pf[i]);
        }
    }
    return newVector;
}

/*
//delete - Removes an entry" << endl;
// "update
// search - Searches for a given performer" << endl;
*/

