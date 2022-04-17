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
    normalDeliveries.remove(normalDelivery);
}

void Company::deliverExpressDelivery(const ExpressDelivery &expressDelivery) {
    //TODO
}

/*____________cenário 1____________*/
void Company::scenery1() {
    list<pair<int,int>> v1;

    // Different ways of sorting the lists to get best solution
    drivers.sort(Driver::sorting_driver_volume);

    normalDeliveries.sort(NormalDelivery::compareVolume);
    v1.push_back(Company::DriverCount());
    normalDeliveries.sort(NormalDelivery::compareWeight);
    v1.push_back(Company::DriverCount());
    normalDeliveries.sort(NormalDelivery::compareAddition);
    v1.push_back(Company::DriverCount());

    drivers.sort(Driver::sorting_driver_weight);

    normalDeliveries.sort(NormalDelivery::compareVolume);
    v1.push_back(Company::DriverCount());
    normalDeliveries.sort(NormalDelivery::compareWeight);
    v1.push_back(Company::DriverCount());
    normalDeliveries.sort(NormalDelivery::compareAddition);
    v1.push_back(Company::DriverCount());

    drivers.sort(Driver::sorting_driver_addition);

    normalDeliveries.sort(NormalDelivery::compareVolume);
    v1.push_back(Company::DriverCount());
    normalDeliveries.sort(NormalDelivery::compareWeight);
    v1.push_back(Company::DriverCount());
    normalDeliveries.sort(NormalDelivery::compareAddition);
    v1.push_back(Company::DriverCount());

    v1.sort(Company::sorting_by_missing);

    printResults1(v1.front().first,v1.front().second);
}

void Company::printResults1(int driver_count, int missing_packages) {
    int coefficient = (normalDeliveries.size()/(normalDeliveries.size()+missing_packages))*100;
    if (missing_packages > 0) {
        cout << "There are " << driver_count << " drivers needed to deliver all the packages, although " << missing_packages << " packages didn't fit." << endl;
    }
    else {
        cout << "There are " << driver_count << " drivers needed to deliver all the packages." << endl;
    }
    cout << "The coefficient between the number of packages requested and delivered is " << coefficient << "%." << endl;
}

pair<int,int> Company::DriverCount() {
    setProfit(0);
    int missing = 0; // number of packages which didn't fit with available drivers
    int ans = 1; // number of drivers needed to transport the packages

    vector<Driver> remaining; // weight and volume remaining in drivers selected for deliveries
    remaining.push_back(drivers.front());

    for (NormalDelivery delivery : normalDeliveries) {
        int j;
        for (j = 0; j < remaining.size(); j++) {
            if ((delivery.getWeight() <= remaining[j].getMaxWeight()) && (delivery.getVolume() <= remaining[j].getMaxVolume())) {
                remaining[j].setMaxWeight(remaining[j].getMaxWeight()-delivery.getWeight());
                remaining[j].setMaxVolume(remaining[j].getMaxVolume()-delivery.getVolume());
                setProfit(getProfit()+delivery.getDeliveryFee());
                break;
            }
        }

        if (j == ans) { // if package doesn't fit in any of the drivers selected for deliveries
            if(get(drivers,ans).getMaxWeight()-delivery.getWeight() >= 0 && get(drivers,ans).getMaxVolume()-delivery.getVolume() >= 0) {
                get(drivers,ans).setMaxWeight(get(drivers,ans).getMaxWeight()-delivery.getWeight());
                get(drivers,ans).setMaxVolume(get(drivers,ans).getMaxVolume()-delivery.getVolume());
                remaining.push_back(get(drivers,ans));
                setProfit(getProfit()+delivery.getDeliveryFee());
                ans++;
            }
            else { // if package doesn't fit in any of available drivers, package cannot be transported
                missing++;
            }
        }
    }

    for (Driver driver : remaining) {
        setProfit(getProfit()-driver.getDeliveryCost());
    }

    pair<int,int> v1;
    v1.first = ans;
    v1.second = missing;
    return v1;
}

bool Company::sorting_by_missing(const pair<int,int> &v1, const pair<int,int> &v2) {
    // sort by number of missing packages, if  the same, by number of drivers necessary, in ascending order
    if (v1.second==v2.second)
        return v1.first<v2.first;
    return v1.second<v2.second;
}

Driver Company::get(list<Driver> _list, int _i){
    // get value from a list "_list" in the "_i" index
    list<Driver>::iterator it = _list.begin();
    for(int i=0; i<_i; i++){
        ++it;
    }
    return *it;
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

/*____________cenário 2____________*/
void Company::printResults2(int &numDeliveries) const {
    cout << "No maximo sera possivel entregar " << numDeliveries << " encomendas." << endl;
    cout << "A empresa fica com um lucro de " << profit << " euros." << endl;
}
void Company::scenery2() {
    int bestProfit, auxProfit, totalProfit = 0, numDeliveries = 0;
    bool foundDriver;
    list<Driver>::iterator bestDriver;
    list<Driver> copyDrivers = drivers;
    list<NormalDelivery> copyDeliveries = normalDeliveries;

    normalDeliveries.sort(NormalDelivery::compareFee);
    drivers.sort(Driver::compareCost);

    do {
        foundDriver = false;
        bestProfit = 0;
        for(auto driver = drivers.begin(); driver != drivers.end(); driver++){
            auxProfit = totalProfit;
            for (auto &delivery : normalDeliveries){
                if (auxProfit + delivery.getDeliveryFee() - driver->getDeliveryCost() >= 0 && driver->addOrder(delivery)){
                    auxProfit += delivery.getDeliveryFee() - driver->getDeliveryCost();
                }
            }
            if (auxProfit > bestProfit){ //TODO: INCLUIR A CONDICAO DE MAIOR NUMERO DE ENCOMENDAS CASO auxProfit == bestProfit?
                bestProfit = auxProfit;
                bestDriver = driver;
                foundDriver = true;
            }
        }
        if (!foundDriver) continue;
        totalProfit = bestProfit;
        numDeliveries += bestDriver->getOrdersToDeliver().size();
        for (auto &delivery : bestDriver->getOrdersToDeliver()) deliverNormalDelivery(delivery);
        drivers.erase(bestDriver);
        for (auto &driver : drivers) driver.removeOrders();

    }while(foundDriver);
    /*
    if (!normalDeliveries.empty()){
        drivers =copyDrivers;
        normalDeliveries = copyDeliveries;
        int numDeliveriesScenery1 = scenery1().;
        if (numDeliveriesScenery1 > numDeliveries) numDeliveries = numDeliveriesScenery1;
        else profit = totalProfit;
    }*/
    profit = totalProfit;
    printResults2(numDeliveries);
}