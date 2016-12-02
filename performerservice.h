#ifndef PERFORMERSERVICE_H
#define PERFORMERSERVICE_H
#include "performer.h"
#include "dataaccess.h"

using namespace std;

class PerformerService
{
public:
    PerformerService();
    //
    vector<Performer> getPerformers(); //Nær í gögn úr skrá og skilar þeim í vector
    vector<Performer> search(string name); //Leitar að ákveðnu nafni í listanum
    vector<Performer> sortByName(); //Ber saman nöfn og raðar þeim í stafrófsröð
    vector<Performer> sortBybYear(); //Ber saman ár og raðar þeim frá því lægsta til þess hæsta
    vector<Performer> sortByGender(); //Ber saman kyn
    vector<Performer> sortByNationality(); //Ber saman þjóðerni og raðar þeim eftir stafrófsröð
    string removeElement(string name); //Skilar til baka streng eftir að hafa eytt einu tilviki.
    string addPerformer(string name, string gender, string birth, string death, string nation); //Bætir nýjum tölvunarfræðingi inn í skrána
private:
    DataAccess _data;// Sækir upplýsingar og leyfir virkni úr DataAccess.
};

#endif // PERFORMERSERVICE_H
