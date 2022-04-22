#ifndef FEUP_DA_PACKAGEDELIVERY_NORMALDELIVERY_H
#define FEUP_DA_PACKAGEDELIVERY_NORMALDELIVERY_H

class NormalDelivery {
    /**
     * Order volume.
     */
    int volume;
    /**
     * Order weight.
     */
    int weight;
    /**
     * Order delivery fee.
     */
    int deliveryFee;
    /**
     * Order delivery priority.
     */
    int priority;
public:
    NormalDelivery(const int& v,const int& w,const int& fee);
    /**
     *
     * @return Order volume.
     */
    int getVolume() const;
    /**
     *
     * @return Order weight.
     */
    int getWeight() const;
    /**
     *
     * @return Order delivery fee.
     */
    int getDeliveryFee() const;
    /**
     *
     * @return Order delivery priority.
     */
    int getPriority() const;
    /**
     * Increments the order delivery priority.
     */
    void incrementPriority();
    /**
     * Compares orders in descending order according to their "priority" attribute, if they are the same,
     * compares them in descending order according to their "weight" attribute.
     * @param n1 Normal Delivery 1
     * @param n2 Normal Delivery 2
     * @return true if @param n1 is greater than @param n2, else returns false.
     */
    static bool compareWeight(const NormalDelivery& n1, const NormalDelivery& n2);
    /**
     * Compares orders in descending order according to their "priority" attribute, if they are the same,
     * compares them in descending order according to their "volume" attribute.
     * @param n1 Normal Delivey 1
     * @param n2 Normal Delivery 2
     * @return true if @param n1 is greater than @param n2, else returns false.
     */
    static bool compareVolume(const NormalDelivery& n1, const NormalDelivery& n2);
    /**
     * Compares orders in descending order according to their "priority" attribute, if they are the same,
     * compares them in descending order according to the sum of their "weight" and "volume" attributes.
     * @param n1 Normal Delivey 1
     * @param n2 Normal Delivery 2
     * @return true if @param n1 is greater than @param n2, else returns false.
     */
    static bool compareAddition(const NormalDelivery& n1, const NormalDelivery& n2);
    /**
     * Compares orders in descending order according to their "priority" attribute, if they are the same,
     * compares them in ascending order according to the sum of their "deliveryFee" attribute, if they are the same,
     * compares them in descending order according to the sum of their "weight" and "volume" attributes.
     * @param n1
     * @param n2
     * @return true if @param n1 is greater than @param n2, else returns false.
     */
    static bool compareFee(const NormalDelivery& n1, const NormalDelivery& n2);
    /**
     * Two orders are equal if all their attributes are equal.
     * @param delivery is the object to be compared with this instance.
     * @return true if this instance is equal to @param delivery else returns false.
     */
    bool operator== (const NormalDelivery& delivery) const;
};


#endif //FEUP_DA_PACKAGEDELIVERY_NORMALDELIVERY_H