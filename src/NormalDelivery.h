//
// Created by guilh on 06/04/2022.
//

#ifndef FEUP_DA_PACKAGEDELIVERY_NORMALDELIVERY_H
#define FEUP_DA_PACKAGEDELIVERY_NORMALDELIVERY_H

class NormalDelivery {
    int volume;
    int weight;
    int deliveryFee;
public:
    int getVolume() const;
    int getWeight() const;
    int getDeliveryFee() const;
    void setVolume(int vol);
    void setWeight(int wei);
    void setDeliveryFee(int fee);
};


#endif //FEUP_DA_PACKAGEDELIVERY_NORMALDELIVERY_H
