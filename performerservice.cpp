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

   vector<Performer> getPerformers = _data.readData();

   return getPerformers;
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
       sort(pf.begin(), pf.end(), cmp);

       return pf;
 }

 vector <Performer> PerformerService::sortBybYear()
 {
     vector <Performer> pf = getPerformers();
     CompareYear cmp;
     sort(pf.begin(), pf.end(), cmp);
     return pf;
 }

 vector <Performer> PerformerService::sortByGender()
 {
     vector <Performer> pf = getPerformers();
     CompareGender cmp;
     sort(pf.begin(), pf.end(), cmp);
     return pf;
 }

 string PerformerService::addPerformer(string name, string gender, string birth, string death)
 {
    string all = "," + name + "," + gender + "," + birth + "," + death;
    _data.writeData(all);
    return all;
 }


