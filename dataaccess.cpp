#include "dataaccess.h"
#include <fstream>

DataAccess::DataAccess()
{

}



vector<Performer> DataAccess::readData() //Les upplýsingar úr skránni og setur í vektor.
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
            // Meðan það skráin er ekki komin á enda mun fyllast í vektorinn
            // og lesa inn nafn,kyn, fæðingarár,dánarár og þjóðerni í þessari röð.
            getline(myfile, name, ',');
            getline(myfile, gender, ',');
            getline(myfile, bYear, ',');
            getline(myfile, dYear, ',');
            getline(myfile, nation, ',');

            Performer P(name, gender, bYear, dYear, nation);
            //Hvert stak í vektornum er strengur með nafni,kyni, fæðingarári, dánarári og þjóðerni.

            logs.push_back(P);
        }
        myfile.close();
    }


    return logs;
}


void DataAccess::writeData (string all) // Með þessu falli má skrifa streng inn í skránna.
{
    ofstream outputFile;
    outputFile.open("Info.txt", fstream::app);
    outputFile << all;

    outputFile.close();
}


