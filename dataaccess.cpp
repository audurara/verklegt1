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
    string nation;


    ifstream myfile ("Info.txt");
    if ( myfile.is_open() )
    {
        while ( ! myfile.eof() )
        {
            getline(myfile, name, ',');
            getline(myfile, gender, ',');
            getline(myfile, bYear, ',');
            getline(myfile, dYear, ',');
            getline(myfile, nation, ',');

            Performer P(name, gender, bYear, dYear, nation);


            logs.push_back(P);
        }
        myfile.close();
    }


    return logs;
}


void DataAccess::writeData (string all)
{
    ofstream outputFile;
    outputFile.open("Info.txt", fstream::app);
    outputFile << all;

    outputFile.close();
}


