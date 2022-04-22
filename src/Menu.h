#ifndef FEUP_DA_PACKAGEDELIVERY_MENU_H
#define FEUP_DA_PACKAGEDELIVERY_MENU_H

#include <iostream>
#include <string>
#include <stack>
#include "LoadData.h"

class Menu {
private:
    Company company;
    LoadData loadData;
    stack<int> lastMenu;
    int option;
    ifstream f;
public:
    Menu();
    void readOption(const unsigned& minOption, const unsigned& maxOption);
    void processOption();
    void menu0();
    void menu1(const int& normalDelScenery);
    void menu3();
};


#endif //FEUP_DA_PACKAGEDELIVERY_MENU_H
