#include "Order.h"

int Order::getVolume() const {
    return volume;
}

int Order::getWeight() const {
    return weight;
}

int Order::getDeliveryFee() const {
    return deliveryFee;
}

void Order::setVolume(int vol) {
    volume = vol;
}

void Order::setWeight(int wei) {
    weight = wei;
}

void Order::setDeliveryFee(int fee) {
    deliveryFee = fee;
}
