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
    void incrementPriority();
    static bool compareWeight(const NormalDelivery& n1, const NormalDelivery& n2);
    static bool compareVolume(const NormalDelivery& n1, const NormalDelivery& n2);
    static bool compareAddition(const NormalDelivery& n1, const NormalDelivery& n2);
    static bool compareFee(const NormalDelivery& n1, const NormalDelivery& n2);
    bool operator== (const NormalDelivery& delivery) const;
};


#endif //FEUP_DA_PACKAGEDELIVERY_NORMALDELIVERY_H