#include "ExpressDelivery.h"

ExpressDelivery::ExpressDelivery(const int& edt) {
    estimatedDeliveryTime = edt;
    priority = 1;
}

int ExpressDelivery::getEstimatedDeliveryTime() const {
    return estimatedDeliveryTime;
}

int ExpressDelivery::getPriority() const {
    return priority;
}

void ExpressDelivery::incrementPriority() {
    priority++;
}

bool ExpressDelivery::compareExpressDeliveries(const ExpressDelivery& n1, const ExpressDelivery& n2) {
    if (n1.getPriority() == n2.getPriority())
        return n1.getEstimatedDeliveryTime() < n2.getEstimatedDeliveryTime();
    return n1.getPriority() > n2.getPriority();
}
