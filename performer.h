#ifndef PERFORMER_H
#define PERFORMER_H

#include <string>

using namespace std;

class Performer
{
public:
    Performer();
    Performer(string name, char gender, int bYear, int dYear);
    //nafn, kyn, fæðingarár og dánarár (ef við á).

    string getName() const
    {
        return _name;
    }

    char getGender() const
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
    char _gender;
    int _bYear;
    int _dYear;
};

#endif // PERFORMER_H
