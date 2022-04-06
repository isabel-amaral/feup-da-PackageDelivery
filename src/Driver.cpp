#include "Driver.h"

Driver::Driver() {

}

Driver::Driver(string r, int w, int v, int c) {
    this->carRegister = r;
    this->maxWeight = w;
    this->maxVolume = v;
    this->deliveryCost = c;
    this->ordersToDeliver = {};
}

const string &Driver::getCarRegister() const {
    return carRegister;
}

int Driver::getMaxWeight() const {
    return maxWeight;
}

int Driver::getMaxVolume() const {
    return maxVolume;
}

int Driver::getDeliveryCost() const {
    return deliveryCost;
}

const list<Order>& Driver::getOrdersToDeliver() const {
    return ordersToDeliver;
}

void Driver::setCarRegister(const string& carRegister) {
    this->carRegister = carRegister;
}

void Driver::setMaxWeight(int maxWeight) {
    this->maxWeight = maxWeight;
}

void Driver::setMaxVolume(int maxVolume) {
    this->maxVolume = maxVolume;
}

void Driver::setDeliveryCost(int deliveryCost) {
    this->deliveryCost = deliveryCost;
}

void Driver::setOrdersToDeliver(const list<Order> &ordersToDeliver) {
    this->ordersToDeliver = ordersToDeliver;
}

//TODO: verificar se é possível
void Driver::addOrder(const Order &order) {
    this->ordersToDeliver.push_back(order);
}