#ifndef FEUP_DA_PACKAGEDELIVERY_EXPRESSDELIVERY_H
#define FEUP_DA_PACKAGEDELIVERY_EXPRESSDELIVERY_H

#include "order.h"

class ExpressDelivery : public Order {
    int estimatedDeliveryTime;
public:
    void setEstimatedDeliveryTime(int edt);
    int getEstimatedDeliveryTime();
};


#endif //FEUP_DA_PACKAGEDELIVERY_EXPRESSDELIVERY_H