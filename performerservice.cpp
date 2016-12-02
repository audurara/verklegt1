#include "performerservice.h"
#include "dataaccess.h"
#include <algorithm>
#include <iostream>

using namespace std;

struct PerformerComparison { //Struct sem ber saman nöfn
  bool operator() (Performer i,Performer j) {
      return (i.getName()<j.getName());
  }
};

struct CompareYear{ //Fæðingarár borin saman
    bool operator() (Performer i, Performer j) {
        int value = atoi(i.getbYear().c_str());
        int value2 = atoi(j.getbYear().c_str());
        return (value < value2);
    }
};

struct CompareGender{ //Kyn borin saman
    bool operator() (Performer i, Performer j) {
        return (i.getGender() > j.getGender());
    }
};

struct CompareNationality{ //Þjóðerni borin saman
    bool operator() (Performer i, Performer j) {
        return (i.getNation() <j.getNation());
    }
};


PerformerService::PerformerService() //Tómur smiður
{

}

vector<Performer> PerformerService::getPerformers() //Nær í gögn úr skrá og skilar þeim í vector
{

   vector<Performer> getPerformers = _data.readData();

   return getPerformers;
}

vector <Performer> PerformerService:: search(string name) //Leitar að ákveðnu nafni í listanum
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

 vector<Performer> PerformerService::sortByName() { //Ber saman nöfn og raðar þeim í stafrófsröð

       vector<Performer> pf = getPerformers();
       PerformerComparison cmp;
       sort(pf.begin(), pf.end(), cmp);

       return pf;
 }

 vector <Performer> PerformerService::sortBybYear() //Ber saman ár og raðar þeim frá því lægsta til þess hæsta
 {
     vector <Performer> pf = getPerformers();
     CompareYear cmp;
     sort(pf.begin(), pf.end(), cmp);
     return pf;
 }

 vector <Performer> PerformerService::sortByGender() //Ber saman kyn
 {
     vector <Performer> pf = getPerformers();
     CompareGender cmp;
     sort(pf.begin(), pf.end(), cmp);
     return pf;
 }

 vector <Performer> PerformerService::sortByNationality() //Ber saman þjóðerni og raðar þeim eftir stafrófsröð
 {
     vector <Performer> pf = getPerformers();
     CompareNationality cmp;
     sort(pf.begin(), pf.end(), cmp);
     return pf;
 }

 string PerformerService::addPerformer(string name, string gender, string birth, string death, string nation) //Bætir nýjum tölvunarfræðingi inn í skrána
 {
    string all = "," + name + "," + gender + "," + birth + "," + death + "," + nation;
    _data.writeData(all);
    return all;
 }

string PerformerService::removeElement(string name) //Skilar til baka streng eftir að hafa eytt einu tilviki
{
    _data.removeData(name);
    return name;
}

