#ifndef PERFORMER_H
#define PERFORMER_H
//#include "dataaccess.h"
#include <string>

using namespace std;

class Performer
{
public:
    Performer();
    Performer(string name, string gender, string bYear, string dYear);
    //nafn, kyn, fæðingarár og dánarár (ef við á).

    string getName() const
    {
        return _name;
    }

    string getGender() const
    {
        return _gender;
    }

    string getbYear() const
    {
        return _bYear;
    }

    string getdYear() const
    {
        return _dYear;
    }


private:

    string _name;
    string _gender;
    string _bYear;
    string _dYear;
};

#endif // PERFORMER_H
