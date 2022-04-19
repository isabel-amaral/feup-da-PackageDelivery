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

string Company::getOption() const {
    return option;
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
    this->profit = profit;
}

void Company::setOption(string option) {
    this->option = option;
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
int Company::scenery1() {
    list<pair<int,int>> v1;

    // Different ways of sorting the lists to get best solution
    drivers.sort(Driver::compareVolume);

    normalDeliveries.sort(NormalDelivery::compareVolume);
    v1.push_back(Company::DriverCount());
    normalDeliveries.sort(NormalDelivery::compareWeight);
    v1.push_back(Company::DriverCount());
    normalDeliveries.sort(NormalDelivery::compareAddition);
    v1.push_back(Company::DriverCount());

    drivers.sort(Driver::compareWeight);

    normalDeliveries.sort(NormalDelivery::compareVolume);
    v1.push_back(Company::DriverCount());
    normalDeliveries.sort(NormalDelivery::compareWeight);
    v1.push_back(Company::DriverCount());
    normalDeliveries.sort(NormalDelivery::compareAddition);
    v1.push_back(Company::DriverCount());

    drivers.sort(Driver::compareAddition);

    normalDeliveries.sort(NormalDelivery::compareVolume);
    v1.push_back(Company::DriverCount());
    normalDeliveries.sort(NormalDelivery::compareWeight);
    v1.push_back(Company::DriverCount());
    normalDeliveries.sort(NormalDelivery::compareAddition);
    v1.push_back(Company::DriverCount());

    if (option == "1") {
        v1.sort(Company::compareMissingDeliveries);
    }
    else if (option == "2") {
        v1.sort(Company::compareWastedVolume);
    }
    else if (option == "3") {
        v1.sort(Company::compareWastedWeight);
    }
    else if (option == "4") {
        v1.sort(Company::compareWastedSpace);
    }

    printResults1(v1.front().first,v1.front().second);
    return v1.front().second;
}

void Company::printResults1(int driver_count, int missing_packages) {
    if (option == "1") {
        if (missing_packages > 0) {
            cout << "There are " << driver_count << " drivers needed to deliver all the packages, although " << missing_packages << " packages didn't fit." << endl;
        }
        else {
            cout << "There are " << driver_count << " drivers needed to deliver all the packages." << endl;
        }
        int coefficient = (normalDeliveries.size()/(normalDeliveries.size()+missing_packages))*100;
        cout << "The coefficient between the number of packages requested and delivered is " << coefficient << "%." << endl;
    }
    else if (option == "2") {
        cout << "There was a total of " << missing_packages << " wasted volume." << endl;
    }
    else if (option == "3") {
        cout << "There was a total of " << driver_count << " wasted weight." << endl;
    }
    else if (option == "4") {
        cout << "There was a total of " << driver_count << " wasted weight and " << missing_packages << " wasted volume." << endl;
    }
}

pair<int,int> Company::DriverCount() {
    profit = 0;
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
                profit += delivery.getDeliveryFee();
                break;
            }
        }

        if (j == ans) { // if package doesn't fit in any of the drivers selected for deliveries
            if(get(drivers,ans).getMaxWeight()-delivery.getWeight() >= 0 && get(drivers,ans).getMaxVolume()-delivery.getVolume() >= 0) {
                get(drivers,ans).setMaxWeight(get(drivers,ans).getMaxWeight()-delivery.getWeight());
                get(drivers,ans).setMaxVolume(get(drivers,ans).getMaxVolume()-delivery.getVolume());
                remaining.push_back(get(drivers,ans));
                profit += delivery.getDeliveryFee();
                ans++;
            }
            else { // if package doesn't fit in any of available drivers, package cannot be transported
                missing++;
            }
        }
    }

    int wasted_weight = 0;
    int wasted_volume = 0;

    for (Driver driver : remaining) {
        profit -= driver.getDeliveryCost();
        wasted_volume += driver.getMaxVolume();
        wasted_weight += driver.getMaxWeight();
    }

    pair<int,int> v1;
    pair<int,int> v2;
    v1.first = ans;
    v1.second = missing;
    v2.first = wasted_weight;
    v2.second = wasted_volume;
    if (option == "1") return v1;
    return v2;
}

bool Company::compareMissingDeliveries(const pair<int,int> &v1, const pair<int,int> &v2) {
    // sort by number of missing packages, if  the same, by number of drivers necessary, in ascending order
    if (v1.second==v2.second)
        return v1.first<v2.first;
    return v1.second<v2.second;
}

bool Company::compareWastedVolume(const pair<int, int> &v1, const pair<int, int> &v2) {
    return v1.second<v2.second;
}

bool Company::compareWastedWeight(const pair<int, int> &v1, const pair<int, int> &v2) {
    return v1.first<v2.first;
}

bool Company::compareWastedSpace(const pair<int,int> &v1, const pair<int,int> &v2) {
    // sort by number of missing packages, if  the same, by number of drivers necessary, in ascending order
    return ((v1.first+v1.second)<(v2.second+v2.first));
}

Driver Company::get(list<Driver> _list, int _i){
    // get value from a list "_list" in the "_i" index
    list<Driver>::iterator it = _list.begin();
    for(int i=0; i<_i; i++){
        ++it;
    }
    return *it;
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

    copyDeliveries.sort(NormalDelivery::compareFee);
    copyDrivers.sort(Driver::compareCost);

    do {
        foundDriver = false;
        bestProfit = 0;
        for(auto driver = copyDrivers.begin(); driver != copyDrivers.end(); driver++){
            auxProfit = totalProfit;
            for (auto &delivery : copyDeliveries){
                if (driver->addOrder(delivery)){
                    auxProfit += delivery.getDeliveryFee();
                }
            }
            auxProfit -= driver->getDeliveryCost();
            if (auxProfit > bestProfit && auxProfit > 0){ //TODO: INCLUIR A CONDICAO DE MAIOR NUMERO DE ENCOMENDAS (CASO auxProfit == bestProfit)?
                bestProfit = auxProfit;
                bestDriver = driver;
                foundDriver = true;
            }
        }
        if (!foundDriver) continue;
        totalProfit = bestProfit;
        numDeliveries += bestDriver->getOrdersToDeliver().size();
        for (auto &delivery : bestDriver->getOrdersToDeliver()) copyDeliveries.remove(delivery);
        copyDrivers.erase(bestDriver);
        for (auto &driver : copyDrivers) driver.removeOrders();

    }while(foundDriver);

    if (!copyDeliveries.empty()) {
        int remainingDelScenery1 = scenery1();
        if (remainingDelScenery1 < copyDeliveries.size())
            numDeliveries = normalDeliveries.size() - remainingDelScenery1;
        else profit = totalProfit;
    }
    profit = totalProfit;
    printResults2(numDeliveries);
}

/*____________cenário 3____________*/
void Company::printResults() {
    int totalTimeSpent = 0;
    double average_time;

    for (ExpressDelivery e: delivered)
        totalTimeSpent += e.getEstimatedDeliveryTime();
    average_time = (double) totalTimeSpent / delivered.size();

    cout << "No maximo sera possivel entregar " << delivered.size() << " encomendas." << endl;
    cout.precision(3);
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
