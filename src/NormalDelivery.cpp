//
// Created by guilh on 06/04/2022.
//

#include "NormalDelivery.h"

int NormalDelivery::getVolume() const {
    return volume;
}

int NormalDelivery::getWeight() const {
    return weight;
}

int NormalDelivery::getDeliveryFee() const {
    return deliveryFee;
}

void NormalDelivery::setVolume(int vol) {
    volume = vol;
}

void NormalDelivery::setWeight(int wei) {
    weight = wei;
}

void NormalDelivery::setDeliveryFee(int fee) {
    deliveryFee = fee;
}