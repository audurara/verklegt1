#ifndef CONSOLEUI_H
#define CONSOLEUI_H
#include "performerservice.h"

class ConsoleUI
{
public:
    ConsoleUI();
    void run();

private:

    void displayListOfPerformers();
    void displaySearch();
    void displaySort(vector<Performer> newVector);
    void chooseSort();
    void commandHelp();
    void commandAdd();
    void intro();
    void displayTopTable();
    string inputName();
    string inputGender();
    string inputBirth();
    string inputDeath();
    string inputNation();

private: //Eftirfarandi breytur sækja upplýsingar og leyfa virkni sitthvort úr PerformerService og DataAccess.
    PerformerService _service;
    DataAccess _data;
};

#endif // CONSOLEUI_H
