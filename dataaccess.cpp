#include "dataaccess.h"
#include "performer.h"
//#include <ofstream>
#include <fstream>
#include <iostream>
#include <vector>

DataAccess::DataAccess()
{

}



vector<Performer> DataAccess::readData()
{
    vector<Performer> logs;
    Performer logs2;
    string name;
    string gender;
    string bYear;
    string dYear;


    ifstream myfile ("InfoTestFile.txt");
    if ( myfile.is_open() )
    {
        while ( ! myfile.eof() )
        {
            getline(myfile, name, ',');
            getline(myfile, gender, ',');
            getline(myfile, bYear, ',');
            getline(myfile, dYear, ',');

            Performer P(name, gender, bYear, dYear);


            logs.push_back(P);
        }
        myfile.close();
    }
    else
    {
        cout << "Unable to open file." << endl;
    }

    return logs;
}


void DataAccess::writeData ()
{
    ofstream outputFile;
    outputFile.open("InfoTestFile.txt", fstream::app);

    string name;
    string sex;
    int birth;
    string death;
    cin.ignore();
    cout << "Enter name of a Computer Scientist: ";
    getline(cin,name);
    outputFile << name << ", ";
    cout << "Enter sex: ";
    getline(cin,sex);
    outputFile << sex << ", ";
    cout << "Enter year of birth: ";
    cin >> birth;
    outputFile << birth << ", ";
    cout << "Enter year of death or -- if alive: ";
    cin.ignore();
    getline(cin,death);
    outputFile << death << ", " << endl;

    outputFile.close();
    cout << "Done!\n";
}


