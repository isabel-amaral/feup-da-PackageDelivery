#ifndef FEUP_DA_PACKAGEDELIVERY_COMPANY_H
#define FEUP_DA_PACKAGEDELIVERY_COMPANY_H

#include <vector>
#include <algorithm>
#include <iostream>
#include "Driver.h"
#include "ExpressDelivery.h"
#include "NormalDelivery.h"


using namespace std;

class Company {
    vector<Driver> drivers;
    vector<NormalDelivery> normalDeliveries;
    vector<ExpressDelivery> expressDeliveries;
    int profit;
public:
    Company();
    const vector<Driver> &getDrivers() const;
    const vector<NormalDelivery> &getNormalDeliveries() const;
    const vector<ExpressDelivery> &getExpressDeliveries() const;
    int getProfit() const;
    void setDrivers(const vector<Driver> &drivers);
    void setNormalDeliveries(const vector<NormalDelivery> &normalDeliveries);
    void setExpressDeliveries(const vector<ExpressDelivery> &expressDeliveries);
    void setProfit(int profit);
    void addDriver(const Driver &driver);
    void addNormalDelivery(const NormalDelivery &normalDelivery);
    void addExpressDelivery(const ExpressDelivery &expressDelivery);
    void updateProfit (const int& profit);
    void deliverNormalDelivery(const NormalDelivery& normalDelivery);
    void deliverExpressDelivery(const ExpressDelivery& expressDelivery); //TODO: decidir se é necessario

    /*________________scenery1_____________*/
    void scenery1();
    pair<int,int> DriverCount();
    static bool sorting_by_missing(const pair<int, int> &v1, const pair<int, int> &v2);
};


#endif //FEUP_DA_PACKAGEDELIVERY_COMPANY_H
