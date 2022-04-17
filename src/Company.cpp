#include "Company.h"

Company::Company() {
    this->profit = 0;
}

list<Driver> Company::getDrivers() {
    return drivers;
}

list<NormalDelivery> &Company::getNormalDeliveries(){
    return normalDeliveries;
}

list<ExpressDelivery> &Company::getExpressDeliveries(){
    return expressDeliveries;
}

int Company::getProfit() const {
    return profit;
}

void Company::setDrivers(const list<Driver> &drivers) {
    Company::drivers = drivers;
}

void Company::setNormalDeliveries(const list<NormalDelivery> &normalDeliveries) {
    this->normalDeliveries = normalDeliveries;
}

void Company::setExpressDeliveries(const list<ExpressDelivery> &expressDeliveries) {
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

    drivers.sort(Driver::sorting_driver_volume);

    normalDeliveries.sort(NormalDelivery::sorting_package_volume);
    v1.push_back(Company::DriverCount());
    normalDeliveries.sort(NormalDelivery::sorting_package_weight);
    v1.push_back(Company::DriverCount());
    normalDeliveries.sort(NormalDelivery::sorting_package_addition);
    v1.push_back(Company::DriverCount());

    drivers.sort(Driver::sorting_driver_weight);

    normalDeliveries.sort(NormalDelivery::sorting_package_volume);
    v1.push_back(Company::DriverCount());
    normalDeliveries.sort(NormalDelivery::sorting_package_weight);
    v1.push_back(Company::DriverCount());
    normalDeliveries.sort(NormalDelivery::sorting_package_addition);
    v1.push_back(Company::DriverCount());

    drivers.sort(Driver::sorting_driver_addition);

    normalDeliveries.sort(NormalDelivery::sorting_package_volume);
    v1.push_back(Company::DriverCount());
    normalDeliveries.sort(NormalDelivery::sorting_package_weight);
    v1.push_back(Company::DriverCount());
    normalDeliveries.sort(NormalDelivery::sorting_package_addition);
    v1.push_back(Company::DriverCount());

    v1.sort(Company::sorting_by_missing);
    
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
    remaining.push_back(drivers.front());

    for (NormalDelivery delivery : normalDeliveries) {
        int j;
        for (j = 0; j < remaining.size(); j++) {
            if ((delivery.getWeight() <= remaining[j].getMaxWeight()) && (delivery.getVolume() <= remaining[j].getMaxVolume())) {
                remaining[j].setMaxWeight(remaining[j].getMaxWeight()-delivery.getWeight());
                remaining[j].setMaxVolume(remaining[j].getMaxVolume()-delivery.getVolume());
                break;
            }
        }

        if (j == ans) {
            if(get(drivers,ans).getMaxWeight()-delivery.getWeight() >= 0 && get(drivers,ans).getMaxVolume()-delivery.getVolume() >= 0) {
                get(drivers,ans).setMaxWeight(get(drivers,ans).getMaxWeight()-delivery.getWeight());
                get(drivers,ans).setMaxVolume(get(drivers,ans).getMaxVolume()-delivery.getVolume());
                remaining.push_back(get(drivers,ans));
                ans++;
            }
            else {
                missing++;
            }
        }
    }

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
/*____________cenário 3____________*/
void Company::printResults() {
    int totalTimeSpent = 0;
    double average_time;

    for (ExpressDelivery e: delivered)
        totalTimeSpent += e.getEstimatedDeliveryTime();
    average_time = (double) totalTimeSpent / delivered.size();

    cout << "No maximo sera possivel entregar " << delivered.size() << " encomendas." << endl;
    cout << "Nas entregas deste dia serao gastas " << (double) totalTimeSpent / 3600 << " horas." << endl;
    cout << "Em media serao gastos " << (double) average_time / 60 << " minutos por encomenda." << endl << endl;
}

void Company::scenery3() {
    delivered.clear();
    const int START_TIME = 9, END_TIME = 17;
    // number of work seconds in a day
    const int timeToDeliver = (END_TIME - START_TIME)*3600;
    int timeUsed = 0;
    bool outOfTime = false;

    expressDeliveries.sort(ExpressDelivery::compareExpressDeliveries);
    while (!outOfTime && !expressDeliveries.empty()) {
        ExpressDelivery e = expressDeliveries.front();
        expressDeliveries.pop_front();
        if (timeUsed + e.getEstimatedDeliveryTime() > timeToDeliver)
            outOfTime = true;
        else {
            delivered.push_back(e);
            timeUsed += e.getEstimatedDeliveryTime();
        }
    }
    printResults();
}

Driver Company::get(list<Driver> _list, int _i){
    list<Driver>::iterator it = _list.begin();
    for(int i=0; i<_i; i++){
        ++it;
    }
    return *it;
}