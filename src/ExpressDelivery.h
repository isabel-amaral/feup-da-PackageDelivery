#ifndef FEUP_DA_PACKAGEDELIVERY_EXPRESSDELIVERY_H
#define FEUP_DA_PACKAGEDELIVERY_EXPRESSDELIVERY_H

class ExpressDelivery {
    int estimatedDeliveryTime;
    int priority;
public:
    ExpressDelivery(int edt);
    int getEstimatedDeliveryTime() const;
    int getPriority() const;
    void setEstimatedDeliveryTime(int edt);
    void incrementPriority();
    static bool compareExpressDeliveries(const ExpressDelivery& a, const ExpressDelivery& b);
};


#endif //FEUP_DA_PACKAGEDELIVERY_EXPRESSDELIVERY_H