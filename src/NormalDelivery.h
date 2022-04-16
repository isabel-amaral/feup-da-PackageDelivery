#ifndef FEUP_DA_PACKAGEDELIVERY_NORMALDELIVERY_H
#define FEUP_DA_PACKAGEDELIVERY_NORMALDELIVERY_H

class NormalDelivery {
    int volume;
    int weight;
    int deliveryFee;
public:
    NormalDelivery(int v, int w, int fee);
    int getVolume() const;
    int getWeight() const;
    int getDeliveryFee() const;
    void setVolume(int vol);
    void setWeight(int wei);
    void setDeliveryFee(int fee);
    static bool sorting_package_weight(NormalDelivery n1, NormalDelivery n2);
    static bool sorting_package_volume(NormalDelivery n1, NormalDelivery n2);
    static bool sorting_package_addition(NormalDelivery n1, NormalDelivery n2);
    static bool compareFee(const NormalDelivery& a, const NormalDelivery& b);
};


#endif //FEUP_DA_PACKAGEDELIVERY_NORMALDELIVERY_H