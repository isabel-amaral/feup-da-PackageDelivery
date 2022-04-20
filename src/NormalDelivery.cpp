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

bool NormalDelivery::compareWeight(const NormalDelivery& n1, const NormalDelivery& n2) {
    return n1.getWeight() > n2.getWeight();
}

bool NormalDelivery::compareVolume(const NormalDelivery& n1, const NormalDelivery& n2) {
    return n1.getVolume() > n2.getVolume();
}

bool NormalDelivery::compareAddition(const NormalDelivery& n1, const NormalDelivery& n2) {
    return n1.getVolume()+n1.getWeight() > n2.getVolume()+n2.getWeight();
}

bool NormalDelivery::compareFee(const NormalDelivery &a, const NormalDelivery &b) {
    if (a.deliveryFee == b.deliveryFee)
        return a.weight + a.volume < b.weight + b.volume;
    return a.deliveryFee > b.deliveryFee;
}

bool NormalDelivery::operator==(const NormalDelivery &delivery) const {
    return volume == delivery.volume && weight == delivery.weight && deliveryFee == delivery.deliveryFee;
}
