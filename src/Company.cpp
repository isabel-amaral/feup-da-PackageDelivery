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










