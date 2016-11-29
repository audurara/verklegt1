#include <iostream>
#include <string>
#include "consoleui.h"
#include "performer.h"

using namespace std;

ConsoleUI::ConsoleUI()
{

}

// Should not contain logic for individual commands, that should be in separate functions!
void ConsoleUI::run()
{
    cout << "Please enter one of the following commands:" << endl;
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



            //Performer newPerformer(name, gender, bYear, dYear);

            // TODO:
            //_service.addPerformer(newPerformer);
        }

        else if (command == "search")
        {
            // TODO
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
    cout << "\t" << "Name" << "\t\t" << "Gender";
    cout << "\t\t" << "Birth year" << "\t\t" << "Deceased" << endl;
    cout << "\t";
    for (size_t i = 2; i < 28*2; ++i)
    {
        cout << "=";
    }
    cout << endl;
    for (size_t i = 0; i< performers.size(); ++i)
    {
        cout << i+1 << " | " << "\t" << performers[i].getName()
             << "\t" /* << performers[i].getGender << "\t" << performers[i].getSex()
             << "\t" << performers[i].getBirth() << "\t" << performers[i].getDeath() */ << endl;
    }
}

