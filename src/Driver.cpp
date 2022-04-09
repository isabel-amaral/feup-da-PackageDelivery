#include "Driver.h"

Driver::Driver() {

}

Driver::Driver(int w, int v, int c) {
    this->maxWeight = w;
    this->maxVolume = v;
    this->deliveryCost = c;
    this->ordersToDeliver = {};
    this->currentOrderWeight = 0;
    this->currentOrderVol = 0;
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

const list<NormalDelivery>& Driver::getOrdersToDeliver() const {
    return ordersToDeliver;
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

void Driver::setOrdersToDeliver(const list<NormalDelivery> &ordersToDeliver) {
    this->ordersToDeliver = ordersToDeliver;
}

//TODO: verificar se é possível
bool Driver::addOrder(const NormalDelivery &order) {
    if (currentOrderWeight + order.getWeight() > maxWeight)
        return false;
    if (currentOrderVol + order.getVolume() > maxVolume)
        return false;
    this->ordersToDeliver.push_back(order);
    return true;
}