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


    // TODO: business logic!
    Performer p("Duran Duran", 'M', 1950, 1980);
    Performer p2("Madonna Madonna", 'F', 1950, 2000);
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
*/
void PerformerService:: search()
{
    vector<Performer> pf = getPerformers();
    bool found = false;

    string search;
    cout << "Enter name to search for: ";
    cin.ignore();
    getline(cin, search);

    for(size_t i = 0; i < pf.size(); i++)
    {
        if(pf[i].getName() == search)
        {
            cout << "Found:" << endl;
            cout << "Name: " << pf[i].getName() << endl;
            cout << "Gender: " << pf[i].getGender() << endl;
            cout << "Birth year: " << pf[i].getbYear() << endl;
            cout << "Death year: " << pf[i].getdYear() << endl;
            found = true;
        }
        else if(i == pf.size() -1 && found == false)
        {
            cout << "Not found!" << endl;
        }
    }
}

/*
//delete - Removes an entry" << endl;
// "update
// search - Searches for a given performer" << endl;
*/

