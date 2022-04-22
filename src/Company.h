#ifndef FEUP_DA_PACKAGEDELIVERY_COMPANY_H
#define FEUP_DA_PACKAGEDELIVERY_COMPANY_H

#include <vector>
#include <algorithm>
#include <iostream>
#include <list>
#include "Driver.h"
#include "ExpressDelivery.h"
#include "NormalDelivery.h"

using namespace std;

class Company {
    list<Driver> drivers;
    list<NormalDelivery> normalDeliveries;
    list<ExpressDelivery> expressDeliveries;
    list<ExpressDelivery> delivered;
    int profit;
    //auxiliary values for storing/printing results
    struct scenery1Results {
        int drivers;
        list<NormalDelivery> remainingPackages;
        int profit;
    };
    scenery1Results results1;
    int percentage;
    int numDeliveries;

public:
    Company();
    list<Driver>& getDrivers();
    list<NormalDelivery>& getNormalDeliveries();
    list<ExpressDelivery>& getExpressDeliveries();
    void setProfit(const int& profit);
    void addDriver(const Driver& driver);
    void addNormalDelivery(const NormalDelivery& normalDelivery);
    void addExpressDelivery(const ExpressDelivery& expressDelivery);

    //auxiliary methods for storing/printing results
    const scenery1Results &getResults1() const;
    int getPercentage() const;
    int getNumDeliveries() const;

    /*________________scenery1_____________*/
    scenery1Results scenery1();
    static void checkBestResult(scenery1Results& result, scenery1Results& currentBestResult);
    scenery1Results allocatePackages();
    static void printResults1(const scenery1Results& results, const int& percentages);

    /*________________scenery2_____________*/
    void scenery2();
    void printResults2(int numDeliveries) const;

    /*________________scenery3_______________*/
    void scenery3();
    void printResults3() const;
};


#endif //FEUP_DA_PACKAGEDELIVERY_COMPANY_H
