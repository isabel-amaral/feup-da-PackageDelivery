//
// Created by guilh on 06/04/2022.
//

#include "ExpressDelivery.h"

void ExpressDelivery::setVolume(int vol) {
    volume = vol;
}

void ExpressDelivery::setWeight(int wei) {
    weight = wei;
}

void ExpressDelivery::setDeliveryFee(int fee) {
    deliveryFee = fee;
}

void ExpressDelivery::setEstimatedDeliveryTime(int edt) {
    estimatedDeliveryTime = edt;
}

int ExpressDelivery::getVolume() const {
    return volume;
}

int ExpressDelivery::getWeight() const {
    return weight;
}

int ExpressDelivery::getDeliveryFee() const {
    return deliveryFee;
}

int ExpressDelivery::getEstimatedDeliveryTime() {
    return estimatedDeliveryTime;
}