#include "Company.h"

Company::Company() {
    this->profit = 0;
}

list<Driver>& Company::getDrivers() {
    return drivers;
}

list<NormalDelivery>& Company::getNormalDeliveries() {
    return normalDeliveries;
}

list<ExpressDelivery>& Company::getExpressDeliveries() {
    return expressDeliveries;
}

void Company::setProfit(int profit) {
    Company::profit = profit;
}

void Company::addDriver(const Driver& driver) {
    this->drivers.push_back(driver);
}

void Company::addNormalDelivery(const NormalDelivery& normalDelivery) {
    this->normalDeliveries.push_back(normalDelivery);
}

void Company::addExpressDelivery(const ExpressDelivery& expressDelivery) {
    this->expressDeliveries.push_back(expressDelivery);
}

/*____________cenário 1____________*/
void Company::printResults1(const scenery1Results& results, const int& percentage) {

    if (!results.remainingPackages.empty())
        cout << "Sao necessarios " << results.drivers << " estafetas. No entanto, não foi possível entregar " << results.remainingPackages.size() << " encomendas." << endl;
    else
        cout << "Sao necessarios " << results.drivers << " estafetas para entregar todas as encomendas." << endl;
    cout << "A percentagem do numero de encomendas entregue foi " << percentage << "%." << endl;
}

Company::scenery1Results Company::alocatePackages() {
    int auxProfit = 0;
    auto driverIndex = drivers.begin();
    int numDrivers = 1;         // number of drivers needed to transport the packages
    vector<Driver> usedDrivers; // weight and volume remaining in drivers selected for deliveries
    list<NormalDelivery> remainingPackages = normalDeliveries;


    usedDrivers.push_back(drivers.front());
    for (auto delivery = remainingPackages.begin(); delivery != remainingPackages.end(); delivery++){
        int j;
        for (j = 0; j < usedDrivers.size(); j++) {
            if (usedDrivers[j].addOrder(*delivery)) {
                auxProfit += delivery->getDeliveryFee();
                remainingPackages.erase(delivery--);
                break;
            }
        }

        if (j == numDrivers) { // if package doesn't fit in any of the drivers selected for deliveries
            driverIndex++ ;
            Driver driver = *driverIndex;
            if (driver.addOrder(*delivery)) {
                remainingPackages.erase(delivery--);
                usedDrivers.push_back(driver);
                auxProfit += delivery->getDeliveryFee();
                numDrivers++;
            }
        }
    }

    for (const Driver& driver: usedDrivers)
        auxProfit -= driver.getDeliveryCost();

    scenery1Results result{numDrivers, remainingPackages, auxProfit};
    return result;
}

void Company::checkBestResult(Company::scenery1Results& result, Company::scenery1Results& currentBestResult) {
    // sort by number of missing packages, if  the same, by number of drivers necessary, in ascending order
    if (result.remainingPackages.size() < currentBestResult.remainingPackages.size() ||
        (result.remainingPackages.size() == currentBestResult.remainingPackages.size() && result.drivers < currentBestResult.drivers))
        currentBestResult = result;
}

Company::scenery1Results Company::scenery1() {
    scenery1Results bestResult {};
    scenery1Results auxResult{};

    // Different ways of sorting the lists to get best solution
    drivers.sort(Driver::compareVolume);
    normalDeliveries.sort(NormalDelivery::compareVolume);
    bestResult = alocatePackages();

    drivers.sort(Driver::compareWeight);
    normalDeliveries.sort(NormalDelivery::compareWeight);
    auxResult = alocatePackages();
    checkBestResult(auxResult, bestResult);

    drivers.sort(Driver::compareAddition);
    normalDeliveries.sort(NormalDelivery::compareAddition);
    auxResult = alocatePackages();
    checkBestResult(auxResult, bestResult);

    //profit = bestResult.profit;
    int percentage = (normalDeliveries.size()/(normalDeliveries.size()+bestResult.remainingPackages.size()))*100;
    normalDeliveries = bestResult.remainingPackages;
    printResults1(bestResult, percentage);
    return bestResult;
}


/*____________cenário 2____________*/
void Company::printResults2(int &numDeliveries) const {
    cout << "No maximo sera possivel entregar " << numDeliveries << " encomendas." << endl;
    cout << "A empresa fica com um lucro de " << profit << " euros." << endl;
}
void Company::scenery2() {
    int bestProfit, auxProfit, totalProfit = 0, numDeliveries = 0, numPackages = normalDeliveries.size();
    bool foundDriver;
    list<Driver>::iterator bestDriver;
    list<NormalDelivery> remainingPackages2 = normalDeliveries;
    list<Driver> copyDrivers = drivers;

    remainingPackages2.sort(NormalDelivery::compareFee);
    copyDrivers.sort(Driver::compareCost);

    do {
        foundDriver = false;
        bestProfit = 0;
        for (auto driver = copyDrivers.begin(); driver != copyDrivers.end(); driver++) {
            auxProfit = totalProfit;
            for (auto& delivery: remainingPackages2) {
                if (driver->addOrder(delivery))
                    auxProfit += delivery.getDeliveryFee();
            }
            auxProfit -= driver->getDeliveryCost();
            if (auxProfit > bestProfit && auxProfit > 0) { //TODO: INCLUIR A CONDICAO DE MAIOR NUMERO DE ENCOMENDAS (CASO auxProfit == bestProfit)?
                bestProfit = auxProfit;
                bestDriver = driver;
                foundDriver = true;
            }
        }
        if (!foundDriver) continue;
        totalProfit = bestProfit;
        numDeliveries += bestDriver->getOrdersToDeliver().size();
        for (auto& delivery: bestDriver->getOrdersToDeliver())
            remainingPackages2.remove(delivery);
        copyDrivers.erase(bestDriver);
        for (auto& driver: copyDrivers)
            driver.removeOrders();
    } while (foundDriver);

    if (!remainingPackages2.empty()) {
        scenery1Results r1= scenery1();
        if (r1.remainingPackages.size() < remainingPackages2.size()){
            numDeliveries = numPackages - r1.remainingPackages.size();
            profit = r1.profit;
        }

        else{
            profit = totalProfit;
            normalDeliveries = remainingPackages2;
        }

    }
    else profit = totalProfit;
    normalDeliveries = remainingPackages2;
    printResults2(numDeliveries);
}

/*____________cenário 3____________*/
void Company::printResults3() const {
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
    for (ExpressDelivery& e: expressDeliveries)
        e.incrementPriority();
    printResults3();
}
