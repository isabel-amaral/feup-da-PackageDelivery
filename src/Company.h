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
    struct scenery1Results {
        int drivers;
        list<NormalDelivery> remainingPackages;
        int profit;
    };
public:
    Company();
    list<Driver>& getDrivers();
    list<NormalDelivery>& getNormalDeliveries();
    list<ExpressDelivery>& getExpressDeliveries();
    void setProfit(int profit);
    void addDriver(const Driver& driver);
    void addNormalDelivery(const NormalDelivery& normalDelivery);
    void addExpressDelivery(const ExpressDelivery& expressDelivery);

    /*________________scenery1_____________*/
    scenery1Results scenery1();
    static void checkBestResult(scenery1Results& result, scenery1Results& currentBestResult);
    scenery1Results alocatePackages();
    static void printResults1(const scenery1Results& results, const int& percentage) ;

    /*________________scenery2_____________*/
    void scenery2();
    void printResults2(int &numDeliveries) const;

    /*________________scenery3_______________*/
    void scenery3();
    void printResults3() const;
};


#endif //FEUP_DA_PACKAGEDELIVERY_COMPANY_H
