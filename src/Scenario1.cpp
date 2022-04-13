#include "Scenario1.h"

Scenario1::Scenario1(Company c) {
    company = c;
    run();
}

int Scenario1::run() {
    if (!packagesFit()) return -1;

    //cout << firstFitDec(package_weights,n1,driver_weights,size1) << endl;
    //cout << firstFitDec(package_volumes,n2,driver_volumes,size2) << endl;
    cout << final(company.getNormalDeliveries(),company.getDrivers()) << endl;
    return final(company.getNormalDeliveries(),company.getDrivers());
}

int Scenario1::DriverCount(vector<NormalDelivery> orders, vector<Driver> drivers) {
    int missing = 0;
    int ans = 1;

    vector<Driver> remaining;
    remaining.push_back(drivers[0]);

    for (int i = 0; i < orders.size(); i++) {
        int j;
        for (j = 0; j < remaining.size(); j++) {
            if ((orders[i].getWeight() <= remaining[j].getMaxWeight()) && (orders[i].getVolume() <= remaining[j].getMaxVolume())) {
                remaining[j].setMaxWeight(remaining[j].getMaxWeight()-orders[i].getWeight());
                remaining[j].setMaxVolume(remaining[j].getMaxVolume()-orders[i].getVolume());
                break;
            }
        }

        if (j == ans) {
            if(drivers[ans].getMaxWeight()-orders[i].getWeight() >= 0 && drivers[ans].getMaxVolume()-orders[i].getVolume() >= 0) {
                drivers[ans].setMaxWeight(drivers[ans].getMaxWeight()-orders[i].getWeight());
                drivers[ans].setMaxVolume(drivers[ans].getMaxVolume()-orders[i].getVolume());
                remaining.push_back(drivers[ans]);
                ans++;
            }
            else {
                missing++;
            }
        }
    }
    //cout << "There were " << missing << " packages that didn't fit" << endl;
    return ans;
}

int Scenario1::final(vector<NormalDelivery> orders, vector<Driver> drivers) {

    sort(drivers.begin(),drivers.end(), Scenario1::sorting_driver_volume);

    sort(orders.begin(), orders.end(), Scenario1::sorting_package_volume);
    int ans1 = Scenario1::DriverCount(orders,drivers);
    sort(orders.begin(),  orders.end(), Scenario1::sorting_package_weight);
    int ans2 = Scenario1::DriverCount(orders,drivers);
    sort(orders.begin(),  orders.end(), Scenario1::sorting_package_addition);
    int ans3 = Scenario1::DriverCount(orders,drivers);

    sort(drivers.begin(),drivers.end(), Scenario1::sorting_driver_weight);

    sort(orders.begin(), orders.end(), Scenario1::sorting_package_volume);
    int ans4 = Scenario1::DriverCount(orders,drivers);
    sort(orders.begin(),  orders.end(), Scenario1::sorting_package_weight);
    int ans5 = Scenario1::DriverCount(orders,drivers);
    sort(orders.begin(),  orders.end(), Scenario1::sorting_package_addition);
    int ans6 = Scenario1::DriverCount(orders,drivers);

    sort(drivers.begin(),drivers.end(), Scenario1::sorting_driver_addition);

    sort(orders.begin(), orders.end(), Scenario1::sorting_package_volume);
    int ans7 = Scenario1::DriverCount(orders,drivers);
    sort(orders.begin(),  orders.end(), Scenario1::sorting_package_weight);
    int ans8 = Scenario1::DriverCount(orders,drivers);
    sort(orders.begin(),  orders.end(), Scenario1::sorting_package_addition);
    int ans9 = Scenario1::DriverCount(orders,drivers);

    int min1 = min(ans1,ans2);
    int min2 = min(ans3,ans4);
    int min3 = min(ans5,ans6);
    int min4 = min(ans7,ans8);
    int min5 = min(ans9, min1);
    int min6 = min(min5, min2);
    int min7 = min(min3, min4);

    //cout << ans1 << endl << ans2 << endl;

    return min(min6,min7);
}

bool Scenario1::sorting_driver_weight(Driver d1, Driver d2) {
    return d1.getMaxWeight() > d2.getMaxWeight();
}

bool Scenario1::sorting_driver_volume(Driver d1, Driver d2) {
    return d1.getMaxVolume() > d2.getMaxVolume();
}

bool Scenario1::sorting_driver_addition(Driver d1, Driver d2) {
    return d1.getMaxVolume()+d1.getMaxWeight() > d2.getMaxVolume()+d2.getMaxWeight();
}

bool Scenario1::sorting_package_weight(NormalDelivery n1, NormalDelivery n2) {
    return n1.getWeight() > n2.getWeight();
}

bool Scenario1::sorting_package_volume(NormalDelivery n1, NormalDelivery n2) {
    return n1.getVolume() > n2.getVolume();
}

bool Scenario1::sorting_package_addition(NormalDelivery n1, NormalDelivery n2) {
    return n1.getVolume()+n1.getWeight() > n2.getVolume()+n2.getWeight();
}

bool Scenario1::packagesFit() {
    int total_driver_volume = 0;
    int total_driver_weight = 0;
    int total_package_volume = 0;
    int total_package_weight = 0;

    for (int i = 0; i < company.getDrivers().size(); i++) {
        total_driver_volume += company.getDrivers()[i].getMaxVolume();
        total_driver_weight += company.getDrivers()[i].getMaxWeight();
    }

    for (int i = 0; i < company.getNormalDeliveries().size(); i++) {
        total_package_volume += company.getNormalDeliveries()[i].getVolume();
        total_package_weight += company.getNormalDeliveries()[i].getWeight();
    }

    if (total_package_weight > total_driver_weight || total_package_volume > total_driver_volume)
        return false;
    return true;
}