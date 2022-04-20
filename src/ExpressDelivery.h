#ifndef FEUP_DA_PACKAGEDELIVERY_EXPRESSDELIVERY_H
#define FEUP_DA_PACKAGEDELIVERY_EXPRESSDELIVERY_H

class ExpressDelivery {
    int estimatedDeliveryTime;
public:
    ExpressDelivery(int edt);
    int getEstimatedDeliveryTime() const;
    static bool compareExpressDeliveries(const ExpressDelivery& a, const ExpressDelivery& b);
};


#endif //FEUP_DA_PACKAGEDELIVERY_EXPRESSDELIVERY_H