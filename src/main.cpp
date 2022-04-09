#include <iostream>
#include <algorithm>
#include "Company.h"
#include "LoadData.h"

using namespace std;

int firstFit(const int weight[], int n, const int c[], int size)
{
    // Sum of All Weights
    int count = 0;
    for (int i = 0; i < n; i++) {
        count += weight[i];
    }

    // Biggest capacity of all available
    int max = c[0];
    for (int i = 1; i < size; i++) {
        if (c[i] > max)
            max = c[i];
    }

    // If biggest capacity > sum of all weights, they all fit in 1 driver
    if (max >= count) return 1;

    // Initialize result (Count of drivers)
    int res = 0;

    // Create an array to store remaining space in drivers' vans, there can be at most n vans
    int bin_rem[size];
    for (int i = 0; i < size; i++) {
        bin_rem[i] = c[i];
    }

    // Place items one by one
    for (int i = 0; i < n; i++) {
        // Find the first driver that can accommodate weight[i]
        if (weight[i] > max) {
            cout << "This item is too big for any of our drivers!" << endl;
            continue;
        }
        int j;
        for (j = 0; j < res; j++) {
            if (bin_rem[j] >= weight[i]) {
                bin_rem[j] -= weight[i];
                break;
            }
        }

        // If no driver could accommodate weight[i]
        if (j == res) {
            bin_rem[res] = c[res] - weight[i];
            res++;
        }

    }
    return res;
}

int firstFitDec(int weight[], int n, int c[], int size)
{
    // First sort all weights and capacities in decreasing order
    sort(weight, weight + n, greater<>());
    sort(c, c + size, greater<>());

    // Now call first fit for sorted items
    return firstFit(weight, n, c, size);
}

int main(){
    Company company;
    string d= "drivers.txt";
    string n = "normalDel.txt";
    string e = "expressDel.txt";
    LoadData loadData(company, d, n, e);
    company = loadData.getCompany();
    cout << "HEllo" << endl;
}