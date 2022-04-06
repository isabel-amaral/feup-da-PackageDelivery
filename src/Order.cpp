#include "Order.h"

void Order::setVolume(int vol) {
    volume = vol;
}

void Order::setWeight(int wei) {
    weight = wei;
}

void Order::setDeliveryFee(int fee) {
    deliveryFee = fee;
}

int Order::getVolume() {
    return volume;
}

int Order::getWeight() {
    return weight;
}

int Order::getDeliveryFee() {
    return deliveryFee;
}
