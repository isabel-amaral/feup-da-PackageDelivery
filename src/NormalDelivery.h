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
    static bool compareWeight(const NormalDelivery& n1, const NormalDelivery& n2);
    static bool compareVolume(const NormalDelivery& n1, const NormalDelivery& n2);
    static bool compareAddition(const NormalDelivery& n1, const NormalDelivery& n2);
    static bool compareFee(const NormalDelivery& a, const NormalDelivery& b);
    bool operator== (const NormalDelivery& delivery) const;
};


#endif //FEUP_DA_PACKAGEDELIVERY_NORMALDELIVERY_H