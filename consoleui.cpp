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
    cout << "It is also possible to perform a search of a specific person from the list." << endl << endl;
    for (int i = 0; i < 45*2; ++i)
    {
        cout << "=";
    }
    cout << endl;
    cout << endl;
    cout << "Please enter one of the following commands to continue:" << endl;
    cout << endl;
    commandHelp();

    string command;

    do
    {
        cout << endl << "Enter a command: ";
        cin >> command;
        cout << endl;

        if (command == "list")
        {
            displayListOfPerformers();
        }

        else if (command == "add")
        {
            commandAdd();
        }

        else if (command == "search")
        {
            displaySearch();
        }

        else if(command == "sort")
        {
            chooseSort();
        }

        else if (command == "help")
        {
            commandHelp();
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
    cout << endl;
    cout << "            " << "---- List of all computer scientists in the system ----" << endl;
    cout << endl;
    cout << "Nr" << "\t" << "Name" << "\t\t\t" << "Gender";
    cout << "\t\t" << "Birth year" << "\t\t" << "Deceased" << "\t\t" <<"Nationality" << endl;
    for (int i = 0; i < 54*2; ++i)
    {
        cout << "=";
    }
    cout << endl;



    vector<Performer> pf = _service.getPerformers();

    for (size_t i = 0; i < pf.size(); ++i)
        {
            if(pf[i].getName().length() > 16)
            {
                cout << i+1 << "\t" << pf[i].getName();
                cout << "\t"  << pf[i].getGender() << "\t" << "\t";
                cout << pf[i].getbYear() << "\t\t\t" << pf[i].getdYear();
                cout << "\t\t\t" << pf[i].getNation() << endl;
            }
            else if(pf[i].getName().length() < 16 && pf[i].getName().length() > 8)
            {
                cout << i+1 << "\t" << pf[i].getName();
                cout << "\t\t"  << pf[i].getGender() << "\t" << "\t";
                cout << pf[i].getbYear() << "\t\t\t" << pf[i].getdYear();
                cout << "\t\t\t" << pf[i].getNation() << endl;
            }
            else if(pf[i].getName().length() <= 8)
            {
                cout << i+1 << "\t" << pf[i].getName();
                cout << "\t\t\t"  << pf[i].getGender() << "\t" << "\t";
                cout << pf[i].getbYear() << "\t\t\t" << pf[i].getdYear();
                cout << "\t\t\t" << pf[i].getNation() << endl;
            }
        }
}

void ConsoleUI::displaySearch()
{
    string input;
    cout << "Enter name to search for: ";
    cin.ignore();
    getline(cin, input);

    vector <Performer> newVector = _service.search(input);
    if(newVector.size() == 0)
    {
        cout << "Nothing was found!";
    }
    if(newVector.size() > 0)
    {
        cout << "Nr" << "\t" << "Name" << "\t\t\t" << "Gender";
        cout << "\t\t" << "Birth year" << "\t\t" << "Deceased" << "\t\t" <<"Nationality" << endl;
        for (int i = 0; i < 54*2; ++i)
        {
            cout << "=";
        }
        cout << endl;
    }

    for(size_t i = 0; i < newVector.size(); i++)
    {
        if(newVector[i].getName().length() > 16)
        {
            cout << i+1 << "\t" << newVector[i].getName();
            cout << "\t" << newVector[i].getGender() << "\t" << "\t";
            cout << newVector[i].getbYear() << "\t\t\t" << newVector[i].getdYear();
            cout << "\t\t\t" << newVector[i].getNation() << endl;
        }
        else if(newVector[i].getName().length() < 16 && newVector[i].getName().length() > 8)
        {
            cout << i+1 << "\t" << newVector[i].getName();
            cout << "\t\t" << newVector[i].getGender() << "\t" << "\t";
            cout << newVector[i].getbYear() << "\t\t\t" << newVector[i].getdYear();
            cout << "\t\t\t" << newVector[i].getNation() << endl;
        }
        else if(newVector[i].getName().length() <= 8)
        {
            cout << i+1 << "\t" << newVector[i].getName();
            cout << "\t\t\t" << newVector[i].getGender() << "\t" << "\t";
            cout << newVector[i].getbYear() << "\t\t\t" << newVector[i].getdYear();
            cout << "\t\t\t" << newVector[i].getNation() << endl;
        }
    }


}

void ConsoleUI::displaySort(vector<Performer> newVector)
{
    for(size_t i = 0; i < newVector.size(); i++)
    {
        if(newVector[i].getName().length() > 16)
        {
            cout << i+1 << "\t" << newVector[i].getName();
            cout << "\t" << newVector[i].getGender() << "\t" << "\t";
            cout << newVector[i].getbYear() << "\t\t\t" << newVector[i].getdYear();
            cout << "\t\t\t" << newVector[i].getNation() << endl;
        }
        else if(newVector[i].getName().length() < 16 && newVector[i].getName().length() > 8)
        {
            cout << i+1 << "\t" << newVector[i].getName();
            cout << "\t\t" << newVector[i].getGender() << "\t" << "\t";
            cout << newVector[i].getbYear() << "\t\t\t" << newVector[i].getdYear();
            cout << "\t\t\t" << newVector[i].getNation() << endl;
        }
        else if(newVector[i].getName().length() <= 8)
        {
            cout << i+1 << "\t" << newVector[i].getName();
            cout << "\t\t\t" << newVector[i].getGender() << "\t" << "\t";
            cout << newVector[i].getbYear() << "\t\t\t" << newVector[i].getdYear();
            cout << "\t\t\t" << newVector[i].getNation() << endl;
        }
    }
}
string ConsoleUI::inputName()
{
    string name;
    cin.ignore();
    cout << "Enter full name: ";
    getline(cin, name);

    return name;
}

string ConsoleUI::inputGender()
{
    string gender;
    cout << "Enter gender: ";
    do
    {
        getline(cin, gender);
        if(gender == "Male")
        {
            return gender;
        }
        else if (gender == "male")
        {
            gender = "Male";
            return gender;
        }
        else if(gender == "Female")
        {
            return gender;
        }
        else if (gender == "female")
        {
            gender = "Female";
            return gender;
        }
        else
        {
            cout << "That's not a gender!" << endl;
            cout << "Enter gender: ";
        }
    }while(1 == 1);
    return gender;
}

string ConsoleUI::inputBirth()
{
    string birth;
    cout << "Enter year of birth: ";
    getline(cin, birth);
    int value = atoi(birth.c_str());
    while(value < 0 || value > 2016)
    {
        cout << "That's not a valid year" << endl;
        cout << "Enter year of birth: ";
        getline(cin, birth);
        value = atoi(birth.c_str());
    }
    return birth;
}

string ConsoleUI::inputDeath()
{
    string death;
    cout << "Enter year of death or enter '--' if alive: ";
    getline(cin, death);
    int value = atoi(death.c_str());
    if(death == "--"){
        return death;
    }
    while(value < 0 || value > 2016)
    {
        cout << "That's not a valid year" << endl;
        cout << "Enter year of death: ";
        getline(cin, death);
        value = atoi(death.c_str());
    }

    return death;
}
string ConsoleUI::inputNation()
{
    string nation;
    cout << "Enter Nation: ";
    getline(cin, nation);

    return nation;
}

void ConsoleUI::chooseSort()
{
    int choice;
    cout << "Choose 1 to sort in alphabetical order." << endl;
    cout << "Choose 2 to sort by birth year" << endl;
    cout << "Choose 3 to sort by gender" << endl;
    cout << "Choose 4 to sort by nationality" << endl;
    cout << "Choice: ";
    cin >> choice;

    if(choice == 1)
    {
        vector<Performer> newVector = _service.sortByName();
        cout << endl;
        cout << "              " << "---- List ordered alphabetically by first name ----" << endl;
        cout << endl;
        cout << "Nr" << "\t" << "Name" << "\t\t\t" << "Gender";
        cout << "\t\t" << "Birth year" << "\t\t" << "Deceased" << "\t\t" <<"Nationality" << endl;
        for (int i = 0; i < 54*2; ++i)
        {
            cout << "=";
        }
        cout << endl;
        displaySort(newVector);
    }

    else if(choice == 2)
    {
      cout << endl;
      cout << "                      " << "---- List ordered by birth year ----" << endl;
      cout << endl;
      cout << "Nr" << "\t" << "Name" << "\t\t\t" << "Gender";
      cout << "\t\t" << "Birth year" << "\t\t" << "Deceased" << "\t\t" <<"Nationality" << endl;
      for (int i = 0; i < 54*2; ++i)
      {
          cout << "=";
      }
      cout << endl;
      vector <Performer> newVector = _service.sortBybYear();
      displaySort(newVector);

     }

    else if(choice == 3)
    {
        cout << endl;
        cout << "                       " << "---- List ordered by gender ----" << endl;
        cout << endl;
        cout << "Nr" << "\t" << "Name" << "\t\t\t" << "Gender";
        cout << "\t\t" << "Birth year" << "\t\t" << "Deceased" << "\t\t" <<"Nationality" << endl;
        for (int i = 0; i < 54*2; ++i)
        {
            cout << "=";
        }
        cout << endl;
        vector <Performer> newVector = _service.sortByGender();
        displaySort(newVector);
    }
    else if(choice == 4)
    {
        vector<Performer> newVector = _service.sortByNationality();
        cout << endl;
        cout << "              " << "---- List ordered alphabetically by nationality ----" << endl;
        cout << endl;
        cout << "Nr" << "\t" << "Name" << "\t\t\t" << "Gender";
        cout << "\t\t" << "Birth year" << "\t\t" << "Deceased" << "\t\t" <<"Nationality" << endl;
        for (int i = 0; i < 54*2; ++i)
        {
            cout << "=";
        }
        cout << endl;
        displaySort(newVector);
    }

    else {
        cout << "Invalid choice!";
    }
}

void ConsoleUI::commandHelp()
{
    cout << "list   - This will list all computer scientists in the system" << endl;
    cout << "add    - This will add a new computer scientists" << endl;
    cout << "search - Searches for a given computer scientist" << endl;
    cout << "sort   - Sorts the computer scientists by choice" << endl;
    cout << "help   - displays list of commands" << endl;
    cout << "exit   - This will close the application" << endl;
}

void ConsoleUI::commandAdd()
{
    string name = inputName();
    string gender = inputGender();
    string birth = inputBirth();
    string death = inputDeath();
    int value = 0;
    int value2 = 0;

    if(death != "--")
    {
    value = atoi(birth.c_str());
    value2 = atoi(death.c_str());
    }
    while(value2 < value)
    {
        cout << "Death year can't be less than birth year!" << endl;
        death = inputDeath();
        if(death == "--")
        {
            break;
        }
        value2 = atoi(death.c_str());

    }
    string nation = inputNation();
    _service.addPerformer(name, gender, birth, death, nation);
    cout << endl;
    cout << name << " has been added to the database!" << endl;
}
