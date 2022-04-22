#ifndef FEUP_DA_PACKAGEDELIVERY_DRIVER_H
#define FEUP_DA_PACKAGEDELIVERY_DRIVER_H

#include <string>
#include <list>
#include "NormalDelivery.h"

using namespace std;

class Driver {
private:
    /**
     * Maximum weight that the driver's van can support.
     */
    int maxWeight;
    /**
     * Maximum volume that the driver's van can support.
     */
    int maxVolume;
    /**
     * Price charged for the delivery service.
     */
    int deliveryCost;
    /**
     * Orders to be delivered by the driver.
     */
    list<NormalDelivery> ordersToDeliver;
    /**
     * Weight sum of all packages that were allocated to the driver.
     */
    int currentOrderWeight;
    /**
     * Volume sum of all packages that were allocated to the driver.
     */
    int currentOrderVol;
public:
    Driver();
    Driver(const int& w, const int& v, const int& c);
    /**
     *
     * @return Maximum weight that the driver can transport.
     */
    int getMaxWeight() const;
    /**
     *
     * @return Maximum volume that the driver can transport.
     */
    int getMaxVolume() const;
    /**
     *
     * @return Price charged for the delivery service.
     */
    int getDeliveryCost() const;
    /**
     *
     * @return Orders to be delivered by the driver.
     */
    const list<NormalDelivery> &getOrdersToDeliver() const;
    /**
     *
     * @param order package to be added to the van.
     * @return true if the order was successfully added to the driver van (ordersToDeliver)
     */
    bool addOrder(const NormalDelivery& order);
    /**
     * Removes all orders that are allocated to the driver.
     */
    void removeOrders();
    /**
     * Compares drivers in descending order according to their "maxWeight" attribute.
     * @param d1 Driver 1
     * @param d2 Driver 2
     * @return true if @param d1 is greater than the @param d2, else returns false.
     */
    static bool compareWeight(const Driver &d1, const Driver &d2);
    /**
     * Compares drivers in descending order according to their "maxVolume" attribute.
     * @param d1 Driver 1
     * @param d2 Driver 2
     * @return true if @param d1 is greater than @param d2, else returns false.
     */
    static bool compareVolume(const Driver &d1, const Driver &d2);
    /**
     * Compares drivers in descending order according to the sum of "maxWeight" and "maxVolume" attributes.
     * @param d1 Driver 1
     * @param d2 Driver 2
     * @return true if @param d1 is greater than @param d2, else returns false.
     */
    static bool compareAddition(const Driver &d1, const Driver &d2);
     /**
      * Compares drivers in ascending order according to their "deliveryCost" attribute.
      * @param d1 Driver 1
      * @param d2 Driver 2
      * @return true if @param d1 is smaller than @param d2, else returns false.
      */
    static bool compareCost(const Driver& d1, const Driver& d2);
};

#endif //FEUP_DA_PACKAGEDELIVERY_DRIVER_H
