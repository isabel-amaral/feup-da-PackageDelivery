#include "LoadData.h"
LoadData::LoadData() {

}

LoadData::LoadData(Company *company) {
    this->company = company;
}

bool LoadData::loadDrivers(const string &driversFilename) {
    ifstream f;
    string text, tempText;
    int maxVol, maxWeight, cost;

    f.open(driversFilename);
    if (!f.is_open()) {
        cout << "File does not exist." << endl;
        return false;
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
        this->company->addDriver(driver);
    }
    f.close();
    return true;
}

bool LoadData::loadNormalDeliveries(const string &normalDelFilename) {
    ifstream f;
    string text, tempText;
    int vol, weight, fee;

    f.open(normalDelFilename);
    if (!f.is_open()) {
        cout << "File does not exist." << endl;
        return false;
    }

    company->setProfit(0);
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
        this->company->addNormalDelivery(normalDelivery);
    }
    f.close();
    return true;
}

bool LoadData::loadExpressDeliveries(const string &expressDelFilename){
    ifstream f;
    string text, tempText;
    int vol, weight, fee, estimatedTime;

    f.open(expressDelFilename);
    if (!f.is_open()) {
        cout << "File does not exist." << endl;
        return false;
    }

    f.ignore(LONG_MAX, '\n');
    while (getline(f, text)){
        stringstream s(text);
        estimatedTime = stoi(text);

        ExpressDelivery expressDelivery(estimatedTime);
        this->company->addExpressDelivery(expressDelivery);
    }
    f.close();
    return true;
}






