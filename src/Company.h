#ifndef FEUP_DA_PACKAGEDELIVERY_COMPANY_H
#define FEUP_DA_PACKAGEDELIVERY_COMPANY_H

#include <list>
#include "Driver.h"
#include "ExpressDelivery.h"

using namespace std;

class Company {
    list<Driver> drivers;
    list<NormalDelivery> normalDeliveries;
    list<ExpressDelivery> expressDeliveries;
    list<ExpressDelivery> delivered;
    int profit;
public:
    Company();
    list<Driver> getDrivers();
    list<NormalDelivery> &getNormalDeliveries();
    list<ExpressDelivery> &getExpressDeliveries();
    int getProfit() const;
    void setDrivers(const list<Driver> &drivers);
    void setNormalDeliveries(const list<NormalDelivery> &normalDeliveries);
    void setExpressDeliveries(const list<ExpressDelivery> &expressDeliveries);
    void setProfit(int profit);
    void addDriver(const Driver &driver);
    void addNormalDelivery(const NormalDelivery &normalDelivery);
    void addExpressDelivery(const ExpressDelivery &expressDelivery);
    void updateProfit (const int& profit);

    /*________________scenery3_______________*/
    void scenery3();
    void printResults();
};


#endif //FEUP_DA_PACKAGEDELIVERY_COMPANY_H
