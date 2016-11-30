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

/*
void readData (parameters)
{
    ifstream myfile;
    file.open ("info.txt");
    vector <string> information
    for(int i = 0; i < count; i++)

    }


    myfile.close();

    return 0;
}

void writeData (parameters)
{
    ofstream outputFile;
    outputFile.open("InfoTestFile.txt", fstream::app);

    string name;
    string sex;
    int birth;
    int death;

    cout << "Enter name of a Computer Scientist: ";
    cin >> name;
    outputFile << name << ", ";
    cout << "Enter sex: ";
    cin >> sex;
    outputFile << sex << ", ";
    cout << "Enter year of birth: ";
    cin >> birth;
    outputFile << birth << ", ";
    cout << "Enter year of death or -- if alive: ";
    cin >> death;
    outputFile << death << endl;

    outputFile.close();
    cout << "Done!\n";

    return 0;
}
*/
