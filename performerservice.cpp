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

struct CompareYear{
    bool operator() (Performer i, Performer j) {
        return (i.getbYear() < j.getbYear());
    }
};

struct CompareGender{
    bool operator() (Performer i, Performer j) {
        return (i.getGender() > j.getGender());
    }
};

PerformerService::PerformerService()
{

}

vector<Performer> PerformerService::getPerformers()

{
    vector<Performer> performers;


    Performer p("Duran Duran", "M", 1950, 1980);
    Performer p2("Madonna", "F", 1950, 2000);
    Performer p3("David Bowie", "M", 1950, 2016);
    Performer p4("David Bowie", "M", 1945, 2000);


    performers.push_back(p);
    performers.push_back(p2);
    performers.push_back(p3);
    performers.push_back(p4);


    // Sort by name:
    PerformerComparison cmp;
    std::sort(performers.begin(), performers.end(), cmp);

        return performers;
}

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

 vector<Performer> PerformerService::sortByName() {

       vector<Performer> pf = getPerformers();
       PerformerComparison cmp;
       std::sort(pf.begin(), pf.end(), cmp);

       return pf;
 }

 vector <Performer> PerformerService::sortBybDay()
 {
     vector <Performer> pf = getPerformers();
     CompareYear cmp;
     std::sort(pf.begin(), pf.end(), cmp);
     return pf;
 }

 vector <Performer> PerformerService::sortByGender()
 {
     vector <Performer> pf = getPerformers();
     CompareYear cmp;
     std::sort(pf.begin(), pf.end(), cmp);
     return pf;
 }


