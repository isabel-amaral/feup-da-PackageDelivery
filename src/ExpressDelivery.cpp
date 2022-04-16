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

bool ExpressDelivery::compareExpressDeliveries(const ExpressDelivery& a, const ExpressDelivery& b) {
    return a.getEstimatedDeliveryTime() < b.getEstimatedDeliveryTime();
}
