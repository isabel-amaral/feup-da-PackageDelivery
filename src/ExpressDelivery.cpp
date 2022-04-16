#include "ExpressDelivery.h"

ExpressDelivery::ExpressDelivery(int edt) {
    estimatedDeliveryTime = edt;
}

int ExpressDelivery::getEstimatedDeliveryTime() const {
    return estimatedDeliveryTime;
}

void ExpressDelivery::setEstimatedDeliveryTime(int edt) {
    estimatedDeliveryTime = edt;
}

bool ExpressDelivery::compareExpressDeliveries(const ExpressDelivery& a, const ExpressDelivery& b) {
    return a.getEstimatedDeliveryTime() < b.getEstimatedDeliveryTime();
}
