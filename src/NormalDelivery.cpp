#include "NormalDelivery.h"

NormalDelivery::NormalDelivery(int v, int w, int fee) {
    volume = v;
    weight = w;
    deliveryFee = fee;
    priority = 1;
}

int NormalDelivery::getVolume() const {
    return volume;
}

int NormalDelivery::getWeight() const {
    return weight;
}

int NormalDelivery::getDeliveryFee() const {
    return deliveryFee;
}

int NormalDelivery::getPriority() const {
    return priority;
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
