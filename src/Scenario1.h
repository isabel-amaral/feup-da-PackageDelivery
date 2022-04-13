#ifndef FEUP_DA_PACKAGEDELIVERY_SCENARIO1_H
#define FEUP_DA_PACKAGEDELIVERY_SCENARIO1_H

using namespace std;

#include <iostream>
#include <algorithm>
#include "Company.h"

class Scenario1 {
    Company company;
public:
    Scenario1(Company c);
    int run();
    static int DriverCount(vector<NormalDelivery> orders, vector<Driver> drivers);
    int final(vector<NormalDelivery> orders, vector<Driver> drivers);
    static bool sorting_driver_weight(Driver d1, Driver d2);
    static bool sorting_driver_volume(Driver d1, Driver d2);
    static bool sorting_package_weight(NormalDelivery n1, NormalDelivery n2);
    static bool sorting_package_volume(NormalDelivery n1, NormalDelivery n2);
    bool packagesFit();
};


#endif //FEUP_DA_PACKAGEDELIVERY_SCENARIO1_H
