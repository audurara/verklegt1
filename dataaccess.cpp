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
    string name;
    string gender;
    string bYear;
    string dYear;


    ifstream myfile ("InfoTestFile.txt");
    if ( myfile.is_open() )
    {
        while ( ! myfile.eof() )
        {
            getline(myfile, name);
            getline(myfile, gender);
            getline(myfile, bYear);
            getline(myfile, dYear);



            //logs.push_back(name);
            //logs.push_back(gender);
            //logs.push_back(bYear);
            //logs.push_back(dYear);
        }
        myfile.close();
    }
    else
    {
        cout << "Unable to open file." << endl;
    }
    /*
    for(size_t i = 0; i < logs.size(); i++)
    {
        cout << logs[i] << endl;
    }
    */
    return logs;
}


void DataAccess::writeData ()
{
    ofstream outputFile;
    outputFile.open("Info.txt", fstream::app);

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


