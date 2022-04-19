#include "Company.h"

Company::Company() {
    this->profit = 0;
}

list<Driver> &Company::getDrivers() {
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
int Company::scenery1() {
    scenery1Results bestResult {INT_MAX, INT_MAX, INT_MAX};
    scenery1Results auxResult{};

    // Different ways of sorting the lists to get best solution
    drivers.sort(Driver::compareVolume);
    normalDeliveries.sort(NormalDelivery::compareVolume);
    auxResult = driverCount();
    checkBestResult(auxResult, bestResult);

    drivers.sort(Driver::compareWeight);
    normalDeliveries.sort(NormalDelivery::compareWeight);
    auxResult = driverCount();
    checkBestResult(auxResult, bestResult);

    drivers.sort(Driver::compareAddition);
    normalDeliveries.sort(NormalDelivery::compareAddition);
    auxResult = driverCount();
    checkBestResult(auxResult, bestResult);

    profit = bestResult.profit;
    printResults1(bestResult.drivers,bestResult.remainingPackages);
    return bestResult.remainingPackages;
}

void Company::checkBestResult(Company::scenery1Results &result, Company::scenery1Results &currentBestResult) {
    // sort by number of missing packages, if  the same, by number of drivers necessary, in ascending order
    if (result.remainingPackages < currentBestResult.remainingPackages ||
        (result.remainingPackages == currentBestResult.remainingPackages && result.drivers < currentBestResult.drivers))
        currentBestResult = result;
}

Company::scenery1Results Company::driverCount() {
    profit = 0;
    int remainingPackages = 0;  // number of packages which didn't fit with available drivers
    int numDrivers = 1;         // number of drivers needed to transport the packages
    vector<Driver> usedDrivers; // weight and volume remaining in drivers selected for deliveries
    auto driverIndex = drivers.begin();

    usedDrivers.push_back(drivers.front());
    for (NormalDelivery delivery : normalDeliveries) {
        int j;
        for (j = 0; j < usedDrivers.size(); j++) {
            if (usedDrivers[j].addOrder(delivery)) {
                profit += delivery.getDeliveryFee();
                break;
            }
        }

        if (j == numDrivers) { // if package doesn't fit in any of the drivers selected for deliveries
            driverIndex++;
            Driver driver = *(driverIndex);
            if(driver.addOrder(delivery)) {
                usedDrivers.push_back(driver);
                profit += delivery.getDeliveryFee();
                numDrivers++;
            }
            else remainingPackages++; // if package doesn't fit in any of available drivers, package cannot be transported
        }
    }

    for (const Driver& driver : usedDrivers)
        profit -= driver.getDeliveryCost();

    scenery1Results result{numDrivers, remainingPackages, profit};
    return result;
}

void Company::printResults1(int driver_count, int missing_packages) {
    int percentage = (normalDeliveries.size()/(normalDeliveries.size()+missing_packages))*100;
    if (missing_packages > 0) cout << "There are " << driver_count << " drivers needed to deliver all the packages, although " << missing_packages << " packages didn't fit." << endl;
    else cout << "There are " << driver_count << " drivers needed to deliver all the packages." << endl;
    cout << "The coefficient between the number of packages requested and delivered is " << percentage << "%." << endl;
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
