//
// Created by ASUS on 06/04/2022.
//

#include "LoadData.h"

LoadData::LoadData(const Company &company, const string &driversFilename, const string &normalDelFilename, const string &expressDelFilename) {
    this->company = company;
    loadDrivers(driversFilename);
    loadNormalDeliveries(normalDelFilename);
    loadExpressDeliveries(expressDelFilename);
}

const Company& LoadData::getCompany() const {
    return company;
}

void LoadData::loadDrivers(const string &driversFilename) {
    ifstream f;
    string text, tempText;
    int maxVol, maxWeight, cost;

    f.open(driversFilename);
    if (!f.is_open()) {
        cout << "File does not exist." << endl;
        return;
    }

    f.ignore(LONG_MAX, '\n');
    while (getline(f, text)){
        stringstream s(text);

        getline (s, tempText, ' ');
        maxVol = stoi(tempText);
        getline (s, tempText, ' ');
        maxWeight = stoi(tempText);
        getline (s, tempText, ' ');
        cost = stoi(tempText);

        Driver driver(maxWeight, maxVol, cost); 
        this->company.addDriver(driver);
    }
    f.close();
}

void LoadData::loadNormalDeliveries(const string &normalDelFilename) {
    ifstream f;
    string text, tempText;
    int vol, weight, fee;

    f.open(normalDelFilename);
    if (!f.is_open()) {
        cout << "File does not exist." << endl;
        return;
    }

    f.ignore(LONG_MAX, '\n');
    while (getline(f, text)) {
        stringstream s(text);

        getline(s, tempText, ' ');
        vol = stoi(tempText);
        getline(s, tempText, ' ');
        weight = stoi(tempText);
        getline(s, tempText, ' ');
        fee = stoi(tempText);

        NormalDelivery normalDelivery(vol, weight, fee);
        this->company.addNormalDelivery(normalDelivery);
    }
    f.close();
}

void LoadData::loadExpressDeliveries(const string &expressDelFilename){
    ifstream f;
    string text, tempText;
    int vol, weight, fee, estimatedTime;

    f.open(expressDelFilename);
    if (!f.is_open()) {
        cout << "File does not exist." << endl;
        return;
    }

    f.ignore(LONG_MAX, '\n');
    while (getline(f, text)){
        stringstream s(text);

        getline (s, tempText, ' ');
        estimatedTime = stoi(tempText);

        ExpressDelivery expressDelivery(estimatedTime);
        this->company.addExpressDelivery(expressDelivery);
    }
    f.close();
}



