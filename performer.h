#ifndef PERFORMER_H
#define PERFORMER_H
//#include "dataaccess.h"
#include <string>

using namespace std;

class Performer
{
public:
    Performer();
    Performer(string name, string gender, int bYear, int dYear);
    //nafn, kyn, fæðingarár og dánarár (ef við á).

    string getName() const
    {
        return _name;
    }

    string getGender() const
    {
        return _gender;
    }

    int getbYear() const
    {
        return _bYear;
    }

    int getdYear() const
    {
        return _dYear;
    }


private:

    string _name;
    string _gender;
    int _bYear;
    int _dYear;
};

#endif // PERFORMER_H
