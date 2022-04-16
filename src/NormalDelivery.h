#ifndef FEUP_DA_PACKAGEDELIVERY_NORMALDELIVERY_H
#define FEUP_DA_PACKAGEDELIVERY_NORMALDELIVERY_H

class NormalDelivery {
    int volume;
    int weight;
    int deliveryFee;
    int priority;
public:
    NormalDelivery(int v, int w, int fee);
    int getVolume() const;
    int getWeight() const;
    int getDeliveryFee() const;

    int getPriority() const;

    void setVolume(int vol);
    void setWeight(int wei);
    void setDeliveryFee(int fee);
};


#endif //FEUP_DA_PACKAGEDELIVERY_NORMALDELIVERY_H