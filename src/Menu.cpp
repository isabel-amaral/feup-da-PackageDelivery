//
// Created by ASUS on 13/04/2022.
//

#include "Menu.h"

Menu::Menu() {
    cout << "--------MENU----------\n";
    option = 0;
    loadData = LoadData(&company);

    lastMenu.push(0);   //'0' representa o menu inicial/principal
    menu0();
}

void Menu::readOption(const unsigned& minOption, const unsigned& maxOption) {
    bool validOption;
    do {
        cin >> option;
        if (cin.fail()) {
            if (cin.eof()) {
                cout << "VOLTE SEMPRE." << endl;
                exit (1);
            }
            else {
                validOption = false;
                cout << "OPCAO INVALIDA! TENTE NOVAMENTE" << endl;
                cin.clear();
                cin.ignore(10000, '\n');
            }
        }
        else if ((minOption <= option &&  option <= maxOption) || option == 0) {
            validOption = true;
            cin.ignore(1000, '\n');
        }
        else {  // O utilizador introduziu um inteiro invalido
            validOption = false;
            cout << "OPCAO INVALIDA! TENTE NOVAMENTE. " << endl;
            cin.clear();
            cin.ignore(10000, '\n');
        }
    } while (!validOption);
}

void Menu::processOption() {
    switch (option) {
        case 0: menu0();
            break;
        case 1: menu1(1);
            break;
        case 2: menu1(2);
            break;
        case 3: menu3();
    }
}

void Menu::menu0() {

    cout << "Cenario 1: Otimizacao do numero de estafetas." << endl;
    cout << "Cenario 2: Otimizacao do lucro da empresa."    << endl;
    cout << "Cenario 3: Otimizacao das entregas expresso." << endl;
    cout << "0. Sair." << endl;
    cout << "\nESCOLHA UMA OPCAO RELATIVA AO CENARIO:";
    readOption(0, 3);

    if (option) {
        lastMenu.push(0);
        processOption();
    }
    else {
        cout << "VOLTE SEMPRE.";
        exit (0);
    }
}

void Menu::menu1(const int& normalDelscenery) {
    string driversFile, normalDelFile;

    cout << "Insira o nome do ficheiro dos drivers: (0 - Voltar)" << endl;
    getline(cin, driversFile);
    if (driversFile == "0")
        menu0();
    else
        driversFile += ".txt";

    cout << "Insira o nome do ficheiro das encomendas normais: (0 - Voltar)" << endl;
    getline(cin, normalDelFile);
    if (normalDelFile == "0")
        menu0();
    else
        normalDelFile += ".txt";

    char priority;
    cout << "Deseja realizar primeiro a entrega de encomendas que tenham sobrado do dia anterior? (s - sim/n - nao)" << endl;
    cin >> priority;
    if (priority != 's' && priority != 'S')
        company.getNormalDeliveries().clear();
    company.getDrivers().clear();

    if (loadData.loadDrivers(driversFile) && loadData.loadNormalDeliveries(normalDelFile)){ //if both files exists
        if (normalDelscenery == 1)  {
            company.scenery1();
            company.printResults1(company.getResults1(), company.getPercentage());
        }
        else {
            company.scenery2();
            company.printResults2(company.getNumDeliveries());
        }
    }

    cout << endl;
    option = lastMenu.top();
    lastMenu.pop();
    processOption();
}

void Menu::menu3() {
    string expressDelFile;

    cout << "Insira o nome do ficheiro das encomendas expresso: (0 - Voltar)" << endl;
    getline(cin, expressDelFile);
    if (expressDelFile == "0")
        menu0();
    else
        expressDelFile += ".txt";

    char priority;
    cout << "Deseja realizar primeiro a entrega de encomendas que tenham sobrado do dia anterior? (s - sim/n - nao)" << endl;
    cin >> priority;
    if (priority != 's' && priority != 'S')
        company.getExpressDeliveries().clear();

    if (loadData.loadExpressDeliveries(expressDelFile)) {
        company.scenery3();
        company.printResults3();
    }

    cout << endl;
    option = lastMenu.top();
    lastMenu.pop();
    processOption();
}