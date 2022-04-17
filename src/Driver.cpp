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
    currentOrderWeight += order.getWeight();
    currentOrderVol += order.getVolume();
    this->ordersToDeliver.push_back(order);
    return true;
}

bool Driver::sorting_driver_weight(Driver d1, Driver d2) {
    return d1.getMaxWeight() > d2.getMaxWeight();
}

bool Driver::sorting_driver_volume(Driver d1, Driver d2) {
    return d1.getMaxVolume() > d2.getMaxVolume();
}

bool Driver::sorting_driver_addition(Driver d1, Driver d2) {
    return d1.getMaxVolume() + d1.getMaxWeight() > d2.getMaxVolume() + d2.getMaxWeight();
}

void Driver::removeOrders() {
    ordersToDeliver.clear();
    currentOrderWeight = 0;
    currentOrderVol = 0;
}

bool Driver::compareCost(const Driver &a, const Driver &b) {
    //if (a.deliveryCost == b.deliveryCost) return a.maxWeight + a.maxVolume > b.maxWeight + b.maxVolume; TODO: Decidir se deve-se considerar este caso ou não
    return a.deliveryCost < b.deliveryCost;
}