#include "Driver.h"

Driver::Driver() {

}

Driver::Driver(const int& w, const int& v, const int& c) {
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

bool Driver::addOrder(const NormalDelivery &order) {
    if (currentOrderWeight + order.getWeight() > maxWeight)
        return false;
    if (currentOrderVol + order.getVolume() > maxVolume)
        return false;
    currentOrderWeight += order.getWeight();
    currentOrderVol += order.getVolume();
    this->ordersToDeliver.push_back(order);
    return true;
}

void Driver::removeOrders() {
    ordersToDeliver.clear();
    currentOrderWeight = 0;
    currentOrderVol = 0;
}

bool Driver::compareWeight(const Driver &d1, const Driver &d2) {
    return d1.getMaxWeight() > d2.getMaxWeight();
}

bool Driver::compareVolume(const Driver &d1, const Driver &d2) {
    return d1.getMaxVolume() > d2.getMaxVolume();
}

bool Driver::compareAddition(const Driver &d1, const Driver &d2) {
    return d1.getMaxVolume() + d1.getMaxWeight() > d2.getMaxVolume() + d2.getMaxWeight();
}

bool Driver::compareCost(const Driver &d1, const Driver &d2) {
    if (d1.deliveryCost == d2.deliveryCost)
        return d1.maxWeight + d1.maxVolume > d2.maxWeight + d2.maxVolume;
    return d1.deliveryCost < d2.deliveryCost;
}