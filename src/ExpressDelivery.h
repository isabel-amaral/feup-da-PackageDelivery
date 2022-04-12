#ifndef FEUP_DA_PACKAGEDELIVERY_EXPRESSDELIVERY_H
#define FEUP_DA_PACKAGEDELIVERY_EXPRESSDELIVERY_H

class ExpressDelivery {
    int estimatedDeliveryTime;
public:
    ExpressDelivery(int v, int w, int fee, int edt);
    int getVolume() const;
    int getWeight() const;
    int getDeliveryFee() const;
    int getEstimatedDeliveryTime() const;
    void setVolume(int vol);
    void setWeight(int wei);
    void setDeliveryFee(int fee);
    void setEstimatedDeliveryTime(int edt);
};


#endif //FEUP_DA_PACKAGEDELIVERY_EXPRESSDELIVERY_H