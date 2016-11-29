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
    vector<Performer> performers;


    // TODO: business logic!
    Performer p("Duran Duran", 'M', 1950, 1980);
    Performer p2("Madonnaaaaaaa", 'F', 1950, 2000);
    Performer p3("David Bowie", 'M', 1950, 2016);

    performers.push_back(p);
    performers.push_back(p2);
    performers.push_back(p3);

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
*/
//delete - Removes an entry" << endl;
// "update
// search - Searches for a given performer" << endl;
