#ifndef FEUP_DA_PACKAGEDELIVERY_EXPRESSDELIVERY_H
#define FEUP_DA_PACKAGEDELIVERY_EXPRESSDELIVERY_H

class ExpressDelivery {
    /**
     * Estimated time for the order delivery.
     */
    int estimatedDeliveryTime;
    /**
     * Order delivery priority.
     */
    int priority;
public:
    ExpressDelivery(const int& edt);
    /**
     *
     * @return Estimated time for the order delivery.
     */
    int getEstimatedDeliveryTime() const;
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
     * compares them in ascending order according to their "estimatedDeliveryTime" attribute.
     * @param n1 Express Delivery 1
     * @param n2 Express Delivery 1
     * @return true if @param n1 is smaller than @param n2, else returns false.
     */
    static bool compareExpressDeliveries(const ExpressDelivery& n1, const ExpressDelivery& n2);
};


#endif //FEUP_DA_PACKAGEDELIVERY_EXPRESSDELIVERY_H