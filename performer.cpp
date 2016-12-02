#include "performer.h"

Performer::Performer()
{

}


 Performer::Performer(string name, string gender, string bYear, string dYear, string nation)
{
    _name = name;
    _gender = gender;
    _bYear = bYear;
    _dYear = dYear;
    _nation = nation;

}
/*
bool operator ==(const Performer& p1, const Performer& p2)
{
    return p1._name == p2._name;
}
*/
