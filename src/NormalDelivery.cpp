#include "NormalDelivery.h"

NormalDelivery::NormalDelivery(const int& v, const int& w, const int& fee) {
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

void NormalDelivery::incrementPriority() {
    priority++;
}

bool NormalDelivery::compareWeight(const NormalDelivery& n1, const NormalDelivery& n2) {
    if (n1.getPriority() == n2.getPriority())
        return n1.getWeight() > n2.getWeight();
    return n1.getPriority() > n2.getPriority();
}

bool NormalDelivery::compareVolume(const NormalDelivery& n1, const NormalDelivery& n2) {
    if (n1.getPriority() == n2.getPriority())
        return n1.getVolume() > n2.getVolume();
    return n1.getPriority() > n2.getPriority();
}

bool NormalDelivery::compareAddition(const NormalDelivery& n1, const NormalDelivery& n2) {
    if (n1.getPriority() == n2.getPriority())
        return n1.getVolume()+n1.getWeight() > n2.getVolume()+n2.getWeight();
    return n1.getPriority() > n2.getPriority();
}

bool NormalDelivery::compareFee(const NormalDelivery& n1, const NormalDelivery& n2) {
    if (n1.getPriority() == n2.getPriority()) {
        if (n1.deliveryFee == n2.deliveryFee)
            return n1.weight + n1.volume < n2.weight + n2.volume;
        return n1.deliveryFee > n2.deliveryFee;
    }
    return n1.getPriority() > n2.getPriority();
}

bool NormalDelivery::operator==(const NormalDelivery &delivery) const {
    return volume == delivery.volume &&
           weight == delivery.weight &&
           deliveryFee == delivery.deliveryFee;
}
