#ifndef CONSOLEUI_H
#define CONSOLEUI_H
#include "performerservice.h"

class ConsoleUI
{
public:
    ConsoleUI();
    void run();

private:

    void displayListOfPerformers(); //Prentar lista af tölvunarfræðingum eins og þeir eru í skránni.
    void displaySearch(); // Prentar niðurstöður leitar
    void displaySort(vector<Performer> newVector);//Prentar út raðaða lista
    void chooseSort(); //Velur eftir hverju á að raða
    void commandHelp();// Prentar út lista af skipunum
    void commandAdd();//Bætir við tölvunarfræðing við listann
    void intro();//Prentar upphafsskilaboð
    void displayTopTable();//Prentar út lista af tölvunarfræðingum, sum önnur föll nota þetta fall.
    string deleteElement();//Eyðir staki úr vektor
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
