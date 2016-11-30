#include "dataaccess.h"
//#include <ofstream>
#include <fstream>
#include <iostream>
#include <vector>

DataAccess::DataAccess()
{

}



vector<string> DataAccess::readData ()
{
    vector<string> logs;
    string line;

    cout << "Testing loading of file." << endl;
    ifstream myfile ("Info.txt");
    if ( myfile.is_open() )
    {
        while ( ! myfile.eof() )
        {
            getline (myfile, line, ',');
            logs.push_back(line);
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


