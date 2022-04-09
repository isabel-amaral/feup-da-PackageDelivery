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
    Company company;
    void loadDrivers(const string& driversFilename);
    void loadNormalDeliveries(const string& normalDelFilename);
    void loadExpressDeliveries(const string& expressDelFilename);

public:
    LoadData(const Company &company, const string& driversFilename, const string& normalDelFilename, const string& expressDelFilename);
    const Company& getCompany() const;
};

#endif //FEUP_DA_PACKAGEDELIVERY_LOADDATA_H
