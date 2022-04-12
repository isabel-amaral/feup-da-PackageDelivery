#include "Company.h"
#include <iostream>

Company::Company() {
    this->profit = 0;
}

const list<Driver> &Company::getDrivers() const {
    return drivers;
}

const list<NormalDelivery> &Company::getNormalDeliveries() const {
    return normalDeliveries;
}

const list<ExpressDelivery> &Company::getExpressDeliveries() const {
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

/*____________cenário 3____________*/
bool compareExpressDeliveries(const ExpressDelivery& a, const ExpressDelivery& b) {
    if (a.getEstimatedDeliveryTime() < b.getEstimatedDeliveryTime())
        return true;
    return false;
}

void Company::printResults() {
    int totalTimeSpent = 0;
    double average_time;

    for (ExpressDelivery e: delivered)
        totalTimeSpent += e.getEstimatedDeliveryTime();
    average_time = (double) totalTimeSpent / delivered.size();

    cout << "No máximo será possível entregar " << delivered.size() << " encomendas." << endl;
    cout << "Nas entregas deste dia serão gastas " << (double) totalTimeSpent / 3600 << " horas." << endl;
    cout << "Em média serão gastos " << (double) average_time / 60 << " minutos por encomenda." << endl << endl;
}

void Company::scenery3() {
    delivered.clear();
    const int START_TIME = 9, END_TIME = 17;
    // number of work seconds in a day
    const int timeToDeliver = (END_TIME - START_TIME)*3600;
    int timeUsed = 0;
    bool outOfTime = false;

    expressDeliveries.sort(compareExpressDeliveries);
    while (!outOfTime) {
        ExpressDelivery e = expressDeliveries.front();
        if (timeUsed + e.getEstimatedDeliveryTime() > timeToDeliver)
            outOfTime = true;
        else {
            delivered.push_back(e);
            timeUsed += e.getEstimatedDeliveryTime();
        }
    }
    printResults();
}
