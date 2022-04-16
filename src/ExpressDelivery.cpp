#include "ExpressDelivery.h"

ExpressDelivery::ExpressDelivery(int edt) {
    estimatedDeliveryTime = edt;
    priority = 1;
}

int ExpressDelivery::getEstimatedDeliveryTime() const {
    return estimatedDeliveryTime;
}

int ExpressDelivery::getPriority() const {
    return priority;
}

void ExpressDelivery::setEstimatedDeliveryTime(int edt) {
    estimatedDeliveryTime = edt;
}

void ExpressDelivery::incrementPriority() {
    priority++;
}

bool ExpressDelivery::compareExpressDeliveries(const ExpressDelivery& a, const ExpressDelivery& b) {
    if (a.getPriority() == b.getPriority())
        return a.getEstimatedDeliveryTime() < b.getEstimatedDeliveryTime();
    return a.getPriority() > b.getPriority();
}
