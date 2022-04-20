#include "ExpressDelivery.h"

ExpressDelivery::ExpressDelivery(int edt) {
    estimatedDeliveryTime = edt;
}

int ExpressDelivery::getEstimatedDeliveryTime() const {
    return estimatedDeliveryTime;
}

bool ExpressDelivery::compareExpressDeliveries(const ExpressDelivery& a, const ExpressDelivery& b) {
    return a.getEstimatedDeliveryTime() < b.getEstimatedDeliveryTime();
}
