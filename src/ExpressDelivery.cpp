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
