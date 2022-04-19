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
    string option;
public:
    Company();
    list<Driver> getDrivers();
    list<NormalDelivery> &getNormalDeliveries();
    list<ExpressDelivery> &getExpressDeliveries();
    int getProfit() const;
    string getOption() const;
    void setDrivers(const list<Driver> &drivers);
    void setNormalDeliveries(const list<NormalDelivery> &normalDeliveries);
    void setExpressDeliveries(const list<ExpressDelivery> &expressDeliveries);
    void setProfit(int profit);
    void setOption(string option);
    void addDriver(const Driver &driver);
    void addNormalDelivery(const NormalDelivery &normalDelivery);
    void addExpressDelivery(const ExpressDelivery &expressDelivery);
    void updateProfit (const int& profit);
    void deliverNormalDelivery(const NormalDelivery& normalDelivery);
    void deliverExpressDelivery(const ExpressDelivery& expressDelivery); //TODO: decidir se é necessario

    /*________________scenery1_____________*/
    int scenery1();
    void printResults1(int driver_count, int missing_packages);
    pair<int,int> DriverCount();
    static bool compareMissingDeliveries(const pair<int, int> &v1, const pair<int, int> &v2);
    static bool compareWastedWeight(const pair<int, int> &v1, const pair<int, int> &v2);
    static bool compareWastedVolume(const pair<int, int> &v1, const pair<int, int> &v2);
    static bool compareWastedSpace(const pair<int, int> &v1, const pair<int, int> &v2);
    static Driver get(list<Driver> _list, int _i);

    /*________________scenery2_____________*/
    void scenery2();
    void printResults2(int &numDeliveries) const;

    /*________________scenery3_______________*/
    void scenery3();
    void printResults();

};


#endif //FEUP_DA_PACKAGEDELIVERY_COMPANY_H
