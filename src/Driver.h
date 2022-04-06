#ifndef FEUP_DA_PACKAGEDELIVERY_DRIVER_H
#define FEUP_DA_PACKAGEDELIVERY_DRIVER_H

#include <string>
#include <list>
//#include "Order.h" //TODO
using namespace std;

class Driver {
private:
    string carRegister;
    int maxWeight;
    int maxVolume;
    int deliveryCost;
    list<Order> ordersToDeliver; //TODO

public:
    Driver();
    Driver(string r, int w, int v, int c);
    const string &getCarRegister() const;
    int getMaxWeight() const;
    int getMaxVolume() const;
    int getDeliveryCost() const;
    //const list<Order> &getOrdersToDeliver() const; //TODO
    void setCarRegister(const string &carRegister);
    void setMaxWeight(int maxWeight);
    void setMaxVolume(int maxVolume);
    void setDeliveryCost(int deliveryCost);
    //void setOrdersToDeliver(const list<Order> &ordersToDeliver); //TODO
    void addOrder(const Order& order);
};

#endif //FEUP_DA_PACKAGEDELIVERY_DRIVER_H