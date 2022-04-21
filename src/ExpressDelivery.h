#ifndef FEUP_DA_PACKAGEDELIVERY_EXPRESSDELIVERY_H
#define FEUP_DA_PACKAGEDELIVERY_EXPRESSDELIVERY_H

class ExpressDelivery {
    int estimatedDeliveryTime;
    int priority;
public:
    ExpressDelivery(int edt);
    int getEstimatedDeliveryTime() const;
    int getPriority() const;
    void incrementPriority();
    static bool compareExpressDeliveries(const ExpressDelivery& n1, const ExpressDelivery& n2);
};


#endif //FEUP_DA_PACKAGEDELIVERY_EXPRESSDELIVERY_H