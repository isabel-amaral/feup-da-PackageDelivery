#ifndef FEUP_DA_PACKAGEDELIVERY_COMPANY_H
#define FEUP_DA_PACKAGEDELIVERY_COMPANY_H

#include <vector>
#include <algorithm>
#include <iostream>
#include <list>
#include "Driver.h"
#include "ExpressDelivery.h"
#include "NormalDelivery.h"

using namespace std;

class Company {
    /**
     * Drivers regitered in the company's platform, available to deliver orders.
     */
    list<Driver> drivers;
    /**
     * Normal shipping orders that must be delivered by the company.
     */
    list<NormalDelivery> normalDeliveries;
    /**
     * Express shipping orders that must be delivered by the company.
     */
    list<ExpressDelivery> expressDeliveries;
    /**
     * Company's profit after the delivery of normal orders.
     */
    int profit;

    /**
     * auxiliary struct for storing scenery 1 results
     */
    struct scenery1Results {
        int drivers;
        list<NormalDelivery> remainingPackages;
        int profit;
    };
    /**
     * auxiliary struct for storing scenery 1 results
     */
    scenery1Results results1;
    /**
     * auxiliary value for storing the percentage of delivered orders in scenery 1
     */
    int percentage;
    /**
     * auxiliary value for storing the number of deliveries to be made in scenery 2
     */
    int numDeliveries;
    /**
     * auxiliary list for storing the Orders to be delivered in scenery 3
     */
    list<ExpressDelivery> delivered;

public:
    Company();
    /**
     *
     * @return list of the drivers regitered in the company's platform, available to deliver orders
     */
    list<Driver>& getDrivers();
    /**
     *
     * @return list of the normal shipping orders that must be delivered by the company.
     */
    list<NormalDelivery>& getNormalDeliveries();
    /**
     *
     * @return list of the express shipping orders that must be delivered by the company.
     */
    list<ExpressDelivery>& getExpressDeliveries();
    /**
     * Updates the company's total profit.
     * @param profit new company's profit value.
     */
    void setProfit(const int& profit);
    /**
     * Adds a new driver to the list of the drivers regitered in the company's platform.
     * @param driver driver to be added to the company's list of available drivers.
     */
    void addDriver(const Driver& driver);
    /**
     * Adds a new normal shipping order to the list of normal shipping orders that must be delivered by the company.
     * @param normalDelivery order to be added to the list of normal shipping deliveires the company has to do.
     */
    void addNormalDelivery(const NormalDelivery& normalDelivery);
    /**
     * Adds a new express shipping order to the list of express shipping orders that must be delivered by the company.
     * @param expressDelivery order to be added to the list of express shipping deliveires the company has to do.
     */
    void addExpressDelivery(const ExpressDelivery& expressDelivery);

    //auxiliary methods for storing/printing results
    /**
     *
     * @return auxiliary struct with the storing of scenery 1 results
     */
    const scenery1Results &getResults1() const;
    /**
     *
     * @return auxiliary value for storing the percentage of delivered orders in scenery 1
     */
    int getPercentage() const;
    /**
     *
     * @return auxiliary value for storing the number of deliveries to be made in scenery 2
     */
    int getNumDeliveries() const;

    /*________________scenery1_____________*/
    /**
     * For each scenery 1 sorting criteria, checks if the current result is better than the current better result.
     * @param result result for the algorithm last computed.
     * @param currentBestResult best result up until now from all the previous computed algorithms.
     */
    static void checkBestResult(scenery1Results& result, scenery1Results& currentBestResult);
    /**
     * Distributes the normal shipping orders to deliver between the company's drivers in order to maximize the number of delivered packages
     * and minimize the number of used drivers. Bin Packing best fit logics.
     * @return struct with several values in order to determine weather the algorithm was the best so far.
     */
    scenery1Results allocatePackages();
    /**
     * Finds best distribution among the available drivers for the normal shipping orders. Considers three different sorting criteria for
     * the list of company drivers and normal shipping deliveries: \n
     * - descending in weight\n
     * - descending in volume\n
     * - descending in weight+volume\n
     * and, for each, finds best distribution by calling allocatePackages().
     * @return struct with several values from the best scenery 1 algorithm among the three.
     */
    scenery1Results scenery1();
    /**
     * Outputs text with scenery 1 result.
     * @param results struct with several values from the best algorithm among the three.
     * @param percentages percentage of delivered orders.
     */
    static void printResults1(const scenery1Results& results, const int& percentages);

    /*________________scenery2_____________*/
    /**
     * Finds best distribution among the available drivers for the normal shipping orders in order to maximize the company's profit.
     */
    void scenery2();
    /**
     * Outputs text with scenery 2 result.
     * @param numDeliveries number of delivered orders.
     */
    void printResults2(int numDeliveries) const;

    /*________________scenery3_______________*/
    /**
     * Decides which express shipping orders to deliver in order to minimize the average delivery time and maximize the number of delivered orders.
     */
    void scenery3();
    /**
     * Outputs text with scenery 3 result.
     */
    void printResults3() const;
};


#endif //FEUP_DA_PACKAGEDELIVERY_COMPANY_H
