#include <iostream>
#include <string>
#include "consoleui.h"
#include "performer.h"
#include "dataaccess.h"

using namespace std;

ConsoleUI::ConsoleUI()
{

}

// Should not contain logic for individual commands, that should be in separate functions!
void ConsoleUI::run()
{
    cout << endl;
    cout << "This program is designed to keep track of some details on known computer scientists. " << endl;
    cout << "User is able to enter known characters from the history of computer science into a database." << endl;
    cout << "The program can display a list of the characters that have been entered into the database." << endl;
    cout << "It is also possible to perform a search of a specific person from the list." << endl;
    for (int i = 0; i < 45*2; ++i)
    {
        cout << "=";
    }
    cout << endl;
    cout << endl;
    cout << "Please enter one of the following commands to continue:" << endl;
    cout << endl;
    cout << "list   - This will list all computer scientists in the system" << endl;
    cout << "add    - This will add a new computer scientists" << endl;
    cout << "delete - Removes an entry" << endl;
    cout << "update - Updates an entry" << endl;
    cout << "search - Searches for a given computer scientist" << endl;
    cout << "help   - displays list of commands" << endl;
    cout << "exit   - This will close the application" << endl;

    string command;

    do
    {
        cout << endl << "Type a command: ";
        cin >> command;
        cout << endl;
        if (command == "list")
        {
            displayListOfPerformers();
        }

        else if (command == "add")
        {

            _data.writeData();

            //Performer newPerformer(name, gender, bYear, dYear);

            // TODO:
            //_service.addPerformer(newPerformer);
        }

        else if (command == "search")
        {

            string input;
            cout << "Enter name to search for: ";
            cin.ignore();
            getline(cin, input);

            vector <Performer> newVector = _service.search(input);
            for(size_t i = 0; i < newVector.size(); i++)
            {
            cout << "Found:" << endl;
            cout << "----------" << endl;
            cout << "Name: " << newVector[i].getName() << endl;
            cout << "Gender: " << newVector[i].getGender() << endl;
            cout << "Birth year: " << newVector[i].getbYear() << endl;
            cout << "Death year: " << newVector[i].getdYear() << endl;
            cout << endl;
            }

            if(newVector.size() == 0)
            {
                cout << "Nothing was found!";
            }
        }

        else if (command == "delete")
        {
            cout << "Entry removed" << endl;
        }

        else if (command == "help")
        {
            cout << "list   - This will list all computer scientists in the system" << endl;
            cout << "add    - This will add a new computer scientist" << endl;
            cout << "delete - Removes an entry" << endl;
            cout << "update - Updates an entry" << endl;
            cout << "search - Searches for a given computer scientist" << endl;
            cout << "help   - Displays list of commands" << endl;
            cout << "exit   - This will close the application" << endl;
        }

        else if (command == "exit")
        {
            cout << "exiting" << endl;
        }

        else if(command == "data")
        {
            vector<string> logs = _data.readData();

            string choose;
            cin >> choose;
            if(choose == "name")
            {
                for(size_t i = 0; i < logs.size(); i++)
                {
                    cout << logs[i] << endl;
                    i =  i + 3;
                }
            }
            else if(choose == "gender")
            {
                for(size_t i = 0; i < logs.size(); i++)
                {
                    cout << logs[i+1] << endl;
                    i =  i + 3;
                }
            }
            else if(choose == "birth")
            {
                for(size_t i = 0; i < logs.size(); i++)
                {
                    cout << logs[i+2] << endl;
                    i =  i + 3;
                }
            }
            else if(choose == "death")
            {
                for(size_t i = 0; i < logs.size(); i++)
                {
                    cout << logs[i+3] << endl;
                    i =  i + 3;
                }
            }


        }

        else
        {
            cout << "invalid command." << endl;
            cout << "type 'help' to see list of commands" << endl;
        }

    }while (command != "exit");
}

void ConsoleUI::displayListOfPerformers()
{
    vector<Performer> performers = _service.getPerformers();
    //cout << "name" << endl;
    //cout << "===============" << endl;
    cout << "Nr" << "\t" << "Name" << "\t\t" << "Gender";
    cout << "\t\t" << "Birth year" << "\t\t" << "Deceased" << endl;
    for (int i = 0; i < 41*2; ++i)
    {
        cout << "=";
    }
    cout << endl;
    for (size_t i = 0; i< performers.size(); ++i)
    {
        cout << i+1 << "\t" << performers[i].getName()
             << "\t"  << performers[i].getGender() << "\t" << "\t"
             << performers[i].getbYear() << "\t\t\t" << performers[i].getdYear()
             << endl;
    }
}

