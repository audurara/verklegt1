#ifndef PERFORMER_H
#define PERFORMER_H

#include <string>

using namespace std;

class Performer
{
public:
    Performer();
    Performer(string name, int age);

    string getName() const
    {
        return _name;
    }

    string getSex() const
    {
        return _sex;
    }
    int getBirth() const
    {
        return _birth;
    }
    int getDeath() const
    {
        return _death;
    }

private:

    string _name;
    string _sex;
    int _birth;
    int _death;
};

#endif // PERFORMER_H
