#include <iostream>
#include "consoleui.h"
#include "performer.h"
#include "dataaccess.h"

using namespace std;

ConsoleUI::ConsoleUI()
{

}

void ConsoleUI::run()
{
    intro(); // Prentar upphafsskilaboð
    commandHelp(); // Prentar lista yfir skipanir

    string command;

    do
    {
        cout << endl << "Enter a command ('help' for list of commands): ";
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

        else if (command == "delete")
        {
            string namedel = deleteElement();
            _service.removeElement(namedel);
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
            cout << "Enter 'help' to see list of commands" << endl;
        }

    }while (command != "exit");
}

void ConsoleUI::displayListOfPerformers() //Prentar lista af tölvunarfræðingum
{
    cout << endl;
    cout << "                      " << "---- List of all computer scientists in the system ----" << endl;
    cout << endl;

    displayTopTable();

    vector<Performer> pf = _service.getPerformers();

    for (size_t i = 0; i < pf.size(); ++i) //Prentar út listann miðað við lengd nafns svo það passi sem best
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

void ConsoleUI::displaySearch() //Prentar út leitarniðurstöður
{
    string input;
    cout << "Enter full name of computer scientist (the search is case-sensitive): ";
    cin.ignore();
    getline(cin, input);

    vector <Performer> newVector = _service.search(input);
    if(newVector.size() == 0)
    {
        cout << "Nothing was found! Please enter 'search' to try again" << endl;
    }
    if(newVector.size() > 0)
    {
        cout << endl;
        cout << "                            " << "---- Result of your search in the system ----" << endl;
        cout << endl;

        displayTopTable();
    }

    for(size_t i = 0; i < newVector.size(); i++) //Forlykkja prentar niðurstöður miðað við lengd nafns svo það passi sem best
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

void ConsoleUI::displaySort(vector<Performer> newVector) //Prentar út niðurstöður úr röðun
{
    for(size_t i = 0; i < newVector.size(); i++) //Forlykkja prentar niðurstöður miðað við lengd nafns svo það passi sem best
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
string ConsoleUI::inputName() //Setur inn nafn
{
    string name;
    cout << "Enter full name: ";
    cin.ignore();
    getline(cin, name);

    int nameLength = name.length();

    for(int i = 0;i < nameLength;i++)
     {
        while(!isalpha(name[i]) && name[i] != ' ') //Passar að inntak fyrir nafn sé ekki tala eða tómt
               {
                   cout << "Invalid input, please try again: ";
                   cin.ignore();
                   getline(cin, name);
                   nameLength = name.length();
                }
    }
    return name;
}

string ConsoleUI::inputGender() //Setur inn kyn
{
    string gender;
    cout << "Enter gender (Male or Female): ";
    do //Passar að öll prentuð kyn séu annaðhvort "Male" eða "Female"
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
            cout << "Invalid input, please try again." << endl;
            cout << "Enter gender (Male or Female): ";
        }
    }while(1 == 1);
    return gender;
}

string ConsoleUI::inputBirth() //Setur inn fæðingarár
{
    string birth;
    cout << "Enter year of birth: ";
    getline(cin, birth);
    int value = atoi(birth.c_str());
    int birthLength = birth.length();

    for(int i = 0;i < birthLength;i++)
     {
        while(!isdigit(birth[i])) //Ef fæðingarár er ekki tala fæst villa
               {
                   cout << "Invalid input, please try again: ";
                   getline(cin, birth);
                   birthLength = birth.length();
               }
    }

    while(value < 0 || value > 2016) //Ef fæðingarár er undir 0 eða yfir 2016 fæst villa
    {
        cout << "That is not a valid year" << endl;
        cout << "Enter year of birth: ";
        getline(cin, birth);
        value = atoi(birth.c_str()); //Breytir strengnum fyrir fæðingarár í tölu.
    }
    return birth;
}

string ConsoleUI::inputDeath() //Setur inn dánarár
{
    string death;
    cout << "Enter year of death or enter '--' if person is alive: ";
    getline(cin, death);
    int value = atoi(death.c_str());
    if(death == "--")
    {
        return death;
    }
    int deathLength = death.length();

    for(int i = 0;i < deathLength;i++)
     {
        while(!isdigit(death[i])) //Ef dánarár er ekki tala fæst villa
               {
                   cout << "Invalid input, please try again: ";
                   getline(cin, death);
                   deathLength = death.length();
               }
    }
    while(value < 0 || value > 2016) //Ef dánarár er undir 0 eða yfir 2016 fæst villa
    {
        cout << "That's not a valid year" << endl;
        cout << "Enter year of death: ";
        getline(cin, death);
        value = atoi(death.c_str());
    }

    return death;
}
string ConsoleUI::inputNation() //Setur inn þjóðerni
{
    string nation;
    cout << "Enter Nationality: ";
    getline(cin, nation);

    int nationLength = nation.length();

    for(int i = 0;i < nationLength;i++)
     {
        while(!isalpha(nation[i])) //Ef þjóðerni er ekki bókstafur fæst villa
               {
                   cout << "Invalid input, please try again: ";
                   getline(cin, nation);
                   nationLength = nation.length();
               }
    }

    return nation;
}


void ConsoleUI::chooseSort() //Fall sem velur eftir hverju á að raða listanum
{
    int choice;
    cout << "Choose '1' to display a list sorted in alphabetical order" << endl;
    cout << "Choose '2' to display a list sorted by birth year" << endl;
    cout << "Choose '3' to display a list sorted by gender" << endl;
    cout << "Choose '4' to display a list sorted by nationality" << endl;
    cout << "Enter a number to continue: ";
    cin >> choice;

    if(choice == 1) //Raðar listanum eftir nafni
    {
        vector<Performer> newVector = _service.sortByName();
        cout << endl;
        cout << "                        " << "---- List ordered alphabetically by first name ----" << endl;
        cout << endl;

        displayTopTable();

        displaySort(newVector);
    }

    else if(choice == 2) //Raðar listanum eftir fæðingarári
    {
        cout << endl;
        cout << "                                " << "---- List ordered by birth year ----" << endl;
        cout << endl;

        displayTopTable();

        vector <Performer> newVector = _service.sortBybYear();
        displaySort(newVector);
    }

    else if(choice == 3) //Raðar listanum eftir kyni
    {
        cout << endl;
        cout << "                                 " << "---- List ordered by gender ----" << endl;
        cout << endl;

        displayTopTable();

        vector <Performer> newVector = _service.sortByGender();
        displaySort(newVector);
    }
    else if(choice == 4) //Raðar listanum eftir þjóðerni
    {
        vector<Performer> newVector = _service.sortByNationality();
        cout << endl;
        cout << "                        " << "---- List ordered alphabetically by nationality ----" << endl;
        cout << endl;

        displayTopTable();
        displaySort(newVector);
    }

    else
    {
        cout << "Invalid choice!";
    }
}

void ConsoleUI::commandHelp()
{
    cout << "-------- The commands are case-sensitive! --------" << endl << endl;
    cout << "list   - This will list all computer scientists in the system" << endl;
    cout << "add    - This will add a new computer scientists" << endl;
    cout << "search - Searches for a given computer scientist" << endl;
    cout << "sort   - Sorts the computer scientists by preferences" << endl;
    cout << "delete - This will remove the entry from the list" << endl;
    cout << "help   - Displays list of commands" << endl;
    cout << "exit   - This will close the application" << endl;
}

void ConsoleUI::commandAdd() //Fall sem bætir við tölvunarfræðingum
{
    string name = inputName();
    string gender = inputGender();
    string birth = inputBirth();
    string death = inputDeath();
    int value = 0;
    int value2 = 0;

    if(death != "--")
    {
    value = atoi(birth.c_str()); // Breytir strengnum í birth í tölu
    value2 = atoi(death.c_str()); // Breytir strengnum í death í tölu
    }
    while(value2 < value) //Passar að talan í dánarári getur ekki verið minni en í fæðingarári
    {
        cout << "Death year can not be less than birth year! Please try again. " << endl;
        death = inputDeath();
        if(death == "--") //Ef tölvunarfræðingur er á lífi heldur fallið áfram
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

void ConsoleUI::intro() //Fall sem útprentar upphafsskilaboð
{
    cout << endl;
    cout << "It is recommended to extend the console when using this program" << endl;
    cout << endl;
    cout << "This program is designed to keep track of some details on known computer scientists. " << endl;
    cout << "The user is able to enter known characters from the history of computer science into a database." << endl;
    cout << "The program can display a list of the persons that have been entered into the database." << endl;
    cout << "The program can sort a list by the user's preferences" << endl;
    cout << "It is possible for the user to perform a search of a specific person from the list." << endl << endl;
    for (int i = 0; i < 54*2; ++i)
    {
        cout << "=";
    }
    cout << endl;
    cout << endl;
    cout << "Please enter one of the following commands to continue:" << endl;
    cout << endl;
}

void ConsoleUI::displayTopTable() //Fall sem prentar lista yfir alla tölvunarfræðinga í skránni
{
    cout << "Nr" << "\t" << "Name" << "\t\t\t" << "Gender";
    cout << "\t\t" << "Birth year" << "\t\t" << "Deceased" << "\t\t" <<"Nationality" << endl;
    for (int i = 0; i < 54*2; ++i)
    {
        cout << "=";
    }
    cout << endl;
}
string ConsoleUI::deleteElement()
{
    string name;
    cout << "what name do you want to delete(case-sensitive): ";
    cin.ignore();
    getline(cin, name);

    cout << name << " has been deleted from file." << endl;


    return name;
}
