#ifndef FEUP_DA_PACKAGEDELIVERY_ORDER_H
#define FEUP_DA_PACKAGEDELIVERY_ORDER_H

class Order {
    int volume;
    int weight;
    int deliveryFee;
public:
    void setVolume(int vol);
    void setWeight(int wei);
    void setDeliveryFee(int fee);
    int getVolume();
    int getWeight();
    int getDeliveryFee();
};


#endif //FEUP_DA_PACKAGEDELIVERY_ORDER_H
