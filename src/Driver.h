#ifndef FEUP_DA_PACKAGEDELIVERY_DRIVER_H
#define FEUP_DA_PACKAGEDELIVERY_DRIVER_H

#include <string>
#include <list>
#include "NormalDelivery.h"

using namespace std;

class Driver {
private:
    int maxWeight;
    int maxVolume;
    int deliveryCost;
    list<NormalDelivery> ordersToDeliver;
    int currentOrderWeight;
    int currentOrderVol;
public:
    Driver();
    Driver(int w, int v, int c);
    int getMaxWeight() const;
    int getMaxVolume() const;
    int getDeliveryCost() const;
    const list<NormalDelivery> &getOrdersToDeliver() const;
    void setMaxWeight(int maxWeight);
    void setMaxVolume(int maxVolume);
    void setDeliveryCost(int deliveryCost);
    void setOrdersToDeliver(const list<NormalDelivery> &ordersToDeliver);
    bool addOrder(const NormalDelivery& order);
    void removeOrders();
    static bool compareWeight(const Driver &d1, const Driver &d2);
    static bool compareVolume(const Driver &d1, const Driver &d2);
    static bool compareAddition(const Driver &d1, const Driver &d2);
    static bool compareCost(const Driver& a, const Driver& b);
};

#endif //FEUP_DA_PACKAGEDELIVERY_DRIVER_H
