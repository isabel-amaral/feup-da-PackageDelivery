#ifndef FEUP_DA_PACKAGEDELIVERY_LOADDATA_H
#define FEUP_DA_PACKAGEDELIVERY_LOADDATA_H

#include "Company.h"
#include "Driver.h"
#include <fstream>
#include <sstream>
#include <string>
#include <iostream>
class LoadData{
private:
    Company *company;

public:
    LoadData();
    LoadData(Company *company);
    //LoadData(Company *company, const string& driversFilename, const string& normalDelFilename, const string& expressDelFilename);
    bool loadDrivers(const string& driversFilename);
    bool loadNormalDeliveries(const string& normalDelFilename);
    bool loadExpressDeliveries(const string& expressDelFilename);
    //const Company& getCompany() const;
};

#endif //FEUP_DA_PACKAGEDELIVERY_LOADDATA_H
