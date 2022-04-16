#include "Company.h"

Company::Company() {
    this->profit = 0;
}

const vector<Driver> &Company::getDrivers() const {
    return drivers;
}

const vector<NormalDelivery> &Company::getNormalDeliveries() const {
    return normalDeliveries;
}

const vector<ExpressDelivery> &Company::getExpressDeliveries() const {
    return expressDeliveries;
}

int Company::getProfit() const {
    return profit;
}

void Company::setDrivers(const vector<Driver> &drivers) {
    Company::drivers = drivers;
}

void Company::setNormalDeliveries(const vector<NormalDelivery> &normalDeliveries) {
    this->normalDeliveries = normalDeliveries;
}

void Company::setExpressDeliveries(const vector<ExpressDelivery> &expressDeliveries) {
    this->expressDeliveries = expressDeliveries;
}

void Company::setProfit(int profit) {
    Company::profit = profit;
}

void Company::addDriver(const Driver &driver) {
    this->drivers.push_back(driver);
}

void Company::addNormalDelivery(const NormalDelivery &normalDelivery) {
    this->normalDeliveries.push_back(normalDelivery);
}

void Company::addExpressDelivery(const ExpressDelivery &expressDelivery) {
    this->expressDeliveries.push_back(expressDelivery);
}

void Company::updateProfit(const int &profit) {
    this->profit = profit;
}

void Company::deliverNormalDelivery(const NormalDelivery &normalDelivery) {
    //TODO
}

void Company::deliverExpressDelivery(const ExpressDelivery &expressDelivery) {
    //TODO
}

void Company::scenery1() {
    list<pair<int,int>> v1;

    sort(drivers.begin(),drivers.end(), Driver::sorting_driver_volume);

    sort(normalDeliveries.begin(), normalDeliveries.end(), NormalDelivery::sorting_package_volume);
    v1.push_back(Company::DriverCount());
    sort(normalDeliveries.begin(),  normalDeliveries.end(), NormalDelivery::sorting_package_weight);
    v1.push_back(Company::DriverCount());
    sort(normalDeliveries.begin(),  normalDeliveries.end(), NormalDelivery::sorting_package_addition);
    v1.push_back(Company::DriverCount());

    sort(drivers.begin(),drivers.end(), Driver::sorting_driver_weight);

    sort(normalDeliveries.begin(), normalDeliveries.end(), NormalDelivery::sorting_package_volume);
    v1.push_back(Company::DriverCount());
    sort(normalDeliveries.begin(),  normalDeliveries.end(), NormalDelivery::sorting_package_weight);
    v1.push_back(Company::DriverCount());
    sort(normalDeliveries.begin(),  normalDeliveries.end(), NormalDelivery::sorting_package_addition);
    v1.push_back(Company::DriverCount());

    sort(drivers.begin(),drivers.end(), Driver::sorting_driver_addition);

    sort(normalDeliveries.begin(), normalDeliveries.end(), NormalDelivery::sorting_package_volume);
    v1.push_back(Company::DriverCount());
    sort(normalDeliveries.begin(),  normalDeliveries.end(), NormalDelivery::sorting_package_weight);
    v1.push_back(Company::DriverCount());
    sort(normalDeliveries.begin(),  normalDeliveries.end(), NormalDelivery::sorting_package_addition);
    v1.push_back(Company::DriverCount());

    //sort(v1.begin(),  v1.end(), Scenario1::sorting_by_missing);

    //v1.sort([](const pair<int,int> & a, const pair<int,int> & b) { return a.first < b.first; });
    v1.sort(Company::sorting_by_missing);

    //cout << ans1 << endl << ans2 << endl;

    /*
    int min1 = INT_MAX;
    int min0 = INT_MAX;

    list<list<int>>::iterator it;
    for (it = v1.begin(); it != v1.end(); ++it) {
        if (*it[0] <= min0 && it[1] <= min1) {
            min0 = i[0];
            min1 = i[1];
            cout << i[0] << " , " << i[1] << endl;
        }
    }
     */

    for (const auto& paire : v1) {
        cout << paire.first << " , " << paire.second << endl;
    }
    if (v1.front().second > 0)
        cout << "There are " << v1.front().first << " drivers needed to carry all the packages, although " << v1.front().second << " packages didn't fit." << endl;
    else {
        cout << "There are " << v1.front().first << " drivers needed to carry all the packages." << endl;
    }
}

pair<int,int> Company::DriverCount() {
    int missing = 0;
    int ans = 1;

    vector<Driver> remaining;
    remaining.push_back(drivers[0]);

    for (int i = 0; i < normalDeliveries.size(); i++) {
        int j;
        for (j = 0; j < remaining.size(); j++) {
            if ((normalDeliveries[i].getWeight() <= remaining[j].getMaxWeight()) && (normalDeliveries[i].getVolume() <= remaining[j].getMaxVolume())) {
                remaining[j].setMaxWeight(remaining[j].getMaxWeight()-normalDeliveries[i].getWeight());
                remaining[j].setMaxVolume(remaining[j].getMaxVolume()-normalDeliveries[i].getVolume());
                break;
            }
        }

        if (j == ans) {
            if(drivers[ans].getMaxWeight()-normalDeliveries[i].getWeight() >= 0 && drivers[ans].getMaxVolume()-normalDeliveries[i].getVolume() >= 0) {
                drivers[ans].setMaxWeight(drivers[ans].getMaxWeight()-normalDeliveries[i].getWeight());
                drivers[ans].setMaxVolume(drivers[ans].getMaxVolume()-normalDeliveries[i].getVolume());
                remaining.push_back(drivers[ans]);
                ans++;
            }
            else {
                missing++;
            }
        }
    }
    //cout << "There were " << missing << " packages that didn't fit" << endl;
    pair<int,int> v1;
    v1.first = ans;
    v1.second = missing;
    return v1;
}

bool Company::sorting_by_missing(const pair<int,int> &v1, const pair<int,int> &v2) {
    if (v1.second==v2.second)
        return v1.first<v2.first;
    return v1.second<v2.second;
}