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
    cout << "sort   - Sorts the computer scientists by choice" << endl;
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

        else if(command == "sort")
        {
            int choice;
            cout << "Choose 1 to sort in alphabetical order." << endl;
            cout << "Choose 2 to sort by birth year" << endl;
            cout << "Choose 3 to sort by gender" << endl;
            cout << "Choice: ";
            cin >> choice;
            if(choice == 1) {

                vector<Performer> newVector = _service.sortByName();
                cout << "---- List ordered by name ----" << endl;

                for(size_t i = 0; i < newVector.size(); i++) {
                    cout << newVector[i].getName() << endl;
                }
            }
            else if(choice == 2)
            {
              cout << "---- List ordered by birth year ----" << endl;
              vector <Performer> newVector = _service.sortBybDay();
              for(size_t i = 0; i < newVector.size(); i++)
              {
                    cout << newVector[i].getName() << ", birth year: ";
                    cout << newVector[i].getbYear() << endl;
              }

             }

            else if(choice == 3)
            {
                cout << "---- List ordered by gender ----" << endl;
                vector <Performer> newVector = _service.sortByGender();
                for(size_t i = 0; i < newVector.size(); i++)
                {
                      cout << newVector[i].getName() << ", gender: ";
                      cout << newVector[i].getGender() << endl;
                }
            }

            else {
                cout << "Invalid choice!";
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

        else
        {
            cout << "invalid command." << endl;
            cout << "type 'help' to see list of commands" << endl;
        }

    }while (command != "exit");
}

void ConsoleUI::displayListOfPerformers()
{
    cout << "Nr" << "\t" << "Name" << "\t\t\t" << "Gender";
    cout << "\t\t" << "Birth year" << "\t\t" << "Deceased" << endl;
    for (int i = 0; i < 41*2; ++i)
    {
        cout << "=";
    }
    cout << endl;



    vector<Performer> pf = _data.readData();

    for (size_t i = 0; i< pf.size() - 4; ++i)
        {
            if(pf[i].getName().length() > 16)
            {
                cout << i+1 << "\t" << pf[i].getName();
                cout << "\t"  << pf[i].getGender() << "\t" << "\t";
                cout << pf[i].getbYear() << "\t\t\t" << pf[i].getdYear();
                cout << endl;
            }
            else if(pf[i].getName().length() < 16 && pf[i].getName().length() > 8)
            {
                cout << i+1 << "\t" << pf[i].getName();
                cout << "\t\t"  << pf[i].getGender() << "\t" << "\t";
                cout << pf[i].getbYear() << "\t\t\t" << pf[i].getdYear();
                cout << endl;
            }
            else if(pf[i].getName().length() <= 8)
            {
                cout << i+1 << "\t" << pf[i].getName();
                cout << "\t\t\t"  << pf[i].getGender() << "\t" << "\t";
                cout << pf[i].getbYear() << "\t\t\t" << pf[i].getdYear();
                cout << endl;
            }
        }
}

