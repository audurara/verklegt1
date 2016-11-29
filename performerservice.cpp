#include "performerservice.h"
#include <algorithm>

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
    //performers = ..


    // TODO: business logic!

    /*
    // Sort by name:
    PerformerComparison cmp;
    std::sort(performers.begin(), performers.end(), cmp);

    */

    return performers;
}

vector<Performer> addPerformer(newPerformer) {

    newVector = getPerformers();
    push_back(newPerformer);
    return newVector;
}

void search(string search) {

    performers = getPerformers();

    if(perfomers[i].name == search) {
         cout << performers[i].getName() << endl;
         cout << performers[i].getGender() << endl;
         cout << performers[i].getbYear() << endl;
         cout << perfoerms[i].getdyear() << endl;
    }
    else {
        cout << "Scientist not found!";
    }
}

//delete - Removes an entry" << endl;
// "update
// search - Searches for a given performer" << endl;
