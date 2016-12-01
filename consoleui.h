#ifndef CONSOLEUI_H
#define CONSOLEUI_H
#include "performerservice.h"
#include "dataaccess.h"

class ConsoleUI
{
public:
    ConsoleUI();

    // Displays the main menu of the program.
    void run();

private:

    void displayListOfPerformers();
    void displaySearch();

private:
    PerformerService _service;
    DataAccess _data;
};

#endif // CONSOLEUI_H
